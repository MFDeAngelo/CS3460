#include "distributions.hpp"

#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins)
{
    std::vector<DistributionPair> results;
    int binSize = (max - min + 1) / numberBins;
    for (unsigned int i = min; i < max; i += binSize)
    {
        DistributionPair pair(i, i + binSize - 1);
        results.push_back(pair);
    }

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution dist(min, max);

    for (unsigned int i = 0; i < howMany; i++)
    {
        results[dist(engine) / binSize].count++;
    }

    return results;
}

std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins)
{
    int max, min;
    max = static_cast<int>(mean + 4 * stdev);
    min = static_cast<int>(mean - 4 * stdev);

    std::vector<DistributionPair> results;
    int binSize = (max - min + 1) / numberBins;
    for (int i = min; i < max; i += binSize)
    {
        DistributionPair pair(i, i + binSize - 1);
        results.push_back(pair);
    }

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::normal_distribution normalDist(mean, stdev);

    for (unsigned int i = 0; i < howMany; i++)
    {
        int index = static_cast<int>(normalDist(engine)) - min;
        if (index >= results.size())
            index = static_cast<int>(results.size()) - 1;
        if (index < 0)
            index = 0;
        results[index].count++;
    }

    return results;
}

std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins)
{
    std::vector<DistributionPair> results;
    for (unsigned int i = 0; i < numberBins; i++)
    {
        DistributionPair pair(i, i);
        results.push_back(pair);
    }

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::poisson_distribution poisson(howOften);

    for (unsigned int i = 0; i < howMany; i++)
    {
        int index = static_cast<int>(poisson(engine));
        if (index >= 0 && index < results.size())
            results[index].count++;
    }

    return results;
}

void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize)
{
    unsigned int max = 0;
    for (int i = 0; i < distribution.size(); i++)
    {
        if (distribution[i].count > max)
        {
            max = distribution[i].count;
        }
    }

    std::cout << title << std::endl;
    for (unsigned int i = 0; i < distribution.size(); i++)
    {
        std::cout << "[" << std::setw(3) << std::right << distribution[i].minValue << "," << std::setw(3) << std::right << distribution[i].maxValue << "] : " << std::string(distribution[i].count * maxPlotLineSize / max, '*') << std::endl;
    }
    std::cout << std::endl;
}