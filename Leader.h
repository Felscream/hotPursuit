#ifndef LEADER_H
#define LEADER_H
#pragma once

#include "Vehicle.h"
#include "SteeringBehaviors.h"

class Leader : public Vehicle {

private:
	std::vector<Follower*> followers;
	int offsetx = 10;
	int offsety = 5;
	


public:
	bool down = false;
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
		this->Steering()->WanderOn(); 
		
		this->SetMaxSpeed(100);
		this->SetEntityType(leader_entity_type);


	}

	void AddFollower(Follower* foll) { this->followers.push_back(foll); }
	Vector2D GetPosition() {
		Vector2D vect;
		int size = this->followers.size();
		int sign = size % 2 == 0 ? 1 : -1;
		if (sign>0)
		{
			vect = Vector2D(-offsetx * (size - 1)-10, sign * (size - 1) * offsety);
		}
		else
		{
			vect = Vector2D(-offsetx * size-10, sign * size * offsety);
		}
		return vect;
	}

	void ChangeX(bool inc) {
		if (inc)
		{
			this->offsetx++;
		}
		else
		{
			this->offsetx--;
		}
		this->MajFollowers();
	}

	void ChangeY(bool inc) {
		if (inc)
		{
			this->offsety++;
		}
		else
		{
			this->offsety--;
		}
		this->MajFollowers();
	}

	void MajFollowers() {
		Vector2D vect;
		for (unsigned int i =0; i<followers.size(); i++)
		{
			if (followers[i] != NULL) {
				int sign = i % 2 == 0 ? 1 : -1;
				if (sign>0)
				{
					double x = - (double)(offsetx) * ((double)i + 1) - 10;
					double y = (double)sign * ((double)i + 1) * (double)offsety;
					vect = Vector2D(x,y);
				}
				else
				{
					double x = - (double)(offsetx) * ((double)i) - 10;
					double y = (double)sign * ((double)i) * (double)offsety;
					vect = Vector2D(x, y);
				}
				followers[i]->Steering()->OffsetPursuitOff();
				followers[i]->Steering()->OffsetPursuitOn(this, vect);
			}
		}
	}

};

#endif
