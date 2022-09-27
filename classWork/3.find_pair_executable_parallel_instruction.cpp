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

vector<int>adj[30];

bool vis[27];
string str;
void dfs(int n){
    vis[n]=true;
    for(int i=0;i<adj[n].size();i++){

        if(vis[adj[n][i]]) continue;
        //cout<<adj[n][i]<<endl;
        str+=(adj[n][i]+'A');
        //cout<<str<<endl;
        dfs(adj[n][i]);
    }
}

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

void solve()
{

    int n = 5;
    string s;
    vector<string>list;
    for(int i=0;i<n;i++){
        cin>>s;
        s=s.substr(3,s.size()-3);
        list.push_back(s);
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
    vector<string>dependency_list;
    for(int i=0;i<n;i++){
        int id = list[i][0]-'A';
        //cout<<id<<" :";
        for(int j=2;j<list[i].size();j++){
            if(list[i][j]>='A' and list[i][j]<='Z'){
                adj[id].push_back(list[i][j]-'A');
                //printf("%d ",list[i][j]-'A');
            }
        }
        //printf("\n");
    }
    printf("\n");
    for(int i=0;i<n;i++){
        clr(vis,0);
        dfs(list[i][0]-'A');
        //cout<<str<<endl;
        vector<int>dep;
        for(int j=0;j<n;j++){
            for(int x=0;x<str.size();x++){
                if(list[i][0]==str[i]) continue;
                if(list[j][0]==str[x]){
                    dep.push_back(j);
                    
                }
            }
        }
        printf("P%d dependes on: ",i+1);
        for(int j=0;j<dep.size();j++){
            printf("P%d ",dep[j]+1);
        }
        printf("\n");
        str="";
    }
    printf("\n");


    
    
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
