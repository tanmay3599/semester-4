 #include<iostream>

using namespace std;

struct node{
	int  data;
	struct node* left;
	struct node* right;
}*root;



		struct node *new_Node(int data)
		{	 
			struct node *temp;
			temp=new(struct node);
			temp->data=data;
			temp->left=NULL;
			temp->right=NULL;
			return temp;
    	}
	
	void inorder(struct node *root)
	{
		if(root!=NULL)
		{
			inorder(root->left);
			cout<<root->data<<endl;
			inorder(root->right);
		}
	}
	
	struct node* insert(struct node* node,int data)
	{
		if(node==NULL)
		return new_Node(data);
		
		if(node->data>data)
		node->left=insert(node->left,data);
		
		else if(node->data<data)
		node->right=insert(node->right,data);
		
		return node;
	}
	


int check_exactly_identical(struct node* temp1,struct node* temp2)
	{
				
		if(temp1==NULL && temp2==NULL)
		return 1;
		else
		{
		
		if(temp1!=NULL && temp2!=NULL)
		{
			return((temp1->data == temp2->data) && check_exactly_identical(temp1->left,temp2->left) && check_exactly_identical(temp1->right,temp2->right));	
		}
	}
		return 0;
	}

int check_structural_identical(struct node* temp1,struct node* temp2)
	{
				
		if(temp1==NULL && temp2==NULL)
		return 1;
		else
		{
		
		if(temp1!=NULL && temp2!=NULL)
		{
			return(check_structural_identical(temp1->left,temp2->left) && check_structural_identical
			(temp1->right,temp2->right));	
		}
	}
		return 0;
	}

struct node* mirror(struct node* node)  
{ 
  if (node==NULL)  
    return 0;   
  else 
  { 
    struct node* temp; 
    
    mirror(node->left); 
    mirror(node->right); 
  
    temp        = node->left; 
    node->left  = node->right; 
    node->right = temp; 
  } 
  
  return node;
}  
  
  
 int check_mirror(struct node* r1,struct node *r2)
 {
 	if((r1 == NULL) && (r2==NULL))
 		return 1;
 		
 	else if((r1 != NULL) && (r2==NULL) || (r1 == NULL) && (r2!=NULL)) 	
 		return 1;
 		
 	else
	{
	 	return((r1->data == r2->data) && check_mirror(r1->left,r2->right) && check_mirror(r1->right,r2->left)) ;
	}
  } 

int check_bst(struct node* node)
{
	if(root!=NULL)
	{
		check_bst(node->left);
		check_bst(node->right);
		if(node->left->data < node->right->data)
		{
			return 0;
		}
}

}
int main()
{
    
    struct node *root1 = NULL; 
   	root1 = insert(root1,50); 
    insert(root1, 30); 
    insert(root1, 20); 
    insert(root1, 40); 
    insert(root1, 70); 
    insert(root1, 60); 
    insert(root1, 80); 

   
    inorder(root1); 
   
   cout<<"\n";
   
   
   struct node *root2 = NULL; 
   	root2 = insert(root2,50); 
    insert(root2, 30); 
    insert(root2, 20); 
    insert(root2, 40); 
    insert(root2, 70); 
    insert(root2, 60); 
    insert(root2, 80); 
   	insert(root2, 10); 
   	
   	inorder(root2);
   	
     cout<<"checking indentical \n \n";
    
	 if(check_exactly_identical(root1,root2))
	 {
	 	cout<<"is exactly identical \n \n"; 
	 }
	 
	 else
	 {
	 cout<<"not exactly identical \n \n";
	}
		
		
	cout<<"checking structural \n \n";	
		
	 if(check_structural_identical(root1,root2))
	 {
	 	cout<<"is structural identical\n"; 
	 }
	 
	 else
	 {
	 cout<<"not structural identical\n";
	}	
	
	struct node* mirror_image = mirror(root1);
	inorder(mirror_image);
	
/*	cout<<"checking whether the given lists are  mirror images or not \n \n";
	 
	 if(check_mirror(mirror_image,root1))
	 {
	 	cout<<"is mirror image \n \n"; 
	 }
	
	 else
	 {
	 cout<<"not a mirror image \n \n";
	}	*/
	
	if(check_bst(root1))
	 {
	 	cout<<"is mirror image \n \n"; 
	 }
	
	 else
	 {
	 cout<<"not a mirror image \n \n";
	}	
	
	return 0;
}
