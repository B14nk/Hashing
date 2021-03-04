#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

class Hashtable{
    private:
        long m;
        int p;
        int a;
        int b;
        vector<int> table; 
        bool find(int &);
        int hashfunction(int &);
        void new_p();
    public:
        
        Hashtable();
        Hashtable(int);
        ~Hashtable();
        void insert(vector<int> &);
        void print();
        
        
};

#endif