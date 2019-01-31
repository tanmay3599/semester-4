#include<stdio.h>
#include<stdlib.h>

 struct node
{
	struct node* link;
	int data;
};


void enumerate(struct node *head)
{
	printf("your list is ==>  \n \n"); 
	
	struct node* current=head;
	while(current!=NULL)
	{	
		printf("%d \n",current->data);
		current = current->link;
	}
}

int is_element(struct node* head,int num)
{

	struct node* current = head;	
	while(current!=NULL)
	{
		if(num==current->data)
		{
		printf(" element exists==>%d\n \n",num);
			return 1;
		}
		current=current->link;
	}
	return 0;
}

void is_empty(struct node* head)
{
	struct node* temp=head;
	if(temp!=NULL)
	{
		printf("list is not empty \n \n");
	}
	
	else
	{
		printf("set is empty \n");
	}
}

void size_of_list(struct node* head)
{
	int n=0;
	struct node* current=head;
	while(current!=NULL)
	{	
		n++;
		current = current->link;
	}
	printf("size of the list is==> %d \n",n);

}

struct node* add_element(struct node* head,int n)
{
	if(!is_element(head,n))
	{
	
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  
  temp->data=n;
  temp->link=NULL;
  // for 1st element
  if(head==NULL)
  {
  	head=temp;
  }
  // for rest of the elements
  else
  {
  	       struct node* current = head;
  	       
  	       // traversing till last node
           while(current->link != NULL)
            {
               current=current->link;
            }
            current->link = temp;
  }
  
 }

 return head;
 
}


struct node * remove_element(struct node *head, int n)     
{
	struct node *current= head;
	struct node *prev;
	
	// checking and removing first element
	
	if(current!=NULL && current -> data == n)
	{
		head = head->link;  
		free(current);
		return head;
	}
	
	//removing other elements
	
	if(is_element(current,n)==1)
	{
			
		while(current !=NULL && current->data!=n)
		{
			prev = current;
			current=current->link;	
		}
		if(current==NULL)
			return head;	
		prev -> link = current -> link;
		free(current);
	}
	return head;
}

struct node* build(int a[],int n)
{
	int i;
	struct node* head = NULL; 
	
	// passing array into list
	
	for(i=0;i<n;i++)
	{
		head=add_element(head,a[i]);
	}
	return head;
}

struct node* union_of_set(struct node* s1,struct node* s2)
{
		struct node * s2_copy = s2; 
	
		struct node * temp = NULL; 
		// s1_copy created 

			while (s2_copy != NULL)
		{
			temp = add_element(temp, s2_copy->data);
			s2_copy = s2_copy->link;
		}

		int data;
		//temp variable will used if loop
		for (s2_copy = s1; s2_copy!= NULL; )
		{
			data = s2_copy->data;
			s2_copy = s2_copy->link;
			if (is_element(s2,data) != 1)
				temp = add_element(temp,data); // adding elements which are not present at set1
	}
		
		return temp;	
    
}

	struct node * difference(struct node* s1, struct node* s2)
	{
		struct node * s1_copy = NULL;
		struct node * temp = s1; 
		// s1_copy created 
		while (temp != NULL)
		{
			s1_copy = add_element(s1_copy, temp->data);
			temp = temp->link;
		}

		int data;
		//temp variable will used if loop
		for (temp = s1_copy; temp!= NULL; )
		{
			data = temp->data;
			temp = temp->link;
			if (is_element(s2,data) == 1)
				s1_copy = remove_element(s1_copy, data); // removing elements which are not present at set2
		}
		return s1_copy;	
	} 
	
	struct node* intersection_of_sets(struct node* s1,struct node* s2)
	{
	 struct node* temp = difference(s1,s2);
     temp = difference(s1,temp);
     return temp;
	}

  int is_subset(struct node* s1,struct node* s2)
{
    struct node* temp;
    temp=s1;
    	while(temp!=NULL)
    	{
        	if(is_element(temp->data,s2)!= 1)
			return 0;
			 
        	temp = temp->link;
    	}
    return 1;
}
	

int main()
{
	int choice,x,y,i;
	
	
	struct node* set_1 = NULL;
	struct node* set_2 = NULL;
	
	printf("enter the number of elements you want to enter in array a \n");
	scanf("%d",&x);
	
	int a[x];
	for(i=0;i<x;i++)
	{
		printf("enter the elements==> \n");
		scanf("%d",&a[i]);
	}
	
	set_1=build(a,x);
	
	
	printf("enter the number of elements you want to enter in array b \n");
	scanf("%d",&y);
	
	int b[y];
	for(i=0;i<y;i++)
	{
		printf("enter the elements==> \n");
		scanf("%d",&b[i]);
	}
	
	set_2=build(b,y);

  	enumerate(set_1);
	
	enumerate(set_2);
	
    struct node* union_of_sets = union_of_set(set_1,set_2);
    printf("your union of set is \n");
   	enumerate(union_of_sets);


    struct node * diff_set = difference (set_1, set_2);
    printf("your difference of set is \n");
    enumerate(diff_set);
	
	printf("your intersection of set is \n");
	struct node* intersection = intersection_of_sets(set_1,set_2); 
	enumerate(intersection);

}
