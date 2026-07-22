/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // ==========================
    // SERIALIZE
    // ==========================
    // Tree ko String mein convert karna

    void dfs(TreeNode* root, string &s){

        // Agar node NULL hai to "N" store karo aur return kar do
        if(root == NULL){
            s += "N,";
            return;
        }

        // Current node ki value store karo
        s += to_string(root->val) + ",";

        // Left subtree serialize karo
        dfs(root->left, s);

        // Right subtree serialize karo
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {

        // Final serialized string
        string s = "";

        // Preorder traversal se tree ko string mein convert karo
        dfs(root, s);

        return s;
    }

    // ==========================
    // DESERIALIZE
    // ==========================

    TreeNode* build(vector<string> &v, int &i){

        // Agar current value "N" hai to yahan koi node nahi hai
        if(v[i] == "N"){
            i++;                    // Agli value ke liye index badhao
            return NULL;            // NULL return karo
        }

        // Current value se node banao
        TreeNode* root = new TreeNode(stoi(v[i]));

        // Node ban gaya, next value ke liye index badhao
        i++;

        // Left subtree recursively banao
        root->left = build(v, i);

        // Right subtree recursively banao
        root->right = build(v, i);

        // Current subtree complete
        return root;
    }

    TreeNode* deserialize(string data) {

        // Serialized string ko values mein todne ke liye vector
        vector<string> v;

        // Ek temporary string
        string temp = "";

        // String ke har character ko traverse karo
        for(char c : data){

            // Comma mila matlab ek value complete ho gayi
            if(c == ','){

                // Empty string ko vector mein mat daalo
                if(!temp.empty())
                    v.push_back(temp);

                // Next value ke liye temp empty karo
                temp = "";
            }
            else{

                // Character current value mein add karo
                temp += c;
            }
        }

        // Vector ko start se read karne ke liye index
        int i = 0;

        // Recursive function se original tree banao
        return build(v, i);
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec ser, deser;
 * TreeNode* ans = deser.deserialize(ser.serialize(root));
 */