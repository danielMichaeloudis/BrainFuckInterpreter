#include <string>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        throw "Invalid Arguments";
    };
    std::string file = argv[1];
    unsigned char *bfMem[3000];
    return 0;
}