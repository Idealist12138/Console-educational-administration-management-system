#include <iostream>
#include "teacher.h"
#include "experimenter.h"
#include "administrativer.h"
#include "teacher_experimenter.h"
#include "administrativer_teacher.h"
using namespace std;
void quit();
int choose();
void teacher();
void experimenter();
void administrativer();
void teacher_experimenter();
void administrativer_teacher();
void interface();
void quit()
{
    cout<<endl<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"---------------已退出---------------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl<<endl;
    exit(1);
}
int choose()
{
    int a;
    cout<<"0.退出"<<endl;
    cout<<"1.添加"<<endl;
    cout<<"2.查找"<<endl;
    cout<<"3.修改"<<endl;
    cout<<"4.删除"<<endl;
    cout<<"5.保存"<<endl;
    cout<<"6.读取"<<endl<<endl;
    cout<<"选择操作(0~6)：";
    cin>>a;
    cout<<endl;
    return a;
}
void teacher()
{   
    Teacher_t tt;
    int a;
    a=choose();
    switch (a)
    {
    case 0:interface();break;
    case 1:tt.Add();tt.Save();break;
    case 2:tt.Find();tt.Save();break;
    case 3:tt.Change();tt.Save();break;
    case 4:tt.Delete();tt.Save();break;
    case 5:tt.Save();break;
    case 6:tt.Read();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}
void experimenter()
{   
    Experimenter_e ee;
    int a;
    a=choose();
    switch (a)
    {
    case 0:interface();break;
    case 1:ee.Add();ee.Save();break;
    case 2:ee.Find();ee.Save();break;
    case 3:ee.Change();ee.Save();break;
    case 4:ee.Delete();ee.Save();break;
    case 5:ee.Save();break;
    case 6:ee.Read();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}
void administrativer()
{   
    Administrativer_a aa;
    int a;
    a=choose();
    switch (a)
    {
    case 0:interface();break;
    case 1:aa.Add();aa.Save();break;
    case 2:aa.Find();aa.Save();break;
    case 3:aa.Change();aa.Save();break;
    case 4:aa.Delete();aa.Save();break;
    case 5:aa.Save();break;
    case 6:aa.Read();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}
void teacher_experimenter()
{
    Teacher_Experimenter_te te_te;
    int a;
    a=choose();
    switch (a)
    {
    case 0:interface();break;
    case 1:te_te.Add();te_te.Save();break;
    case 2:te_te.Find();te_te.Save();break;
    case 3:te_te.Change();te_te.Save();break;
    case 4:te_te.Delete();te_te.Save();break;
    case 5:te_te.Save();break;
    case 6:te_te.Read();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}

void administrativer_teacher()
{
    Administrativer_Teacher_at at_at;
    int a;
    a=choose();
    switch (a)
    {
    case 0:interface();break;
    case 1:at_at.Add();at_at.Save();break;
    case 2:at_at.Find();at_at.Save();break;
    case 3:at_at.Change();at_at.Save();break;
    case 4:at_at.Delete();at_at.Save();break;
    case 5:at_at.Save();break;
    case 6:at_at.Read();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}
void interface()
{
    int choice;
    cout<<endl<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"----------高校工资管理系统----------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl<<endl;
    cout<<"0.退出"<<endl;
    cout<<"1.教师"<<endl;
    cout<<"2.实验员"<<endl;
    cout<<"3.行政人员"<<endl;
    cout<<"4.教师兼职实验员"<<endl;
    cout<<"5.行政人员兼职教师"<<endl<<endl;
    cout<<"选择操作对象(0~5)：";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
    case 0:quit();break;
    case 1:teacher();break;
    case 2:experimenter();break;
    case 3:administrativer();break;
    case 4:teacher_experimenter();break;
    case 5:administrativer_teacher();break;
    default:cout<<"数据错误，请重新输入！"<<endl;break;
    }
}
int main()
{
	int a=1;
	while(1)
    {
		interface();
    	cout<<endl<<"是否继续操作？"<<endl;
    	cout<<endl<<"0.退出 1.继续"<<endl;
		cout<<endl<<"选择操作："; cin>>a;
	}
	if(!a)quit();
    return 0;
}
