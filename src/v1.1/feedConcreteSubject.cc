
#include "./feedConcreteSubject.h"


FeedConcreteSubject::FeedConcreteSubject(){}
FeedConcreteSubject::~FeedConcreteSubject(){}


std::list<std::string> FeedConcreteSubject::getState(std::shared_ptr<Observer> o){
    if(std::find(membersCristiano.begin(), membersCristiano.end(), o) != membersCristiano.end()){
        if(std::find(membersMessi.begin(), membersMessi.end(), o) != membersMessi.end()){
            std::list<std::string> aux = messagesMessi;
            aux.insert(aux.end(),messagesCristiano.begin(), messagesCristiano.end());
            return aux;
        }else{
            return messagesCristiano;
        }
    }else if(std::find(membersMessi.begin(), membersMessi.end(), o) != membersMessi.end()){
        return messagesMessi;
    }else{
        return messages;
    }
}



void FeedConcreteSubject::setState(std::string s, std::string interest){
    if(interest == "cristiano"){
        messagesCristiano.push_back(s);
        Notify(interest);
    }else if(interest == "messi"){
        messagesMessi.push_back(s);
        Notify(interest);
    }
}

