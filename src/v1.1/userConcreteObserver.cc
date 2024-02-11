#include "./userConcreteObserver.h"


UserConcreteObserver::UserConcreteObserver(std::string n, FeedConcreteSubject* s, std::string filename): name(n), subject(s){
    //create a file and should be the file descriptor in private. So each user will have a file where he will write the messages
    file.open(filename, std::ios::out | std::ios::trunc | std::ios::in);
    if (!file.is_open()){
        std::cout << "Error opening file" << std::endl;
    }
    
    
}

UserConcreteObserver::UserConcreteObserver(std::string n, FeedConcreteSubject* s): name(n), subject(s){}
UserConcreteObserver::~UserConcreteObserver(){}

void UserConcreteObserver::Send(int i, std::string interest){
    std::srand(i);
    int randomNumber = std::rand() % 49;
    msg.push_back(MESSAGES[randomNumber]);
    subject->setState(MESSAGES[randomNumber], interest);

}


void UserConcreteObserver::Update(){
    std::shared_ptr<Observer> aux = shared_from_this();
    msg = subject->getState(aux);
    getMessages();
}

std::list<std::string> UserConcreteObserver::getMessages(){
    file << "---------------------"<< std::endl;
    for (auto i : msg){
        file << i << std::endl;
    }
    return msg;

}