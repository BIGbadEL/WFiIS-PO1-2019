//Tomasz Praszkiewicz
//Grzegorz Litarowicz

#pragma once
#include <iostream>
/**
 * @brief represents dynamic array
 * 
 * @tparam T type stored in array
 */
template <typename T>
class DynArray{
    public:
        /**
         * @brief iterator for DynArray
         * 
         */
        class Iterator {
            public:
            /**
             * @brief Construct a new Iterator object
             * 
             * @param data stores data
             * @param index stores index
             */
                Iterator(T* data, int index = 0): _data(data), _index(index) {}
                /**
                 * @brief increments index
                 * 
                 * @return Iterator& returns reference to interator
                 */

                Iterator& operator++(){
                    ++_index;
                    return *this;
                }
                /**
                 * @brief compares current iterator adress
                 * 
                 * @param other iterator to compare to
                 * @return true aren't equal
                 * @return false are equal
                 */
                bool operator!=(const Iterator& other) const { 
                    return (_data + _index) != (other._data + other._index); 
                }
                /**
                * @brief overladed * operator
                *      
                * @return T returns current element 
                */
                T& operator*(){
                    return *(_data + _index);
                }

                /**
                 * @brief overladed -> operator
                 * 
                 * @return T* pointer to current element
                 */
                T* operator->(){
                    return _data + _index;
                }
            private:

                T* _data; /**<stores data >*/
                int _index;/**<stores current index>*/
        };
        /**
         * @brief Construct a new Dyn Array object
         * 
         * @param size size of array
         */
        DynArray(int size): _size(size), _data(new T[size]) { }
        /**
         * @brief Construct a new Dyn Array object
         * 
         * @param size size of array
         * @param other const array of T
         */
        DynArray(int size, const T* other): DynArray(size) {
            for(int i = 0; i < this->size(); i++){
                _data[i] = other[i]; 
            }
        }
        /**
         * @brief Destroy the Dyn Array object
         * 
         */
        ~DynArray(){
            delete[] _data;
        }
        /**
         * @brief allows acces via [] interfate to data
         * 
         * @param i index
         * @return T& refetence to data at index i
         */
        T& operator[](int i) { return _data[i]; }
        
        /**
         * @brief allows acces via [] interfate to data as const
         * 
         * @param i index
         * @return const T& refetence to const data at index i 
         */
        const T& operator[](int i) const { return _data[i]; }

        /**
         * @brief returns size of array
         * 
         * @return int size of array
         */
        int size() const { return _size; }
        /**
         * @brief creates mew iterator to begins of array
         * 
         * @return Iterator created iterator
         */
        Iterator begin() {
            return Iterator(_data);
        }
        /**
         * @brief creates mew iterator to end of array
         * 
         * @return Iterator created iterator
         */
        Iterator end() {
            return Iterator(_data, _size);
        }


    private:
        int _size;/**<stores size of array>*/
        T* _data;/**<stores content of array>*/

};
/**
 * @brief alloes desplay of array
 * 
 * @tparam T type of elements stored in array
 * @param stream ostream that will be add to
 * @param arr array to be desplayed
 * @return std::ostream& stream which added array
 */
template <typename T>
std::ostream& operator<<(std::ostream& stream, const DynArray<T>& arr){
    stream << "{";
    for(int i = 0; i < arr.size() - 1; i++){
        stream << "\"" << arr[i] << "\","; 
    }
    stream << "\"" << arr[arr.size() - 1] << "\"}"; 
    return stream;
}

