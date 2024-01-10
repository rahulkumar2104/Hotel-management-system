#include<iostream>
using namespace std;
class Hotel
{
	private:
		struct Node
		{
			int id,date;
			string name,roomtype;
			Node* next;
		};
		
	public:
		Node* head = NULL;
		void insert();
		void menu();
		void update();
		void search();
		void del();
		void sort();
		void show();
		void list();
};
void Hotel::menu()
{
	p:
		
	int choice;
	cout<<"\n";
	cout<<"\tWelcome To Hotel Management System Application\n" << endl;
	cout<<"\n\t_______Hotel Management System________";
	cout<<"\n\nS.No     Functions              Description"<<endl;
	cout<<"\n1\tAllocate Room\t\t\tInsert New Room";    
	cout<<"\n2\tSearch Room\t\t\tSearch Room with RoomID";    
	cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";    
	cout<<"\n4\tDelete Room\t\t\tDelete Room with RoomID";    
	cout<<"\n5\tShow Room Records\t\tShow Room Records that (we Added)";   
	cout<<"\n6\tExit"<<endl;
	
	cout<<"Enter Your Choice"<<endl;
	cin>>choice;
	switch(choice)
	{
	    case 1:
	        insert();
	        menu();
	
      	case 2:
	        search();
	        menu();
	
      	case 3:
	       update();
	       menu();

	    case 4:
	        del();
	        menu();
	
	
     	case 5:
	        show();
	        menu();
	
	case 6:
	    exit(0);  //if user will enter 0 then output will be invalid
		default:
		    cout<<"Invalid";						
	} 

}
void Hotel::insert()  //function code begin from here
{
	cout<<"\n\t______Hotel Management System_______";
	Node *new_node = new Node;
	cout<<"\nEnter Room ID "<<endl;  //these are details entered by user
	cin>>new_node->id;
	cout<<"\nEnter Customer Name "<<endl;
	cin>>new_node->name;
	cout<<"\nEnter Allocated Date "<<endl;
	cin>>new_node->date;
	cout<<"\nEnter Room Type(single/double/twin) "<<endl;
	cin>>new_node->roomtype;
	
	if(head==NULL)
	{
		head =new_node;
	}
	else    // if head is not null then next of pointer will check all node if there is empty node then it will create a new node
	{
		Node* ptr = head;
		while(ptr->next !=NULL)
		{
			ptr= ptr->next;
		}
		ptr->next = new_node;
	}
	cout<<"\n\n\t\t New Room Inserted";
}
void Hotel::search()
{
	cout<<"\n\t______Hotel Management System_______";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\nLinked List is Empty";
	}
	else   
	{
		cout<<"\n\nRoom ID";
		cin>>t_id;
		Node* ptr = head;
		while(ptr!=NULL)
		{
			if(t_id == ptr->id)  //if id entered by user is matched with id stored in pointer then this type of output is displayed
			{
				cout<<"\n\nRoom ID: "<<ptr->id;
				cout<<"\n\nCustomer Name: "<<ptr->name;
				cout<<"\n\nRoom Allocated Date: "<<ptr->date;
				cout<<"\n\nRoom Type: "<<ptr->roomtype;
				break; // Exit the loop after finding a match
			}
			ptr = ptr->next; // Move to the next node
		}
		
		if(ptr == NULL)
		{
			cout << "Room not found." << endl;
		}
	}
}

void Hotel::update()
{
	cout<<"\n\t________Hotel Management System________";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\nLinked list is Empty";
	}

else    //if room id matched with pointer id which is stored already then we can update the things which we want
{
	cout<<"\n\nRoom ID";
	cin>>t_id;
	Node *ptr = head;
	while(ptr!=NULL)
	{
		if(t_id==ptr->id)
		{
			cout<<"\n\nRoomID";
			cin>>ptr->id;
			
			cout<<"\n\nCustomer Name";
			cin>>ptr->name;
			
			cout<<"\n\nAllocated Date";
			cin>>ptr->date;
			
			cout<<"\n\nRoom Type";
			cin>>ptr->roomtype;
			
			cout<<"\n\n\t\t Update Record Successfully";
		}
		ptr = ptr->next;
	}
} 
}
void Hotel::del()
{
	cout<<"\n\t________Hotel Management System________";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\nLinked list is Empty";
	}
else
{
	cout<<"\n\nRoom ID";
	cin>>t_id;
	if(t_id == head->id)
	{
		Node* ptr = head;
		head = head->next;
		cout<<"Delete Room Record Successfully\n";
	}
else
{
	Node* pre = head;
	Node* ptr = head;
	while(ptr!=NULL)
	{
		if(t_id == ptr->id)
		{
			ptr->next=ptr->next;
			delete ptr;
			cout<<"Delete Room Record Successfully\n";
			break;
		}
		pre = ptr;
		ptr=ptr->next;
	}
}
}}

void Hotel::show()
{
	Node* ptr = head;
	while (ptr!= NULL)
	{
		cout<<"\n\nRoomID"<<ptr->id;
		
		cout<<"\n\nCustomer Name"<<ptr->name;
		
		cout<<"\n\nAllocated Date"<<ptr->date;
		
		cout<<"\n\nRoom Type"<<ptr->roomtype;
		ptr = ptr->next;
	}
}
void Hotel::sort()
{
	if(head==NULL)
	{
		cout<<"\n\nLinked list is Empty";
		menu();
	}
	int count = 0, t_date,t_id;
	string t_name, t_roomtype;
	Node* ptr = head;
	while (ptr!=NULL)
	{
		count++;
		ptr = ptr->next;
	}
	for(int i = 1; i<=count; i++)
	{
		Node *ptr = head;
		for(int j=1; j<count; j++)
		{
			if( ptr->id > ptr->next->id)
			{
				t_id=ptr->id;
				t_name=ptr->name;
                t_date=ptr->date;
                t_roomtype=ptr->roomtype;
                //save date into current mode
                ptr->id=ptr->next->id;
                ptr->name=ptr->next->name;
                ptr->date=ptr->next->date;
                ptr->roomtype=ptr->next->roomtype;
                //save data into next node
                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
			    ptr->next->roomtype = t_roomtype;	  
			}
			ptr = ptr->next;
		}
	}
}
int main()
{
	Hotel h;
	h.menu();
}








