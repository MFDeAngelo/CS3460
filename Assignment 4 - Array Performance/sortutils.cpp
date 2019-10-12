#include "sortutils.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <vector>

void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[])
{
    for (unsigned int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        dest[i] = source[i];
    }
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data)
{
    for (unsigned int i = 0; i < HOW_MANY_ELEMENTS / 2; i++)
    {
        data[HOW_MANY_ELEMENTS - 1 - i] = data[i];
    }
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::microseconds time1(0);
    int rawArray[HOW_MANY_ELEMENTS];
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(random, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time2(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(sorted, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time2 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time3(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(reversed, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time3 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time4(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(organPipe, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time4 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time5(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(rotated, rawArray);
        auto start = std::chrono::steady_clock::now();
        std::sort(rawArray, rawArray + HOW_MANY_ELEMENTS);
        auto end = std::chrono::steady_clock::now();
        time5 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::cout << "---Raw Array Performance---" << std::endl;
    std::cout << "Random Time     : " << time1.count() / 1000 << " ms" << std::endl;
    std::cout << "Sorted Time     : " << time2.count() / 1000 << " ms" << std::endl;
    std::cout << "Reversed Time   : " << time3.count() / 1000 << " ms" << std::endl;
    std::cout << "Organ Pipe Time : " << time4.count() / 1000 << " ms" << std::endl;
    std::cout << "Rotated Time    : " << time5.count() / 1000 << " ms\n"
              << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::microseconds time1(0);
    SourceArray array = random;
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        array = random;
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time2(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        array = sorted;
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time2 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time3(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        array = reversed;
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time3 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time4(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        array = organPipe;
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time4 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time5(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        array = rotated;
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time5 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::cout << "---std::array Performance---" << std::endl;
    std::cout << "Random Time     : " << time1.count() / 1000 << " ms" << std::endl;
    std::cout << "Sorted Time     : " << time2.count() / 1000 << " ms" << std::endl;
    std::cout << "Reversed Time   : " << time3.count() / 1000 << " ms" << std::endl;
    std::cout << "Organ Pipe Time : " << time4.count() / 1000 << " ms" << std::endl;
    std::cout << "Rotated Time    : " << time5.count() / 1000 << " ms\n"
              << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::microseconds time1(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> array(random.begin(), random.end());
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time2(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> array(sorted.begin(), sorted.end());
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time2 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time3(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> array(reversed.begin(), reversed.end());
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time3 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time4(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> array(organPipe.begin(), organPipe.end());
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time4 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::chrono::microseconds time5(0);
    for (unsigned int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> array(rotated.begin(), rotated.end());
        auto start = std::chrono::steady_clock::now();
        std::sort(array.begin(), array.end());
        auto end = std::chrono::steady_clock::now();
        time5 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::cout << "---std::vector Performance---" << std::endl;
    std::cout << "Random Time     : " << time1.count() / 1000 << " ms" << std::endl;
    std::cout << "Sorted Time     : " << time2.count() / 1000 << " ms" << std::endl;
    std::cout << "Reversed Time   : " << time3.count() / 1000 << " ms" << std::endl;
    std::cout << "Organ Pipe Time : " << time4.count() / 1000 << " ms" << std::endl;
    std::cout << "Rotated Time    : " << time5.count() / 1000 << " ms\n"
              << std::endl;
}
