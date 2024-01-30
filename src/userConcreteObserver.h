#pragma once


#include "chatConcrectSubject.h"
#include <list>
#include <memory>
#include <string>

class UserConcreteObserver : public Observer {
    private:
        std::string name;
        std::list<std::string> msg;
        ChatConcreteSubject* subject;
        
        
    public:
        UserConcreteObserver(std::string n, ChatConcreteSubject* s);
        ~UserConcreteObserver();
      

        std::list<std::string> getMessages();
        
};