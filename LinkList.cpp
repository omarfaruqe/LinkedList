#include<iostream>
using namespace std;

/* a singly-linked list contains two values: 1. the value of the current node 2.link to the next node

struct Node
{
    int data;
    Node* pnext;
};

*/

class Node {
    Node* pnext;
public:
    int data;

    // Constructor taking initial value:
    Node( int value = 0 ): pnext( NULL ), data( value )
    {
    }

    // Copy constructor:
    Node( Node const& other )
        : pnext( NULL ), data( other.data )
    {
    }


    // Reverse recursive way
	Node* recursive_reverse(Node* head)
	{
	    Node* result;
	    if(!(head && head->pnext)) 
	        return head;
	 
	    result = recursive_reverse(head->pnext);
	    head->pnext->pnext = head;
	    head->pnext = NULL;
	 
	    return result;
	}

	// Reverse non recursive way
	Node * non_recursive_reverse( Node * ptr )
	{
		Node * temp;
	    Node * previous = NULL;
	    while(ptr != NULL) {
	        temp = ptr->pnext;
	        ptr->pnext = previous;
	        previous = ptr;
	        ptr = temp;
	    }
	    return previous;
	}



    friend void print_list( Node const& head );
    friend void printList(Node* head);


    // Insert new node in front:
    void insert( Node* newNode )
    {
        newNode->pnext = pnext;
        pnext = newNode;
    }


    // Remove node in front:
    void remove_next()
    {
        if ( pnext == NULL ) return;
        Node* obsolete = pnext;
        this->pnext = obsolete->pnext;
        // Make node "single":
        obsolete->pnext = NULL;
    }

    // Calculate number of nodes in the list:
    size_t size() const
    {
        return distance( NULL );
    }

    // Measure distance to other node:
    int distance( Node const* other ) const
    {
        int hops = 1;
        Node const* iter = pnext;
        while ( iter != other ) {
            if ( iter == NULL )
                return hops - 1;
            iter = iter->pnext;
            ++hops;
        }
        return hops;
    }
};

// Print contents of the list:
void print_list( Node const& head )
{
    //cout << '[' << head.size() << "] ";  //size of list
    Node const* iter = &head;
    do {
        cout << iter->data << ' ';
        iter = iter->pnext;

    } while ( iter != NULL );
    cout << '\n';
}

// void printList(Node* head)
// {
//     while(head != NULL) {
//         std::cout<<head->data<<" ";
//         head = head->pnext;
//     }
// }

int main(){

	Node A,B,C,D,E,F;

    A.data = 12;
    B.data = 99;
    C.data = 37;

    A.insert( &C );
    A.insert( &B );


	//cout << "List size is: " << A.size()<<"\n";
    cout<<"\nRecursive way Reverse Linked List\n";
    print_list(A);
    Node* revlist = A.recursive_reverse(&A);
	print_list(*revlist);
    

    //Non recursive
    cout<<"\nNon recursive way Reverse Linked List\n";
    D.data = 112;
    E.data = 919;
    F.data = 317;

    D.insert( &E );
    D.insert( &F );
    print_list(D);
    Node* revlist1 = D.non_recursive_reverse(&D);
    print_list(*revlist1);

    //Remove
    //A.remove_next();

    //cout << "List size is: " << A.size()<<"\n";
    

	return 0;
}