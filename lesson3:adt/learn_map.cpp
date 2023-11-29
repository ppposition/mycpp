#include<iostream>
#include<map>
#include<string>
#include<iterator>
#include<fstream>
#include<algorithm>
using namespace std;
int main(int argc, char **argv){
	map<string,int> m1;
	m1["jishen"]=32;
	cout<<m1["jishen"]<<endl;
	multimap<string, string> m2;
	cout<<argv[1]<<": ";
	istream_iterator<string> rings(cin);
	m2.insert({argv[1],*rings});
	for(int i=2;i<argc;i++){
		cout<<argv[i]<<": ";
		m2.insert({argv[i],*++rings});
	}
	ofstream output("rings.txt");
	for_each(m2.cbegin(),m2.cend(),[&output](const pair<string,string>& p){output<<p.first<<" "<<p.second<<endl;});
	return 0;
}
