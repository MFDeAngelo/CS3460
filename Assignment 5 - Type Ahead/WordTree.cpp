#include "WordTree.hpp"

#include <memory>
#include <queue>
#include <vector>

WordTree::WordTree() :
    root(std::make_shared<Node>()) {}

void WordTree::add(std::string word)
{
    if (word == "")
        return;
    this->add(word, this->root);
}

void WordTree::add(std::string word, std::shared_ptr<Node> ptr)
{
    if (word.length() == 0)
    {
        ptr->endOfWord = true;
        return;
    }

    int i = word[0] - 97;

    if (ptr->children[i] == nullptr)
    {
        ptr->children[i] = std::make_shared<Node>();
    }

    add(word.substr(1, word.length() - 1), ptr->children[i]);
}

bool WordTree::find(std::string word)
{
    return this->find(word, this->root);
}

bool WordTree::find(std::string word, std::shared_ptr<Node> ptr)
{
    if (word.length() == 0)
    {
        return ptr->endOfWord;
    }

    int i = word[0] - 97;

    if (ptr->children[i] == nullptr)
    {
        return false;
    }

    return find(word.substr(1, word.length() - 1), ptr->children[i]);
}

std::size_t WordTree::size()
{
    return size(root);
}

std::size_t WordTree::size(std::shared_ptr<Node> ptr)
{
    if (ptr == nullptr)
        return 0;
    std::size_t sum = 0;
    if (ptr->endOfWord)
        sum++;

    for (int i = 0; i < 26; i++)
    {
        sum += size(ptr->children[i]);
    }
    return sum;
}

std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    std::vector<std::string> result = {};
    if (partial == "")
    {
        return result;
    }

    std::shared_ptr<Node> ptr = root;
    std::uint8_t i = 0;

    while (ptr != nullptr)
    {
        std::uint8_t index = partial[i] - 97;
        ptr = ptr->children[index];
        if (ptr == nullptr)
        {
            std::vector<std::string> emptyVector = {};
            return emptyVector;
        }
        i++;
        if (i == partial.length())
        {
            std::queue<WordPtrPair> queue;
            for (int j = 0; j < 26; j++)
            {
                if (ptr->children[j] != nullptr)
                {
                    WordPtrPair temp(partial + static_cast<char>(j + 97), ptr->children[j]);
                    queue.push(temp);
                }
            }
            while (queue.size() > 0 && howMany != result.size())
            {

                WordPtrPair pair = queue.front();
                queue.pop();
                if (pair.ptr->endOfWord)
                    result.push_back(pair.word);

                for (int j = 0; j < 26; j++)
                {
                    if (pair.ptr->children[j] != nullptr)
                    {
                        WordPtrPair temp(pair.word + static_cast<char>(j + 97), pair.ptr->children[j]);
                        queue.push(temp);
                    }
                }
            }
            return result;
        }
    }
    return result;
}
