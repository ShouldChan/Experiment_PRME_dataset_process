//process1：主要将原数据集中的地理位置属性中的逗号转换为\t，从而分出lat和lon
#include<iostream>
#include<fstream>
#include<sstream>
#include<ostream>
//控制主要是对cin,cout之类的一些操纵运算子，比如setfill,setw,setbase,setprecision等等。它是I/O流控制头文件,就像C里面的格式化输出一样.以下是一些常见的控制函数的:
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
		cerr << "打开错误！" << endl;
		exit(1);
	}

	ofstream outfile;
	outfile.open(ofilename, ios::out);

	string x;
	char c = ',';//将训练集中的逗号转换为空格

	while (getline(infile, x)){//这里的getline函数是头文件<string>中的
		//寻找一个字符串中某个字符的位置，返回这个字符在这个字符串中的位置
		int len = x.length();
		for (int i = 0; i < len; i++){
			if (x[i] == c){
				x[i] = '\t';
			}
		}
		outfile << x << endl;//将字符串写入文件
	}

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
