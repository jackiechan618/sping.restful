//
//  main.cpp
//  HW_Random Access Iterator
//
//  Created by Feng Chen on 15/10/8.
//  Copyright © 2015年 Jackie. All rights reserved.
//


#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//T1 is the type of the container of the data for storing
//T2 is the return type of the "operator*"
template<typename T1, typename T2>
class my_iterator{
private:
    int index;
    int containerLength;
    vector<T2> myVector;
    vector<T2>* p;
    T2* myContainer;
    
public:
    my_iterator(T1* array, int index, int length){
        myContainer = array;
        containerLength = length;
        this->index = index;
        p = nullptr;
    }
    
    my_iterator(T1 sourceVector, int index){
        p = &sourceVector;
        myVector = sourceVector;
        containerLength = myVector.size();
        this->index = index;
        myContainer = nullptr;
    }
    
    my_iterator &operator++() {
        if(index <= containerLength - 1)
            index++;
        return *this;
    }
    my_iterator &operator--() {
        if(index > 0)
        index--;
        return *this;
    }
    T2 operator*() const{
        if(myVector.empty())
            return myContainer[index];
        else
            return myVector.at(index);
    }
    
    bool operator==(const my_iterator &other)const{
        if(myVector.empty())
            return ( (myContainer == other.myContainer) && (index == other.index) );
        else
            return ( (myVector == other.myVector) && (p == other.p) && (index == other.index) );
    }
    bool operator!=(const my_iterator &other)const{
        if(myVector.empty())
            return ( (myContainer != other.myContainer) || (index != other.index) );
        else
            return ( (myVector != other.myVector) || (p != other.p) || (index != other.index) );
    }
    
    void showMyVector(){
        cout << "traverse from index to the end: ";
        for(int i = index; i < containerLength; i++){
            if(myVector.empty())
                cout << myContainer[i] << " " ;
            if(myContainer == nullptr)
                cout << myVector.at(i) << " " ;
        }
        cout << endl;
    }
};

int main(){
    int a[5] = {2,4,5,27,9};
    my_iterator<int, int> test(a, 0, 5);
    test.showMyVector();
    my_iterator<int, int> test2(a, 5, 5);
    for(my_iterator<int, int> iter = test; iter != test2; ++iter)
        cout << *iter << " ";
    cout <<endl;
    cout << "*(test) = "<< *(test) <<endl;
    cout << "*(++test) = "<< *(++test) <<endl;
    cout << "*(--test) = "<< *(--test) <<endl;
    
    int b[5] = {2,4,5,27,9};
    my_iterator<int, int> test3(a, 0, 5);
    my_iterator<int, int> test4(b, 0, 5);
    if(test == test2) cout << "test == test2" << endl;
    else cout << "test != test2" << endl;
    if(test != test2) cout << "test != test2" << endl;
    else cout << "test == test2" << endl;
    if(test == test3) cout << "test == test3" << endl;
    else cout << "test != test3" << endl;
    if(test == test4) cout << "test == test4" << endl;
    else cout << "test != test4" << endl;
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    my_iterator<vector<int>, int> test5(v1, 0);
    cout << "*(test5) = " << *(test5) <<endl;
    cout << "*(++test5) = "<< *(++test5) <<endl;
    cout << "*(--test5) = "<< *(--test5) <<endl;
    
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    my_iterator<vector<int>, int> test6(v2, 0);
    if(test5 == test6) cout << "test5 == test6" <<endl;
    else cout << "test5 != test6" <<endl;
}

