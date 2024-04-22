#include <iostream>
#include <vector>
#include <fstream>

const int ALPHABET_SIZE = 27;
 
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode *root, std::string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, std::string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndOfWord);
}

std::vector<std::string> readFileIntoVector(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return lines;
}

int main() 
{
    std::vector<std::string> words = readFileIntoVector("/home/superalex0102/Desktop/workspace/c++/hatekony/labor8/wordsEn.txt");

    /*for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }*/

    struct TrieNode *root = getNode();

    for (size_t i = 0; i < words.size(); i++)
    {
        insert(root, words[i]);
    }

    char output[][32] = {"Not present in trie", "Present in trie"};

    std::cout<<"atttila"<<" --- "<<output[search(root, "atttila")]<<std::endl;
}