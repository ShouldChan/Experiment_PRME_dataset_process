//process2������checkin_time֮�������
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

#define ifilename "D:\\test_process1.txt"
#define ofilename "D:\\test_process2.txt"

struct data{
	//ֻ�Ƕ�ȡ��д�� Ϊ�˱��ⶪʧ���� ʹ��string
	string user_id;
	string poi_id;
	string lat;
	string lon;
	string time;
	string date_id;
};

void ReadDataFromFile(){
	cout << "��ʶ�ȡ��" << endl;
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

void deleteBack(){//������
	ifstream infile;
	infile.open(ifilename);
	ofstream outfile;
	outfile.open(ofilename);

	if (!infile){
		cerr << "���ļ�����!" << endl;
		exit(1);
	}
	string x, y;
	vector<string> str;
	//ÿ�ж�ȡ�������\tʱ ����ľͲ�Ҫ��
	char c = '\t';
	const int countc = 5;
	while (getline(infile, x)){
		int len = x.length();
		int count = 0;//��countһ�³���\t��ֵ
		for (int i = 0; i < len; i++){
			if (x[i] == c)
				count++;
			y = x.substr(0, i);//substr(int1,int2)int1��ʾ��һ���±꣬int2��ʾ���ٸ��ַ�
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