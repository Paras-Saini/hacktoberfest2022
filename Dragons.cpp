#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define lower(x) transform(x.begin(), x.end(),x.begin(),::tolower)
#define upper(x) transform(x.begin(), x.end(),x.begin(),::toupper)
#define maxv(x) *max_element(x.begin(), x.end())
#define minv(x) *min_element(x.begin(), x.end())
#define rev(x) reverse(x.begin(), x.end())
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;ll y;
    cin>>x>>y;
    pair <ll,ll> p[y];
    for(int i=0;i<y;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+y);
    for(int j=0;j<y;j++)
    {
        if(x>p[j].first)
		{
		    x=x+p[j].second;
		}
		else
		{
		    cout<<"NO"; 
		    return 0;
		}
    }
	cout<<"YES";
}
