/*
 *
 *
 KnapScak Dp function :

 input : given the weight and max capacity calculate maximum profit

 types of questions :
 1.
 2.
 3.

 *
 *
 * */

/* implementation */

#include<iostream>
using namespace std;

void newVoidFunction(){
    cout << "inside newVoid function";
    // do nothing
    cout << "Lets print something";
    cout << "Inside this function";
    cout << "not inside this function";
    return;
}

void callAnotherNonVoidFunction(){
    cout << "inside callAnotherNonVoidFunction";
}

void callVoidFunction(){
    cout << "inside void function";
    return;
}

int main(){
    cout << "KanpSack Dyanmic Programming problem \n";
    newVoidFunction();
    callAnotherNonVoidFunction();
    callVoidFunction();
    return 0;
}


