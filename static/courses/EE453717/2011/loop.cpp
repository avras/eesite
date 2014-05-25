#include <iostream>

using namespace std;

struct node
{
    node* next;
};

void detectLoop(node* head);

int main()
{
    int numNodes, x, y;
    cin >> numNodes;
    node* nodeList = new node[numNodes];
    for (int i = 0; i < numNodes; i++)
    {
        cin >> x;
        cin >> y;
        if(y == 0)
            nodeList[x-1].next = NULL;
        else
            nodeList[x-1].next = &nodeList[y-1];
    }

    detectLoop(&nodeList[0]);

    delete[] nodeList;
    return 0;
}

void detectLoop(node* head)
{
}
