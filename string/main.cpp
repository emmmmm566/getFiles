#include <iostream>
#include <io.h>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;


char * filePath = R"(D:\SVN\WNF_IT_QIU\採購以及倉庫相關\shenjiliu\WNF申购审批采购入库出库照合一条龙)";
void getFiles(string path, vector<string> &file){
	//文件句柄
	long long hFile = 0;

	struct _finddata_t fileinfo;

	string p;
	//findfirst 找列表中的文件
	hFile = _findfirst(p.assign(path).append("\\*.cpp").c_str(), &fileinfo);
	//如果你能找到文件
	if (hFile != -1){

		do{
			//如果你是目录
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