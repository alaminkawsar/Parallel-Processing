#include<bits/stdc++.h>
#define MAX 10
using namespace std;

vector<pair<int,int>>adj[1<<8+5];

int getRightShift(int parent_state,int cnt){

    for(int i=0;i<cnt;i++){
        parent_state/=2;
    }
    return parent_state;
}

int getDecimal(string s){
    int num = 0,pw=1;
    for(int i=0;i<s.size();i++){
        num+=(pw*(s[i]-'0'));
        pw*=2;
        
    }
    return num;
}

vector<int> get_permissible_latency(int n){
    vector<int>ans;
    for(int i=0;i<8;i++){
        if((n&(1<<i))==0){
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main(){
    //Task-1: Find State Diagram
    string s= "10001101";
    string icv_str = s;
    //reverse(icv_str.begin(),icv_str.end());
    int num = getDecimal(icv_str);
    cout<<num<<endl;

    queue<int>Q;

    vector<int>vis(1<<8,0);
    Q.push(num);
    while(!Q.empty()){
        int parent_state = Q.front(); Q.pop();
        vis[parent_state]=1;
        vector<int>permissible=get_permissible_latency(parent_state);

        for(int i=0;i<permissible.size();i++){
            //let's shift and do operation
            int child_state = parent_state | getRightShift(parent_state,permissible[i]);
            //printf("parent_state=%d, Right Shift->%d\n",parent_state,parent_state>>permissible[i]);
            //printf("parent_state=%d, permissible=%d ,child=%d\n",parent_state, permissible[i],child_state);
            adj[parent_state].push_back({child_state,permissible[i]});
            if(vis[child_state]) continue;
            //adj[parent_state].push_back({child_state,permissible[i]});
            //let's make an edge
            Q.push(child_state);
        }
        
    }
    
    // show connection between two state
    Q.push(num);
    while (!Q.empty())
    {
        int par = Q.front(); Q.pop();
        printf("%d--->",par);
        for(int i=0;i<adj[par].size();i++){
            printf("(%d,%d) ",adj[par][i].first,adj[par][i].second);
            Q.push(adj[par][i].first);
        }
        cout<<endl;
        
    }

}