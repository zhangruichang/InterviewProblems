#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <cstdio>
#include <memory>
#include <climits>
using namespace std;

struct Node
{
    //int have_value = 0;
    int value;
    shared_ptr<Node> left,right;
    Node() : value(INT_MIN), left(NULL), right(NULL){}
};
shared_ptr<Node> root;
/*
shared_ptr<Node> newnode()
{
    shared_ptr<Node> nn(new Node);
    if (nn != NULL) {
        nn->left = nn->right = NULL;
        nn->value=INT_MIN;
    }
    return nn;
}*/
int stoi(string x)
{
    int sum=0;
    for(auto e: x)
        sum=sum*10+e-'0';
    return sum;
}
bool invalid;
void addNode(string s,int v)
{
    int len = s.length();
    shared_ptr<Node> r = root;
    for(auto e:s)
    {
        if(e == 'L'){
            if(r->left == NULL) r->left=make_shared<Node>();
            r = r->left;
        }
        else if(e == 'R'){
            if(r->right == NULL) r->right=make_shared<Node>();
            r = r->right;
        }
    }
    if(r->value==INT_MIN)
        r->value = v;
    else invalid=1;
}

int main()
{
    invalid = 0;
    string str;
    root = make_shared<Node>();
    while(cin>>str)
    {
        int len = str.size();
        str = str.substr(1,len-2);
        int pos = str.find(",");
        if (pos == -1) break;
        int val = stoi(str.substr(0,pos));
        string dir = str.substr(pos+1, str.size()-pos-1);
        addNode(dir,val);
    }
    queue<shared_ptr<Node>> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty())
    {
        auto cur=q.front();q.pop();
        if(cur->value!=INT_MIN) ans.push_back(cur->value);
        else
        {
            invalid=1;
            break;
        }
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    if(invalid) cout<<"-1"<<endl;
    else
    {
        for(auto e: ans) cout<< e << " ";
        cout << endl;
    }
    return 0;
}
