# ToyRobot
## Setup
* Checkout this repository: ```git checkout https://github.com/alvinesquivel/ToyRobot.git```
* Open ToyRobot.sln with Visual Studio (I used VS 2019)
* Set the the project configuration to **Release** and **x64** and Build the **ToyRobot** project

## Running the App
* After building the project, navigate to *x64/Release* folder in the **ToyRobot** project directory
* Run **ToyRobot.exe**
* The compiled **ToyRobot** app accepts input/s from STDIN

Example valid commands:
  ```
  PLACE 1,3,EAST
  MOVE
  RIGHT
  REPORT
  ```

## Running Unit Tests
In Visual Studio, navigate to Solution Explorer and Right-click the **ToyRobotTest** project then select **Run Tests**
