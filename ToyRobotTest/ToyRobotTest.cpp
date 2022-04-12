#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/Robot.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTest
{
	TEST_CLASS(RobotClass)
	{
	public:
		TEST_METHOD(TestPlaceMethodValidArgs)
		{
			Robot robot;
			Assert::IsTrue( robot.place( 1, 2, "NORTH" ) );
		}
		TEST_METHOD( TestPlaceMethodInvalidPosition )
		{
			Robot robot;
			Assert::IsFalse( robot.place( 5,5,"WEST" ));
		}
		TEST_METHOD( TestPlaceMethodInvalidFaceDir )
		{
			Robot robot;
			Assert::IsFalse( robot.place( 1, 2, "SOUTHEAST" ) );
		}
		TEST_METHOD( TestMoveMethodValidPos )
		{
			Robot robot;
			robot.place( 1, 2, "EAST");
			Assert::IsTrue( robot.move() );
		}
		TEST_METHOD( TestMoveMethodInvalidPos )
		{
			Robot robot;
			robot.place( 4, 2, "EAST" );
			Assert::IsFalse( robot.move() );
		}
		TEST_METHOD( TestMoveMethodNotPlaced )
		{
			Robot robot;
			Assert::IsFalse( robot.move() );
		}
		TEST_METHOD( TestRightMethodValid )
		{
			Robot robot;
			robot.place( 3, 2, "NORTH" );
			Assert::IsTrue( robot.right() );
		}
		TEST_METHOD( TestRightMethodNotPlaced )
		{
			Robot robot;
			Assert::IsFalse( robot.move() );
		}
		TEST_METHOD( TestLeftMethodValid )
		{
			Robot robot;
			robot.place( 3, 2, "WEST" );
			Assert::IsTrue( robot.left() );
		}
		TEST_METHOD( TestLeftMethodNotPlaced )
		{
			Robot robot;
			Assert::IsFalse( robot.left() );
		}
	};
}
