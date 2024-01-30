/* ----------------------------------------------------------------------------
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   feberero 2024
 * Coms:   Práctica 1 Arquitectura software
 *         
 * -----------------------------------------------------------------------------
 */

#pragma once
#include "chatSubject.h"
#include <string>

class ChatConcreteSubject : public ChatSubject {
    private:
        std::list<std::string> messages;
        
    public:

        ChatConcreteSubject();

        ~ChatConcreteSubject();
        std::list<std::string> getState();
        void setState(std::string s);
        
};