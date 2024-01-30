
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

class ChatSubject {

    private:
        // observers list
        std::list<std::shared_ptr<Observer>> members;
         
        
        
    public:
        ChatSubject();
        ~ChatSubject();
        void Attach(std::shared_ptr<Observer> o);
        void Detach(std::shared_ptr<Observer> o);
        void Notify();
};