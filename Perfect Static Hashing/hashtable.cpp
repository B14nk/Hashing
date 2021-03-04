#include "Hashtable.h"
Hashtable::Hashtable(){
    m = 0;
    p = 0;
    a = 0;
    b = 0;
}

Hashtable::Hashtable(int m){
    this->m = m;
    p = 0;
    new_p();
    a = 0;
    b = 0;
    table.resize(m);
    for (int i = 0; i < m; i++)
    {
        table[i] = INT_MIN;
    }
    
}

void Hashtable::new_p(){
    if (m < p)
    {
        return;
    }
    p = m+1;
    
    bool notPrime = true;
    while(notPrime)
    {
        if(p <= 3)
        {
            return;
        }
        
        notPrime = false;

        if(p % 2 != 0 && p % 3 != 0)
        {
            int i = 5;
            
            while(i^2 <= p)
            {
                if(p % i == 0 && p % (i+2) == 0)
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

Hashtable::~Hashtable(){

}

void Hashtable::print(){
    cout<<"[ ";
    for (int i = 0; i < m; i++)
    {
        if (table[i] == INT_MIN)
        {
            cout<<"- ";
        }
        else cout<<table[i] << " ";
    }
    cout<<"]";
}

void Hashtable::insert(vector<int> &elements){
    bool collision = true;
    while (collision)
    {
        a += 1;
        b += 1;
        collision = false;
        for(int i = 0; i < elements.size(); i++)
        {
            int pos = hashfunction(elements[i]);
            if(table[pos] == INT_MIN)
            {
                table[pos] = elements[i];
            }
            else
            {
                collision = true;
            }
        }
    }
}

bool Hashtable::find(int &element){
    return table[hashfunction(element)] == element;
}

int Hashtable::hashfunction(int &element){
    return (((element * a) + b) % p) % m;
}
