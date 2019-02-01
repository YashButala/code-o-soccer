#pragma once
#include "skills.h"
#include "Attacker.hpp"
#include "Defender.hpp"
#include "GoalKeeper.hpp"

// Change your team color here (BLUE_TEAM/YELLOW_TEAM)face

Simulator::TeamColor teamColor = Simulator::YELLOW_TEAM;

// Make usingDebugger is false when playing against an opponent
bool usingDebugger = true;

namespace MyStrategy
{
  // Write your strategy here in game function.
  // You can also make new functions and call them from game function.
  void game(BeliefState *state)
  {
	  /*
	  int x = state->ballPos.x;
	  int y = state->ballPos.y;
	  if (x <= HALF_FIELD_MAXX * 2 / 5.0 && x >= -HALF_FIELD_MAXX / 5.0)
	  {
		  attacker(state, 2);
		  defender(state, 1);
		  goalkeeper(state, 0);
	  }
	  else if (x > HALF_FIELD_MAXX * 2 / 5)
	  {
		  attacker(state, state->ourBotNearestToBall);
		  attacker(state, 3 - state->ourBotNearestToBall);
		  goalkeeper(state, 0);
	  }
	  else if (x < -HALF_FIELD_MAXX * 1 / 5)
	  {
		  defender(state, 1);
		  defender(state, 2);
		  goalkeeper(state, 0);
	  }
	  */
	  attacker(state, 2);
	  defender(state, 1);
	  goalkeeper(state, 0);
	  
  }
}