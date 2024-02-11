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

          std::shared_ptr<Observer> user1 = std::make_shared<UserConcreteObserver>("Pablo", feed, "feedPablo.txt");
          std::shared_ptr<Observer> user2 = std::make_shared<UserConcreteObserver>("Miguel",feed, "feedMiguel.txt");
          std::shared_ptr<Observer> user3 = std::make_shared<UserConcreteObserver>("Lucas", feed, "feedLucas.txt");

          feed->Attach(user1, "cristiano");
          feed->Attach(user2, "messi");
          feed->Attach(user3, "messi");
          feed->Attach(user2, "cristiano");

          mes->Send(1, "messi");
          cris->Send(2, "cristiano");
          cris->Send(3, "cristiano");


}