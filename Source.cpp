#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node
{
	int i;
		Node* pLeft;
		Node* pRight;

		Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr){}
};
void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}
void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}
bool Findingtheway(Node* pRoot, int j)
{
	
	if (j == 0) {
		return true;
	}

	
	if (pRoot == nullptr) {
		return false;
	}
	bool left = Findingtheway(pRoot->pLeft, j- pRoot->i);
	bool right = Findingtheway(pRoot->pRight, j - pRoot->i);
	if (left || right) {
		cout << pRoot->i << " ";
	}

	return left || right;
}
int TotalSum(Node* pRoot)
{
	
	if (pRoot == nullptr) {
		return 0;
	}

	int left = TotalSum(pRoot->pLeft);

	int right = TotalSum(pRoot->pRight);
	
	return (left > right ? left : right) + pRoot->i;
}


void Answer(Node* pRoot)
{
	int sum = TotalSum(pRoot);
	cout << "Largest Branch is= " << sum << endl;
}

void main()
	{
		Node* pRoot = nullptr;
		/* Question tree

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
		*/

		pRoot = new Node(5);
		pRoot->pLeft = new Node(4);
		pRoot->pRight = new Node(8);
		pRoot->pLeft->pLeft = new Node(11);
		pRoot->pRight->pLeft = new Node(13);
		pRoot->pRight->pRight = new Node(4);
		pRoot->pLeft->pLeft->pLeft = new Node(7);
		pRoot->pLeft->pLeft->pRight = new Node(2);
		pRoot->pRight->pRight->pRight = new Node(1);


		Answer(pRoot);

		
}