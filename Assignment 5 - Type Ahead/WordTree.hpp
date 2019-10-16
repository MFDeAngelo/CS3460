#include <array>
#include <iostream>
#include <memory>
#include <vector>

class WordTree
{

  public:
    WordTree();
    void add(std::string word);
    bool find(std::string word);
    std::size_t size();
    std::vector<std::string> predict(std::string partial, std::uint8_t howMany);

  private:
    class Node
    {
      public:
        std::array<std::shared_ptr<Node>, 26> children;
        bool endOfWord;
        Node() :
            endOfWord(false)
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    class WordPtrPair
    {
      public:
        std::string word;
        std::shared_ptr<Node> ptr;
        WordPtrPair(std::string word, std::shared_ptr<Node> ptr) :
            word(word),
            ptr(ptr) {}
        WordPtrPair(const WordPtrPair& original) :
            word(original.word),
            ptr(original.ptr) {}
    };

    std::shared_ptr<Node> root;
    void add(std::string word, std::shared_ptr<Node> ptr);
    bool find(std::string word, std::shared_ptr<Node> ptr);
    std::size_t size(std::shared_ptr<Node> ptr);
};