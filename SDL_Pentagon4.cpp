// SDL_Pentagon4.cpp
// Anita Alex
// 3/12/2025

// This is our SDL Template that we'll use for our SDL projects
/*******Dont't forget to add your .DLL file to your project**************/

/*This program opens an SDL window and intialize the SDL subsystems
If we get the window with a line drawn appears on the renderer,
then you know it works*/

#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;


const int SCREENWIDTH = 640, SCREENHEIGHT = 480;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect rectangle;


void initialize();
void refreshScreen();
void cleanUp();
void trace_outline_star(SDL_Renderer* renderer, int, int, int, int);
void filledTriangle(SDL_Renderer* renderer, int , int , int , int , int , int );

int main(int arc, char* argv[]) // these arguments are needed for SDL projects
{
	// first initialize! then refresh screen, then clean up!
	initialize();
	refreshScreen();
	cleanUp();
	return 0;
}

/***************************FUNCTION DEFENITIONS*****************************/

void refreshScreen()
{
	SDL_bool done = SDL_FALSE;



	while (!done)
	{
		SDL_Event event;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);


		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		trace_outline_star(renderer, 320, 240, 100, 0);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				done = SDL_TRUE;
		}
	}
}



void initialize()
{ // initialize all subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL did not load corectly. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "Congratulations! SDL loaded correctly!\n";
		SDL_CreateWindowAndRenderer(SCREENWIDTH, SCREENHEIGHT, 0, &window, &renderer);
	}
} // end of initialize() method

void cleanUp() // frees up any memory we've allocated to our SDL objects
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit(); // these functions already written for us, called at end of program
} // end of Clean_Up() function

