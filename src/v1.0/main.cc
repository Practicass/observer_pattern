#include <iostream>
#include "feedConcreteSubject.h"
#include "userConcreteObserver.h"


#include <thread>


using namespace std;




int main()
{
     
        FeedConcreteSubject* feed = new FeedConcreteSubject();


        std::shared_ptr<Observer> Pablo = std::make_shared<UserConcreteObserver>("Pablo", feed, "feedPablo.txt");
        std::shared_ptr<Observer> Miguel = std::make_shared<UserConcreteObserver>("Miguel",feed, "feedMiguel.txt");
        std::shared_ptr<Observer> Lucas = std::make_shared<UserConcreteObserver>("Lucas", feed, "feedLucas.txt");

        feed->Attach(Pablo);
        feed->Attach(Miguel);
        feed->Attach(Lucas);

        std::dynamic_pointer_cast<UserConcreteObserver>(Lucas)->Send(3);
        std::dynamic_pointer_cast<UserConcreteObserver>(Pablo)->Send(1);
        std::dynamic_pointer_cast<UserConcreteObserver>(Miguel)->Send(2);

        feed->Detach(Lucas);

        std::dynamic_pointer_cast<UserConcreteObserver>(Pablo)->Send(1);                   
}