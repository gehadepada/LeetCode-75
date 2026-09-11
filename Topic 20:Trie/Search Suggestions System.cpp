class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    vector<vector<string>> strs = vector<vector<string>>(26);
    TrieNode() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    void insert(string word, TrieNode* root) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node->strs[index].push_back(word);
            node = node->children[index];
        }
        node->endOfWord = true;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        TrieNode* root = new TrieNode();
        for (auto x : products) {
            root->insert(x, root);
        }
        vector<vector<string>> res;
        vector<string> v;
        for (auto x : searchWord) {
            if(root){
            v = root->strs[x - 'a'];
            sort(v.begin(), v.end());
            res.push_back(
                vector<string>(v.begin(), v.begin() + min(3, (int)v.size())));
            root = root->children[x-'a'];
            }
            else{
                res.push_back(v);
            }
        }
        return res;
    }
};