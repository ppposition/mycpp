#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream input;
    ofstream output;
    input.open("try.txt");
    output.open("try_out.txt");
    if (!output.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }
    string word,line;
    int num=0;
    /*while(input>>word){
        num++;
        cout<<word<<endl;
        output<<word<<endl;
    }*/
    cout<<num<<endl;
    while (getline(input, line))
    {
        cout<<line<<endl;
    }
    input.close();
    output.close();
    return 0;
}