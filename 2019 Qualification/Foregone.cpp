#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

int main(){
    int tc, flag;
    string inp, ans1, ans2;
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++){
        cin >> inp;
        ans1 = ans2 = "";
        flag = 0;
        for(int j = 0; j < inp.length(); j++){
            if(inp[j] == '4') ans1+='3', ans2+='1', flag++;
            else{
                ans1+=inp[j];
                if(flag) ans2+='0';
            }
        }
        cout << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}