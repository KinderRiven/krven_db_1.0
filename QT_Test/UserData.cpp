#include "UserData.h"


UserData::UserData()
{

}


UserData::~UserData()
{
}

void UserData::upDate()
{
	fstream fs,ft;
	fs.open("user\\AllUserData", ios::in | ios::out);
	char cname[256], cpassword[256];
	//�����û����Ķ�ȡ����
	while (!fs.eof())
	{
		fs.getline(cname, 256);
		userName.push_back(string(cname));
		fs.getline(cpassword, 256);
		userPassword.push_back(string(cpassword));
	}
	fs.close();
}