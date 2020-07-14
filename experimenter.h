#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include "person.h"
using namespace std;
class Experimenter:virtual public Person
{
public:
    int exp_allowance;
    Experimenter():Person()
    {
        type="experimenter";
    }
    void setnum(){cin>>num;}
    void input()
    {
        cout<<"请输入该人员的工号：";
		cin>>num;
		cout<<"请输入该人员的姓名：";
		cin>>name;
		cout<<"请输入该人员的性别：";
		cin>>sex;
        cout<<"请输入该人员的基本工资：";
        cin>>base_pay;
		cout<<"请输入该人员的实验补助：";
		cin>>exp_allowance;
    }
    void Output()                                          
   {
		cout<<"该人员的工号："<<num<<endl;
		cout<<"该人员的姓名："<<name<<endl;
		cout<<"该人员的性别："<<sex<<endl;
    	cout<<"该人员的基本工资："<<base_pay<<endl;
    	cout<<"该人员实验补助："<<exp_allowance<<endl;
   }
   int Getnum()
	{
		return num;
	}
	string Getname()
	{
		return name;
	}
};
class Experimenter_e
{
    Experimenter experimenter[N];
	int vc;          
    int a;                                
public:
	Experimenter_e(){vc=0;} 
	void Add();
    void Find();	
	void Change();
	void Delete();
	void Save();
	void Read();
};
void Experimenter_e::Add()                                             
{		    
	if(vc>=N) 
	{ 
	    cout<<"人员已存满!"<<endl;  
		return; 
	}
	else
    {		
		Experimenter ex;
		cout<<"请输入要添加的该人员工号："<<endl<<endl;
		cout<<"输入0 可结束添加"<<endl<<endl;
		cin>>a;
        while(a)
		{
           int i;
		   for(i=0;i<vc;i++)     
		   {
			   if(a==experimenter[i].Getnum())
			   {
			       cout<<"您输入的该人员工号已存在!请再次输入该人员工号："<<endl;	
				   break;
			   }
		   }
		   if(i==vc)
		   {       
			   cout<<"该人员可添加："<<endl;
			   ex.input();
               experimenter[vc]=ex;
			   vc++;
			   cout<<"您已经成功添加，输入0可结束添加！"<<endl;
		   }
		   cin>>a;
		}
	}
}
void Experimenter_e::Find()                                                 
{
	int c;
	cout<<"按编号查询，请输入1"<<endl;
	cout<<"按姓名查询，请输入2"<<endl;
	cout<<"按0可以结束查询"<<endl;
	cin>>c;
	if(c==1)
	{
	    int a;
	    cout<<"请输入您想查询的该人员工号：";
	    cin>>a;
	    while(a)
	    {
            int i;
	        for(i=0;i<vc;i++)
		    if(a==experimenter[i].Getnum())
		    {
		        experimenter[i].Output();
		    	break;
		    }
	        if(i==vc)
		    cout<<"记录为空"<<endl;	
		    cout<<"请输入您想查询的该人员工号：";
	        cin>>a;
	    }
	}
    if(c==2)
	{
	    char l[20],s[20]="0";
		int k=0;
        cout<<"请输入您想查询的该人员姓名：";
        cin>>l; 
	    while(strcmp(l,s)!=0)
		{
            for(int i=0;i<vc;i++)
			    if(l==experimenter[i].Getname())
				{
				    k=1;
	                experimenter[i].Output();
				}
            if(k==0)
			    cout<<"记录为空"<<endl;
	            cout<<"请输入您想查询的该人员姓名：";
                cin>>l;
		}		
	}
}
void Experimenter_e::Change()                                                        
{
    int a;
	Experimenter b;
    cout<<"请输入您想修改的该人员工号：";
    cin>>a;
	while(a)
	{   
        int i;
        for(i=0;i<vc;i++)
		{
	        if(a==experimenter[i].Getnum())
			{ 
				cout<<"人员信息为："<<endl;
				experimenter[i].Output();
				cout<<"请输入修改后的工号"<<endl;
			    b.setnum();
                int j;
			    for(j=0;j<vc;j++)
	     	     	if(b.Getnum()==experimenter[j].Getnum()&&a!=experimenter[j].Getnum())
					{
						cout<<"输入工号已存在请重新输入："<<endl;
					   	b.setnum();
					}
		        if(j==vc)
				{
					cout<<"该人员信息可以录入"<<endl;
                    experimenter[i].input();
                    cout<<"修改成功！"<<endl;	
				}
				break;
			}
		}
	    if(i==vc)
        cout<<"记录为空"<<endl;	
		cout<<"请输入您想修改的该人员工号：";
	    cin>>a;
	}
}
void Experimenter_e::Delete()                                                   
{
	cout<<"按编号删除，请输入1"<<endl;
	cout<<"按姓名删除，请输入2"<<endl;
	cout<<"按0可以结束此功能"<<endl;
	int a,c;
	char x;
	cin>>c;
	if(c==1)
	{
		cout<<"请输入您想删除的该人员工号：";
	    cin>>a;
		while(a)
		{
            int i;
	        for( i=0;i<vc;i++)
			{
		        if(a==experimenter[i].Getnum())
				{
			        experimenter[i].Output();	
				    cout<<"是否删除该该人员信息?【是(t)，否(f)】";
					cin>>x;
					if('t'==x)
					{
						vc=vc-1;
						for(int j=i+1;j<=vc;i++,j++)
				        experimenter[i]=experimenter[j];
						cout<<"删除成功!"<<endl;
						return;
					}
					if('f'==x)
					return;
				}
			}
	        if(i==vc)
			{
		      cout<<"记录为空！"<<endl;
			  return;
			}
			
	}
}
	if(c==2)
	{
	     char l[20],s[20]="0";
         cout<<"请输入您想删除该人员的姓名：";
   	     cin>>l;
		 while(strcmp(l,s)!=0)
		 {
             int i;
   	         for( i=0;i<vc;i++)
	         {
				if(l==experimenter[i].Getname())
				{
	                experimenter[i].Output();	
				    cout<<"是否删除该该人员信息?【是(t)，否(f)】";
					cin>>x;
					  
					if('t'==x)
					{
						vc=vc-1;
						for(int j=i+1;j<=vc;i++,j++)
				        experimenter[i]=experimenter[j];
						cout<<"删除成功!"<<endl;
						return;
					}
					if('f'==x)
					return;
				}
			}
				if(i==vc)
				{
		           cout<<"记录为空！"<<endl;
				   return;
				}
			   
	   }
	}
}
void Experimenter_e::Save()                                              
{
   ofstream outfile("Experimenter.txt");
   if(!outfile)
   {
	  cout<<"OPEN ERROR!"<<endl;
	  exit(1);
   }
   outfile.write((char*)&experimenter,vc*sizeof(experimenter[0]));
   cout<<"保存成功"<<endl;
   outfile.close();
}
void Experimenter_e::Read()                                                     
{
	ifstream infile("Experimenter.txt");
	if(!infile)
	{
	   cout<<"OPEN ERROR!"<<endl;
	   exit(1);
	}
	   
	while(infile.read((char*)&experimenter[vc],sizeof(experimenter[0])))
	{
		vc++;
	}	
	cout<<"vc的值为："<<vc;
	cout<<"读取成功"<<endl;
infile.close();
}


