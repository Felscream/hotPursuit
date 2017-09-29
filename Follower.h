#ifndef FOLLOWER_H
#define FOLLOWER_H
#pragma once


#include "Vehicle.h"
#include "SteeringBehaviors.h"

class Follower : public Vehicle {

public:
	Follower::Follower(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		double    mass,
		double    max_force,
		double    max_speed,
		double    max_turn_rate,
		double    scale)
		: Vehicle(world,
			position,
			rotation,
			velocity,
			mass,
			max_force,
			max_speed,
			max_turn_rate,
			scale) {

	}

};
#endif