#include "../engine/Server/Router.cpp"
#include "../app/http/controllers/testController.cpp"
#pragma once
void routers(){

    router->Get("/",&TestController::index);
    router->Get("/about",&TestController::about);
    router->Get("/test",&TestController::test);
}


