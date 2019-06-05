#pragma once
#include <vector>
#include <typeinfo>

class NodeInterface{
    friend class List;
    public:
        NodeInterface(): _next(nullptr) {}
        virtual ~NodeInterface(){
            if(_next != nullptr){
                delete _next;
            }
        }
        template <typename T>
        bool isType();
        NodeInterface* next() const { return _next; }
    private:
        NodeInterface* _next;
};

template <typename T>
class Node : public NodeInterface {
    public:
        Node(T data): _data(data) {}
        T getData() const { return _data; }
    private:
        T _data;
};

class List {
    public:

        List(): _elements(nullptr) {}
        ~List(){
           delete _elements;           
        }

        template <typename T>
        void add(T el) { 
            if(_elements == nullptr){
                _elements = new Node<T>(el);
            } else {
                NodeInterface* temp = _elements;
                _elements = new Node<T>(el);
                _elements->_next = temp;   
            }
        }

        NodeInterface* head() { return _elements; };
        
        template <typename T>
        static T get(NodeInterface* _element){
            return dynamic_cast<Node<T>&>(*_element).getData();   
        }

    private:
        NodeInterface* _elements;
};

template <typename T>
bool NodeInterface::isType(){
    return typeid(*this) == typeid(Node<T>);
}