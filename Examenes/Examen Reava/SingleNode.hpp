#pragma once

/*
 *  NOM: xxxxxxxx
 *  COGNOM: xxxxxxxx
 *  DNI O NIUB: xxxxxxxx
 */

template <class Element>
class SingleNode
{
public:
    SingleNode();
    SingleNode(Element element);
    SingleNode(const SingleNode<Element>& other);
    ~SingleNode();

    const Element& getElement() const;

    SingleNode<Element>* getNext() const;
    void setNext(SingleNode<Element>* node);

private:
    Element _element;
    SingleNode<Element>* _next;
};

/************* constructors *****************/
// add code here


/************* destructor *****************/
// add code here


/************* sets/gets *****************/
// add code here


