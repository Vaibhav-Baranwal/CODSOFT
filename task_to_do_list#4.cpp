#include<iostream>
#include<vector>
using namespace std;

vector <string>LIST;
vector<bool>status;

void add_task()
{
	string task;
	bool com;
	char choice;
	
	while(1)
	{
		cout<<"\nDo you want to add task in the TO-DO-LIST,\nPress 'Y' to say YES and 'N' to say NO: \n";
	    cin>>choice;
	    if(choice!='Y')
		{
			break;
		}  	
		cout<<"Enter the task to add:";
		cin>>task;
		LIST.push_back(task);
		cout<<"Enter 1 for task completion and 0 for not completed: ";
		cin>>com;
		status.push_back(com);
		cout<<"\nYour tasks has been entered SUCCESSFULLY!"<<endl;
		
	}	
}
void display()
{
	for(int i=0;i<LIST.size();i++)
	{
		cout<<"Task: "<<LIST[i]<<"  Status: "<<status[i]<<endl;
	}
}
void remove()
{
	string task;
	int flag=0;
	cout<<"Enter the task you want to remove: ";
	cin>>task;
	
	for(int i=0;i<LIST.size();i++)
	{
		if(LIST[i]==task)
		{
			LIST.erase(LIST.begin()+i);
			status.erase(status.begin()+i);
			cout<<"Your task has been deleted successfully!"<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"The task could not be found in the list"<<endl;
	}
	
}
void update_task()
{
	string task;
	cout<<"Enter the task you want to change the status of:";
	cin>>task;
	
	for(int i=0;i<LIST.size();i++)
	{
		if(LIST[i]==task)
		{
			if(status[i]==0)
			{
				status[i]=1;
				cout<<"You have marked your TASK as COMPLETE.\n";
			}
			else 
			{
				status[i]=0;
				cout<<"Complete the task to mark it as COMPLETE.\n";      
			}
	        break;
	    }
    }
}
int main()
{
	
	int op;
	while(1)
	{
	cout<<"MENU"<<endl;
	cout<<"1- To ADD task \n2- Display the Task List\n3- Update the status of the task\n4- Remove the Task\n5- Exit."<<endl;
	cin>>op;
	
	switch(op)
	{
		case 1:
			add_task();
			break;
		case 2:
			display();
			break;
		case 3:
			update_task();
			break;
		case 4:
			remove();
			break;	
		case 5:
			exit(0);
		default:
		    cout<<"Wrong Choice!"<<endl;	
	}
    }
	
	return 0;
}