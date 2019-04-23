#include "Body.h"


//void Body::setupArm(Arm arm, string com) {
//	arm.setup(com);
//}

void Body::bodySetup() {
	larm.armSetup(leftcom);
	rarm.armSetup(rightcom);
}
void Body::bodyUpdate() {
	larm.armUpdate();
	rarm.armUpdate();
}

Body::Body()
{
}


Body::~Body()
{
}
