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

int gcd(int a, int b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

int main(){
    int tc, l, n, di, last;
    scanf("%d", &tc);
    for(int i = 0, j; i < tc; i++){
        set<int> primes;
        vector<int> data;
        deque<int> order;
        map<int, char> alpha;
        char letter = 'A';
        scanf("%d %d", &n, &l);
        for(j = 0; j < l; j++){
            scanf("%d", &di);
            data.pb(di);
        }
        last = data[0];
        for(j = 1; j < l; j++){
            if(last != data[j]) break;
        }
        last = gcd(data[j - 1], data[j]);
        primes.ins(last);
        order.pb(last);
        for(int k = j - 1; k >= 0; k--){
            primes.ins(data[k]/last);
            order.push_front(data[k]/last);
            last = data[k]/last;
            primes.ins(last);
        }
        last = gcd(data[j - 1], data[j]);
        for(int k = j; k < l; k++){
            primes.ins(data[k]/last);
            order.pb(data[k]/last);
            last = data[k]/last;
            primes.ins(last);
        }
        for(auto p : primes){
            alpha[p] = letter;
            letter++;
        }
        printf("Case #%d: ", i + 1);
        for(auto p : order) printf("%c", alpha[p]);
        printf("\n");
    }
    return 0;
}