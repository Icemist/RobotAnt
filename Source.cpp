#include <iostream>
#include <unistd.h>
#include "Ant.h"

int main() {
	Ant ant;
    std::cout << "Started" << std::endl;
    ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Coxa, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Femur, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tabia, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus, 90, Segment::MAX_SPEED);

	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Coxa, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Trochanter, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Femur, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tabia, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tarsus, 90, Segment::MAX_SPEED);
        
	sleep(4);

	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Coxa, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Femur, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tabia, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus, 135, Segment::MAX_SPEED);

	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Coxa, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Trochanter, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Femur, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tabia, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tarsus, 135, Segment::MAX_SPEED);

	sleep(4);

	ant.setSegmentAsPeversed(LEG_NAME::RightFront, SEGMENT_NAME::Coxa);
	ant.setSegmentAsPeversed(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter);
	ant.setSegmentAsPeversed(LEG_NAME::RightFront, SEGMENT_NAME::Femur);
	ant.setSegmentAsPeversed(LEG_NAME::RightFront, SEGMENT_NAME::Tabia);
	ant.setSegmentAsPeversed(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus);

	ant.setSegmentAsPeversed(LEG_NAME::LeftFront, SEGMENT_NAME::Coxa);
	ant.setSegmentAsPeversed(LEG_NAME::LeftFront, SEGMENT_NAME::Trochanter);
	ant.setSegmentAsPeversed(LEG_NAME::LeftFront, SEGMENT_NAME::Femur);
	ant.setSegmentAsPeversed(LEG_NAME::LeftFront, SEGMENT_NAME::Tabia);
	ant.setSegmentAsPeversed(LEG_NAME::LeftFront, SEGMENT_NAME::Tarsus);

	//reverse

	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Coxa, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Trochanter, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Femur, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tabia, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightFront, SEGMENT_NAME::Tarsus, 135, Segment::MAX_SPEED);

	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Coxa, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Trochanter, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Femur, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tabia, 135, Segment::MAX_SPEED);
	ant.action(LEG_NAME::LeftFront, SEGMENT_NAME::Tarsus, 135, Segment::MAX_SPEED);

	sleep(4);

    std::cout << "Finished" << std::endl;
	return 0;
}