#include <iostream>
#include <io.h>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;


char * filePath = R"(D:\SVN\WNF_IT_QIU\��ُ�Լ��}�����P\shenjiliu\WNF�깺�����ɹ��������պ�һ����)";
void getFiles(string path, vector<string> &file){
	//�ļ����
	long long hFile = 0;

	struct _finddata_t fileinfo;

	string p;
	//findfirst ���б��е��ļ�
	hFile = _findfirst(p.assign(path).append("\\*.cpp").c_str(), &fileinfo);
	//��������ҵ��ļ�
	if (hFile != -1){

		do{
			//�������Ŀ¼
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				getFiles(path.append("\\").append(fileinfo.name),file);
			}
		}while (_findnext(hFile, &fileinfo) == 0);
	}
}

int main()
{

	return 0;
}