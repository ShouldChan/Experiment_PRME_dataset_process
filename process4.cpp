//process4:修改2017-01-10格式为2017/01/10
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
/*			
					 ┏┓      ┏┓
					┏┛┻━━━┛┻┓
					┃      ☃      ┃
					┃  ┳┛  ┗┳  ┃
					┃      ┻      ┃
					┗━┓      ┏━┛
					┃      ┗━━━┓
					┃  神兽保佑    ┣┓
					┃　永无BUG！   ┏┛
					┗┓┓┏━┳┓┏┛
					┃┫┫  ┃┫┫
					┗┻┛  ┗┻┛
*/
#define ifilename "D:\\train_process3_2.txt"
#define ofilename "D:\\train_process4.txt"
#define iifilename "D:\\test_process3_2.txt"
#define oofilename "D:\\test_process4.txt"

void timeChange(){
	ifstream fin(iifilename);
	ofstream fout(oofilename);
	if (!fin){
		cerr << "wrong open!" << endl;
		exit(1);
	}
	string s;
	while (getline(fin, s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];//2010-03-03
		//cout << str[4] << endl;
		str[4][4] = '/'; str[4][7] = '/';//会报越界的错误 是因为数据集里存在几行为空行
		//cout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << str[0] << "\t" <<str[1]<< "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
	}
	fin.close();
	fout.close();
}
int main(){
	timeChange();
	system("pause");
	return 0;
}