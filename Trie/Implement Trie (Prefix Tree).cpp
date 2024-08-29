class Node{
    public : 
    Node * child[26];
    bool flag;
    Node(){
        flag=false;
        for(auto &a : child) a=nullptr;
    }
};

class Trie {
    Node * root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * temp=root;
        for(auto ch : word){
            if(temp->child[ch-'a']==nullptr){
                 temp->child[ch-'a']=new Node();
            }
            temp=temp->child[ch-'a'];
           
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node * temp=root;
        for(auto ch : word){
            if(temp->child[ch-'a']==nullptr){
                return false;
            }
            temp=temp->child[ch-'a'];
           
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node * temp=root;
        for(auto ch : prefix){
            if(temp->child[ch-'a']==nullptr){
                 return false;
            }
            temp=temp->child[ch-'a'];
           
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */