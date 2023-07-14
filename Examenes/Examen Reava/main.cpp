/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: professors_ED
 *
 * Created on June 29, 2023
 */

#include <cstdlib>
#include "SpecialQueue.hpp"

using namespace std;

// NOTA: aquest fitxer NO ES POT MODIFICAR,
// nomes comentar les linies de codi que no us funcionen
/*
 *  NOM: xxxxxxxx
 *  COGNOM: xxxxxxxx
 *  DNI O NIUB: xxxxxxxx
 */

int main(int argc, char** argv) {
    
    cout << "Main EXAM June 2a aval 2023 " << endl;      
    cout <<  " ......................................... " << endl; 
    
    SpecialQueue<int> sq;
    
    cout << "Is sq empty? (1=true/0=false): " << sq.isEmpty() << endl; // 1 (true)
    
    cout << "Add element (1)" << endl;
    sq.enqueue(1);
    cout << "sq: "; sq.print(); // 1
    cout << "Add element (2)" << endl;
    sq.enqueue(2);
    cout << "sq: "; sq.print(); // 1,2
    cout << "Add element (3)" << endl;
    cout << "sq: "; sq.enqueue(3);
    sq.print(); // 1,2,3
    
    cout << "Is sq empty? (1=true/0=false): " << sq.isEmpty() << endl; // 0 (false)
    cout <<  " ......................................... " << endl; 
    cout << "Constructor còpia: " << endl;
    SpecialQueue<int> sq2(sq);
    cout << "sq2: "; sq2.print();
    cout << "Removing first element of sq2" << endl;
    cout << sq2.dequeue() << endl; // 1
    cout << "sq: "; sq.print(); // [1,2,3]
    cout << "sq2: "; sq2.print(); // [2,3]
    cout << "size(sq) = " << sq.size() << endl;
    cout << "size(sq2) = " << sq2.size() << endl;
    cout <<  " ......................................... " << endl; 
    
    cout << "--------------------" << endl;
    
    cout <<  " ......................................... " << endl; 
    
    cout << sq.dequeue() << endl; // 1
    cout << "sq: "; sq.print(); // []
    
    cout << "Add element (5)" << endl;
    sq.enqueue(5); cout << "sq: "; sq.print();
    cout << "Add element (6)" << endl;
    sq.enqueue(6); cout << "sq: "; sq.print();
    cout << "Add element (7)" << endl;
    sq.enqueue(7); cout << "sq: "; sq.print(); // [5,6,7]

    cout << "--------------------" << endl;

    cout <<  " ......................................... " << endl; 
    cout << "------  enqueueFront " << endl; 
    sq.enqueueFront(0, 1); 
    sq.print(); 

     cout << "enqueueFront " << endl; 
    sq.enqueueFront(11, 22); 
    sq.print(); 

   
   cout <<  " ......................................... " << endl; 

    cout << " ---- dequeue "  << endl ; 
    for (int i = 0; i < 3 ; i++)  cout << sq.dequeue() << endl;
    sq.print(); 

    
    cout <<  " ......................................... " << endl; 
    // swapThirdPenultimate
    cout << "-- First call to swapThirdPenultimate:" << endl;
    cout << "Queue before swapping" << endl;
    sq.print(); 
    cout << "Swapping the third and the penultimate node "<< endl; // Exception cannot swap
    try{
        sq.swapThirdPenultimate();
        sq.print(); 
    } catch (const std::runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "-- Second call to swapThirdPenultimate:" << endl;
    cout << "Add element (1)" << endl;
    sq.enqueue(1);
    cout << "sq: "; sq.print(); // 1
    cout << "Add element (2)" << endl;
    sq.enqueue(2);
    cout << "sq: "; sq.print(); // 1,2
    cout << "Swapping the third and the penultimate node "<< endl; // Exception cannot swap
    try{
        sq.swapThirdPenultimate();
        sq.print(); 
    } catch (const std::runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    cout << "-- Third call to swapThirdPenultimate:" << endl;
    cout << "sq: "; sq.print(); // [1,2]
    cout << "Add element (3)" << endl;
    sq.enqueue(3); 
    cout << "sq: "; sq.print(); //[1,2,3]
    cout << "Swapping the third and the penultimate node "<< endl; // [1, 3, 2]
    try{
        sq.swapThirdPenultimate();
        sq.print(); 
    } catch (const std::runtime_error& e) {
        cout << "Main: " << e.what() << endl;
    }

    cout << "-- Fourth call to swapThirdPenultimate:" << endl;
    cout << "sq: "; sq.print(); // [1,3,2]
    cout << "Add element (4)" << endl;
    sq.enqueue(4); cout << "sq: "; sq.print(); //[1,3,2,4]
    try{
        cout << "Swapping the third and the penultimate nodes "<< endl; 
        sq.swapThirdPenultimate();
        sq.print(); 
    } catch (const std::runtime_error& e) {
        cout << "Main: " << e.what() << endl;
    }

    cout << "-- Fifth call to swapThirdPenultimate:" << endl;
    cout << "sq: "; sq.print(); 
    cout << "Add element (5)" << endl;
    sq.enqueue(5); cout << "sq: "; sq.print(); 
    try{
        cout << "Swapping the third and the penultimate nodes "<< endl; 
        sq.swapThirdPenultimate();
        sq.print(); 
    } catch (const std::runtime_error& e) {
        cout << "Main: " << e.what() << endl;
    }

    
   
 cout <<  " ......................................... " << endl; 
  cout << " --------- dequeueIfExists -----" << endl; 
  SpecialQueue<int> cua1; 
    cua1.enqueue(2);
    cua1.enqueue(2);
    cua1.enqueue(3);
    cua1.enqueue(2);
    cua1.enqueue(4);
    cua1.enqueue(2);
    cua1.enqueue(2);
    try{
        cout << "Test 1: Dequeue 2 if exists" << endl;
        cua1.print();
        cua1.dequeueIfExists(2);
        cua1.print();
    } catch (const std::runtime_error& e) {
        cout << "Main: (dequeueIfExists) " << e.what() << endl;
    }

    for (int i = 0; i < 5; i++) cua1.enqueue(i); 
    try{
        cout << "Test 2: Dequeue 0 if exists" << endl;
        cua1.print();
        cua1.dequeueIfExists(0);
         cout << "Test 3: Dequeue 3 if exists" << endl;
        cua1.print();
        cua1.dequeueIfExists(3); 
        cua1.print();
         cout << "Test 4: Dequeue 4 if exists" << endl;
        cua1.dequeueIfExists(4); 
        cua1.print();
    } catch (const std::runtime_error& e) {
        cout << "Main: (removeIfExists) " << e.what() << endl;
    }

   cout <<  " ......................................... " << endl; 

    cout << "End of main EXAM June  2023 " << endl; 
    
    return 0;
}

