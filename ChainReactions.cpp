#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
#define mod 1000000007
# define M_PI           3.14159265358979323846
#define prime6 347717
#define fori for(int i=0;i<n;i++)
#define forj for(int j=0;j<m;j++)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 

const ll inf=ll(1e18)+5;
const ll mo=998244353;
//const int p=31;

void no(){
	cout<<"NO"<<endl;
}
void yes(){
	cout<<"YES"<<endl;
}

ll ans;
vector<int> adj[100005],vis(100005);
vector<ll> F(100005);

ll dfs(int x)
{
	vis[x]=1;
	ll sum=0;
	ll m=INT_MAX;
	for(auto y: adj[x])
	{
		ll d= dfs(y);
		sum+=d;
		m = min(m, d);
	}
	if(adj[x].size())
	{
		ans+=sum-m;
		return max(F[x],m);
	}
	return F[x];

}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cout<<fixed<<showpoint;
	cout<<setprecision(10);
	
	int t;
	cin>>t;
	for(int h=1;h<=t;h++)
	{
		int n;
		cin>>n;
		for(int i=0 ; i<100005;i++)
		{
			vis[i]=0;
			adj[i].clear();
		}
		
		ans=0;
		fori cin>>F[i+1];
		fori
		{
			int p;
			cin>>p;
			if(p!=0)
				adj[p].push_back(i+1);
		}
		fori
		{
			if(!vis[i+1])
				ans+=dfs(i+1);
		}
		cout<<"Case #"<<h<<": ";
		cout<<ans<<endl;
	}
	return 0;
}