#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

string readFileIntoString3(const string& path) {
    struct stat sb{};
    string res;

    FILE* input_file = fopen(path.c_str(), "r");
    if (input_file == nullptr) {
        perror("fopen");
    }

    stat(path.c_str(), &sb);
    res.resize(sb.st_size);
    fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
    fclose(input_file);

    return res;
}


int main()
{
    string filename("input.txt");
    string file_contents;

    file_contents = readFileIntoString3(filename);
    // cout << file_contents << endl;
    map <string,int> freq;
    vector<vector<string>> arr;
    int i=0;
    string st="";

    while(i!=file_contents.length()){

        if(file_contents[i]==' '){
            i++;
        }

        st+=file_contents[i];
        i++;
    }
    // cout << st << endl << endl;

    i=0;
    while(i!=st.length()){
        vector <string> temp; int flag=0;

        if(st[i]=='=' && st[i+1]!='=' && st[i-1]!='=' && st[i+1]!='<' && st[i-1]!='<' && st[i+1]!='>' && st[i-1]!='>'){
            int j=i-1;

            while(st[j]!='\n' && st[j]!=';' && j>=0 && st[j]!=' '){
                j--;
            }

            string var1="";
            j++;

            while(j!=i){
                var1+=st[j];
                j++;
            }
            temp.push_back(var1);

            if(freq.find(var1)==freq.end()){
                freq.insert({var1,1});
            }

            else {
                freq[var1]++;
            }
            j++;
            var1="";

            while(st[j]!='+' && st[j]!='-' && st[j]!='*' && st[j]!='/' && st[j]!=';'){
                var1+=st[j];
                j++;
            }

            if(st[j]==';'){
                flag=1;
            }

            temp.push_back(var1);
            var1=st[j];
            temp.push_back(var1);
            var1="";
            j++;

            while(st[j]!=';' && (st[j]!='+' && st[j]!='-' && st[j]!='*' && st[j]!='/')){
                var1+=st[j];
                j++;
            }
            temp.push_back(var1);
        }
        if(temp.size()>1 && flag==0){
            arr.push_back(temp);
        }
        i++;
    }
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr[i].size();j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl << endl;
    // }

    for(auto itr=freq.begin();itr!=freq.end();itr++){
        // cout << itr->first << " " << itr->second << endl;

        if(itr->second>1){
            int count =48;

            for(int i=0;i<arr.size();i++){
                for(int j=0;j<arr[i].size();j++){

                    if(arr[i][j]==itr->first){

                        if(j==0){
                            count++;
                            arr[i][j]+=(char)count;
                        }

                        else{
                            arr[i][j]+=(char)count;
                        }
                    }
                }
            }
        }
    }
    cout << endl;

    cout << "Data Flow Graph :" << endl;
    for(int i=0;i<arr.size();i++){
        cout << arr[i][1] << "\t" << arr[i][3] << "\t" << arr[i][2] << "\t" << arr[i][0];
        cout << endl;
    }
    cout << endl;



    exit(EXIT_SUCCESS);
}

/* Data Flow graph implementation in C++
   
   Authored By : Deepanshu Agrawal
   E-mail ID   : agrawal.14@iitj.ac.in
   Instructor  : Prof. Binod Kumar
   Dated       : 24/04/2022
*/