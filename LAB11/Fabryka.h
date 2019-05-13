#pragma once

/**
 * @brief klasa pozwalajaca na zapisanie specyficznego obietku i produkowanie nowych obiektow takich samch jak zapisany w prototypie
 * 
 */

class Factory {
    public:

    /**
     * @brief funkcja pozwalacaza na ustaiwnie porototypu ktory zostanie uzyty do pozniejszego stwoczenia obiektu
     * 
     * @tparam T -> typ obiektu dla ktorego chcemy ustaiwc prototyp
     * @param obj -> obiekt ktory ma sie stac prototypem
     * @param change -> flaga pozwalacaca na rozroznienie czy chcemy zaktualizowac prototyp czy odczytac wczesniej ustawiony
     * @return T -> aktulany prototyp
     */

     template <typename T>
     T prototype(const T& obj, bool change = true){
        static T prototyp = obj;
        if(change){
            prototyp = obj;
        }
        return prototyp;
     }

        /**
         * @brief funkcja ktora pozwala na stworznie obiektu za pomoca prototypu jesli nie zostal on wczesniej stworzony to zostanie wykorzystany konstruktor domyslny
         * 
         * @tparam T -> typ obiektu ktory tworzymy
         * @return T -> nowy obiekt
         */

     template <typename T>
     T produce(){
        return prototype(T{}, false);
     }
};