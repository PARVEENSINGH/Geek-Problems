#include <iostream>
#include<fstream>
using namespace std;
typedef long long ll;

class BST{
    private:
        int data;
        BST *left,*right;
    public:
        BST()
        {
           data=0;
           left=NULL;
           right=NULL;  
        }

        BST(int value)
        {
           data=value;
           left=NULL;
           right=NULL; 
        } 

        BST* insert(BST* ,int );
        void PrintBST(BST*,ofstream &op_file);
};

// BST::BST() : data(0),left(NULL),right(NULL)
// {
// }

// BST::BST(int value) : data(value),left(NULL),right(NULL)
// {

// }

BST* BST::insert(BST* root,int value)
{
    if(root==NULL)
       return new BST(value);

    //Inserting to left child if value is less than it's root node
    if(value<root->data) 
        root->left=insert(root->left,value);

    //Inserting to right child if value is less than it's root node
    if(value>root->data)
        root->right=insert(root->right,value);  

    return root;
}

void BST::PrintBST(BST* root,ofstream &op_file)
{
    if(root==NULL)
        return;

    PrintBST(root->left,op_file);

    //Writing node values into output file
    op_file << root->data<<"  ";

    PrintBST(root->right,op_file);

}

int main()
{

    BST* root=NULL;

    //object creartion
    BST obj;

    ifstream ip_file;
    ip_file.open("C:\\Users\\Praveen\\Desktop\\GITHUB\\GEEK_Problems\\Geek_Code\\input1.txt");

    int data;
    if(!ip_file)
    {
        cout<<"unable to opem input file";
        exit(1);
    }
    
    //Reading inout file & inserting into BST
    while(ip_file >> data)
        root=obj.insert(root,data);

     

    ip_file.close();

    //Opening output file to write into it
    ofstream op_file;
    op_file.open("input2.txt");

    if(!op_file)
    {
        cout<<"unable to open output file";
        exit(1);
    }

    obj.PrintBST(root,op_file);

    op_file.close();
}