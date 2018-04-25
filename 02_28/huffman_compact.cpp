#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
struct helement
{
	char c;
	ll f;
	helement *right;
	helement *left;
	helement *me;
	bool operator<(const helement &o) const
    {
        return f < o.f;
    }
};
void traverse(helement *h,string s)
{
	//cout<<s<<endl;
    if(h->right==NULL&&h->left==NULL)
	{
	cout<<h->c<<" "<<s<<endl;
	}
	else
	{	
	traverse((h->left),s+'0');
	traverse((h->right),s+'1');
	}
}
int main()
{
    cout<<"input no. of characters"<<endl;
    ll n;
    cin>>n;
    priority_queue<helement> q;
  	cout<<"input char and respective freq"<<endl;
	for(ll i=0;i<n;i++)
	{
	char ch;
	ll num;
	cin>>ch;
	cin>>num;
	helement *h1 = new helement;
	h1->c=ch;
	h1->f=(-1*num);
	h1->right=NULL;
	h1->left=NULL;
	h1->me = h1;
	q.push(*h1);
	}
    while(q.size()>1)
	{
       helement h2,h3,h11,h22;
       h2=q.top();
       q.pop();
       h3=q.top();
       cout<<endl;
       q.pop();
       helement *h4 = new helement;
       h4->c='#';
       h4->f=h2.f+h3.f;
       h4->left=h2.me;
       h4->right=h3.me;
       h4->me = h4;
       q.push(*h4);
	}
    string s;
	helement h5=q.top();
	helement *h6=h5.me;
	traverse(h6,s);
	return 0;
}