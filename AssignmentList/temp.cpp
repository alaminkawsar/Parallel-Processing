#include<bits/stdc++.h>
#include <stdio.h>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[])
{
    MPI_File fh;
    char buf[1000];
    int rank;

    MPI_Init(0,0);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_File_open(MPI_COMM_WORLD, "input.txt", MPI_MODE_CREATE | MPI_MODE_RDWR, MPI_INFO_NULL, &fh);

    if (rank == 0){
        MPI_File_read(fh, buf, 1000, MPI_CHAR, MPI_STATUS_IGNORE);
        //cout<<buf<<endl;
        int len = strlen(buf);
        buf[len-7]='\0';
        cout<<"Our main message is:\n"<<buf<<endl;

        string s;
        for(int i=0;i<len-7;i++) s+=buf[i];

        string word;
        vector<pair<int,string>>wordList;
        map<string,int>has;

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(word.size()>0){
                    has[word]++;
                    word="";
                }
            }else word+=s[i];
        }
        if(word.size()>0) has[word]++;
        for(auto it:has){
            wordList.push_back({it.second,it.first});
        }

        sort(wordList.begin(),wordList.end(),greater<>());

        cout<<"\nNumber of Word: "<<' '<<wordList.size()<<endl;

        printf("\nWord List:\n");
        for(int i=0;i<wordList.size();i++){
            cout<<wordList[i].second<<' '<<wordList[i].first<<endl;
        }

    }

    MPI_File_close(&fh);
    
    MPI_Finalize();
    return 0;
}