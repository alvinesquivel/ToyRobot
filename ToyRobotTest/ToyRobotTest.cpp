#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/Robot.cpp"
#include "../ToyRobot/Table.h"
#include <tuple>


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
			std::tuple<int, int, std::string> exp( 5, 5, "WEST" );
			Robot robot;
			robot.place( std::get<0>( exp ), std::get<1>( exp ), std::get<2>( exp ) );
			Assert::AreEqual( std::get<0>( exp ), robot.getPosition().first );
			Assert::AreEqual( std::get<1>( exp ), robot.getPosition().second );
			Assert::AreEqual( std::get<2>( exp ), robot.getFacingDirection() );
		}
		TEST_METHOD( TestMoveMethod )
		{
			Robot robot;
			robot.place( 3, 2, "EAST" );
			robot.move();
			Assert::AreEqual( 4, robot.getPosition().first );
		}
		TEST_METHOD( TestRightMethodFromEast )
		{
			Robot robot;
			robot.place( 2, 2, "EAST" );
			robot.right();
			Assert::AreEqual( std::string{ "SOUTH" }, robot.getFacingDirection() );
		}
		TEST_METHOD( TestLeftMethodFromNorth )
		{
			Robot robot;
			robot.place( 2, 3, "NORTH" );
			robot.left();
			Assert::AreEqual( std::string{ "WEST" }, robot.getFacingDirection() );
		}
	};
}
