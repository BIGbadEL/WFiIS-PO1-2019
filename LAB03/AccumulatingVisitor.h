#pragma once

#include "Visitor.h"

/**
 * @class AccumulatingVisitor
 * @brief klasa sluzaca do sumowania informacji obiektach pochodnych typu Data
 * 
 */

class AccumulatingVisitor : public Visitor {
    public:

        /**
         * @brief dodaje do sumy dane zawarte w obiekcie typu IntData
         * 
         * @param data wskaznik na obiekt typu IntData
         */

        void visit(IntData* data){
            _sum += static_cast<float>(data->get());
        }

        /**
         * @brief dodaje do sumy dane zawarte w obiekcie typu FloatData
         * 
         * @param data wskaznik na obiekt typu FloatData
         */

        void visit(FloatData* data){
            _sum += data->getFloat();
        }

        /**
         * @brief zwraca zakumulowana wczesniej sume
         * 
         * @return float -> suma
         */

        float getTotalSum() const { return _sum; }
    private:
        float _sum = 0;
};