void filledTriangle(SDL_Renderer* renderer, int vertex1_x, int vertex1_y,
	int vertex2_x, int vertex2_y,
	int vertex3_x, int vertex3_y)
{ // the plan is, given three vertices put them in order from top of screen donwards
	// and then start at the top and draw horizontal lines all the way down
	/*** except for that one case where I couldn't get that to work yet ***/

	// first, let's put them in order
	int xmin(vertex1_x), ymin(vertex1_y), xmid, ymid, xmax, ymax;
	double slope1(0.0), slope2(0.0), slope3(0.0); // initialize slopes
	bool slope_1_is_undefined(true), slope_2_is_undefined(true), slope_3_is_undefined(true);
	// so right now, vertex1 is the min, let's compare vertex2 to it!
	if (vertex2_y >= vertex1_y)
		xmid = vertex2_x, ymid = vertex2_y;
	else
	{// if not vertex2 should be the new min
		xmid = xmin, ymid = ymin;
		xmin = vertex2_x, ymin = vertex2_y;
	}
	// now two verticies are properly ordererd, let's introduce vertex3 now
	if (vertex3_y <= ymin)
	{// vertex3 become the new min, the other two have to move up!
		xmax = xmid, ymax = ymid;
		xmid = xmin, ymid = ymin;
		xmin = vertex3_x, ymin = vertex3_y;
	}
	else if (vertex3_y <= ymid)
	{// only the mid has to move to max
		xmax = xmid, ymax = ymid;
		xmid = vertex3_x, ymid = vertex3_y;
	}
	else // last case is if vertex 3 is the max
		xmax = vertex3_x, ymax = vertex3_y;
	// Now hopefully the 3 vertecies are in order from top of the screen to the bottom
	// we can;t draw just yet we need the slopes for each of the sides
	if (xmin - xmid != 0)
	{
		slope1 = 1.0 * (ymin - ymid) / (xmin - xmid);
		slope_1_is_undefined = false;
	}
	if (xmin - xmax != 0)
	{
		slope2 = 1.0 * (ymin - ymax) / (xmin - xmax);
		slope_2_is_undefined = false;
	}
	if (xmid - xmax != 0)
	{
		slope3 = 1.0 * (ymid - ymax) / (xmid - xmax);
		slope_3_is_undefined = false;
	}

	// to sum up so far: we have verticies in prder, we have slopes
	// as long as we can keep track of x_left and x_right along the sides
	// we should be able to draw horizontal lines all the way down!

	double what_x_is_left = 1.0 * xmin, what_x_is_right = 1.0 * xmin;
	for (int i = ymin; i <= ymid; i++)
	{
		SDL_RenderDrawLine(renderer, what_x_is_left, i, what_x_is_right, i);
		// slope 1 cases:
		if (xmin <= xmid) // NOTE this is slope1, it goes from min to mid
		{
			if (slope1 < 0)
				what_x_is_left -= 1.0 / slope1; // this may be confuding bc positive is down
			else if (slope1 > 0)
				what_x_is_left += 1.0 / slope1;
			else if (slope_1_is_undefined) // equal to 0
				what_x_is_left = xmin;
		}
		else
		{
			if (slope1 < 0)
				what_x_is_left += 1.0 / slope1; // go the OTHER WAY
			else if (slope1 > 0)
				what_x_is_left -= 1.0 / slope1;
			else if (slope_1_is_undefined) // slope of 0 (vertical line)
				what_x_is_left = xmin;
		}
		// slope2 cases:
		if (xmin <= xmax) // this is my slope 2: it goes from min all the way to max
		{
			if (slope2 < 0)
				what_x_is_right -= 1.0 / slope2;
			else if (slope2 > 0)
				what_x_is_right += 1.0 / slope2;
			else if (slope_2_is_undefined)
				what_x_is_right = xmax; // vertical line case
		}
		else
		{ // if xmax is o the left of xmin
			if (slope2 < 0)
				what_x_is_right += 1.0 / slope2;
			else if (slope2 > 0)
				what_x_is_right -= 1.0 / slope2;
			else if (slope_2_is_undefined)
				what_x_is_right = xmax;
		}
	} // we made it to the mid
	// the third side begins here and we begin using slope3
	// slope3 is for the side that goes from mid to max
	if (xmid <= xmax)
	{ // a new st of horizontal lines, so we need a new loop
		what_x_is_left = xmid;
		for (int i = ymid; i <= ymax; i++)
		{
			SDL_RenderDrawLine(renderer, what_x_is_left, i, what_x_is_right, i);
			// slope3 cases:
			if (slope3 < 0)
				what_x_is_left -= 1.0 / slope3;
			else if (slope3 > 0)
				what_x_is_left += 1.0 / slope3;
			else if (slope_3_is_undefined)
				what_x_is_left = xmid;
			// slope2 cases: 
			if (xmin <= xmax) // this is my slope 2: it goes from min all the way to max
			{
				if (slope2 < 0)
					what_x_is_right -= 1.0 / slope2;
				else if (slope2 > 0)
					what_x_is_right += 1.0 / slope2;
				else if (slope_2_is_undefined)
					what_x_is_right = xmax; // vertical line case
			}
			else
			{ // if xmax is o the left of xmin
				if (slope2 < 0)
					what_x_is_right += 1.0 / slope2;
				else if (slope2 > 0)
					what_x_is_right -= 1.0 / slope2;
				else if (slope_2_is_undefined)
					what_x_is_right = xmax;
			}

		}

	}
	else if (xmid > xmax) // this is the one that gave me problems...
	{ // so i started at the bottom ymax and went up to ymid
		what_x_is_right = xmax;
		what_x_is_left = xmax;
		for (int i = ymax; i >= ymid; i--)
		{
			SDL_RenderDrawLine(renderer, what_x_is_left, i, what_x_is_right, i);
			// slope 3 cases:
			if (slope3 < 0)
				what_x_is_right -= 1.0 / slope3;
			else if (slope3 > 0)
				what_x_is_right += 1.0 / slope3;
			else if (slope_3_is_undefined)
				what_x_is_right = xmid;
			// slope 2 cases:
			if (xmin <= xmax)
			{
				if (slope2 < 0)
					what_x_is_left += 1.0 / slope2;
				else if (slope2 > 0)
					what_x_is_left -= 1.0 / slope2;
				else if (slope_2_is_undefined)
					what_x_is_left = xmax;
			}
			else // xmin on the left, xmax is on the right
			{
				if (slope2 < 0)
					what_x_is_left -= 1.0 / slope2;
				else if (slope2 > 0)
					what_x_is_left += 1.0 / slope2;
				else if (slope_2_is_undefined)
					what_x_is_left = xmax;
			}
		}
	}
} // end of function!

