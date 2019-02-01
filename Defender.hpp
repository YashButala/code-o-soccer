#pragma once
#include "skills.h"

namespace MyStrategy
{
  // Naive example for defender
    void defender(BeliefState *state, int botID)
    {
        //print("Defender\n");
        //It follows the ball

        /*Vec2D dpoint;
        dpoint.x = state->ballPos.x;
        dpoint.y = state->ballPos.y;
        //if (! state -> pr_ball_in_our_dbox)
        //GoToPoint(botID, state, dpoint, 0, true, true);

        if (state->pr_ball_in_our_dbox)
        {
            GoToPointStraight(botID, state, state->ballPos, PI / 2, true, false);
            //GoToBall(botID, state, true);
            Velocity(botID, 50, 50);
        }
        if (state->ballPos.x < 0)
        {
            //print("Defense");
            if (state->ballPos.x > state->homePos[botID].x && abs(state->ballPos.y) < 1000 )
            {
                if (state->pr_ball_in_our_dbox)
                {
                    print("ball in d\n");
                    //GoToBall(botID, state, false);
                    GoToPoint(botID, state, state->ballPos, 0, true, true);
                    if (state->pr_ourBall)
                    {
                        GoToPointStraight(botID, state, state->awayPos[state->oppBotNearestToBall], 0, true, false);
                    }
                }
                else
                {
                    Vector2D<float> ballVel = state->ballVel;
                    float intercept_dist = 5 * BOT_RADIUS;
                    float angle = atan2(ballVel.y, ballVel.x);
                    dpoint.x = state->ballPos.x + intercept_dist * cos(angle);
                    dpoint.y = state->ballPos.y + intercept_dist * sin(angle);
                    GoToPoint(botID, state, dpoint, 0, true, true);
                    print("ball out of D\n");
                    if (Vector2D<int>::distSq(state->homePos[botID], state->ballPos) < 3 / 2 * pow(BOT_BALL_THRESH, 2))
                    {
                        Vector2D<int> target;
                        target.x = HALF_FIELD_MAXX;
                        target.y = 450;
                        GoToPointStraight(botID, state, target, 0, true, true);
                    }
                }
                //Velocity(botID, 200, 200);
            }
            else if (state->ballPos.x <= state->homePos[botID].x && abs(state->ballPos.y) < 1000)
            {
                Vector2D<int> aim;
                float away_angle = atan2(state->awayVel[state->oppBotNearestToBall].y, state->awayVel[state->oppBotNearestToBall].x);
                print("Obstruct opp\n");
                if (state->awayPos[state->oppBotNearestToBall].x < state->homePos[botID].x)
                {
                    aim.x = state->awayPos[state->oppBotNearestToBall].x; //+4 * BOT_RADIUS*cos(away_angle);
                    aim.y = state->awayPos[state->oppBotNearestToBall].y; //+4 * BOT_RADIUS*sin(away_angle);
                    print("%d, %d", aim.x, aim.y);
                    GoToPoint(botID, state, aim, 0, true, true);
                    if (Vector2D<int>::distSq(state->homePos[botID], aim) < 3 / 2 * pow(BOT_BALL_THRESH, 2))
                    {
                        GoToPointStraight(botID, state, state->awayPos[state->oppBotNearestToBall], 0, true, true);
                    }
                }
                else
                {
                    GoToPoint(botID, state,state->ballPos, 0, true, true);

                }
            }
            else if (abs(state->ballPos.y) > 1000 && state->ballPos.x < -3200 && state->ballPos.x > state->homePos[botID].x)
            {
                GoToPoint(botID, state, state->ballPos, 0, true, true);
                print("In our corner: %f", sqrt(pow(state->homePos[botID].x - state->ballPos.x, 2) + pow(state->homePos[botID].y - state->ballPos.y, 2)));
                if (Vector2D<int>::distSq(state->homePos[botID], state->ballPos) < 3 * pow(BOT_BALL_THRESH, 2) / 2)
                {
                    print("Spinning");
                    if (state->ballPos.y > state->homePos[botID].y) Spin(botID, -MAX_BOT_OMEGA);
                    else Spin(botID, MAX_BOT_OMEGA);
                    /*if (state->pr_ourBall&&state->ballPos.y > 0 && state->ballPos.y > state->homePos[botID].y)
                    {
                    GoToBall(botID, state, true);
                    GoToPointStraight(botID, state, state->awayPos[state->oppBotNearestToBall], PI / 2, true, false);
                    }
                    if (state->pr_ourBall&&state->ballPos.y<0 && state->ballPos.y>state->homePos[botID].y)
                    {
                    GoToBall(botID, state, true);
                    GoToPointStraight(botID, state, state->awayPos[state->oppBotNearestToBall], PI / 2, true, false);
                    }
                }
            }
            else
            {
                print("Outside all conditions\n");
                GoToBall(botID, state, true);
            }

        }
        if (state->pr_ballOppSide)
        {
            GoToBall(botID, state, true);
            dpoint.x = OPP_GOAL_X;
            dpoint.y = state->ballPos.y;
            GoToPoint(botID, state, dpoint, 0, true, false);
            Velocity(botID, 200, 200);
        }*/
        //print("%d, %d\n",state->ballPos.x, state->ballPos.y);
        if (state->ballPos.x< 0)
        {
            
            if (abs(state->ballPos.y) < DBOX_WIDTH)
            {
                if (Vector2D<int>::distSq(state->homePos[botID], state->ballPos) < 1.5*pow(BOT_BALL_THRESH, 2))
                {
                    Vector2D<int> aim;
                    aim.x = OPP_GOAL_X;
                    aim.y = 300;
                    GoToPointStraight(botID, state, aim, PI/4, true, true);
                }
                Vector2D<int> target;
                if (state->ballPos.x >state->homePos[botID].x)
                {
                    Vector2D<float> ballVel = state->ballVel;
                    float intercept_dist = 5* BOT_RADIUS;
                    float angle = atan2(ballVel.y, ballVel.x);
                    target.x = state->ballPos.x + intercept_dist * cos(angle);
                    target.y = state->ballPos.y +  intercept_dist * sin(angle);
                    if (abs(target.x) > HALF_FIELD_MAXX)
                    {
                        target.x = (-HALF_FIELD_MAXX + DBOX_HEIGHT);
                    }
                    if (abs(target.y) > HALF_FIELD_MAXY)
                    {
                        target.y = state->awayPos[state->oppBotNearestToBall].y + ((state->awayVel[state->oppBotNearestToBall].y)*(target.x - state->awayPos[state->oppBotNearestToBall].x)/(state->awayVel[state->oppBotNearestToBall].x));
                        if (abs(target.y) > HALF_FIELD_MAXY)
                        {
                            target.y = state->awayPos[state->oppBotNearestToBall].y;
                        }
                    }

                }
                else if (state->ballPos.x <= state->homePos[botID].x)
                {
                    target.x = OUR_GOAL_X + 3 * BOT_RADIUS;
                    target.y = state->awayPos[state->oppBotNearestToBall].y;
                }
                GoToPointStraight(botID, state, target, 0, true, true);
            }
            
            else
            {
                if (Vector2D<int>::distSq(state->homePos[botID], state->ballPos) < 1.5*BOT_RADIUS)
                {
                    if (state->ballPos.x > state->homePos[botID].x)
                    {
                        if (state->ballPos.y > state->homePos[botID].y)
                            Spin(botID,  MAX_BOT_OMEGA);
                        else
                            Spin(botID,  -MAX_BOT_OMEGA);
                    }
                    else
                    {
                        GoToPoint(botID, state, state->awayPos[state->oppBotNearestToBall], PI / 2, true, true);
                    }
                }
                else
                {
                    GoToPointStraight(botID, state, state->ballPos, 0, true, false);
                }
            }
        }
        else
        {
            if (!state->ballPos.x > HALF_FIELD_MAXX*1/3 && state->ballVel.x < -15)
            {
                Vector2D<int> intercept;
                intercept.x = (-HALF_FIELD_MAXX + 0.5*DBOX_WIDTH);
                intercept.y = state->ballPos.y + (state->ballVel.y / state->ballVel.x)*(intercept.x - state->ballPos.x);
                if (abs(intercept.y) > HALF_FIELD_MAXY)
                {
                    intercept.y = state->awayPos[state->oppBotNearestToBall].y;
                }
                GoToPoint(botID, state, intercept, 0, false, true); //Bot overspeeding on its way back. So set incresingspeed to false.
            }
            else if( state->ballPos.x > HALF_FIELD_MAXX - 1.5*DBOX_WIDTH && abs(state->ballPos.y) < DBOX_HEIGHT)
            {
                 if (!Vector2D<int>::distSq(state->ballPos, state->homePos[botID]) <= 1.5*pow(BOT_BALL_THRESH, 2))
                 {
                     GoToPointStraight(botID, state, state->ballPos, 0, false, true);
                 }
                 else
                 {
                     Vec2D goal;
                     goal.x = OPP_GOAL_X;
                     goal.y = 500;
                     GoToPointStraight(botID, state, goal, 0, true, true);
                 }
            }
            else if(state->ballVel.x < 0 && abs(state->ballPos.y) > DBOX_HEIGHT)
            {
                Vec2D hover;
                hover.x = HALF_FIELD_MAXX/2;
                hover.y = state->ballPos.y;
                if (hover.y > DBOX_HEIGHT)
                    hover.y = DBOX_HEIGHT;
                if (hover.y < -DBOX_HEIGHT)
                    hover.y = -DBOX_HEIGHT;
                GoToPoint(botID, state, hover, 0, true, true);
            }
        }
  }
}
