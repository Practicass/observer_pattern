#include <iostream>
#include "chatConcrectSubject.h"
#include "userConcreteObserver.h"

using namespace std;


int main()
{
     ChatConcreteSubject* chat = new ChatConcreteSubject();

     // Create users and think them to be a thread
     UserConcreteObserver* user1 = new UserConcreteObserver("Pablo", chat);
     UserConcreteObserver* user2 = new UserConcreteObserver("Miguel",chat);
     UserConcreteObserver* user3 = new UserConcreteObserver("Lucas", chat);
}