void trace_outline_star(SDL_Renderer* renderer, int x_cent, int y_cent, int radius, int degrees) // ready to be twirled
{  // trace the outline of a star (outside, not the diagonals)                              The points not on circle aren't cooperating!
	// using the center of a circle so that we can rotate if we want
	// we want 10 lines, use the unit circle to identify the five coordinates on circle
	// and algebra to find other five
	// 54° = 0.3pi, 126° = 0.7pi, 198° = 1.1pi, 270° = 1.5pi, 342° = 1.9pi 
	// 18° = 0.1pi, 216° = 1.2pi, 306° = 1.7pi
	double theta = degrees * M_PI / 180; // turn degrees into radians real quick
	// i used law of sines to get 0.381966 as the radius for the inside pentagon
	double rad_sf = 0.381966; // i did r = (sin(18) / sin (126)) * radius to get the scale factor for the larger radius
	double x_coord1(x_cent + radius * cos(1.1 * M_PI + theta)), y_coord1(y_cent + radius * sin(1.1 * M_PI + theta)),
		x_coord2(x_cent + radius * rad_sf * cos(1.3 * M_PI + theta)), y_coord2(y_cent + radius * rad_sf * sin(1.3 * M_PI + theta)),
		x_coord3(x_cent + radius * cos(1.5 * M_PI + theta)), y_coord3(y_cent + radius * sin(1.5 * M_PI + theta)),
		x_coord4(x_cent + radius * rad_sf * cos(1.7 * M_PI + theta)), y_coord4(y_cent + radius * rad_sf * sin(1.7 * M_PI + theta)), // can borrow from point 2, just change sign
		x_coord5(x_cent + radius * cos(1.9 * M_PI + theta)), y_coord5(y_cent + radius * sin(1.9 * M_PI + theta)),
		x_coord6(x_cent + radius * rad_sf * cos(0.1 * M_PI + theta)),
		y_coord6(y_cent + radius * rad_sf * sin(0.1 * M_PI + theta)), // used original function and sin^-1 to find angle in radians
		x_coord7(x_cent + radius * cos(0.3 * M_PI + theta)), y_coord7(y_cent + radius * sin(0.3 * M_PI + theta)),
		x_coord8(x_cent + radius * rad_sf * cos(0.5 * M_PI + theta)), // on the center x!
		y_coord8(y_cent + radius * rad_sf * sin(0.5 * M_PI + theta)), // solved system of equations using unit circle on desmos
		x_coord9(x_cent + radius * cos(0.7 * M_PI + theta)), y_coord9(y_cent + radius * sin(0.7 * M_PI + theta)),
		x_coord10(x_cent + radius * rad_sf * cos(0.9 * M_PI + theta)),
		y_coord10(y_cent + radius * rad_sf * sin(0.9 * M_PI + theta)); // due to symmetry, I could borrow from point 6
	/* SAMPLE LINE EQUATION:
	   y - sin(1.9 * M_PI) = (sin(1.9 * M_PI)-sin(0.7 * M_PI))/(cos(1.9 * M_PI)-cos(1.7) * M_PI) * (x - cos(1.9 * M_PI))
	   I graphed the two lines that I needed using the 5 points of the star and then graphed on desmos to find intersection */

	SDL_RenderDrawLine(renderer, x_coord1, y_coord1, x_coord2, y_coord2);
	SDL_RenderDrawLine(renderer, x_coord2, y_coord2, x_coord3, y_coord3);
	SDL_RenderDrawLine(renderer, x_coord3, y_coord3, x_coord4, y_coord4);
	SDL_RenderDrawLine(renderer, x_coord4, y_coord4, x_coord5, y_coord5);
	SDL_RenderDrawLine(renderer, x_coord5, y_coord5, x_coord6, y_coord6);
	SDL_RenderDrawLine(renderer, x_coord6, y_coord6, x_coord7, y_coord7);
	SDL_RenderDrawLine(renderer, x_coord7, y_coord7, x_coord8, y_coord8);
	SDL_RenderDrawLine(renderer, x_coord8, y_coord8, x_coord9, y_coord9);
	SDL_RenderDrawLine(renderer, x_coord9, y_coord9, x_coord10, y_coord10);
	SDL_RenderDrawLine(renderer, x_coord10, y_coord10, x_coord1, y_coord1);

	// pentagon
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	filledTriangle(renderer, x_coord2, y_coord2, x_coord3, y_coord3, x_coord5, y_coord5);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
	filledTriangle(renderer, x_coord7, y_coord7, x_coord5, y_coord5, x_coord4, y_coord4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	filledTriangle(renderer, x_coord9, y_coord9, x_coord6, y_coord6, x_coord7, y_coord7);

	SDL_SetRenderDrawColor(renderer, 178, 102, 255, SDL_ALPHA_OPAQUE);
	filledTriangle(renderer, x_coord9, y_coord9, x_coord8, y_coord8, x_coord1, y_coord1);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	filledTriangle(renderer, x_coord10, y_coord10, x_coord3, y_coord3, x_coord1, y_coord1);

}



