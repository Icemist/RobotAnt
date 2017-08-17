#ifndef ANT_H
#define ANT_H

#include <vector>
#include "pca9685.hpp"
#include "Leg.h"
#include "Segment.h"

enum LEG_NAME {
	RightFront = 0,
	RightMiddle,
	RightBack,
	LeftFront,
	LeftMiddle,
	LeftBack,
};

class Ant
{
public:    
    Ant() {
        rightController = new upm::PCA9685(I2C_BUS, FIRST_I2C_ADDRESS);
        rightController->setModeSleep(true);
        rightController->setPrescaleFromHz(50);
        rightController->setModeSleep(false);
  
        leftController = new upm::PCA9685(I2C_BUS, SECOND_I2C_ADDRESS);
        leftController->setModeSleep(true);
        leftController->setPrescaleFromHz(50);
        leftController->setModeSleep(false);
        
        for (int i = 0; i < COUNT_LEGS / 2; ++i) {
            std::vector<int> channels({ 0 + i*Leg::COUNT_SEGMENTS,
                                        1 + i*Leg::COUNT_SEGMENTS,
                                        2 + i*Leg::COUNT_SEGMENTS,
                                        3 + i*Leg::COUNT_SEGMENTS,
                                        4 + i*Leg::COUNT_SEGMENTS,
            });
            legs.push_back(new Leg(*rightController, channels));
        }
		
        
        for (int i = COUNT_LEGS / 2; i < COUNT_LEGS; ++i) {
            std::vector<int> channels({ 0 + (i - COUNT_LEGS/2)*Leg::COUNT_SEGMENTS,
                                        1 + (i - COUNT_LEGS/2)*Leg::COUNT_SEGMENTS,
                                        2 + (i - COUNT_LEGS/2)*Leg::COUNT_SEGMENTS,
                                        3 + (i - COUNT_LEGS/2)*Leg::COUNT_SEGMENTS,
                                        4 + (i - COUNT_LEGS/2)*Leg::COUNT_SEGMENTS,
            });
            legs.push_back(new Leg(*leftController, channels));
        }
    }
    
    ~Ant() {
        for(int i = 0; i < COUNT_LEGS; ++i) {
            delete legs[i];
        }
        off(rightController);
        off(leftController);
        delete rightController;
        delete leftController;
    }
    
    void action(LEG_NAME leg, SEGMENT_NAME segment, double angle, double speed) {
        legs[leg]->action(segment, angle, speed);
    }

	void setSegmentAsPeversed(LEG_NAME leg, SEGMENT_NAME segment) {
		legs[leg]->setSegmentAsPeversed(segment);
	}

private:
    void off(upm::PCA9685* controller){
        controller->writeByte(upm::PCA9685::REG_ALL_LED_ON_L, 0);
        controller->writeByte(upm::PCA9685::REG_ALL_LED_ON_H, 0);
        controller->writeByte(upm::PCA9685::REG_ALL_LED_OFF_L, 0);
        controller->writeByte(upm::PCA9685::REG_ALL_LED_OFF_H, 0);
    }

private:
    upm::PCA9685* rightController;
    upm::PCA9685* leftController;
    std::vector<Leg*> legs;
    const int FIRST_I2C_ADDRESS = 0x40;
    const int SECOND_I2C_ADDRESS = 0x41;
    const int I2C_BUS = 0;
    static const int COUNT_LEGS = 6;
};

#endif // ANT_H