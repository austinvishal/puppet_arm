
#include<vector>
#include <algorithm>
#include <iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;

int main() {


	vector<int> Pos;
	vector<string> Output,name;
	string str[] = {"head_nod","head_pan","left_e0","left_e1","left_s0","left_s1","left_w0","left_w1","left_w2","right_e0","right_e1","right_s0","right_s1","right_w0","right_w1","right_w2","torso_t0"};
	//cout<<"Existing robot states"<<endl;
	int size_str=sizeof(str)/sizeof(str[0]);
	//cout<<"Total : "<<size_str<<endl;
	for( int l = 0; l<size_str; l++)
	{
		name.push_back(str[l]);
	}


	/*cout << "mapping right to left"<<endl;
	for(unsigned int k= 0 ; k < name.size();k++)
		{
			cout<<name[k] <<endl;
		}*/





	int a = -2;
	int b = 2;
	for(unsigned int i = 0; i < name.size() ; i++ )
		{
			if(name[i].substr(0,5)=="right")
			{
			//cout<<"state found"<<name[i]<<endl;
			  if(name[i]=="right_e0" || name[i]=="right_s0"|| name[i]=="right_w0"|| name[i]=="right_w2")
				Pos.push_back(a);
			  else
				  Pos.push_back(b);
			}
			  if(name[i].substr(0,4)=="left")
			{
				//  cout<<"left found"<<name[i]<<endl;
			  Output.push_back(name[i]);
			}

		}
	for(unsigned int k= 0 ; k < Output.size();k++)
	{
		cout<<Output[k] <<endl;
	}
cout<<"pose"<<endl;
	for(unsigned int j = 0 ; j < Pos.size();j++)
	{
		cout<<Pos[j] <<endl;
	}

cin.get();
		}




