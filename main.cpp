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

struct TrieNode{
    map<char,TrieNode*> children;
    bool endofword;
    TrieNode(){
        endofword=false;
    }
};
TrieNode *root=new TrieNode();
void insert(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node){
            node=new TrieNode();
            current->children[ch]=node;
        }
        current=node;
    }
    current->endofword=true;
}
bool prefixsearch(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return true;
}
bool wordsearch(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node){
            return false;
        }
        current=node;
    }
    return current->endofword;
}
void deletion(string word){
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    current->endofword=false;
}
void recurse(char last_letter,string last_word,TrieNode *node){
    TrieNode *current=node;
    auto it=(current->children).begin();
    if(current->endofword==true)
        cout<<last_word+last_letter<<endl;
    while(it!=(current->children).end()){
        recurse(it->first,last_word+last_letter,it->second);
        it++;
    }
}
void suggestions(string word){
    if(!prefixsearch(word))
        return;
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    auto it=(current->children).begin();
    if((current->children).size()==0){
        cout<<word<<endl;
        return;
    }
    while(it!=(current->children).end()){
        recurse(it->first,word,it->second);
        it++;
    }
}
int32_t main(){
    freopen("input.txt","r",stdin);
    ll ma=0;
    string d;
    for(ll i=0;i<100000;i++){
        string s;
        cin>>s;
        insert(s);
        ll x=s.size();
        if(x>ma){
            ma=x;
            d=s;
        }
    }
    suggestions("you");
}
