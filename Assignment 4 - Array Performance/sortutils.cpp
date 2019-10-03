#include "sortutils.hpp"

#include <chrono>
#include <iostream>

#include <array>

void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[])
{
    for (int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        dest[i] = source[i];
    }
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data)
{
    for (int i = 0; i < HOW_MANY_ELEMENTS / 2; i++)
    {
        data[HOW_MANY_ELEMENTS - 1 - i] = data[i];
    }
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{	
	std::chrono::microseconds time(0);
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        int rawArray[HOW_MANY_ELEMENTS];
        initializeRawArrayFromStdArray(random, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	}
    std::cout << time.count() << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}
