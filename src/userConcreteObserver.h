#pragma once


#include "chatConcrectSubject.h"
#include "messages.cc"
#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>   

class UserConcreteObserver : public Observer {
    private:
        std::string name;
        std::list<std::string> msg;
        ChatConcreteSubject* subject;
        std::ofstream file;

        
        
        
    public:
        UserConcreteObserver(std::string n, ChatConcreteSubject* s, std::string filename);
        ~UserConcreteObserver();
      
        void Update() override;
        std::list<std::string> getMessages();

        void Chat(int i);
        
};