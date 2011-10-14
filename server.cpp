#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib/application.h"


int main(int argc, char **argv)
{
  short          http_port = 8081;
  char          *http_addr = "127.0.0.1";
  struct evhttp *http_server = NULL;

  int opt;
  while((opt = getopt(argc, argv, "p:")) != -1 ){
    switch(opt){
      case 'p':
        http_port = (short)atoi(optarg);
        printf("%d", http_port);
      break;
    }
  }

  Application* app = new Application(http_port, http_addr);
  app->init();
  // app->set_router(router);
  app->set_self();
  app->run();
  delete app;
  return 0;

}
