// //SHREE GANESHAYA NAMAH// //OM NAMAHA SHIVAY// #include<bits/stdc++.h>// #define ll long long// #define endl '\n'// #define pb push_back// #define pob pop_back// #define mp make_pair// #define ff first// #define ss second// #define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);// using namespace std;// const int m=(int)1e9+7;// const int N=1000;// // etf in sqrt(n) using prime factorisation// // ll int phi(ll int n){// //     ll int res=n;// //     for(ll int i=2;i*i<=n;i++){// //         if(n%i==0){// //             res/=i;// //             res*=(i-1);// //         }// //         while(n%i==0){// //             n/=i;// //         }// //     }// //     if(n>1){// //         res/=n;// //         res*=(n-1);// //     }// //     return res;// // }// // etf in nlog(logn) using sieve algo// // ll int p[1000001];// // void phif(ll int n){// //     for(ll int i=1;i<=n;i++){// //         p[i]=i;// //     }// //     for(ll int i=2;i<=n;i++){// //         if(p[i]==i){// //             for(ll int j=i;j<=n;j+=i){// //                 p[j]/=i;// //                 p[j]*=(i-1);// //             }// //         }// //     }// //     // for(ll int i=0;i<n;i++){// //     //     cout<<p[i]<<" ";// //     // }// // }// // ll int bin(ll int a,ll int b,ll int m){// //     ll int ans=1;// //     while(b>0){// //         if(b&1){// //             ans=(ans*a)%m;// //         }// //         a=(a*a)%m;// //         b>>=1;// //     }// //     return ans%m;// // }// int main(){//     fastio()//     // ////     // ll int t;//     // cin>>t;//     // while(t--){        //     // }//     // 3 pointers problem,3 sum problem//     ll int n,x;//     cin>>n>>x;//     vector<pair<ll int,ll int>>v;//     for(ll int i=0;i<n;i++){//         ll int ele;//         cin>>ele;//         v.pb({ele,i});//     }//     sort(v.begin(),v.end());//     ll int p1=0,p2=n-1;//     for(ll int i=1;i<n-1;i++){//         while(p2>p1){//             if(p2!=i && p1!=i && (v[i].ff+v[p1].ff+v[p2].ff)==x){//                 cout<<v[p1].ss+1<<" "<<v[i].ss+1<<" "<<v[p2].ss+1;//                 return 0;//             }//             else if((v[i].ff+v[p1].ff+v[p2].ff)>x){//                 p2--;//             }//             else if((v[i].ff+v[p1].ff+v[p2].ff)<x){//                 p1++;//             }//         }//     }//     cout<<"IMPOSSIBLE";//     return 0;// }#include <bits/stdc++.h>using namespace std;int main(){	ios_base::sync_with_stdio(0); cin.tie(0);	int n,x; cin >> n >> x;	vector<pair<int, int>> arr;	for(int i = 1; i <= n; i++){		int a; cin >> a;		pair<int, int> p; p.first = a; p.second = i;		// first in pair represents value, second represents index		arr.push_back(p);	}	sort(begin(arr), end(arr));	for(int i = 0; i < n; i++){		int l, r; l = 0; r = n-1;		while(l != r){			int target; target = x - arr.at(i).first;			if(l != i && r != i && arr.at(l).first + arr.at(r).first == target){				cout << arr.at(i).second << " " << arr.at(l).second					 << " " << arr.at(r).second << endl;				return 0;			}			if(arr.at(l).first + arr.at(r).first < target){				l++;			}			else{				r--;			}		}	}	cout << "IMPOSSIBLE" << endl;}