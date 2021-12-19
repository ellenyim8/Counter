#include "mcounter.h"
#include "CONSTS.h"
#include <iostream>
#include <iomanip>
using namespace std;

MCounter::MCounter()
{
    const bool debug = false;
    if (debug) cout<<"DEBUG: MCounter: "<<endl;
    _count = 0;
    max_count = 9999;
    _error = NO_ERROR;
}

int MCounter::add_1(){
    const bool debug = false;
    if (_error != NO_ERROR) {
        if (debug) cout<<"MCounter: object in state of error: returning: "
                      <<error_description()<<endl;
    }

    _count+=1;
    // check for error:
    _error = check_error();
    error();
    display_count();
    if (_error != NO_ERROR) {
        cout<<"OVERFLOW"<<endl;
    }
    return _count;
}

int MCounter::add_10(){
    const bool debug = false;
    if (_error != NO_ERROR) {
        if (debug) cout<<"MCounter: object in state of error: returning: "
                      <<error_description()<<endl;
    }

    _count+=10;
    _error = check_error();
    error();
    display_count();
    if (_error != NO_ERROR){
        cout<<"OVERFLOW"<<endl;
    }
    return _count;
}

int MCounter::add_100(){
    const bool debug = false;
    if (_error != NO_ERROR) {
        if (debug) cout<<"MCounter: object in state of error: returning: "
                      <<error_description()<<endl;
    }

    _count+=100;
    _error = check_error();
    error();
    display_count();
    if (_error != NO_ERROR) {
        cout<<"OVERFLOW"<<endl;
    }
    return _count;
}

int MCounter::add_1000(){
    const bool debug = false;
    if (_error != NO_ERROR) {
        if (debug) cout<<"MCounter: object in state of error: returning: "
                      <<error_description()<<endl;
    }

    _count+=1000;
    _error = check_error();
    error();
    display_count();
    if (_error != NO_ERROR) {
        cout<<"OVERFLOW"<<endl;
    }
    return _count;
}

int MCounter::reset() {
    const bool debug = false;
    if (debug) cout<<"reseting _count: "<<endl;

    reset_error();
    _count = 0;
    cout<<setfill('0')<<setw(4)<<_count;
    return _count;
}

int MCounter::count() const{
    return _count;
}

void MCounter::display_count(){
    const bool debug = false;
    if (debug) {
        cout<<"DEBUG: MCounter.display(): (count: "<<_count<<")"<<endl;
    }
    else{
        if (_error) {
            cout<<"MCounter is in state of error: "<<error_description()<<endl;
        }
        else {
            if (_count >= 0 && _count < 10) {
                cout<<setfill('0')<<setw(4)<<_count;
            }
            else if (_count >= 10 && _count < 100) {
                cout<<setfill('0')<<setw(4)<<_count;
            }
            else if (_count >= 100 && _count < 1000) {
                cout<<setfill('0')<<setw(4)<<_count;
            }
            else {
                cout<<setw(0)<<_count;
            }
        }
    }
}

//================================================
// ERROR HANDLING :
// ===============================================

string MCounter::error_description() {
    switch(_error) {
    case NO_ERROR: return "NO ERROR";
    case INVALID: return "INVALID COUNT";
        default:  return "UNKNOWN ERROR";
    }
}

int MCounter::error() {
    // reports error;
    return _error;
}

void MCounter::reset_error(){
    // reset error code
    _error = 0;
}

int MCounter::check_error(){
    if (_count >= max_count) {
        return INVALID;
    }
    return NO_ERROR;
}

//================================================

// test function for MCounter
void test_MCounter(){
    MCounter count;
    char option = '\0';
    cout<<setfill('0')<<setw(4);
    while (option != 'x'){
        cout<<"MENU: [a] 1000 | [s] 100 | [d] 10 | [f] 1 | [r]eset | e[x]it :";
        cin>>option;
        if (option == 'a') {
            count.add_1000();
            cout<<endl;
        }
        else if (option == 's') {
            count.add_100();
            cout<<endl;
        }
        else if (option == 'd') {
            count.add_10();
            cout<<endl;
        }
        else if (option == 'f') {
            count.add_1();
            cout<<endl;
        }
        else if (option == 'r') {
            count.reset();
            cout<<endl;
        }
    }
}


