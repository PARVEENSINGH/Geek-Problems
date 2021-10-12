#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to connect nodes at same level.
    queue<Node*> q;
    void connect(Node *root)
    {
       // Your Code Here
       if(!root)
        return;
       q.push(root);
       int n;
       while(!q.empty()) {
            n= q.size();
            Node* prev = NULL;
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(prev!=NULL)
                    prev->nextRight = temp;
                prev = temp;    
            }
            prev = NULL;
       }
    }    
      
};

 Node* getNextRight(Node* p){
     Node* temp = p->nextRight;
     while(temp!=NULL){
         if(p->left!= NULL)
            return p->left;
         if(p->right!=NULL)
            return p->right;
         temp = temp->nextRight;      
     }
     return NULL;
 }
 void connect(Node *root)
    {
      if(!root)
        return;
      root->nextRight = NULL;
      Node* q = root;
      while(!q){
          Node *p = q;
          while(!p){
              if(p->left){
                  if(p->right)
                    p->left->nextRight = p->right;
                  else
                    p->left->nextRight = getNextRight(p);  
              }
              if(p->right)
                p->right->nextRight = getNextRight(p);
              p = p->nextRight;  
          }
          if(q->left)
            q = q->left;
          else if(q->right)
            q = q->right;
          else
            q = getNextRight(q);    
      }  
       
    }

// Iterative CPP program to connect
// nodes at same level using
// constant extra space
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	node *nextRight;
	
	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};

/* This function returns the leftmost
child of nodes at the same level as p.
This function is used to getNExt right
of p's right child If right child of
is NULL then this can also be used for
the left child */
node *getNextRight(node *p)
{
	node *temp = p->nextRight;

	/* Traverse nodes at p's level
	and find and return the first
	node's first child */
	while (temp != NULL)
	{
		if (temp->left != NULL)
			return temp->left;
		if (temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}

	// If all the nodes at p's level
	// are leaf nodes then return NULL
	return NULL;
}

/* Sets nextRight of all nodes
of a tree with root as p */
void connectRecur(node* p)
{
	node *temp;

	if (!p)
	return;

	// Set nextRight for root
	p->nextRight = NULL;

	// set nextRight of all levels one by one
	while (p != NULL)
	{
		node *q = p;

		/* Connect all childrem nodes of p and
		children nodes of all other nodes at
		same level as p */
		while (q != NULL)
		{
			// Set the nextRight pointer
			// for p's left child
			if (q->left)
			{
				// If q has right child, then
				// right child is nextRight of
				// p and we also need to set
				// nextRight of right child
				if (q->right)
					q->left->nextRight = q->right;
				else
					q->left->nextRight = getNextRight(q);
			}

			if (q->right)
				q->right->nextRight = getNextRight(q);

			// Set nextRight for other
			// nodes in pre order fashion
			q = q->nextRight;
		}

		// start from the first
		// node of next level
		if (p->left)
			p = p->left;
		else if (p->right)
			p = p->right;
		else
			p = getNextRight(p);
	}
}


/* Driver code*/
int main()
{

	/* Constructed binary tree is
			10
			/ \
		8 2
		/	 \
	3	 90
	*/
	node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	root->right->right	 = new node(90);

	// Populates nextRight pointer in all nodes
	connectRecur(root);

	// Let us check the values of nextRight pointers
	cout << "Following are populated nextRight pointers in the tree"
		" (-1 is printed if there is no nextRight) \n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight? root->nextRight->data: -1) <<endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight? root->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight? root->right->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->left->left->data<< " is "
		<< (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->right->data << " is "
		<< (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl;
	return 0;
}

// This code is contributed by rathbhupendra



// // Recursive C program to connect nodes at same level
// // using constant extra space
// void connectRecur(struct node* p);
// struct node *getNextRight(struct node *p);

// // Sets the nextRight of root and calls connectRecur() for other nodes
// void connect (struct node *p)
// {
// 	// Set the nextRight for root
// 	p->nextRight = NULL;

// 	// Set the next right for rest of the nodes (other than root)
// 	connectRecur(p);
// }

// /* Set next right of all descendents of p. This function makes sure that
// nextRight of nodes ar level i is set before level i+1 nodes. */
// void connectRecur(struct node* p)
// {
// 	// Base case
// 	if (!p)
// 	return;

// 	/* Before setting nextRight of left and right children, set nextRight
// 	of children of other nodes at same level (because we can access
// 	children of other nodes using p's nextRight only) */
// 	if (p->nextRight != NULL)
// 	connectRecur(p->nextRight);

// 	/* Set the nextRight pointer for p's left child */
// 	if (p->left)
// 	{
// 	if (p->right)
// 	{
// 		p->left->nextRight = p->right;
// 		p->right->nextRight = getNextRight(p);
// 	}
// 	else
// 		p->left->nextRight = getNextRight(p);

// 	/* Recursively call for next level nodes. Note that we call only
// 	for left child. The call for left child will call for right child */
// 	connectRecur(p->left);
// 	}

// 	/* If left child is NULL then first node of next level will either be
// 	p->right or getNextRight(p) */
// 	else if (p->right)
// 	{
// 		p->right->nextRight = getNextRight(p);
// 		connectRecur(p->right);
// 	}
// 	else
// 	connectRecur(getNextRight(p));
// }

// /* This function returns the leftmost child of nodes at the same level as p.
// This function is used to getNExt right of p's right child
// If right child of p is NULL then this can also be used for the left child */
// struct node *getNextRight(struct node *p)
// {
// 	struct node *temp = p->nextRight;

// 	/* Traverse nodes at p's level and find and return
// 	the first node's first child */
// 	while(temp != NULL)
// 	{
// 		if(temp->left != NULL)
// 			return temp->left;
// 		if(temp->right != NULL)
// 			return temp->right;
// 		temp = temp->nextRight;
// 	}

// 	// If all the nodes at p's level are leaf nodes then return NULL
// 	return NULL;
// }
