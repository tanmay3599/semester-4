#include<iostream>
#include<stdlib.h>
#define size 7
using namespace std;

struct node{
	int data;
	struct node* next;
};

void create_index_array(struct node* arr[])
{
	for(int i=0;i<size;i++)
	{
		arr[i]=NULL;
	}
}

int is_element(struct node* set,int num)
{
	struct node* s=set;
		while(s!=NULL)
		{
			
			if(num==s->data)
			{
				return 1;
			}
			s=s->next;
		}
	return 0;
}

int size_of(struct node* arr[])
{
	int count=0;
	
	struct node* temp[size];
	for(int i=0; i<size; i++)
	temp[i]=arr[i];
	
	for(int i=0; i<size; i++)
	{
		while(temp[i]!=NULL)
		{
			temp[i]=temp[i]->next;
			count++;
		}
	}
	return count;
}


void enumerate_list(struct node *head)
{
	printf("your list is ==>  \n \n"); 
	
	struct node* current=head;
	while(current!=NULL)
	{	
		printf("%d \n",current->data);
		current = current->next;
	}
}



void enumerate_map(struct node* arr[])
{
	struct node* temp[size];
	
	for(int i=0; i<size; i++)
	temp[i]=arr[i];
	
	int is_empty(struct node* arr[]);
	
	if(!is_empty(arr))
	{
		cout<<"Empty\n";
		return;
	}
	
	for(int i=0; i<size; i++)
	{
		while(temp[i]!=NULL)
		{
			cout<<temp[i]->data<<" ";
			temp[i]=temp[i]->next;
		}
	}
	cout<<endl;
}


struct node* add_elements(struct node* set,int data)
{
	struct node	*s = set;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
		
	if(!is_element(set,data)) 
	{
		if(s==NULL)
		{
			set = temp;
		}
		else
		{
			while(s->next!=NULL)
			{
				s = s->next;
			}
			 s->next = temp;
		}
	}
	return set;
}

struct node * remove_element(struct node *head, int n)     
{
	struct node *current= head;
	struct node *prev;

	if(current!=NULL && current -> data == n)
	{
		head = head->next;  
		free(current);
		return head;
	}

	if(is_element(current,n)==1)
	{
			
		while(current !=NULL && current->data!=n)
		{
			prev = current;
			current=current->next;	
		}
		if(current==NULL)
			return head;	
		prev -> next = current -> next;
		free(current);
	}
	return head;
}

int is_empty(struct node* arr[])
{
	for(int i=0; i<10; i++)
	{
		if(arr[i]!=NULL)
		return 1;
	}
	return 0;
}



void build(int a[],struct node* arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		arr[(a[i])%size] = add_elements(arr[(a[i])%size],a[i]);
	}
	
}

struct node * union_(struct node* s1[],struct node* s2[])
{
	struct node * temp = NULL;
	for(int i=0;i<size;i++)
	{
		struct node * s2_copy = s2[i]; 
	 
			while (s2_copy != NULL)
		{
			temp = add_elements(temp, s2_copy->data);
			s2_copy = s2_copy->next;
		}
		
		int data;
		
		for (s2_copy = s1[i]; s2_copy!= NULL;)
		{
			data = s2_copy->data;
			s2_copy = s2_copy->next;
			if (is_element(s2[i],data) != 1)
				temp = add_elements(temp,data); 
		}
			
	}
		return temp;
}


	struct node * difference(struct node* s1[], struct node* s2[])
	{
		struct node * s1_copy = NULL;
		for(int i=0;i<size;i++)
		{
	
		struct node * temp = s1[i]; 
		// s1_copy created 
		while (temp != NULL)
		{
			s1_copy = add_elements(s1_copy, temp->data);
			temp = temp->next;
		}

		int data;
		//temp variable will used if loop
		for (temp = s1_copy; temp!= NULL; )
		{
			data = temp->data;
			temp = temp->next;
			if (is_element(s2[i],data) == 1)
				s1_copy = remove_element(s1_copy, data); // removing elements which are not present at set2
		}
		
	}
	return s1_copy;	
	} 

	struct node* intersection_of_sets(struct node* s1[],struct node* s2[])
	{
		/*for(int i=0;i<size;i++)
		{
			temp[i] = difference(s1,s2);
    		temp[i] = difference(s1,temp);
		}
		return temp;*/
		
	    struct node * s1_copy = NULL;
	    struct node* intersect = NULL;
		for(int i=0;i<size;i++)
		{
	
		struct node * temp = s1[i]; 
		// s1_copy created 
		while (temp != NULL)
		{
			s1_copy = add_elements(s1_copy, temp->data);
			temp = temp->next;
		}

		int data;
		
		for (temp = s1_copy; temp!= NULL; )
		{
			data = temp->data;
			temp = temp->next;
			if (is_element(s2[i],data) == 1)
				intersect = add_elements(intersect, data);
		}
		
	}
	return intersect;	
	}
	
  int is_subset(struct node* s1[],struct node* s2[])
{
	
	struct node* temp[size];
	for(int i=0;i<size;i++)
	{
    	temp[i]=s1[i];
    	while(temp[i]!=NULL)
    	{
        	if(is_element(s2[(temp[i]->data)%size],temp[i]->data)!= 1)
			return 0;
			 
        	temp[i] = temp[i]->next;
    	}
	}
	return 1;
}


int main()
{
	int choice,x,y,i;
	
	struct node* set1[size];
	struct node* set2[size];
	
	create_index_array(set1);
	create_index_array(set2);
	
	printf("enter the number of elements you want to enter in array a \n");
	scanf("%d",&x);
	
	int a[x];
	for(i=0;i<x;i++)
	{
		printf("enter the elements==> \n");
		scanf("%d",&a[i]);
	}
	
	build(a,set1,x);
	
	printf("enter the number of elements you want to enter in array b \n");
	scanf("%d",&y);
	
	int b[y];
	for(i=0;i<y;i++)
	{
		printf("enter the elements==> \n");
		scanf("%d",&b[i]);
	}
	
	build(b,set2,y);

	cout<<"Set 1 ==> \n \n";
  	enumerate_map(set1);
	
	cout<<"Set 2 ==> \n \n";
	enumerate_map(set2);
	
	
	cout<<"union of the sets \n \n";
	struct node* union_of_elements = union_(set1,set2);
	enumerate_list(union_of_elements);
	
	cout<<"difference of the sets \n \n";
	struct node* diff = difference(set1,set2);
	enumerate_list(diff);
	
	cout<<"Intersection of sets \n \n";
	struct node* intersect = intersection_of_sets(set1,set2);
	enumerate_list(intersect);
	
	if(is_subset(set1,set2)){
		cout<<"set 1 is subset of set 2 \n \n";
	}
	
	else{
		cout<<"not a subset \n \n";
	}
	
}
