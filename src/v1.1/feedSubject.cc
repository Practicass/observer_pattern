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


void FeedSubject::Attach(std::shared_ptr<Observer> o, std::string interest){
    if(interest == "cristiano"){
        membersCristiano.push_back(o);
    }else if(interest == "messi"){
        membersMessi.push_back(o);
    }
}

void FeedSubject::Detach(std::shared_ptr<Observer> o, std::string interest){
    if(interest == "cristiano"){
        membersCristiano.remove(o);
    }else if(interest == "messi"){
        membersMessi.remove(o);
    }

}



void FeedSubject::Notify(std::string interest){

    if (interest == "cristiano")
    {
                                
        for (auto i : membersCristiano) {
            i->Update();
        }
    }else
    {            
        for (auto i : membersMessi) {
            i->Update();
        }
    }
    
    
}