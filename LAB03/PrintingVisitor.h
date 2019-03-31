#pragma once

#include "Visitor.h"
#include "ElData.h"

/**
 * @class PrintingVisitor
 * @brief klasa sluzaca do wypisywania danch zawartych w pochonych obiektch typu Data
 * 
 */

class PrintingVisitor : public Visitor {
    public:

        PrintingVisitor() = default;

        /**
         * @brief wypisuje dane zawarte w obiekcie typu IntData
         * 
         * @param data wskaznik na obiekt typy IntData
         */

        void visit(IntData* data) {
            std::cout << ' ' << data->get() ;
        }

        /**
         * @brief wypisuje dane zawarte w obieci typu FloatData
         * 
         * @param data wskaznik na obiekt typu FloatData
         */

        void visit(FloatData* data) {
            std::cout << ' ' << data->getFloat() ;
        }
};