/* ----------------------------------------------------------------------------
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   feberero 2024
 * Coms:   Práctica 1 Arquitectura software
 *         
 * -----------------------------------------------------------------------------
 */

#pragma once
#include "feedSubject.h"
#include <string>
#include <iostream>

class FeedConcreteSubject : public FeedSubject {
    private:
        std::list<std::string> messages;
        
    public:

        FeedConcreteSubject();

        ~FeedConcreteSubject();
        std::list<std::string> getState();
        void setState(std::string s);
        void setState(std::string s, std::string interest);
        
};