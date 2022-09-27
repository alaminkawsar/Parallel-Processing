#include<bits/stdc++.h>
#define MAX 10
using namespace std;

vector<pair<int,int>>adj[1<<8+5];
map<int,string>has;

int getDecimal(string s){
    int num = 0,pw=1;
    for(int i=s.size()-1;i>=0;i--){
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

void make_decimal_to_binary(){
    has[0]="0";
    for(int i=0;i<1000;i++){
        string s;
        int num=i;
        while(num){
            s+=(num%2+'0');
            num/=2;
        }
        reverse(s.begin(),s.end());
        has[i]=s;
    }
    // for(int i=0;i<100;i++){
    //     cout<<has[i]<<endl;
    // }
}

int main(){

    //Task-1: Find State Diagram
    string s= "10110001";
    string icv_str = s;
    //reverse(icv_str.begin(),icv_str.end());
    int num = getDecimal(icv_str);
    cout<<num<<endl;

    queue<int>Q;

    vector<int>vis(1<<16,0);
    int ICV = num;
    //printf("Paici \n");
    vector<int>temp=get_permissible_latency(num);
    for(int i=0;i<temp.size();i++){
        printf("%d ",temp[i]);
    }
    cout<<endl;

    Q.push(num);
    while(!Q.empty()){
        int parent_state = Q.front(); Q.pop();
        vector<int>permissible=get_permissible_latency(parent_state);

        for(int i=0;i<permissible.size();i++){
            //let's shift and do operation
            int child_state = ICV | (parent_state>>permissible[i]);
            //printf("parent_state=%d, Right Shift->%d\n",parent_state,parent_state>>permissible[i]);
            //printf("parent_state=%d, permissible=%d ,child=%d\n",parent_state, permissible[i],child_state);
            if(vis[child_state]) continue;
            adj[parent_state].push_back({child_state,permissible[i]});
            vis[child_state]=1;
            //adj[parent_state].push_back({child_state,permissible[i]});
            //let's make an edge
            Q.push(child_state);
        }
        
    }
    make_decimal_to_binary();
    
    // show connection between two state
    for(int i=0;i<(1<<16);i++) vis[i]=0;
    Q.push(num);
    while (!Q.empty())
    {
        int par = Q.front(); Q.pop();
        cout<<has[par]<<"--->";
        for(int i=0;i<adj[par].size();i++){
            cout<<"("<<has[adj[par][i].first]<<","<<adj[par][i].second<<") ";
            //printf("(%d,%d) ",has[adj[par][i].first],adj[par][i].second);
            if(vis[i]) continue;
            vis[i]=1;
            Q.push(adj[par][i].first);
        }
        cout<<endl;
        
    }

}