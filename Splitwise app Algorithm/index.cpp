#include <iostream>
#include <set>
#include <map>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;


class mycmp{
    public:
bool operator() (pair<string,int>a,pair<string,int>b){
    return a.second<b.second;
}

};


int main()
{

    int transactions,friends;
    cin>>transactions>>friends;

   

  map<string,int>net;

    for(int i=0;i<transactions;i++)
    {
         string x,y;
         int val;

        cin>>x>>y>>val;


// if name is not present then initialize
        if(net.find(x)==net.end())
        {
            net[x]=0;
        }
// if name is not present then initialize
        if(net.find(y)==net.end())
        {
            net[y]=0;
        }

// First person is in debit so it will be substracted by val
        net[x]-=val;

// Other person is in credit so it will be added by val
        net[y]+=val;


    }

    // Now we will find out people who has some balance to take or give (i.e not 0)

    // Those who have balance 0 their settlement is clear so they don't need to interact

    multiset<pair<string,int>,mycmp>mp;

    for(auto res:net)
    {
        string person = res.first;
        int balance = res.second;

    // if balance is zero that means that person's balance is settled out
        if(balance!=0)
        {
            mp.insert(make_pair(person,balance));

        }
    }



   // We are sorting it according to balance values as it was sorting wrt to string 
  //  sort(mp.begin(),mp.end()); -> can't use it in multiset

 // Used to calculate total number of transactions which will be taking place 
    int transaction_count =  0;

// mp is an multiset which sorts the value according to string but since we have used mycmp class to specify 
// To sort according to values present
// so starting pointers will have debit values and end pointer in mp(multiset) will have credit values
   while(!mp.empty())
   {
       // low initialize with starting pointer
       auto low = mp.begin();

       // high initialize with end pointer -1 -> used prev() for it
       auto high = prev(mp.end());


    int debit_amount = low->second;
    string debit_person = low->first;


    int credit_amount = high->second;
    string credit_person = high->first;


// Settlement amount will be minimum of this 2 because that is the amount debit guy can give to credit guy
       int settlement_amount = min(abs(debit_amount),credit_amount);
       
       // Now since that settlement_amount is given by debit guy his balance to give money will be reduced 
       // since it is negative(debit_amount) we will add it
       debit_amount += settlement_amount;


      // Now since that settlement_amount is taken by credit guy his balance to take money will be reduced 
       // since it is positive(credit_amount) we will substract it
       credit_amount -= settlement_amount;


    // erase both pointers from mp
       mp.erase(low);
       mp.erase(high);

      // printing the each transaction detail 
       cout<<debit_person<<" needs to pay amount "<<settlement_amount<<" to "<<credit_person<<endl;
       
       
     // if debit_amount balance is not 0 that means his settlement is not cleared so we insert in again with update
     // details in amount
       if(debit_amount!=0)
       {
 
         mp.insert(make_pair(debit_person,debit_amount));   
       }

     // if credit_amount balance is not 0 that means his settlement is not cleared so we insert in again with update
     // details in amount
       if(credit_amount!=0)
       {

        mp.insert(make_pair(credit_person,credit_amount));
       }

// Keeping track of number of transactions happening 
       transaction_count++;
   }
//Printing total transactions took place
    cout<<" Total Transactions occured is "<<transaction_count<<endl;

    //Printing how many transctions have been reduced by uaing Splitwise Algorithm
    cout<<" Total Transaction Operations saved -> "<<transactions-transaction_count<<endl;
    

     return 0;
}