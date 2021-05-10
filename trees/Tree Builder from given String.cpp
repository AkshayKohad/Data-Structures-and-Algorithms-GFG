// Program to build tree from given string

#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int data;
    Node*left;
    Node*right;
};

Node* newNode(int val)
{
    Node*temp = new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    
    return temp;
}
Node* TreeBuilder(string str){
    if(str.length()==0 || str[0]=='N')
    return NULL;
    
    istringstream iss(str);
    
    vector<string>ip;
    
    for(string s; iss>>s;)
    ip.push_back(s);
    
    Node*root = newNode(stoi(ip[0]));
    
    queue<Node*>q;
    q.push(root);
    
    int i=1;
    while(!q.empty() && i<ip.size())
    {
       Node*curr = q.front();
       q.pop();
       string curr_val;
       curr_val = ip[i];
       
       if(curr_val!="N")
       {
           curr->left = newNode(stoi(curr_val));
           q.push(curr->left);
           
       }
       
       i++;
       if(i>=q.size())
       break;
       
       curr_val= ip[i];
       
       if(curr_val!="N"){
           curr->right = newNode(stoi(curr_val));
           q.push(curr->right);
       }
       i++;
       
    }
    
    return root;
    
}


int main()
{
    string a; 
    cout<<"this program is used to make tree from given string,Hence you are required to enter string such that you have to give space after each node and also specify NULL if possible in level order fashion"<<endl;
    getline(cin,a);
    Node*root;
    root=TreeBuilder(a);
    return 0;
}
