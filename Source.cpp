#include <iostream>
#include <unistd.h>
#include "Ant.h"

int main() {
	Ant ant;
        //for(int i = 0; i < 1; ++i){
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Coxa, 70, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter, 70, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Femur, 70, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tabia, 70, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus, 70, Segment::MAX_SPEED);        
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Coxa, 120, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter, 120, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Femur, 120, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tabia, 120, Segment::MAX_SPEED);
            sleep(1);
            ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus, 120, Segment::MAX_SPEED);        
            sleep(1);
        //}
	return 0;
}