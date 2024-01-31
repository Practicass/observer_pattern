#include <iostream>
#include "feedConcreteSubject.h"
#include "userConcreteObserver.h"
#include <thread>


using namespace std;

void User(int i, FeedConcreteSubject* feed, std::string filename, std::string name){
     // for (int i = 0; i < 5; i++)
     // {
     //      std::this_thread::sleep_for(std::chrono::seconds(i));
     //      std::dynamic_pointer_cast<UserConcreteObserver>(user)->Send(i);
     
     // }
     std::shared_ptr<Observer> user = std::make_shared<UserConcreteObserver>(name, feed, filename);
     feed->Attach(user);

     // if (i==1){
     //      for (int i = 0; i < 10; i++){
     //           std::dynamic_pointer_cast<UserConcreteObserver>(user)->Send(i);  
               
     //      }
     // }
     
     for (int i = 0; i < 2; i++){
          std::dynamic_pointer_cast<UserConcreteObserver>(user)->Send(i);  
          
     }
     
}


int main()
{
     

     int mode;
     std::cout << "Choose mode: 1 for manual, 2 for threads and 3 for interest modification" << std::endl;
     std::cin >> mode;

     if (mode == 1){
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
               
     }else if (mode == 2){
          FeedConcreteSubject* feed = new FeedConcreteSubject();

          thread users[3];
          std::string filenames[3] = {"feedPablo.txt", "feedMiguel.txt", "feedLucas.txt"};
          std::string names[3] = {"Pablo", "Miguel", "Lucas"};
          
          for (int i = 0; i < 3; i++)
          {
               users[i] = thread(&User, i, feed, filenames[i], names[i]);
          }
          

          for (int i = 0; i < 3; i++)
          {
               users[i].join();
          }

     }else{
          
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
          cris->Send(2, "cristiano");


          // std::dynamic_pointer_cast<UserConcreteObserver>(user3)->Send(3);
          // std::dynamic_pointer_cast<UserConcreteObserver>(user1)->Send(1);
          // std::dynamic_pointer_cast<UserConcreteObserver>(user2)->Send(2);


     }
     
    

     


}