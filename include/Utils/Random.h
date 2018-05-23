//
// Created by scollon on 5/22/18.
//

#ifndef MINECRAFT_RANDOM_H
#define MINECRAFT_RANDOM_H

#include <random>
#include <cstdint>
#include <ctime>


namespace Random
{

    void    init();
    int64_t intInRange(int64_t low, int64_t high);
    float   floatInRange(float low, float high);

    template<typename Engine>
    class Generator
    {
    	public:
			Generator()
			{
				_randomEngine.seed(std::time(nullptr));
			}

		    int64_t intInRange(int64_t low, int64_t high)
		    {
			    std::uniform_int_distribution<int64_t> dist(low, high);
			    return dist(_randomEngine);
		    }

		    float   floatInRange(float low, float high)
		    {
			    std::uniform_real_distribution<float> dist(low, high);
			    return dist(_randomEngine);
		    }

		    template<typename T>
		    T numberInRange(T low, T high)
		    {
			    std::uniform_real_distribution<T> dist(low, high);
			    return dist(_randomEngine);
		    }
    	private:
    	    Engine _randomEngine;
    };
}

#endif //MINECRAFT_RANDOM_H
