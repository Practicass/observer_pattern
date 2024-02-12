#include <iostream>
#include "./feedConcreteSubject.h"


#include "./userConcreteObserver.h"
#include <thread>


using namespace std;




int main()
{

    FeedConcreteSubject* feed = new FeedConcreteSubject();

    UserConcreteObserver* mes = new UserConcreteObserver("Messi", feed);
    UserConcreteObserver* cris = new UserConcreteObserver("Cristiano", feed);

    std::shared_ptr<Observer> Pablo = std::make_shared<UserConcreteObserver>("Pablo", feed, "feedPablo.txt");
    std::shared_ptr<Observer> Miguel = std::make_shared<UserConcreteObserver>("Miguel",feed, "feedMiguel.txt");
    std::shared_ptr<Observer> Lucas = std::make_shared<UserConcreteObserver>("Lucas", feed, "feedLucas.txt");

    feed->Attach(Pablo, "cristiano");
    feed->Attach(Miguel, "messi");
    feed->Attach(Lucas, "messi");
    feed->Attach(Miguel, "cristiano");

    mes->Send(1, "messi");
    cris->Send(2, "cristiano");
    cris->Send(3, "cristiano");

    feed->Detach(Pablo, "cristiano");
    cris->Send(4, "cristiano");





}