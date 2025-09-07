#include <string>
#include <iostream>
#include <fstream>
#include <vector>

const int MEM_SIZE = 30000;

void interpretLoop(std::ifstream *CodeFile)
{
    unsigned char *bfMem[MEM_SIZE];
    int bfMemPtr = 0;
    char nextCmd;
    std::vector<int> loops;
    while (CodeFile->get(nextCmd))
    {
        std::cout << "char: " << nextCmd << "\n";
        switch (nextCmd)
        {
        case '>':
            bfMemPtr++;
            if (bfMemPtr >= MEM_SIZE)
                bfMemPtr = 0;
            break;
        case '<':
            bfMemPtr--;
            if (bfMemPtr < 0)
                bfMemPtr = MEM_SIZE - 1;
            break;
        case '+':
            bfMem[bfMemPtr]++;
            break;
        case '-':
            bfMem[bfMemPtr]--;
            break;
        case '.':
            std::cout << (int)bfMem[bfMemPtr];
            break;
        case ',':
            std::cin >> bfMem[bfMemPtr];
        };
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        throw "Invalid Arguments";
    };
    std::string filePath = argv[1];
    std::ifstream CodeFile(filePath);
    interpretLoop(&CodeFile);
    return 0;
}