
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
    node *left;
    node *right;
    double freq;
    string content;
    string code;
};

vector<node> nodeArray;

node Min() {
    double temp;
    vector<node>::iterator i1, pos;
    for(i1 = nodeArray.begin(); i1!=nodeArray.end(); i1++) {
        if(temp > (*i1).freq) {
            pos = i1;
            temp = (*i1).freq;
        }
    }
    node tempNode = (*pos);
    nodeArray.erase(pos);
    return tempNode;
}

node HuffmanTree() {
    while(!nodeArray.empty()) {
        node * tempNode = new node;
        node * tempNode1 = new node;
        node * tempNode2 = new node;
        *tempNode1 = Min();
        *tempNode2 = Min();
        tempNode -> left = tempNode1;
        tempNode -> right = tempNode2;
        tempNode -> freq = tempNode1 -> freq+tempNode2 -> freq;
        nodeArray.push_back(*tempNode);
        if(nodeArray.size() == 1) {
            break;
        }
    }
    return nodeArray[0];
}

void BFS(node * temproot, string str) {
    node * root1 = new node;
    root1 = temproot;
    root1->code = str;
    if(root1 == NULL) {
        
    } else if(root1 -> left == NULL && root1 -> right == NULL){
        cout << root1->content << endl;
        cout << root1->code << endl;
    } else {
        root1 -> left -> code = str.append("0");
        str.erase(str.end()-1);
        root1 -> right -> code = str.append("1");
        str.erase(str.end()-1);
    }
}

void HuffmanCode() {
    int size, i;
    double tempDouble;
    string tempString = "";
    cin >> size;
    for(i=0; i<size; i++) {
        node tempNode;
        cin>>tempString;
        cin>>tempDouble;
        tempNode.freq = tempDouble;
        tempNode.content = tempString;
        tempNode.left = NULL;
        tempNode.right = NULL;
        nodeArray.push_back(tempNode);
    }
    node root = HuffmanTree();
    BFS(&root, "");
}

int main() {
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    vector<int>::iterator i1 = test.begin();
    test.erase(i1);
    
    HuffmanCode();
    return 0;
}
