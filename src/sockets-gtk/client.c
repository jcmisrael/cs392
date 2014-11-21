#include "sockets.h"

#define BUF_LEN_MAX 256

int servfd = -1;
char connected_gl = 0;

void sig_bye(){
  extern int servfd;
  send(servfd, "/exit", 6, 0);
  close(servfd);
  my_str("\nExiting myirc_client.\n");
  exit(0);
}

void logout(){
  extern int servfd;
  extern char connected_gl;
  char str[6] = "/exit";
  send(servfd, str, 6, 0);
  close(servfd);
  connected_gl = 0;
}


static void connect_cb(GtkWidget* button, gpointer fields){
  struct addrinfo* ailist;
  struct addrinfo* currai;
  struct addrinfo hint;
  extern int servfd;
  extern char connected_gl;
  char* hostname;
  char* port;
  char* username;
  int err;
  GtkEntry** data = fields;
  hostname = my_strdup((char*)gtk_entry_get_text(data[0]));
  port = my_strdup((char*)gtk_entry_get_text(data[1]));
  username = my_strdup((char*)gtk_entry_get_text(data[2]));

  hint.ai_flags = 0;
  hint.ai_family = AF_INET;
  hint.ai_socktype = SOCK_STREAM;
  hint.ai_protocol = 0;
  hint.ai_addrlen = 0;
  hint.ai_canonname = NULL;
  hint.ai_addr = NULL;
  hint.ai_next = NULL;
  
  if((err = getaddrinfo(hostname, port, &hint, &ailist)) != 0){
    connected_gl = 0;
    my_str((char*)gai_strerror(err));
  } else {
    for(currai = ailist; currai != NULL; currai = currai->ai_next){
      if((servfd = socket(currai->ai_family, SOCK_STREAM, 0)) >= 0){
	if(connect(servfd, currai->ai_addr, currai->ai_addrlen) == 0){
	  send(servfd, username, BUF_LEN_MAX, 0);
	  connected_gl = 1;
	  break;
	}
	connected_gl = 0;
	close(servfd);
	my_str("Connection error");
      }
      connected_gl = 0;
      close(servfd);
      my_str("Socket error");
    }
  }
#ifdef DEBUG
  my_str("connect_cb finished\n");
#endif
}

static void connect_cb_cancel(GtkWidget* dialog, GtkWidget* button){
  gtk_dialog_response(GTK_DIALOG(dialog), GTK_RESPONSE_CANCEL);
  gtk_widget_hide(dialog);
}

static void connect_cb_ok(GtkWidget* dialog, GtkWidget* button){
  extern char connected_gl;
  if(connected_gl){
    gtk_dialog_response(GTK_DIALOG(dialog), GTK_RESPONSE_ACCEPT);
  } else {
    gtk_dialog_response(GTK_DIALOG(dialog), GTK_RESPONSE_CANCEL);
  }
  gtk_widget_hide(dialog);
}

static void exitdialogue(GtkWidget* widget,
			    gpointer data){
  gint res = gtk_dialog_run((GtkDialog*)widget);
  extern char connected_gl;
  switch(res){
  case GTK_RESPONSE_ACCEPT:
    if(connected_gl)
      logout();
    gtk_main_quit();
    break;
  }
  gtk_widget_hide(widget);
}

static void enter_callback(GtkWidget *widget,
			   GtkWidget* entry){
  char*  message_text = NULL;
  char** mVect = NULL;
  extern char connected_gl;
  extern int servfd;
  int strLen;
  if(connected_gl){
    message_text = my_strdup((char*)gtk_entry_get_text(GTK_ENTRY(entry)));
    strLen = my_strlen(message_text);
    mVect = my_str2vect(message_text);
    if(!my_strcmp(mVect[0], "/exit")){
      logout();
    } else {
      send(servfd, message_text, strLen, 0);
    }
    my_freevect(mVect);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    free(message_text);
  }
}


static void toggle_button_callback(GtkWidget* widget,
				   GtkWidget* button){
  gint res;
  extern int servfd;
  extern char connected_gl;
  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button))){
    res = gtk_dialog_run((GtkDialog*)widget);
    switch(res){
    case GTK_RESPONSE_CANCEL:
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), FALSE);
      gtk_button_set_label(GTK_BUTTON(button), "Connect");
      close(servfd);
      break;
    default:
      gtk_button_set_label(GTK_BUTTON(button), "Disconnect");
      break;
    }
    gtk_widget_hide(widget);
  } else {
    logout();
    gtk_button_set_label(GTK_BUTTON(button), "Connect");
  }
}

static void destroy(GtkWidget* widget,
		    gpointer data){
  gtk_main_quit();
}

static gboolean delete_event(GtkWidget* widget,
			     GdkEvent* event,
			     gpointer data){
  g_print("Error: Could Not Close Window.\n");
  return TRUE;
}

