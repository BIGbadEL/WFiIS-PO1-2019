#pragma once

class FloatData;
class IntData;

class Visitor {
    public:

    /**
     * @brief defaultoy kontrukotr kalsy Visitor
     * 
     */

    Visitor() = default;

    /**
     * @brief obsuguje vistiora dla IntData
     * 
     * @param data wskanik na obiekt IntData
     */

    virtual void visit(IntData* data) = 0;

    /**
     * @brief obsluguje visitora dla FloatData
     * 
     * @param data wskaznik na obiekt FloatData
     */

    virtual void visit(FloatData* data) = 0;

    /**
     * @brief Virtualny destrkutor stworzony ze wzgledu na polimorficzny charakter klasy
     * 
     */

    virtual ~Visitor() = default;
};