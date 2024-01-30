#include "userConcreteObserver.h"

UserConcreteObserver::UserConcreteObserver(std::string n, ChatConcreteSubject* s): name(n), subject(s){
    //create a file and should be the file descriptor in private. So each user will have a file where he will write the messages
}
UserConcreteObserver::~UserConcreteObserver(){}