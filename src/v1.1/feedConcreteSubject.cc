
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
        std::list<std::string> ans;
        for (auto i : messagesCristiano){
            ans.push_back(i);
        }
        for (auto i : messagesMessi){
            ans.push_back(i);
        }

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

