#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for Huffman Tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char ch, int freq, Node *left = nullptr, Node *right = nullptr)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};
void buildtree(Node *root, string s, unordered_map<char, string> &huffman)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        huffman[root->ch] = s;
    buildtree(root->left, s + '0', huffman);
    buildtree(root->right, s + '1', huffman);
}
unordered_map<char, string> huffmanEncoding(string &text)
{
    unordered_map<char, int> freq;
    for (char it : text)
    {
        freq[it]++;
    }
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto it : freq)
    {
        pq.push(new Node(it.first, it.second));
    }
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }
    Node *root = pq.top();
    unordered_map<char, string> huffman;
    buildtree(root, "", huffman);
    return huffman;
}

int main()
{
    string text = "aaabbc";
    unordered_map<char, string> huffmanCode = huffmanEncoding(text);

    cout << "Huffman Codes:\n";
    for (auto &pair : huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    cout << "\nEncoded Text: ";
    for (char ch : text)
        cout << huffmanCode[ch];
    cout << endl;
    return 0;
}
