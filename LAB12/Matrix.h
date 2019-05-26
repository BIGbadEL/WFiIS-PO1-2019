#pragma once
#include <iostream>

/**
 * @brief klasa reprezutujaca macierz o dowolnym rozmiarze i dowolnym typie
 * 
 * @tparam T -> typ jaki macierz ma przetryzmywac
 * @tparam c -> liczba kolumn
 * @tparam k -> liczba wierszy
 */

template <typename T, int c, int k>
class Matrix {
    public:
    /**
     * @brief Konstruje nowy obiekt typu matrix oraz wypelnia go zerami
     * 
     */
        Matrix();

        /**
         * @brief ustawia wszystkie elementy macierzy na zadana wartosc
         * 
         * @param value -> zadana wartosc
         */

        void reset(T value);

        /**
         * @brief metoda pozwalajaca na dodawanie macierzy roznego typu ale z takimi samymi rozmiarami
         * 
         * @tparam D -> typ przetrzymywany przez inna macierz
         * @param other -> macierz ktora ma zostac dodany do naszej macirzy
         */

        template <typename D >
        void add(const Matrix<D, c, k>& other);

        /**
         * @brief funkajca pozwalajaca na dostep do elementow macierzy oraz modyfikownia ich
         * 
         * @tparam x -> numer kolumny
         * @tparam y -> numer wiersza
         * @return T& -> referencja na element macierzy
         */

        template <int x, int y>
        T& at() { return m_data[x][y]; }

        /**
         * @brief odpowiednik funkcji wyzszej dla stalych obiektow pozwala na dostep ale nie na modyfikacje zawarotosci
         * 
         * @tparam x -> numer kolumny
         * @tparam y -> numer wiersza
         * @return const T& refenercja na staly element macirzy
         */

        template <int x, int y>
        const T& at() const { return m_data[x][y]; }

        /**
         * @brief nie szablonowa wersja wyzszych metod
         * 
         * @param x -> numer kolumny
         * @param y -> numer wiersza
         * @return const T& referencja na stala wartosc
         */
    
        inline const T& at(int x, int y) const {
            return m_data[x][y];
        }

    private:
        T m_data[c][k]; /**< tablica z elementami macierzy >*/
};

/**
 * @brief przeladowany operator struminia dla klasy macierz
 * 
 * @param stream -> strumien 
 * @param mat -> macirzy ktora chcemy wypisac na ekran
 * @return std::ostream& -> referencja na zmodyfikowny strumiec
 */

template <typename T, int c, int k>
std::ostream& operator<<(std::ostream& stream, const Matrix<T, c, k>& mat){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < c; j++){
            stream << mat.at(j, i) << " ";
        }
        stream << "\n";
    }
    return stream;
}

template <typename T, int c, int k>
Matrix<T, c, k>::Matrix() {
        for(int i = 0; i < c; i++){
            for(int j = 0; j < k; j++){
                m_data[i][j] = 0;
        }
    }
}

template <typename T, int c, int k>
void Matrix<T, c, k>::reset(T value){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < k; j++){
            m_data[i][j] = value;
        }
    }
}

template <typename T, int c, int k>
template <typename D>
void Matrix<T, c, k>::add(const Matrix<D, c, k>& other){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < k; j++){
            m_data[i][j] += other.at(i, j);
        }
    }
}