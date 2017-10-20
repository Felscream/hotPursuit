#ifndef LEADER_H
#define LEADER_H
#pragma once

#include "Vehicle.h"
#include "SteeringBehaviors.h"

class Leader : public Vehicle {

public:
	Leader::Leader(GameWorld* world, 
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

		this->SetScale(Vector2D(10, 10));
		//this->Steering()->WanderOn(); 
		
		this->SetMaxSpeed(100);
		this->SetEntityType(leader_entity_type);

	}


};

#endif
