//process3: 遍历userid locationid 重新编号
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

#define ifilename "d:\\train_process2.txt"
#define ofilename "d:\\train_process3_2.txt"
#define iifilename "d:\\test_process2.txt"
#define oofilename "d:\\test_process3_2.txt"
#define intest "e:\\process2.txt"
#define outtest "e:\\process3.txt"


void mapreno(){
	ifstream fin(ifilename);
	ifstream ffin(iifilename);
	ofstream fout(ofilename);
	ofstream ffout(oofilename);
	if (!fin||!ffin){
		cerr << "wrong open!" << endl;
		exit(1);
	}
	string s;
	map<string, int> mapuser;
	map<string, int> mappoi;
	map<string, int>::iterator iteruser;
	map<string, int>::iterator iterpoi;
	int i = 1, j = 1;//记录user和poi的个数
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		iteruser = mapuser.find(str[0]);
		iterpoi = mappoi.find(str[1]);
		if (iteruser != mapuser.end()){
			//找到元素  不插入
		}
		else{
			//未找到元素    插入
			mapuser.insert(pair<string, int>(str[0], i));
			i++;
		}
		if (iterpoi != mappoi.end()){
			//找到元素
		}
		else{
			//未找到元素
			mappoi.insert(pair<string, int>(str[1], j));
			j++;
		}
	}
	fin.close();
	fin.open(ifilename);
	//遍历map
	/*map<string, int>::iterator iter;
	for (iter = mapuser.begin(); iter != mapuser.end(); iter++){
		fout << iter->first << "\t" << iter->second << endl;
	}
	for (iter = mappoi.begin(); iter != mappoi.end(); iter++){
		fout << iter->first << "\t" << iter->second << endl;
	}
	fout << "user num:" << i << "\tpoi num:" << j << endl;*/
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		//iteruser = mapuser.find(str[0]);
		//iterpoi = mappoi.find(str[1]);
		//fout << mapuser[str[0]] <<"\t"<< mappoi[str[1]]<<endl;
		//if (iteruser != mapuser.end() && iterpoi != mappoi.end()){
		//cout << iteruser->second << "\t" << iterpoi->second << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << mapuser[str[0]]<< "\t" << mappoi[str[1]] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		//}
	}
	cout << "user num:" << mapuser.size() << "\tpoi num:" << mappoi.size() << endl;
	
	while (getline(ffin, s)){
		string str[6];
		ffin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		ffout << mapuser[str[0]] << "\t" << mappoi[str[1]] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
	}
	fin.close();
	ffin.close();
	fout.close();
	ffout.close();
}
void reno(){//重新编号
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	if (!fin){
		cerr << "wrong open " << endl;
		exit(1);
	}
	string s;
	string temp = "user_3769";//临时存储比较的userid
	int i = 1;
	while (!fin.eof()){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		getline(fin, s);
		if (temp == str[0]){
			str[0] = to_string(i);
			//cout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
			fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		}
		else{
			i++;
			temp = str[0];//更新temp
			str[0] = to_string(i);
			//cout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
			fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		}
	}
	fin.close();
	fout.close();
}

struct loca{
	string loc;
	int no;
};

void userrenew(){
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	if (!fin){
		cerr << "wrong open" << endl;
		exit(1);
	}
	string s;
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		//cout << str[1] << endl;
		str[0][4] = ' ';//fin遇到空格暂停
		stringstream ostr(str[0]);
		string w;
		int t;
		ostr >> w >> t;
		//cout << t << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << t << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
	}
	fin.close();
	fout.close();
}
void locrenew(){//修改loc值//
	ifstream fin(ofilename);
	ofstream fout(oofilename);
	vector<loca> locat;
	if (!fin){
		cerr << "wrong open " << endl;
		exit(1);
	}
	string s;
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		//cout << str[1] << endl;
		str[1][3] = ' ';
		stringstream ostr(str[1]);
		string w;
		int t;
		ostr >> w >> t;
		//cout << str[0] << "\t" << t << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << str[0] << "\t" << t << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
	}
	fin.close();
	fout.close();
}
int main(){
	//reno();
	//userrenew();
	//locrenew();
	mapreno();
	system("pause");
	return 0;
}