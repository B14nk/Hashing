#include "Hashtable.h"
#include <iostream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bucket_vector;
vector<Hashtable> table;
int p = 0;
long m;

void prime(){
    if (m < p)
    {
        return;
    }
    p = m+1;
    
    bool notPrime = true;
    while (notPrime)
    {
        if (p <= 3)
        {
            return;
        }
        
        notPrime = false;

        if (p % 2 != 0 && p % 3 != 0)
        {
            int i = 5;
            
            while(i^2 <= p)
            {
                if (p % i == 0 && p % (i+2) == 0)
                {
                    notPrime = true;
                }
                i += 6;
            }
            
        }
        else
        {
            notPrime = true;
            p += 1;
        }
    }
}

void insert_bucket(vector<int> &elements){
    m = 5;
    bucket_vector.resize(m);
    prime();
    for (int i = 0; i < elements.size(); i++)
    {
        bucket_vector[(((elements[i] * 3) + 15) % p) % m].emplace_back(elements[i]);
    }
}

void insert_hashtable(){
    table.resize(m);
    for (int i = 0; i < m; i++)
    {
        int size = bucket_vector[i].size();
        table[i] = Hashtable(size * size);
    }

    for (int i = 0; i < m; i++)
    {
        table[i].insert(bucket_vector[i]);
    }
}



int main(int argc, char** argv){
    vector<int> values;
    srand (time(0));
    for (int i = 0; i < 10; i++)
    {
        values.push_back(rand() % 5000);
    }

    cout<<"numbers to be hashed: ";
    for (int i = 0; i < values.size(); i++)
    {
        cout<<values[i]<< " ";
    }
    cout<<endl;

    insert_bucket(values);

    insert_hashtable();

    cout<<"[";
    for (int i = 0; i < m; i++)
    {
        table[i].print();   
    }
    cout<<"]"<<endl;

}