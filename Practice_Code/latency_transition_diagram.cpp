#include<bits/stdc++.h>

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
        for(int j=0;j<m;j++){
            if(s[i][j]=='1'){
                for(int k=j+1;k<m;k++){
                    if(s[i][k]=='1'){
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
    printf("\n\n");
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
        bool flag=true;
        for(auto x: adj[parent_state]){
            int child = x.first;
            int permi = x.second;

            if(has[{parent_state,child,permi}]) continue;
            if(flag){
                cout<<"Parent: "<<getBinary(parent_state)<<"--->";
                flag=false;
            }
            cout<<"("<<getBinary(child)<<","<<permi<<") ";
            has[{parent_state,child,permi}]=true;
            Q.push(child);
        }
        if(!flag) printf("\n");
    }
}

void makeStateTransitionDiagram(string str_icv){
    int ICV = getDecimal(str_icv);
    queue<int>Q;
    Q.push(ICV);
    while(!Q.empty()){
        int parent_state = Q.front(); Q.pop();
        vector<int>permissible = findPermissible(parent_state);
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
    /* TASK-1: Find Forbidden Latency */
    printf("Forbidden Latency:\n");
    set<int> forbidden = getForbiddenLatency();
    for(auto it: forbidden){
        printf("%d ",it);
    }
    cout<<endl;
    vector<int>permissible = getPermissible(forbidden);

    /* TASK-2: Permissible Latency */
    printf("Permissible Latency:\n");
    for(auto it: permissible){
        printf("%d ",it);
    }
    printf("\n\n");

    /* TASK-3: Collision Vector */
    vector<int>collision(m+1,0);
    for(auto it: forbidden){
        collision[it]=1;
    }
    printf("Collistion Vector:\n");
    for(int i=m;i>=1;i--){
        printf("%d ",collision[i]);
    }
    printf("\n\n");

    /*Task-4: Finding Collision Point*/
    queue<pair<int,int>>Q;
    map<pair<int,int>, bool>have;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i]=='1') Q.push({j,i}),have[{j,i}]=true;
        }
    }
    //check every initiation
    for(int i=0;i<m;i++){
        int x = 0;
        int y = i-1;
        bool found = true;
        queue<pair<int,int>>temp=Q;
        vector<pair<int,int>>store;
        while(!temp.empty() and found){
            auto u = temp.front(); temp.pop();
            x=u.first,y++;
            if(have[{x,y}]){
                printf("Initiation(1,%d),Collision found at point(%d,%d)\n",i+1,x+1,y+1);
                found=false;
            }
            store.push_back({x,y});
        }
        if(found){
            for(auto it: store) have[it]=true;
        }
    }
    // Task-5: Draw State Transition Diagram

    string str_icv;
    int icv=0,j=0;
    for(int i=m;i>=1;i--,j++){
        str_icv+=collision[i]+'0';
    }

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
