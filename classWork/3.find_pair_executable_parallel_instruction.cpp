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

int mat[50][50];

bool vis[27];
string str;

bool find_dependency(string a,string b){
    // dependency check
    for(int i=0;i<b.size();i++){
        if(a[0]==b[i]) return false;
    }
    // anti dependency check
    for(int i=0;i<a.size();i++){
        if(b[0]==a[i]) return false;
    }

    return true;
}
string get_dependency(string a,string b){
    string ans;
    for(int i=2;i<a.size();i++){
        if(a[i]!=b[0]) ans+=(i+1+'0');
    }
    return ans;
}

void solve()
{

    int n = 5;
    string s;
    vector<string>list;
    for(int i=0;i<n;i++){
        cin>>s;
        s=s.substr(3,s.size()-3);
        list.push_back(s);
        cout<<s<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<list[i]<<endl;
    }
    vector<pair<int,int>>ans;

    // Task-1: Get Parallel Executable Pair
    printf("\nGet Parallel Executable Pair:\n");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(find_dependency(list[i],list[j])){
                ans.push_back({i,j});
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        printf("Pair of Execuation: P%d P%d\n",ans[i].first+1,ans[i].second+1);
    }


    // Task-2: Find Dependency Graph
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            for(int k=3;k<list[j].size();k++){
                if(list[i][0]==list[j][k]){
                    mat[i][j]=1;
                    break;
                }
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("P%d--->",i+1);
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(mat[i][j]){
                printf("P%d ",j+1);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");    
}
int main()
{
    freopen("bernstain_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
