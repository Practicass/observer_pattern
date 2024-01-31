#include <iostream>
#include "chatConcrectSubject.h"
#include "userConcreteObserver.h"
#include <thread>


using namespace std;

void User(std::shared_ptr<Observer> user, int i){
     // for (int i = 0; i < 5; i++)
     // {
     //      std::this_thread::sleep_for(std::chrono::seconds(i));
     //      std::dynamic_pointer_cast<UserConcreteObserver>(user)->Chat(i);
     
     // }
     if (i==1){
          for (int i = 0; i < 10; i++){
               std::dynamic_pointer_cast<UserConcreteObserver>(user)->Chat(i);  
               std::dynamic_pointer_cast<UserConcreteObserver>(user)->Chat(i);
          }
     }
     
}


int main()
{
     

     int mode;
     std::cout << "Choose mode: 1 for manual, 2 for threads" << std::endl;
     std::cin >> mode;

     if (mode == 1){
          ChatConcreteSubject* chat = new ChatConcreteSubject();


          std::shared_ptr<Observer> user1 = std::make_shared<UserConcreteObserver>("Pablo", chat, "chatPablo.txt");
          std::shared_ptr<Observer> user2 = std::make_shared<UserConcreteObserver>("Miguel",chat, "chatMiguel.txt");
          std::shared_ptr<Observer> user3 = std::make_shared<UserConcreteObserver>("Lucas", chat, "chatLucas.txt");

          chat->Attach(user1);
          chat->Attach(user2);
          chat->Attach(user3);
          
          std::dynamic_pointer_cast<UserConcreteObserver>(user3)->Chat(3);
          std::dynamic_pointer_cast<UserConcreteObserver>(user1)->Chat(1);
          std::dynamic_pointer_cast<UserConcreteObserver>(user2)->Chat(2);
               
     }else {
          ChatConcreteSubject* chat = new ChatConcreteSubject();


          std::shared_ptr<Observer> user1 = std::make_shared<UserConcreteObserver>("Pablo", chat, "chatPablo.txt");
          std::shared_ptr<Observer> user2 = std::make_shared<UserConcreteObserver>("Miguel",chat, "chatMiguel.txt");
          std::shared_ptr<Observer> user3 = std::make_shared<UserConcreteObserver>("Lucas", chat, "chatLucas.txt");

          chat->Attach(user1);
          chat->Attach(user2);
          chat->Attach(user3);

          thread t1;
          thread t2;
          thread t3;
          t1 = thread(&User, ref(user1),1);
          t2 = thread(&User, ref(user2),2);
          t3 = thread(&User, ref(user3),3);
          t1.join();
          t2.join();
          t3.join();
     }
     
    

     


}