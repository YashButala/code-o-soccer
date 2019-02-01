#pragma once
#include "skills.h"
namespace MyStrategy
{
	// Naive example for attacker
	/*void attacker(BeliefState *state, int botID)
	{
		print("Attacker\n");
		Vec2D fpoint(HALF_FIELD_MAXX, 0);
		//Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
		// Go to ball if ball is far
		// Take ball to the goal
		if (state->ballPos.x>0)
		{


			if (!state->pr_ourBall)
			GoToPoint(botID, state, state->ballPos, 0, true, true);
			if (state->pr_ballInOppCorner&&state->ballPos.y > 0)
			{
				GoToPointStraight(botID, state, state->ballPos, 0, true, true);
			}
			if (state->pr_ballInOppCorner&&state->ballPos.y < 0)
			{
				GoToPointStraight(botID, state, state->ballPos, 0, true, true);
			}
			else
			{
				fpoint.x = OPP_GOAL_X;
				fpoint.y = 0;
				GoToPoint(botID, state, fpoint, 0, true, true);
			}
		}

		if (state->pr_ballOurSide)
		{
			Vec2D dpoint;
			dpoint.x = state->ballPos.x;
			dpoint.y = state->ballPos.y;
			fpoint.x = OPP_GOAL_X;
			fpoint.y = 0;

			if (state->ballPos.x < state->homePos[botID].x)
			{
				GoToPoint(botID, state, state->ballPos, 0, true, true);
				if (state->pr_ourBall)
				{
					GoToPointStraight(botID, state,fpoint, PI / 2, true, false);
				}
				//Velocity(botID, 200, 200);
			}
			else
			{
				dpoint.x = state->ballPos.x + 5 * BOT_RADIUS;
				dpoint.y = state->ballPos.y;
				GoToPoint(botID, state, state->ballPos, 0, true, true);

			}
			if (state->pr_balInOurCorner||state->pr_ball_in_our_dbox)
			{
				GoToBall(botID, state, true);
				if (state->pr_ourBall)
				{
					GoToPointStraight(botID, state, state->awayPos[state->oppBotNearestToBall], PI / 2, true, false);
				}
			}
		}

	}*/
	void attacker(BeliefState *state, int botID)
	{
		print("Attacker\n");
		//
		float my_team=1.0;
		if(abs(state->ballPos.x)<300 &&  abs(state->ballPos.y)<300)
		{
			GoToBall(botID, state, true);
		}
		//
		Vec2D fpoint(HALF_FIELD_MAXX, 0);
		Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
		// Go to ball if ball is far
		// Take ball to the goal
		

		if (state->ballPos.x*my_team > 0.9*HALF_FIELD_MAXX &&state->ballPos.y*my_team > 0.9*HALF_FIELD_MAXY)
		{
			Spin(botID, 500*my_team);
			fpoint.x = OPP_GOAL_X;
			fpoint.y = 0;
			GoToPointStraight(botID, state, state->ballPos, PI / 2, true, true);
		}
		if (state->ballPos.x*my_team > 0.9*HALF_FIELD_MAXX &&state->ballPos.y*my_team < -0.9*HALF_FIELD_MAXY)
		{
			Spin(botID, my_team*(-500));
			fpoint.x = OPP_GOAL_X;
			fpoint.y = 0;
			GoToPointStraight(botID, state, state->ballPos, PI / 2, true, true);
		}
		if(state->ballPos.x*my_team > (my_team)*(-HALF_FIELD_MAXX/2) && abs(state->ballPos.y) < HALF_FIELD_MAXY/2 && (state->ballPos.x)*my_team < my_team*(-HALF_FIELD_MAXX+DBOX_HEIGHT))
		{
			if (Vec2D::dist(state->homePos[botID],state->ballPos) <1.1*BOT_RADIUS )
			{
				fpoint.x = OPP_GOAL_X;
				fpoint.y = -(float)DBOX_WIDTH*21/100;
				GoToPointStraight(botID, state, state->ballPos, 0, true, true);
			}
			else 
			{
				fpoint.x = state->ballPos.x;
				fpoint.y = state->ballPos.y;
				GoToPoint(botID, state, state->ballPos, 0, true, true);
			}
		}
		else if (Vec2D::dist(state->homePos[botID],state->ballPos)<BOT_RADIUS)
		{
			/*fpoint.x = OPP_GOAL_X;
			fpoint.y = 0;
			GoToPointStraight(botID, state, fpoint, 0, true, true);
			Vec2D f1point;
			f1point.x = HALF_FIELD_MAXX - DBOX_HEIGHT;
			f1point.y = 0;
			GoToPoint(botID, state, f1point, 0, false, true);*/
			//fpoint.x = state->ballPos.x + BOT_RADIUS;
			//fpoint.y = (float)state->ballPos.y + 0.95*BOT_RADIUS;
			//GoToPoint(botID, state, fpoint, 0, false, true);
			if(state->homePos[botID].y < 0)
				Spin(botID,-500*my_team);
			if(state->homePos[botID].y > 0)
				Spin(botID,500*my_team);
		}
		else 
		{
			GoToPoint(botID, state, state->ballPos, 0, true, true);
		}
	}
}