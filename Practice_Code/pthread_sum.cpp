#include<bits/stdc++.h>
#define MAX 9
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d",&a)
#define p1(a) cout<<"Check "<<a<<endl;
#define p2(a,b) cout<<"Check "<<a<<' '<<b<<endl;
#define fo(i,n) for (i=0;i<n;i++)
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz=(int)2e5+5;

#define MAX_THREAD 3

int a[]={1,2,3,4,5,6,7,8,9};
int sum[4]={0};
int part = 0;

void* SUM(void* arg){
    int thread_sum = part++;
    for(int i=thread_sum*(MAX/3);i<(thread_sum+1)*(MAX/3);i++){
        sum[thread_sum]+=a[i];
    }
}

void solve()
{
    pthread_t threads[MAX_THREAD];
    for(int i=0;i<MAX_THREAD;i++){
        pthread_create(&threads[i],NULL,SUM,(void*)NULL);
    }

    for(int i=0;i<MAX_THREAD;i++){
        pthread_join(threads[i],NULL);
    }
    int s = 0;
    for(int i=0;i<MAX_THREAD;i++){
        s+=sum[i];
    }
    cout<<s<<endl;

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
