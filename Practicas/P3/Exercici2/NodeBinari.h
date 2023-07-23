#ifndef NODEBINARI_H
#define NODEBINARI_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <class Clau, class Valor>
class NodeBinari {
    public:
        NodeBinari(const Clau& key, const Valor& v);
        NodeBinari(const NodeBinari<Clau,Valor >& orig);
        virtual ~NodeBinari();

        /* Modificadors */
        // declareu aquí els modificadors (setters) dels atributs que necessiteu
        void setParent(NodeBinari<Clau, Valor>* parent);
        void setLeft(NodeBinari<Clau, Valor>* left);
        void setRight(NodeBinari<Clau, Valor>* right);
        

        /* Consultors */
        const Clau& getKey() const;
        const Valor& getValue() const;
        // declareu aquí els consultors (getters) dels atributs que necessiteu
        NodeBinari<Clau, Valor>* getParent() const;//retorna el parent del node
        NodeBinari<Clau, Valor>* getLeft() const;//retorna el fill esquerra del node
        NodeBinari<Clau, Valor>* getRight() const;//retorna el fill dret del node
        

        /* Operacions */
        bool isRoot() const;
        bool hasLeft() const;
        bool hasRight() const;
        bool isExternal() const;
        void insertValue(const Valor & v);
        int height() const;
        bool operator==(const NodeBinari<Clau,Valor >& node) const;

    private:
        Clau key;
        Valor value;
        // afegiu aquí els atributs que falten
        NodeBinari<Clau, Valor>* _parent;
        NodeBinari<Clau, Valor>* _left;
        NodeBinari<Clau, Valor>* _right;
        
};

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const Clau& key, const Valor& v){
    this->key = key;
    this->value = v;
    this->_parent = nullptr;
    this->_left = nullptr;
    this->_right = nullptr;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const NodeBinari<Clau,Valor>& orig){
    this->key = orig.key;
    this->value = orig.value;
    //comprobar si es correcte
    if(orig._left != nullptr){
        this->_left = new NodeBinari<Clau, Valor>(*orig._left);
        this->_left->setParent(this);
    }
    if(orig._right != nullptr){
        this->_right = new NodeBinari<Clau, Valor>(*orig._right);
        this->_right->setParent(this);
    }
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::~NodeBinari(){
    cout << "Eliminant " << this->key << "\n";
    
    delete _left;
    delete _right;
}

template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setParent(NodeBinari<Clau, Valor>* parent){
    _parent = parent;
}

template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setLeft(NodeBinari<Clau, Valor>* left){
    _left = left;
}

template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setRight(NodeBinari<Clau, Valor>* right){
    _right = right;
}

template <class Clau, class Valor>
const Clau& NodeBinari<Clau, Valor>::getKey() const{
    return key;
}

template <class Clau, class Valor>
const Valor& NodeBinari<Clau, Valor>::getValue() const{
    return value;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getParent() const{
    return _parent;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getLeft() const{
    return _left;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getRight() const{
    return _right;
}

template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isRoot() const{
    return _parent == nullptr;
}

template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasLeft() const{
    return _left != nullptr;
}

template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasRight() const{
    return _right != nullptr;
}

template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isExternal() const{
    return _left == nullptr && _right == nullptr;
}



template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::insertValue(const Valor& v) {
    NodeBinari<Clau, Valor>* node = new NodeBinari<Clau, Valor>(getKey(), v);
    node->setParent(_parent);
    node->setLeft(_left);
    node->setRight(_right);

    if(isRoot()){ 
        if(_parent->getLeft() == this){
            _parent->setLeft(node);
        }else if(_parent->getRight() == this) {
            _parent->setRight(node);
        }
    }

    if(hasLeft()){
        _left->setParent(node);
    }
    if(hasRight()){
        _right->setParent(node);
    }

    _parent = nullptr;
    _left = nullptr;
    _right = nullptr;
}

template <class Clau, class Valor>
int NodeBinari<Clau, Valor>::height() const{
    if(this->isExternal()){
        return 1;
    }
    else if( _left != nullptr && _right != nullptr){
        return max(_left->height(), _right->height()) + 1;
    }
    else if(_left == nullptr){
        return _right->height() + 1;
    }
    else{
        return _left->height() + 1;
    }
}

template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::operator==(const NodeBinari<Clau,Valor >& node) const{
    return key == node.key && value == node.value;
}


#endif // NODEBINARI_H