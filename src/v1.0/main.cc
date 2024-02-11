#include <iostream>
#include "feedConcreteSubject.h"
#include "userConcreteObserver.h"


#include <thread>


using namespace std;




int main()
{
     
        FeedConcreteSubject* feed = new FeedConcreteSubject();


        std::shared_ptr<Observer> user1 = std::make_shared<UserConcreteObserver>("Pablo", feed, "feedPablo.txt");
        std::shared_ptr<Observer> user2 = std::make_shared<UserConcreteObserver>("Miguel",feed, "feedMiguel.txt");
        std::shared_ptr<Observer> user3 = std::make_shared<UserConcreteObserver>("Lucas", feed, "feedLucas.txt");

        feed->Attach(user1);
        feed->Attach(user2);
        feed->Attach(user3);

        std::dynamic_pointer_cast<UserConcreteObserver>(user3)->Send(3);
        std::dynamic_pointer_cast<UserConcreteObserver>(user1)->Send(1);
        std::dynamic_pointer_cast<UserConcreteObserver>(user2)->Send(2);

        feed->Detach(user3);

        std::dynamic_pointer_cast<UserConcreteObserver>(user1)->Send(1);                   
}