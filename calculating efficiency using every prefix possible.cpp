#include <bits/stdc++.h>
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
    freopen("input.txt","r",stdin);

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
