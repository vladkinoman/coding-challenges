#include <stdio.h>
#include "robot_simulator.h"
int main(int argc, char const *argv[])
{
	robot_grid_status_t instance = robot_init_with_position(HEADING_NORTH, 7, 3);
	robot_grid_status_t * robot = &instance;
	robot_simulator(robot, "RAALAL");
	printf("Robot is at the position (%d, %d).\n", robot->grid.x_position, robot->grid.y_position);
	return 0;
}