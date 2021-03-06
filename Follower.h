#ifndef FOLLOWER_H
#define FOLLOWER_H
#pragma once


#include "Vehicle.h"
#include "SteeringBehaviors.h"
class Leader;
class Follower : public Vehicle {

private:
	bool isFollowing;
	Leader* leader;

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

		this->isFollowing = false;
		this->SetEntityType(follower_entity_type);
		this->Steering()->SeparationOn();


	}

	bool GetisFollowing() {
		return this->isFollowing;
	}

	void ToggleFolowwing() {
		this->isFollowing = !this->isFollowing;
	}

	Leader* GetLeader() { return this->leader; }
	void SetLeader(Leader* L) { this->leader = L; }
};
#endif