#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/Robot.cpp"
#include "../ToyRobot/Table.h"
#include "../ToyRobot/Direction.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTest
{
	TEST_CLASS(RobotClass)
	{
	public:
		TEST_METHOD( TestPlaceMethodIfPlaced )
		{
			Robot robot;
			robot.place( 1, 2, "NORTH" );
			Assert::IsTrue( robot.isPlaced() );
		}
		TEST_METHOD( TestPlaceMethodPositionAndFace )
		{
			
			Robot robot;
			robot.place( 1, 4, "WEST" );
			Assert::AreEqual( 1, robot.getPosition().first );
			Assert::AreEqual( 4, robot.getPosition().second );
			Assert::AreEqual( int(WEST), robot.getFacingDirection() );
		}
		TEST_METHOD( TestMoveMethod )
		{
			Robot robot;
			robot.place( 3, 2, "EAST" );
			robot.move();
			Assert::AreEqual( 4, robot.getPosition().first );
		}
		TEST_METHOD( TestRotateMethodToRight )
		{
			Robot robot;
			robot.place( 2, 2, "EAST" );
			robot.rotate( "RIGHT" );
			Assert::AreEqual( int(SOUTH), robot.getFacingDirection() );
		}
		TEST_METHOD( TestRotateMethodToLeft )
		{
			Robot robot;
			robot.place( 2, 3, "NORTH" );
			robot.rotate( "LEFT");
			Assert::AreEqual( int(WEST), robot.getFacingDirection() );
		}
	};
}
