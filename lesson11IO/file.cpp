#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char **argv){
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    string temp;
    while(getline(input, temp)){
        output<<temp<<endl;
    }
    return 0;
}