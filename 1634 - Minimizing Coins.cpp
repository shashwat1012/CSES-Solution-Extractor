// //SHREE GANESHAYA NAMAH// //OM NAMAHA SHIVAY// #include<bits/stdc++.h>// #define ll long long// #define endl '\n'// #define pb push_back// #define pob pop_back// #define mp make_pair// #define ff first// #define ss second// #define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);// using namespace std;// // const int m=(int)1e9+7;// // const int N=1000000;// // etf in sqrt(n) using prime factorisation// // ll int phi(ll int n){// //     ll int res=n;// //     for(ll int i=2;i*i<=n;i++){// //         if(n%i==0){// //             res/=i;// //             res*=(i-1);// //         }// //         while(n%i==0){// //             n/=i;// //         }// //     }// //     if(n>1){// //         res/=n;// //         res*=(n-1);// //     }// //     return res;// // }// // etf in nlog(logn) using sieve algo// // ll int p[1000001];// // void phif(ll int n){// //     for(ll int i=1;i<=n;i++){// //         p[i]=i;// //     }// //     for(ll int i=2;i<=n;i++){// //         if(p[i]==i){// //             for(ll int j=i;j<=n;j+=i){// //                 p[j]/=i;// //                 p[j]*=(i-1);// //             }// //         }// //     }// //     // for(ll int i=0;i<n;i++){// //     //     cout<<p[i]<<" ";// //     // }// // }// // vector<ll int>factorial(N+20);// // ll int bin(ll int a,ll int b,ll int m){// //     ll int ans=1;// //     while(b>0){// //         if(b&1){// //             ans=(ans*a)%m;// //         }// //         a=(a*a)%m;// //         b>>=1;// //     }// //     return ans%m;// // }// // ll int cei(ll int a,ll int b){// //     if(a%b==0){// //         return a/b;// //     }// //     else{// //         return (a/b)+1;// //     }// // }// // bool prime(ll int n){// //     for(ll int i=2;i*i<=n;i++){// //         if(n%i==0){// //             return false;// //         }// //     }// //     return true;// // }// ll int f(ll int i,ll int t,ll int a[],vector<vector<ll int>>&dp){//     if(t==0){//         return 0;//     }//     if(i==0){//         if(t%a[i]==0){//             return t/a[i];//         }//         return 1e9;//     }//     if(dp[i][t]!=-1){//         return dp[i][t];//     }//     ll int p=1e9,np=f(i-1,t,a,dp);//     if(a[i]<=t){//         p=1+f(i,t-a[i],a,dp);//     }//     dp[i][t]=min(p,np);//     return dp[i][t];// }// int main(){//     fastio()//     // freopen("input.txt", "r", stdin);//     // freopen("output.txt", "w", stdout);//     ll int t=1;//     //cin>>t;//     while(t--){//         ll int n,x;//         cin>>n>>x;//         ll int c[n];//         for(ll int i=0;i<n;i++){//             cin>>c[i];//         }//         vector<vector<ll int>>dp(n,vector<ll int>(x+1,0));//         for(ll int i=0;i<=x;i++){//             if(i%c[0]==0){//                 dp[0][i]=i/c[0];//             }//             else{//                 dp[0][i]=1e9;//             }//         }//         for(ll int i=1;i<n;i++){//             for(ll int t=0;t<=x;t++){//                 int notTake = 0 + dp[i-1][t];//                 int take = 1e9;//                 if(c[i]<=t)//                     take = 1 + dp[i][t- c[i]];                //                 dp[i][t] = min(notTake, take);//             }//         }//         if(dp[n-1][x]>=1e9){//             cout<<"-1";//         }//         else{//             cout<<dp[n-1][x];//         }//     }    //     return 0;// }#include <bits/stdc++.h>using namespace std;int main() {  int n, target;  cin >> n >> target;  vector<int> c(n);  for (int&v : c) cin >> v;  vector<int> dp(target+1,1e9);  dp[0] = 0;  for (int i = 1; i <= target; i++) {    for (int j = 0; j < n; j++) {      if (i-c[j] >= 0) {	dp[i] = min(dp[i], dp[i-c[j]]+1);      }    }  }  cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;}