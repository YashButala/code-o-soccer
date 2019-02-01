#pragma once
#include "skills.h"

/*
Vec2D can be used to make variables that can store points as (x,y) and provide utility functions.
Vec2D point1;
Vec2D point2;
point1.x = HALF_FIELD_MAXX;
point1.y = 0;
similarly for point2 can be specified
Some utility functions:
These will appear automatically as you type Vec2D::
float angle = Vec2D::angle(point1,point2);
int distance = Vec2D::distSq(point1,point2);
*/

namespace MyStrategy
{
	float my_team=1.0;
	void oscillate(BeliefState *state, int meanX, int meanY, int amp)
	{
		Vec2D mean(meanX, meanY);
		Vec2D e1(meanX, meanY + amp);
		Vec2D e2(meanX, meanY - amp);

		float botX = state->homePos[0].x;
		float botY = state->homePos[0].y;

		float velX = state->homeVel[0].x;
		float velY = state->homeVel[0].y;

		//if( abs(meanX-botX) >= 100 || abs(meanY-botY) >= amp ) 
		//	GoToPoint(0,state,mean,PI/2,false,false);
		//else
		{
			if (velY >= 0)      GoToPoint(0, state, e1, PI / 2, false, false);
			else if (velY <= 0) GoToPoint(0, state, e2, PI / 2, false, false);
			else if (velY == 0) GoToPoint(0, state, e2, PI / 2, false, false);
		}
	}

	void goalkeeper(BeliefState *state, int botID)
	{
		float dist;
		dist = sqrt(pow((state->ballPos.x - state->homePos[0].x), 2) + pow((state->ballPos.y - state->homePos[0].y), 2));
		float X = HALF_FIELD_MAXX;
		float Y = HALF_FIELD_MAXY;

		Vec2D ball(state->ballPos.x, state->ballPos.y);
		// take bit outside
		Vec2D push(OUR_GOAL_X+1.5*BOT_RADIUS,state->ballPos.y);
		if(state->homePos[botID].x < -HALF_FIELD_MAXX)
			GoToPoint(botID,state,push,0,true,false);

		//if the ball is near the bot, spin the shit out of that ball, irrespective of where you are :
		if (dist < BOT_RADIUS)
		{
			if (state->ballPos.y >= state->homePos[0].y) Spin(0, 200);
			else if (state->ballPos.y <= state->homePos[0].y) Spin(0, -200);
		}
		//if ball isnt near bot :
		else
		{
			//if the ball is in our half :
			
			{
				//if the ball is in the corner areas :
				if (ball.x <= -4000 && (ball.y) >= OUR_GOAL_MAXY)
				{
					Vec2D point(OUR_GOAL_X+1.5*BOT_RADIUS,OUR_GOAL_MAXY-BOT_RADIUS);
					GoToPoint(botID,state,point,-PI/2.0,false,false);
				}
				else if (ball.x <= -4000 && (ball.y) <= -OUR_GOAL_MAXY)
				{
					Vec2D point(OUR_GOAL_X+1.5*BOT_RADIUS,-OUR_GOAL_MAXY+BOT_RADIUS);
					GoToPoint(botID,state,point,PI/2.0,false,false);
				}
				//ball is in the general area of our half.
				else
				{

					TurnToAngle(botID,state,PI/2.0);
					float Vx = state->ballVel.x;
					float Vy = state->ballVel.y;

					float yToGo = -(Vy / Vx)*(X + ball.x) + ball.y;

					//if its heading towards the goal : 
					if (abs(yToGo) <= OUR_GOAL_MAXY && Vx < 0)
					{
						print("predddddd %f\n",yToGo);
						//WITH A GREAT VELOCITY, track it down and get in its way :
						//if (Vx < -10)
						{
							Vec2D ToBlock(OUR_GOAL_X+1.5*BOT_RADIUS , yToGo);
							GoToPoint(0, state, ToBlock, PI/2.0 , false, false);
						}
					}
						//WITH A MEDIOCRE VELOCITY, match up the y coordinates :
					else
					{
						//if its within goal limits, GO TO the point. if its outside goal limits, OSCILLATE at ends

						Vec2D ToGuard(OUR_GOAL_X+1.5*BOT_RADIUS, ball.y);
						if (ball.y < OUR_GOAL_MINY)
						{
							ToGuard.y = OUR_GOAL_MINY;
							oscillate(state, ToGuard.x, ToGuard.y, 300);
						}
						else if (ball.y > OUR_GOAL_MAXY)
						{
							ToGuard.y = OUR_GOAL_MAXY;
							oscillate(state, ToGuard.x, ToGuard.y, 300);
						}
						else GoToPoint(0, state, ToGuard, -PI / 2.0, false, false);
					}
					
					//if it isnt heading towards the goal; stand in the proper corner
					
				}
			}
			
		}
	}
}