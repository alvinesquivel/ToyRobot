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
		TEST_METHOD(TestValidPosition)
		{
			int x = 1;
			int y = 1;
			Robot r;
			Assert::IsTrue( r.is_valid_position( x,y ) );
		}
		TEST_METHOD( TestInvalidPosition )
		{
			int x = 5;
			int y = 3;
			Robot r;
			Assert::IsFalse( r.is_valid_position( x, y ) );
		}
		TEST_METHOD( TestPlaceValidArgs )
		{
			int x = 1;
			int y = 3;
			std::string face = "EAST";
			Robot r;
			Assert::IsTrue( r.place( x, y, face ) );
		}
		TEST_METHOD( TestPlaceInvalidPos )
		{
			int x = 6;
			int y = 5;
			std::string face = "EAST";
			Robot r;
			Assert::IsFalse( r.place( x, y, face ) );
		}
		TEST_METHOD( TestPlaceInvalidFace )
		{
			int x = 1;
			int y = 3;
			std::string face = "NOR";
			Robot r;
			Assert::IsFalse( r.place( x, y, face ) );
		}
		TEST_METHOD( TestRotateRight )
		{
			std::string dir = "RIGHT";
			int x = 1, y = 2;
			std::string face = "EAST";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.rotate( dir ) );
		}
		TEST_METHOD( TestRotateLeft )
		{
			std::string dir = "LEFT";
			int x = 1, y = 2;
			std::string face = "NORTH";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.rotate( dir ) );
		}
		TEST_METHOD( TestMoveNorth )
		{
			int x = 1, y = 2;
			std::string face = "NORTH";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.move() );
		}
		TEST_METHOD( TestMoveSouth )
		{
			int x = 1, y = 2;
			std::string face = "SOUTH";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.move() );
		}
		TEST_METHOD( TestMoveEast )
		{
			int x = 3, y = 2;
			std::string face = "EAST";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.move() );
		}
		TEST_METHOD( TestMoveWest )
		{
			int x = 2, y = 2;
			std::string face = "WEST";
			Robot r;
			r.place( x, y, face );
			Assert::IsTrue( r.move() );
		}
		TEST_METHOD( TestMoveInvalid ) // move without placing the robot
		{
			Robot r;
			Assert::IsFalse( r.move() );
		}
	};
}
