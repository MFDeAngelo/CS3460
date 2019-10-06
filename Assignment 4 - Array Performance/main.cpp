#include "sortutils.hpp"

#include <algorithm>
#include <iostream>
#include <random>

int main()
{

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution dist(-10'000'000, 10'000'000);

    SourceArray randomArray = {};
    for (unsigned int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        randomArray[i] = dist(engine);
    }

    SourceArray sortedArray = randomArray;
    std::sort(sortedArray.begin(), sortedArray.end());

    SourceArray reversedArray = sortedArray;
    std::reverse(reversedArray.begin(), reversedArray.end());

    SourceArray organPipeArray = sortedArray;
    organPipeStdArray(organPipeArray);

    SourceArray rotatedArray = sortedArray;
    std::rotate(rotatedArray.begin(), rotatedArray.begin() + 1, rotatedArray.end());

    evaluateRawArray(randomArray, sortedArray, reversedArray, organPipeArray, rotatedArray);
    evaluateStdArray(randomArray, sortedArray, reversedArray, organPipeArray, rotatedArray);
    evaluateStdVector(randomArray, sortedArray, reversedArray, organPipeArray, rotatedArray);

    return 0;
}
