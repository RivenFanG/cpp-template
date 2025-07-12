#include<bits/stdc++.h>
using namespace std;

#define ll long long

void nod(int n){
    ll ans = 1, cnt = 0;
    while(n % 2 == 0) n /= 2, cnt++;
    ans *= (cnt + 1);
    for(int i = 3; i * i <= n; i += 2){
        cnt = 0;
        while(n % i == 0) n /= i, cnt++;
        ans *= (cnt + 1);
    }
    if(n != 1) ans *= 2;
    cout << ans << '\n';
}

int main(){
    int n; cin >> n;
    nod(n);
    return 0;
}
