//SHREE GANESHAYA NAMAH//OM NAMAHA SHIVAY#include<bits/stdc++.h>#define ll long long#define endl '\n'#define pb push_back#define pob pop_back#define mp make_pair#define ff first#define ss second#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);using namespace std;const int m=(int)1e9+7;const int N=1000;// etf in sqrt(n) using prime factorisation// ll int phi(ll int n){//     ll int res=n;//     for(ll int i=2;i*i<=n;i++){//         if(n%i==0){//             res/=i;//             res*=(i-1);//         }//         while(n%i==0){//             n/=i;//         }//     }//     if(n>1){//         res/=n;//         res*=(n-1);//     }//     return res;// }// etf in nlog(logn) using sieve algo// ll int p[1000001];// void phif(ll int n){//     for(ll int i=1;i<=n;i++){//         p[i]=i;//     }//     for(ll int i=2;i<=n;i++){//         if(p[i]==i){//             for(ll int j=i;j<=n;j+=i){//                 p[j]/=i;//                 p[j]*=(i-1);//             }//         }//     }//     // for(ll int i=0;i<n;i++){//     //     cout<<p[i]<<" ";//     // }// }// ll int bin(ll int a,ll int b,ll int m){//     ll int ans=1;//     while(b>0){//         if(b&1){//             ans=(ans*a)%m;//         }//         a=(a*a)%m;//         b>>=1;//     }//     return ans%m;// }int main(){    fastio()    // // sliding window:subarray sum    // ll int t;    // cin>>t;    // while(t--){            // }    ll int n,x;    cin>>n>>x;    ll int a[n],b[n];    for(ll int i=0;i<n;i++){        cin>>a[i];        b[i]=a[i];    }    sort(a,a+n);    ll int p1=0,p2=n-1,sum=a[p1]+a[p2],l=-1,r=-1,f=0;    while(p2>p1){        if(sum==x){            f=1;            l=a[p1];            r=a[p2];            break;        }        else if(sum>x){            sum-=a[p2];            p2--;            sum+=a[p2];        }        else{            sum-=a[p1];            p1++;            sum+=a[p1];        }    }    if(f==1){        ll int li=-1,ri=-1;        for(ll int i=0;i<n;i++){            if(b[i]==l){                li=i+1;                break;            }        }        for(ll int i=n-1;i>=0;i--){            if(b[i]==r){                ri=i+1;                break;            }        }        cout<<li<<" "<<ri;    }    else{        cout<<"IMPOSSIBLE";    }    return 0;}