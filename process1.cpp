//process1����Ҫ��ԭ���ݼ��еĵ���λ�������еĶ���ת��Ϊ\t���Ӷ��ֳ�lat��lon
#include<iostream>
#include<fstream>
#include<sstream>
#include<ostream>
//������Ҫ�Ƕ�cin,cout֮���һЩ���������ӣ�����setfill,setw,setbase,setprecision�ȵȡ�����I/O������ͷ�ļ�,����C����ĸ�ʽ�����һ��.������һЩ�����Ŀ��ƺ�����:
#include<iomanip>
#include<vector>
#include<string>
using namespace std;

#define ifilename "D:\\test.txt"
#define ofilename "D:\\test_process1.txt"

int main()
{
	ifstream infile;
	infile.open(ifilename, ios::in);
	if (!infile){
		cerr << "�򿪴���" << endl;
		exit(1);
	}

	ofstream outfile;
	outfile.open(ofilename, ios::out);

	string x;
	char c = ',';//��ѵ�����еĶ���ת��Ϊ�ո�

	while (getline(infile, x)){//�����getline������ͷ�ļ�<string>�е�
		//Ѱ��һ���ַ�����ĳ���ַ���λ�ã���������ַ�������ַ����е�λ��
		int len = x.length();
		for (int i = 0; i < len; i++){
			if (x[i] == c){
				x[i] = '\t';
			}
		}
		outfile << x << endl;//���ַ���д���ļ�
	}

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
