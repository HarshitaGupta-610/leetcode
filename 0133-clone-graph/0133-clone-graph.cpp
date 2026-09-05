/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
  //Traverse the graph and maintain a map of original node → cloned node so that every original node is cloned only once.
   /*1. Map banao
2. Starting node ka clone banao
3. Original node ko queue mein daalo
4. Node nikalo
5. Uske neighbours dekho
6. Clone nahi hai → clone banao
7. New node ko queue mein daalo
8. Clone-to-clone connection banao
9. Repeat
10. Starting node ka clone return karo*/     

if(node == NULL) return NULL;
unordered_map<Node* , Node*>m;
queue<Node*>q;
m[node] = new Node(node ->val);// // Starting node ka clone banao
q.push(node);// Original starting node ko queue mein daalo
while(!q.empty()){
    //Queue se current original node nikalo
    Node* curr = q .front();
    q.pop();
    //current ke neighbours
    for(Node* neighbour : curr -> neighbors){
        if(m.find(neighbour) == m.end()){
            m[neighbour] = new Node(neighbour -> val);
            q.push(neighbour);
        }
        m[curr] -> neighbors.push_back(m[neighbour]);
    }
}
return m[node];
    }
};