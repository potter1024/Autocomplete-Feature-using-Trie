//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <set>
#include <time.h>
#include <map>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <numeric>
#include <unordered_map>
using namespace std;
#define sz(a)               int((a).size())
#define ll                  long long
#define pb                  push_back
#define ld                  long double
#define pi                  pair<ll,ll>
#define mp                  make_pair
#define vi                  vector<ll>
#define vii                  vector<pi>
#define endl                "\n"
#define ff                  first
#define ss                  second
#define all(c)              (c).begin(),(c).end()
#define allr(c)             (c).rbegin(),(c).rend()
#define rep(i,n)            for(ll i=0;i<n;i++)
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define inputt(a,n,m)       for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>a[i][j]
#define outputt(a,n,m)      for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
#define inf                 1e10
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock();
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;

/************************************Debugging Steps*****************************************/

// If aplying ceil,floor,pow,etc convert it into integer (might make you eat shit if you don't
// Whenever using stacks,queues,etc always check that their top / front / back elements are not accessed when they are empty, thus causing runtime error
// Think twice before using greedy
// Remember losing 1 or 2 minutes is better than a penalty of 10 minutes
// Use log2 instead of log()/log(2) to avoid shitty errors
// If MLE occurs, try declaring the large array in int instead of long long
// Always initialise anything while declaring, which will not be taken as input
// In case of a problem having decimal calculations, try declaring everything in double rather than typecasting in each step
// always declare the array with n+5 elements to avoid unexpected errors
// Every problem cannot be solved by DFS easily, think of BFS too
/********************************************************************************************/

/********************************************************************************************/

// Your code need to originate from the deepest of your intellectual mind
// Best of Luck, may there never be "Wrong answer on test ##"

struct TrieNode
{
    map<char,TrieNode*> children;
    bool endofword;
    TrieNode()
    {
        endofword=false;
    }
};
TrieNode *root=new TrieNode();
void insert(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
            node=new TrieNode();
            current->children[ch]=node;
        }
        current=node;
    }
    current->endofword=true;
}
bool prefixsearch(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return true;
}
bool wordsearch(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return current->endofword;
}
void deletion(string word)
{
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    current->endofword=false;
}
void recurse(char last_letter,string last_word,TrieNode *node)
{
    TrieNode *current=node;
    auto it=(current->children).begin();
    if(current->endofword==true);
    //    cout<<last_word+last_letter<<endl;
    while(it!=(current->children).end())
    {
        recurse(it->first,last_word+last_letter,it->second);
        it++;
    }
}
void suggestions(string word)
{
    if(!prefixsearch(word))
        return;
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    auto it=(current->children).begin();
    if((current->children).size()==0)
    {
     //   cout<<word<<endl;
        return;
    }
    while(it!=(current->children).end())
    {
        recurse(it->first,word,it->second);
        it++;
    }
}
int32_t main()
{
   // she_taught_me_to_code

    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll ma=0;
    string d;
    vector<string> v;
    for(ll i=0;i<20000;i++)
    {
        string s;
        cin>>s;
        insert(s);
        v.pb(s);
    }
    vector<ld> re;
    for(ll h=0;h<20000;h++)
    {
        for(ll hh=1;hh<v[h].size();hh++)
        {
            clock_t startTime=clock();
            string s{v[h].begin(),v[h].begin()+hh};
            suggestions(s);
            ld x1=(double(clock()-startTime )/(double)CLOCKS_PER_SEC);
            startTime=clock();
            for(ll i=0;i<20000;i++)
            {
                if(v[i].size()<s.size())
                    continue;
                ll count=0;
                for(ll j=0;j<s.size();j++)
                {
                    if(v[i][j]==s[j])
                    {
                        count++;
                    }
                }
                if(count==s.size());
                //      cout<<v[i]<<endl;
            }
            ld x2=(double(clock()-startTime )/(double)CLOCKS_PER_SEC);
            re.pb(x2/x1);
        }
        if(h%1000==0)
        {
            cout<<((ld)h/((ld)(20000)))*100<<"% completed"<<endl;
        }
    }
    ld x=0.0;
    for(ll i=0;i<re.size();i++)
        x+=re[i];
    cout<<x/(ld)(re.size())<<endl;
}
