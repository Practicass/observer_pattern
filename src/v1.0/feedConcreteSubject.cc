
#include "./feedConcreteSubject.h"


FeedConcreteSubject::FeedConcreteSubject(){}
FeedConcreteSubject::~FeedConcreteSubject(){}

std::list<std::string> FeedConcreteSubject::getState(){
    return messages;
}


void FeedConcreteSubject::setState(std::string s){

    messages.push_back(s);
    Notify();
}



