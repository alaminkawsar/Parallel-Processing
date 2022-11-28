#include<bits/stdc++.h>
#define MAX 100005
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
vector<string>vec;
void solve()
{
    string s;
    int n = 0;
    while(cin>>s){
        s = s.substr(0,s.size()-1);
        vec.push_back(s);
        cout<<s<<endl;
        n++;
    }
    char output[100];
    vector<char>input[sz];
    for(int i=0;i<n;i++){
        output[i]=vec[i][3];
        for(int j=5;j<vec[i].size();j++){
            if(vec[i][j]>='A' and vec[i][j]<='Z'){
                input[i].push_back(vec[i][j]);
            }
        }
    }
    int N=100;
    int mat[N][N];
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++) mat[i][j]=0;

    // flow dependency
    vector<pair<int,int>>flow,anti;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<input[j].size();k++){
                if(output[i]==input[j][k]){
                    flow.push_back({i,j});
                    mat[i][j]=1;
                }
            }
        }
    }
    //Anti dependency
    for(int i=0;i<n;i++){
        for(int j=0;j<input[i].size();j++){
            for(int k=i+1;k<n;k++){
                if(input[i][j]==output[k]){
                    anti.push_back({i,k});
                    if(mat[i][k]) mat[i][k]=3;
                    else mat[i][k]=2;
                }
            }
        }
    }
    printf("   ");
    for(int i=0;i<n;i++){
        printf("P%d ",i+1);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("P%d:",i+1);
        for(int j=0;j<n;j++){
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }

    // for(int i=0;i<n;i++){
    //     printf("%c-->",output[i]);
    //     for(int j=0;j<input[i].size();j++){
    //         printf("%c ",input[i][j]);
    //     }
    //     printf("\n");
    // }



    

    
}
int main()
{
    freopen("bernstain.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0;// cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
