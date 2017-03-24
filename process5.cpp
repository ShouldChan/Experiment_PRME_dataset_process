//process5:筛选next poi 处理时间的问题
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <time.h>
using namespace std;

#define ifilename "D:\\train_process5.txt"
#define ofilename "D:\\train_process6.txt"

void calTime(){
	tm tm_, tm1;
	time_t t1, t;
	char buf[128] = { 0 };
	strcpy(buf, "2012-01-01\t14:00:00");
	strptime(buf,"%Y/%m/%d\t%H:%M:%S",&tm_);
	tm_.tm_isdst = -1;
	strcpy(buf, "2012-01-01\t15:00:00");
	strptime(buf, "%Y/%m/%d\t%H:%M:%S", &tm_);
	tm1.tm_isdst = -1;
	t1 = mktime(&tm1);
	cout << (t1 - t) / 3600 << endl;

}
void selectNextPOI(){
	ifstream fin("E:\\process5.txt");
	ofstream fout("E:\\process6.txt");
	if (!fin){
		cerr << "wrong open" << endl;
		exit(1);
	}
	string s;
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];

	}
}
int main(){
	calTime();
	return 0;
}