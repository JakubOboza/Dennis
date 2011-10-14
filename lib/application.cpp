#include "application.h"

// implemnetation of application class

Application::Application(short port, char* http_addr){
  this->port = port;
  this->http_addr = http_addr;
}

void Application::run(){
  fprintf(stderr, "Server started on port %d\n", this->port );
  event_dispatch();
}

void Application::set_self(){
  http_server = evhttp_start(this->http_addr, this->port );
  evhttp_set_gencb(this->http_server, this->generic_request_handler, (void*)this);
}

void Application::set_handler( void (*generic_request_handler)(struct evhttp_request*, void* ) ){
  http_server = evhttp_start(this->http_addr, this->port );
  evhttp_set_gencb(this->http_server, generic_request_handler, (void*)this);
}

void Application::init(){
  event_init();
}

