#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream story;
    story.open("story.txt");

    std::stringstream ws;

    std::string sentence;
    std::string word;

    std::map<std::string, std::vector<int>> dictionary;

    int position = 1;

    while (std::getline(story, sentence, '\n'))
    {
        if (sentence == "")
            ++position;
        ws.str(sentence);
        while (ws >> word)
        {
            dictionary[word].push_back(position);
            position += 2;
        }
        --position;
        ws.clear();
    }

    for (const auto &[entry, positions] : dictionary)
    {
        std::cout << "Rijec je " << entry << " i nalazi se na sljedecim pozicijama:\n";
        for (int position : positions)
        {
            std::cout << position << " ";
        }
        std::cout << std::endl;
    }
}