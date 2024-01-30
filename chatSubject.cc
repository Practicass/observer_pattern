/* ----------------------------------------------------------------------------
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   feberero 2024
 * Coms:   Práctica 1 Arquitectura software
 *         
 * -----------------------------------------------------------------------------
 */
#include "chatSubject.h"


ChatSubject::ChatSubject(){

}

ChatSubject::~ChatSubject(){

}

void ChatSubject::Attach(std::shared_ptr<Observer> o){
    members.push_back(o);
}

void ChatSubject::Detach(std::shared_ptr<Observer> o){
    members.remove(o);
}

void ChatSubject::Notify(){
    for (auto i : members) {
        i->Update();
    }
}