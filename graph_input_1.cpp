//Adonis!!
#include<bits/stdc++.h>
using namespace std;
 
#define ll              long long
#define endl            '\n'
 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define srt(s)          sort(s.begin(),s.end())
#define rsrt(s)         sort(s.rbegin(),s.rend())
#define fo(i,a,n)       for(int i = a; i < n; i++)
 
 
void solve(){
 
    int n; 
    cin >> n;
    int arr[n];
    fo(i,0,n) cin >> arr[i];
    int mx = arr[0];
    int mn = arr[0];
    int temp1 = arr[0],temp2=arr[0];
    int cnt = 0;
    fo(i,1,n){
    	mx = max(mx,arr[i]);
    	mn = min(mn,arr[i]);
    	if(temp1!=mx || temp2!=mn){
    		temp1 = mx;
    		temp2 = mn;
    		cnt++;
    	}
    }
    cout << cnt << endl;
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //int t;
    //cin >> t;
    //while(t--){
        solve();
    //}
 
    return 0;
}