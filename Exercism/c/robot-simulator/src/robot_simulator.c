#include "robot_simulator.h"
#include <stdlib.h>

robot_grid_status_t robot_init(void)
{
	robot_grid_status_t robot;
	robot.bearing = DEFAULT_BEARING;
	robot.grid.x_position = DEFAULT_X_COORDINATE;
	robot.grid.y_position = DEFAULT_Y_COORDINATE;
	return robot;
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y)
{
	if (bearing == 99)
		bearing = DEFAULT_BEARING;

	robot_grid_status_t robot;
	robot.bearing = bearing;
	robot.grid.x_position = x;
	robot.grid.y_position = y;
	return robot;
}

void robot_turn_right(robot_grid_status_t * robot)
{
	if     (robot->bearing == HEADING_NORTH)
		robot->bearing = HEADING_EAST;
	else if(robot->bearing == HEADING_EAST)
		robot->bearing = HEADING_SOUTH;
	else if(robot->bearing == HEADING_SOUTH)
		robot->bearing = HEADING_WEST;
	else if(robot->bearing == HEADING_WEST)
		robot->bearing = HEADING_NORTH;
}

void robot_turn_left(robot_grid_status_t * robot)
{
	if     (robot->bearing == HEADING_NORTH)
		robot->bearing = HEADING_WEST;
	else if(robot->bearing == HEADING_WEST)
		robot->bearing = HEADING_SOUTH;
	else if(robot->bearing == HEADING_SOUTH)
		robot->bearing = HEADING_EAST;
	else if(robot->bearing == HEADING_EAST)
		robot->bearing = HEADING_NORTH;
}

void robot_advance(robot_grid_status_t * robot)
{
	if     (robot->bearing == HEADING_NORTH)
		robot->grid.y_position += 1;
	else if(robot->bearing == HEADING_EAST)
		robot->grid.x_position += 1;
	else if(robot->bearing == HEADING_SOUTH)
		robot->grid.y_position -= 1;
	else if(robot->bearing == HEADING_WEST)
		robot->grid.x_position -= 1;
}

void robot_simulator(robot_grid_status_t * robot, const char *commands)
{
	for (int i = 0; *(commands + i) != '\0'; ++i)
		if     (*(commands + i) == COMMAND_LEFT)
			robot_turn_left(robot);
		else if(*(commands + i) == COMMAND_RIGHT)
			robot_turn_right(robot);
		else if(*(commands + i) == COMMAND_ADVANCE)
			robot_advance(robot);
}