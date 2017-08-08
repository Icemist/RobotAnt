#ifndef LEG_H
#define LEG_H

#include <vector>
#include <stdexcept>
#include "pca9685.hpp"
#include "Segment.h"

enum SEGMENT_NAME {
	Coxa = 0,
	Trochanter,
	Femur,
	Tabia,
	Tarsus,
};

class Leg {
public:


    Leg(upm::PCA9685& controller, std::vector<int>& channels)
    : controller(controller)
    {
        if (channels.size() != COUNT_SEGMENTS){
            throw std::invalid_argument(std::string(__FUNCTION__) +
                                  ": Leg() failed. Invalid channels count.");
            return;
        }
        for(int i = 0; i < COUNT_SEGMENTS; ++i) {
            segments.push_back(new Segment(controller, channels[i]));
        }
    }
    
    ~Leg() {
        for(int i = 0; i < COUNT_SEGMENTS; ++i) {
            delete segments[i];
        }
    }
    
    void action(SEGMENT_NAME segment, int angle, int speed) {
        segments[segment]->action(angle, speed);
    }
public:
	static const int COUNT_SEGMENTS = 5;
private:
    upm::PCA9685& controller;
    std::vector<Segment*> segments;
    
};

#endif // LEG_H