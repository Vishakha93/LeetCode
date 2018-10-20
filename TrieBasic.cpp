#include <iostream>
#include <string>
using namespace std;

struct Trienode 
{
    struct Trienode *children[26];
    bool isLeaf = false;
};

struct Trienode* getNode()
{
    Trienode *node = new Trienode();
    for(unsigned int i = 0; i<26; i++)
    {
        node->children[i] = NULL;
    }
    
    node->isLeaf = false;
    return node;
}

void insert(Trienode *root, string str)
{
    if(root == NULL)
    {
        return;
    }
    
    Trienode *temp = root;
    for(int i=0; i<str.length(); i++)
    {
        int idx = str[i] - 'a';
        if(!temp->children[idx])
        {
            temp->children[idx] = getNode();
        }
        
        temp = temp->children[idx];
    }
    
    temp->isLeaf = true;
}

bool search(Trienode *root, string str)
{
    if(root == NULL)
    {
        return false;
    }
    
    Trienode *temp = root;
    
    int i, n = str.length();
    for(i=0; i < n; i++)
    {
        int idx = str[i] - 'a';
        if(!temp->children[idx])
        {
            return false;
        }
        
        temp = temp->children[idx];
    }
    
    return (temp != NULL && temp->isLeaf == true);
    
}
int main()
{
    string arr[] = {"Hello", "Hey", "Temperature", "Kite"};
    
    Trienode *root = getNode();
    for(int i=0; i<4; i++)
    {
        insert(root, arr[i]);
    }
    
    bool res1 = search(root, "TeHey") ;
    bool res2 = search(root, "Temperature") ;
    cout <<  res1 << " " << res2 << endl;
    return 0;
}
