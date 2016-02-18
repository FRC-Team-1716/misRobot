// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DriveSS.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveSS::DriveSS() : Subsystem("DriveSS") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    gyro = RobotMap::driveSSGyro;
    frontleft = RobotMap::driveSSfrontleft;
    frontright = RobotMap::driveSSfrontright;
    backleft = RobotMap::driveSSbackleft;
    backright = RobotMap::driveSSbackright;
    robotDrive = RobotMap::driveSSRobotDrive;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveSS::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveSS::start(){
	begTime = clock();
}

unsigned long DriveSS::elapsedTime() {
		return ((unsigned long) clock() - begTime);
	}

void DriveSS::Stop() {
	Robot::driveSS->robotDrive->StopMotor();
	}

/*void DriveSS::wait(double second) {
	clock_t endwait;
	endwait = clock() + second * CLOCKS_PER_SEC;
	while (clock() < endwait);
}*/

void DriveSS::main()
{
	gyro->Reset();
	unsigned long seconds = 15;
	DriveSS t;
	t.start();
	std::cout<<"timer started . . .";
	while(seconds >= t.elapsedTime())
	{
		if (t.elapsedTime()>= seconds)
		{
			break;
		}
		else {
			angle = gyro->GetAngle();
			robotDrive->Drive(-1.0, -angle * kP);
			Wait(0.004);
		}
	}
}

/*void DriveSS::TankDrive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right){
	Robot::driveSS->robotDrive->TankDrive(left,right);
}*/



// Put methods for controlling this subsystem
// here. Call these from Commands.

