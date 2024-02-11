/* ----------------------------------------------------------------------------
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   feberero 2024
 * Coms:   Práctica 1 Arquitectura software
 *         
 * -----------------------------------------------------------------------------
 */
#include "./feedSubject.h"


FeedSubject::FeedSubject(){

}

FeedSubject::~FeedSubject(){

}

void FeedSubject::Attach(std::shared_ptr<Observer> o){
    members.push_back(o);
}


void FeedSubject::Detach(std::shared_ptr<Observer> o){
    members.remove(o);
}

void FeedSubject::Notify(){

    for (auto i : members) {
        i->Update();
    }

}
