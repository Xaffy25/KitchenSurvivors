#pragma once

#include "GameObject.h"
#include <vector>
#include "Projectile.h"
//#include "../Weapons/Weapon.h"
#include "../Common.h"
#include <memory>

class Weapon;
class Player : public GameObject
{
public:
	Player(glm::vec2 pos, glm::vec2 size, Texture2D* sprite, Shader* shader, RenderLayer layer, std::vector<std::shared_ptr<Projectile>>* pprojptr,glm::vec2* _pos, glm::vec3 color = glm::vec3(1.0f), float rotation = 0.0f);
	glm::vec2* _pos;
	void TakeDamage(float amount);
	void UpdateCooldowns(float dt);
	void GetXp(int type);
	PlayerStats stats;
	Texture2D* NormalMap;

	unsigned int Level = 0;
	float LvlProgress = 0;
	float Health = stats.MaxHealth;
	bool Alive = true;
	unsigned int Kills;
	Weapon *weapons[6];

	float xp;
	float xpToLvl;
private:

	float InvulnerabilityCD;
	std::vector<std::shared_ptr<Projectile>>* PlayerProjectilesPtr;

	
};
