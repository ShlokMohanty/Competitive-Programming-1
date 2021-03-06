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

int n, q;

int a[N];

int main(){
	sd2(n, q);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	while(q--){
		int d; sd(d);
		deque<int> q;
		
		for(int i = 0; i < d; i++){
			while(!q.empty() and a[q.front()] < a[i]) q.pop_front();
			q.push_front(i);
		}
		
		int ans = a[q.back()];
		
		for(int i = d; i < n; i++){
			while(!q.empty() and a[q.front()] < a[i]) q.pop_front();
			q.push_front(i);
			
			while(!q.empty() and q.back() <= i-d) q.pop_back();
			ans = min(ans, a[q.back()]);
		}
		
		printf("%d\n", ans);
	}
	
	
	return 0;
}
