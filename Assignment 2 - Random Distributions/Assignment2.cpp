#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

class DistributionPair
{
  public:
    DistributionPair(std::uint32_t minValue, std::uint32_t maxValue) :
        minValue(minValue),
        maxValue(maxValue),
        count(0)
    {
    }

    std::uint32_t minValue;
    std::uint32_t maxValue;
    std::uint32_t count;
};

std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins);
std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins);
std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins);
void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize);

int main()
{
    auto uniform = generateUniformDistribution(100000, 0, 79, 40);
    plotDistribution("--- Uniform ---", uniform, 80);
    auto normal = generateNormalDistribution(100000, 50, 5, 40);
    plotDistribution("--- Normal ---", normal, 80);
    auto poisson = generatePoissonDistribution(100000, 6, 40);
    plotDistribution("--- Poisson ---", poisson, 80);

    return 0;
}

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
        if (index >= 0 && index < results.size())
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