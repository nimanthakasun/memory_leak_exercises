// Memory_Leaks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <type_traits>
//#include <vector>
//#include <algorithm>
//#include <ranges>

#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class B;
class C;

//class A {
//public:
//    A* ref;
//    A() { std::cout << "A created\n"; }
//    void show() { std::cout << "A::show()" << std::endl; }
//    ~A() { std::cout << "A destroyed\n"; }
//};

class B {
public:
    //std::shared_ptr<C> c_obj;
    std::unique_ptr<C> c_obj;
    ~B() { std::cout << "Disctructor B\n"; }
};

class C {
public:
    //std::shared_ptr<B> b_obj;
    std::unique_ptr<B> b_obj;
    ~C() { std::cout << "Disctructor C\n"; }
};

//class Node {
//public:
//    Node* next;
//    //Node* prev;
//
//    Node() : next(nullptr) {//, prev(nullptr) {
//        std::cout << "Node created" << std::endl;
//    }
//
//    ~Node() {
//        std::cout << "Node destroyed" << std::endl;
//    }
//};

int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    auto b = std::make_unique<B>();
    auto c = std::make_unique<C>();

    b->c_obj = std::move(c);


    //Node* node1 = new Node();
    //Node* node2 = new Node();

    //// Creating a cyclic reference
    //node1->next = node2;
    //node2->next = node1;

    //// Manual delete
    //delete node1;
    //delete node2;
    //// Manual Referencing with other class
    //A* a1 = new A();
    //A* a2 = new A();

    //a1->ref = a2;
    //a2->ref = a1;

    //delete a1; //
    ////delete a2; // Never reached

    //    // Creating a shared pointer and accessing the object
    //std::shared_ptr<A> p1(new A);
    //// Printing the address of the managed object
    //std::cout << p1.get() << std::endl;
    //p1->show();

    //// Creating a new shared pointer that shares ownership
    //std::shared_ptr<A> p2(p1);
    //p2->show();

    //// Printing addresses of p1 and p2
    //std::cout << p1.get() << std::endl;
    //std::cout << p2.get() << std::endl;

    //// Returns the number of shared_ptr objects
    //// referring to the same managed object
    //std::cout << p1.use_count() << std::endl;
    //std::cout << p2.use_count() << std::endl;

    //// Relinquishes ownership of p1 on the object
    //// and pointer becomes NULL
    //p1.reset();
    //std::cout << p1.get() << std::endl; // This will print nullptr or 0
    //std::cout << p2.use_count() << std::endl;
    //std::cout << p2.get() << std::endl;

    /*
    These lines demonstrate that p1 no longer manages an
    object (get() returns nullptr), but p2 still manages the
    same object, so its reference count is 1.
    */

    //_CrtDumpMemoryLeaks();

    return 0;
}
