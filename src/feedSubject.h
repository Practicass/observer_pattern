
/* ----------------------------------------------------------------------------
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   feberero 2024
 * Coms:   Práctica 1 Arquitectura software
 *         
 * -----------------------------------------------------------------------------
 */
#pragma once

#include "observer.h"
#include <list>
#include <memory>
#include <string>

class FeedSubject {

    private:
        // observers list
        std::list<std::shared_ptr<Observer>> members;
        std::list<std::shared_ptr<Observer>> membersCristiano;
        std::list<std::shared_ptr<Observer>> membersMessi;

        
         
        
        
    public:
        FeedSubject();
        ~FeedSubject();
        void Attach(std::shared_ptr<Observer> o);
        void Attach(std::shared_ptr<Observer> o, std::string interest);
        void Detach(std::shared_ptr<Observer> o);
        void Notify();
        void Notify(std::string interest);
};