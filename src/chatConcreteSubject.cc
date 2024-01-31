
#include "chatConcrectSubject.h"


ChatConcreteSubject::ChatConcreteSubject(){}
ChatConcreteSubject::~ChatConcreteSubject(){}

std::list<std::string> ChatConcreteSubject::getState(){
    return messages;
}

void ChatConcreteSubject::setState(std::string s){

    messages.push_back(s);
    Notify();
}

