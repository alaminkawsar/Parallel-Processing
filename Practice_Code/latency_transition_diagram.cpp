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

int n,m;
string s[sz];
vector<pair<int,int>>adj[sz];
map<tuple<int, int, int> ,bool>has;

set<int> getForbiddenLatency(){
    set<int>forbidden;

    for(int i=0;i<n;i++){
        m = s[i].size();
        // cout << m << endl;
        for(int j=0;j<m;j++){
            if(s[i][j]=='1'){
                //p2(i,j);
                for(int k=j+1;k<m;k++){
                    if(s[i][k]=='1'){
                        //p2(j,k);
                        forbidden.insert(abs(k-j));
                    }
                }
            }
        }
    }
    return forbidden;
}

vector<int> getPermissible(set<int>s){
    vector<int>permissible;
    for(int i=1;i<=m;i++){
        if(s.find(i)!=s.end()) continue;
        permissible.push_back(i);
    }
    return permissible;
}

int getDecimal(string s){
    int sum = 0, j = 0;
    for(int i=s.size()-1;i>=0;i--,j++){
        sum+=pow(2,j)*(s[i]-'0');
    }
    return sum;
}

vector<int>findPermissible(int n){
    vector<int>permissible;
    for(int i=0;i<m;i++){
        if((n&(1<<i))==0){
            permissible.push_back(i+1);
        }
    }


    return permissible;
}

void Print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    printf("\n");
}

string getBinary(int n){
    string bin;
    while(n){
        bin+=(n%2+'0');
        n/=2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

void Display(int ICV){
    queue<int>Q;
    Q.push(ICV);
    has.clear();
    while(!Q.empty()){
        int parent_state = Q.front(); Q.pop();
        cout<<"Parent: "<<getBinary(parent_state)<<"--->";
        for(auto x: adj[parent_state]){
            int child = x.first;
            int permi = x.second;
            cout<<"("<<getBinary(child)<<","<<permi<<") ";

            if(has[{parent_state,child,permi}]) continue;

            has[{parent_state,child,permi}]=true;
            Q.push(child);
        }
        printf("\n");
    }
}

void makeStateTransitionDiagram(string str_icv){
    int ICV = getDecimal(str_icv);
    //cout<<str_icv<<endl;
    //cout<<icv<<endl;
    queue<int>Q;
    Q.push(ICV);
    while(!Q.empty()){
        int parent_state = Q.front(); Q.pop();
        vector<int>permissible = findPermissible(parent_state);
        //Print(permissible);
        for(auto permi: permissible){
            int child = ICV | (parent_state>>permi);

            if(has[{parent_state,child,permi}]) continue;
            has[{parent_state,child,permi}]=true;
            
            adj[parent_state].push_back(make_pair(child,permi));
            Q.push(child);
        }
    }
    Display(ICV);

}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    printf("Forbidden Latency:\n");
    set<int> forbidden = getForbiddenLatency();
    for(auto it: forbidden){
        printf("%d ",it);
    }
    cout<<endl;
    vector<int>permissible = getPermissible(forbidden);

    printf("Permissible Latency:\n");
    for(auto it: permissible){
        printf("%d ",it);
    }
    printf("\n");

    
    vector<int>collision(m+1,0);
    for(auto it: forbidden){
        collision[it]=1;
    }

    printf("Collistion Vector:\n");
    for(int i=m;i>=1;i--){
        printf("%d ",collision[i]);
    }
    printf("\n");

    // Task-4: Draw State Transition Diagram

    // make string using collision vector
    string str_icv;
    int icv=0,j=0;
    for(int i=m;i>=1;i--,j++){
        str_icv+=collision[i]+'0';
    }
    //cout<<str_icv<<endl;

    makeStateTransitionDiagram(str_icv);

    
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
