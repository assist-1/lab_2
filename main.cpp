#include <iostream>
#include "solve.h"

int main (int argc, char **argv)
{
    bool nf=false, r=false; int c=0;
    if (argc == 1)
    {
        std::cerr << "\nNothing was read.\n";
        return EXIT_FAILURE;
    }
    for (int i=1; i<argc; ++i)
    {
        if (comp(argv[i],"--file")) {nf=true;}
        else if (comp(argv[i],"--forward")) {++c;}
        else if (comp(argv[i],"--reverse")) {r=true; ++c;}
        else {std::cerr << "\nWrong key.\n"; return EXIT_FAILURE;}
    }
    if (c==0)
    {
        std::cerr << "\nKey \'--forward\' or \'--reverse\' is not found.\n";
        return EXIT_FAILURE;
    }
    if (c==2)
    {
        std::cerr << "\nThere must be only one key \'--forward\' or \'--reverse\'.\n";
        return EXIT_FAILURE;
    }
    
    if (r) RevPolNot(nf);
    else ForNot(nf);
    return EXIT_SUCCESS;
}