int main(int argc, char** argv){
  GtkWidget* window;
  GtkWidget* button;
  GtkWidget* table;
  GtkWidget* ctable;
  GtkWidget* textfield;
  GtkWidget* dialog;
  GtkDialogFlags dflags;
  GtkWidget* carea;
  GtkWidget* label;
  GtkWidget** ctfields = xmalloc(3 * sizeof(GtkWidget*));

  gtk_init(&argc, &argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "MyIRC");
  gtk_widget_set_size_request(window, 300, 100);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  
  g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

  table = gtk_table_new(2, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);
  ctable = gtk_table_new(2, 3, FALSE);

  dflags = (GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL);
  dialog = gtk_dialog_new_with_buttons("Really Exit?",
				       (GtkWindow*)window,
				       dflags,
				       GTK_STOCK_YES,
				       GTK_RESPONSE_ACCEPT,
				       GTK_STOCK_NO,
				       GTK_RESPONSE_CANCEL,
				       NULL);

  textfield = gtk_entry_new();
  g_signal_connect(textfield, "activate",
		   G_CALLBACK(enter_callback), textfield);
  gtk_table_attach_defaults(GTK_TABLE(table), textfield, 0, 1, 0, 1);
  gtk_widget_show(textfield);

  button = gtk_button_new_with_label("Send");
  g_signal_connect(button, "clicked", G_CALLBACK(enter_callback), (gpointer) textfield);
  gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 0, 1);
  gtk_widget_show(button);

  button = gtk_button_new_with_label("Quit");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(exitdialogue), dialog);
  gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 1, 2);
  gtk_widget_show(button);

  dialog = gtk_dialog_new();
  carea = gtk_dialog_get_content_area((GtkDialog*)dialog);
  gtk_box_pack_start((GtkBox*)carea, ctable, FALSE, FALSE, 0);
  ctfields[0] = gtk_entry_new();
  label = gtk_label_new("Hostname:");
  gtk_table_attach_defaults(GTK_TABLE(ctable), label, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(ctable), ctfields[0], 1, 2, 0, 1);
  gtk_widget_show(label);
  gtk_widget_show(ctfields[0]);

  label = gtk_label_new("Port:");
  ctfields[1] = gtk_entry_new();
  gtk_table_attach_defaults(GTK_TABLE(ctable), label, 0, 1, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(ctable), ctfields[1], 1, 2, 1, 2);  
  gtk_widget_show(label);
  gtk_widget_show(ctfields[1]);

  label = gtk_label_new("Username:");
  ctfields[2] = gtk_entry_new();
  gtk_table_attach_defaults(GTK_TABLE(ctable), label, 0, 1, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE(ctable), ctfields[2], 1, 2, 2, 3);
  gtk_widget_show(label);
  gtk_widget_show(ctfields[2]);

  gtk_widget_show(ctable);

  ctable = gtk_table_new(2, 1, FALSE);
  carea = gtk_dialog_get_action_area(GTK_DIALOG(dialog));
  gtk_box_pack_start(GTK_BOX(carea), ctable, FALSE, FALSE, 0);
  button = gtk_button_new_with_label("Connect");
  gtk_table_attach_defaults(GTK_TABLE(ctable), button, 0, 1, 0, 1);
  g_signal_connect(button, "clicked", G_CALLBACK(connect_cb), ctfields);
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(connect_cb_ok), dialog);
  gtk_widget_show(button);

  button = gtk_button_new_with_label("Cancel");
  gtk_table_attach_defaults(GTK_TABLE(ctable), button, 1, 2, 0, 1);
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(connect_cb_cancel), dialog);
  gtk_widget_show(button);

  gtk_widget_show(ctable);
  
  button = gtk_toggle_button_new_with_label("Connect");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(toggle_button_callback), dialog);
  gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 1, 2);
  gtk_widget_show(button);

  gtk_widget_show(table);
  gtk_widget_show(window);
  
  gtk_main();

  return 0;
}

/*int main(int argc, char** argv){
  int err;
  char* input = NULL;
  int strLen;
  char** inputVect = NULL;
  if(argc != 3){
    my_str("Usage: ./myirc_client <hostname> <port>\n");
    exit(1);
  }
  signal(SIGINT, sig_bye);
  signal(SIGQUIT, sig_bye);
  input = xmalloc(BUF_LEN_MAX);
	my_str("Enter username: ");
	strLen = read(0, input, BUF_LEN_MAX) - 1;
	input[strLen] = '\0';
#ifdef DEBUG
	my_str("Sending username.\n");
#endif
	send(servfd, input, strLen, 0);
	while(1){
	  my_char('>');
	  strLen = read(0, input, BUF_LEN_MAX) - 1;
	  if(strLen >= 1){
#ifdef DEBUG
	    my_str("Input accepted.\n");
#endif
	    input[strLen] = '\0';
	    inputVect = my_str2vect(input);
	   
	  }
	}
      }
      close(servfd);
      my_err("Connect error");
    }
    close(servfd);
    my_err("Socket error");
  }
  exit(0);
  }*/

