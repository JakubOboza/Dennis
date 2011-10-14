#ifndef __DENNIS_ROUTER_H__
#define __DENNIS_ROUTER_H__

#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <event.h>
#include <evhttp.h>

#include <string>
#include <vector>

struct Response{
  int status;
  std::string& body;
};

class IController {
  public:
  virtual Response& execute(std::string& path, evhttp_request* req);
};

struct Route{
  std::string& path;
  IController* controller_ptr;
};

class Router{
  public:
  std::vector<Route*>* routes;

  Reponse* route(struct evhttp_request *req){
    //TODO implement traversing route list and calling controller
    // Add Boost and regexs
  }

  Router* add_route(Route* route){
    this->routes.push_back(route);
    // enable chaining
    return this;
  }

};


#endif
