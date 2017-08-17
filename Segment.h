#ifndef SEGMENT_H
#define SEGMENT_H
#include "pca9685.hpp"

class Segment {
public:
    Segment(upm::PCA9685& controller, int channel)
    : controller(controller)
    , channel(channel)
    , speed(MAX_SPEED)
    , angle(90)
    , requiredAngle(angle)
    , doingAction(false) 
	, isReversed(false){
        
    }
public:
    upm::PCA9685& controller;
    int channel;
    double speed;
    double angle;
    double requiredAngle;
    bool doingAction;
	bool isReversed;
    static const int MAX_SPEED = 300; // 300 angle per second
    static const int MIN_PW = 110;
    static const int MAX_PW = 580;
    static const int MAX_ANGLE = 180;
        
    void action(double angle, double speed) {
		reverse(angle);
        requiredAngle = angle;
        speed = speed;
        setPWM(0, getPWMbyAngle(requiredAngle));
    }
	
	void reverse(double& angle) {
		if (isReversed) {
			angle = 180 - angle;
		}
	}
	
	void setAsReversed() {
		isReversed = true;
	}
    
private:
    void setPWM(int on, int off){
        controller.writeByte(upm::PCA9685::REG_LED0_ON_L + 4*channel, on & 0xFF);
        controller.writeByte(upm::PCA9685::REG_LED0_ON_H + 4*channel, on >> 8);
        controller.writeByte(upm::PCA9685::REG_LED0_OFF_L + 4*channel, off & 0xFF);
        controller.writeByte(upm::PCA9685::REG_LED0_OFF_H + 4*channel, off >> 8);
    }
    
    double getPWMbyAngle(double angle) {
        if (angle < 0) {
            angle = 0;
        }
        else if (angle > MAX_ANGLE) {
            angle = Segment::MAX_ANGLE;
        }
        return ((Segment::MAX_PW - Segment::MIN_PW) * (angle / Segment::MAX_ANGLE)) + Segment::MIN_PW;;
    }
};

#endif // SEGMENT_H