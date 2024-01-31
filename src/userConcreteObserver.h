#pragma once


#include "feedConcreteSubject.h"
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
        FeedConcreteSubject* subject;
        std::ofstream file;

        
        
        
    public:
        UserConcreteObserver(std::string n, FeedConcreteSubject* s, std::string filename);
        UserConcreteObserver(std::string n, FeedConcreteSubject* s);
        ~UserConcreteObserver();
      
        void Update() override;
        std::list<std::string> getMessages();

        void Send(int i);
        void Send(int i, std::string interest);
        
};