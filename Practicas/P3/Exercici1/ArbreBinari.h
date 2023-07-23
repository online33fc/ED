#ifndef ARBREBINARI_H
#define ARBREBINARI_H

#include <iostream>
#include <stdexcept>
#include "NodeBinari.h"
#include <vector>
using namespace std;

template <class Clau, class Valor>
class ArbreBinari {
    public:
        ArbreBinari();
        ArbreBinari(const ArbreBinari<Clau, Valor>& orig);
        virtual ~ArbreBinari();

        bool isEmpty() const;
        int height() const;

        NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);
        const Valor& valueOf(const Clau& clau) const;
        void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const; //parent, left, right
        void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const; //left, parent, right
        void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const; //left, right, parent
        vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const; 
        void imprimirCami(Clau key) const;
        void eliminaMinim();

    protected:
        NodeBinari<Clau,Valor>* root;
        NodeBinari<Clau,Valor>* search(const Clau& k) const;
        
    private:
        int _size;
        /* Mètodes auxiliars definiu aquí els que necessiteu */
        vector<NodeBinari<Clau,Valor>*> obteValorsRangAux(NodeBinari<Clau,Valor>* node, int k1, int k2, vector<NodeBinari<Clau,Valor>*> resultat) const;
        void imprimirCamiAux(NodeBinari<Clau,Valor>* node, NodeBinari<Clau,Valor>* node2) const;
};

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(){
    this->_size = 0;
    this->root = nullptr;
    cout << "Arbre Creat " <<endl;
}


template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(const ArbreBinari<Clau, Valor>& orig){
    this->_size = orig._size;
    this->root = new NodeBinari<Clau, Valor>(*orig.root);
    cout << "Constructor copia creat " << endl;
}

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::~ArbreBinari(){
    delete root;
    cout<<"Abre binari destruit"<<endl;
}

template <class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const{
    return root == nullptr;
}

template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() const{
    if(isEmpty()){
        throw invalid_argument("L'Arbre es buid");
    }
    return root->height();
}

template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::insert(const Clau& clau, const Valor& value){
    NodeBinari<Clau, Valor>* node;

    if(isEmpty()){
        this->root = new NodeBinari<Clau, Valor>(clau, value); 
        this->root->insertValue(value);
        _size++;
        cout << "Inserta a l'arbre element: " << clau << endl;
        return root;

    }else{
        NodeBinari<Clau, Valor>* tmp = root;
        NodeBinari<Clau, Valor>* tmp2;
        while(tmp != nullptr){ //Busca el ultim node introduit 
            tmp2 = tmp;
            if(clau < tmp->getKey()){
                tmp = tmp->getLeft();
            }else if(clau > tmp->getKey()){
                tmp = tmp->getRight();
            }else{
                tmp = nullptr;
            }  
        }

        //Crea un nou node, el qual afegeix a la esquerra o dreta
        if(clau > tmp2->getKey()){
            node = new NodeBinari<Clau, Valor>(clau, value);
            node->insertValue(value);
            tmp2->setRight(node);
            node->setParent(tmp2);
            _size++;

        }else if(clau < tmp2->getKey()){
            node = new NodeBinari<Clau, Valor>(clau, value);
            node->insertValue(value); 
            tmp2->setLeft(node);
            node->setParent(tmp2);
            _size++;

        }else{
            node = tmp2;
            node->insertValue(value);
        }  
        cout << "Inserta a l'arbre element: "<< clau << endl;
        return node;
    }   
}

