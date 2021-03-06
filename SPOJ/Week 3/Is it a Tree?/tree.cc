#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
vector<int> g[N];

vector<vector<int> > comp;

int vis[N];

void dfs(int x, int id){
	vis[x] = 1;
	comp[id].pb(x);
	foreach(it, g[x]){
		if(vis[*it]) continue;
		dfs(*it, id);
	}
}

int main(){
	int n, m;
	sd2(n,m);
	
	if(m != n-1){
		puts("NO");
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		int x, y; sd2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	
	comp.resize(n+1);
	
	int id = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			id++;
			dfs(i, id);
		}
	}
	
	dfs(1);
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	
	return 0;
}
