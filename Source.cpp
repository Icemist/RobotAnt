#include <iostream>
#include "Ant.h"

int main() {
	Ant ant;
	ant.action(LEG_NAME::RightBack, SEGMENT_NAME::Coxa, 90, Segment::MAX_SPEED);
	ant.action(LEG_NAME::RightBack, SEGMENT_NAME::Tabia, 30, Segment::MAX_SPEED / 2);
	//need wait! and to do next 
	return 0;
}