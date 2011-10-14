#ifndef __DENNIS_APPLICATION_H__
#define __DENNIS_APPLICATION_H__

#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <event.h>
#include <evhttp.h>

class Application {
  public:
  short port;
  char* http_addr;
  struct evhttp* http_server;

  Application (short port, char* http_addr);

  static void generic_request_handler(struct evhttp_request *req, void *app_ptr)
  {
    Application* app = (Application*)app_ptr;
    struct evbuffer *returnbuffer = evbuffer_new();

    evbuffer_add_printf(returnbuffer, "Thanks for the request!");
    evhttp_send_reply(req, HTTP_OK, "Client", returnbuffer);
    evbuffer_free(returnbuffer);
    return;
  }

  void init();
  void set_handler( void (*generic_request_handler)(struct evhttp_request*, void* ) );
  void set_self();
  void run();
};


#endif
