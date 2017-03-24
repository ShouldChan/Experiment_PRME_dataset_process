//process2：擦除checkin_time之后的数据
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

#define ifilename "D:\\test_process1.txt"
#define ofilename "D:\\test_process2.txt"

struct data{
	//只是读取并写入 为了避免丢失数据 使用string
	string user_id;
	string poi_id;
	string lat;
	string lon;
	string time;
	string date_id;
};

void ReadDataFromFile(){
	cout << "逐词读取：" << endl;
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	string s;
	while (getline(fin,s)){
		string str[6];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		//cout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
	}
	fin.close();
	fout.close();
}

void deleteBack(){//有问题
	ifstream infile;
	infile.open(ifilename);
	ofstream outfile;
	outfile.open(ofilename);

	if (!infile){
		cerr << "打开文件错误!" << endl;
		exit(1);
	}
	string x, y;
	vector<string> str;
	//每行读取到第五个\t时 后面的就不要了
	char c = '\t';
	const int countc = 5;
	while (getline(infile, x)){
		int len = x.length();
		int count = 0;//来count一下出现\t的值
		for (int i = 0; i < len; i++){
			if (x[i] == c)
				count++;
			y = x.substr(0, i);//substr(int1,int2)int1表示第一个下标，int2表示多少个字符
			if (count == countc)
				outfile << y << endl;
		}
	}
	infile.close();
	outfile.close();
}
int main(){
	ReadDataFromFile();
	system("pause");
	return 0;

}