template <class Clau, class Valor>
const Valor& ArbreBinari<Clau, Valor>::valueOf(const Clau& clau) const{
    NodeBinari<Clau, Valor>* aux = search(clau);
    if(isEmpty()){
        throw invalid_argument("Es buit");
    }
    return aux->getValue();
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPreordre(const NodeBinari<Clau,Valor>* n) const{ //root, esq, dre
    if(isEmpty()){
        throw invalid_argument("L'Arbre es buid, no es pot fer el Preordre");
    }

    if(n == nullptr){
        imprimirPreordre(root);
    }
    else{
        cout << n->getKey() << endl; //root

        if(n->hasLeft()){
            imprimirPreordre(n->getLeft()); //esq
        }
        if(n->hasRight()){
            imprimirPreordre(n->getRight()); //dre
        }
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirInordre(const NodeBinari<Clau,Valor>* n) const{ //esq, root, dre
    if(isEmpty()){
        throw invalid_argument("L'Arbre es buid, no es pot fer el Inordre");
    }

    if(n == nullptr){
        imprimirInordre(root);
    }
    else{

        if(n->hasLeft()){ //equivalent a fer n->getLeft() != nullptr
            imprimirInordre(n->getLeft());
        }

        cout << n->getKey() << endl; //root

        if(n->hasRight()){
            imprimirInordre(n->getRight());
        }

    }

}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPostordre(const NodeBinari<Clau,Valor>* n) const{ //esq, dre, root
    if(isEmpty()){
        throw invalid_argument("L'Arbre es buid, no es pot fer el Postordre");
    }

    if(n == nullptr){
        imprimirPostordre(root);
    }

    else{

        if(n->hasLeft()){
            imprimirPostordre(n->getLeft());
        }

        if(n->hasRight()){
            imprimirPostordre(n->getRight());
        }

        cout << n->getKey() << endl; //root

    }
}

template <class Clau, class Valor>
vector<NodeBinari<Clau,Valor>*> ArbreBinari<Clau, Valor>::obteValorsRangAux(NodeBinari<Clau,Valor>* node, int k1, int k2, vector<NodeBinari<Clau,Valor>*> resultat) const{
    if(node == nullptr){
        throw invalid_argument("Es buit");
    }

    if(node->getKey() < k1){ //si el node es menor a k1
        obteValorsRangAux(node->getRight(), k1, k2, resultat);
    }
    else if(node->getKey() >= k1 && node->getKey() <= k2){ // si esta entre els 2 valors
        resultat.push_back(node);
        obteValorsRangAux(node->getLeft(), k1, k2, resultat);
        obteValorsRangAux(node->getRight(), k1, k2, resultat);
        
    }else{ //si es major
        obteValorsRangAux(node->getLeft(), k1, k2, resultat);
    }

    return resultat;
}

template <class Clau, class Valor>
vector<NodeBinari<Clau,Valor>*> ArbreBinari<Clau, Valor>::obteValorsRang(int k1, int k2) const{
    vector<NodeBinari<Clau,Valor>*> resultat;
    if(root == nullptr){
        return resultat;
    }
    obteValorsRangAux(root, k1, k2, resultat);
    return resultat;
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCamiAux(NodeBinari<Clau,Valor>* node, NodeBinari<Clau,Valor>* node2) const{
    if(node == nullptr){
        return;
    }
    
    cout << node->getKey() <<endl;

    if(node->getKey() == node2->getKey()){
        cout << " " << endl;
        return;
    }

    imprimirCamiAux(node->getLeft(), node2);
    imprimirCamiAux(node->getRight(), node2);
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau key) const{
    if(isEmpty()){
        throw invalid_argument("L'arbre es buit ");
    }else{
        NodeBinari<Clau,Valor>* node2 = search(key);
        if(node2 != nullptr){
            imprimirCamiAux(root, node2);
        }else{
            cout << "Key no trobada " << endl;
        }
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim(){
    if(root == nullptr){
        return;
    }

    NodeBinari<Clau, Valor>* tmp = root;
    NodeBinari<Clau, Valor>* _parent = nullptr;

    while(tmp->getLeft() != nullptr){
        _parent = tmp;
        tmp = tmp->getLeft();
    }

    if(_parent == nullptr){
        NodeBinari<Clau, Valor>* _dreta = tmp->getRight();
        delete tmp;
        root = _dreta;
    }else{
        _parent->setLeft(tmp->getRight());
        delete tmp;
    }
}

template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::search(const Clau& k) const{
    NodeBinari<Clau, Valor>* tmp = root;
    while(tmp != tmp){
        if(tmp->getKey() == k){
            return tmp; //tornem el tmp perque es el key que busquem
        }else if(tmp->getKey() > k){
            tmp = tmp->getRight();
        }else{
            tmp = tmp->getLeft();
        }
    }
    return tmp;
}

#endif // ARBREBINARI_H