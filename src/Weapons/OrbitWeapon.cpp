#include "OrbitWeapon.h"

extern std::vector<std::shared_ptr<Projectile>> PlayerProjectiles;


OrbitWeapon::OrbitWeapon(std::string _sprite, std::string _name, PlayerStats* _stats, glm::vec2* _pos)
{
	this->sprite = _sprite;
	this->id = 1;
	this->name = _name;
	this->level = 1;
	this->p_Stats = _stats;
	this->p_PlayerPosition = _pos;
}

void OrbitWeapon::Shoot()
{

	Texture2D tex = ResourceManager::GetTexture(this->sprite);
	
	std::vector<std::shared_ptr<Projectile>> batch;

	int k = 0;
	int n = this->p_Stats->projectileCount;
	int r = 100;
	glm::vec2 playerpos = *p_PlayerPosition;
	for (; k < n; k++)
	{
		float tk = (2 * glm::pi<float>() * k) / n;
		glm::vec2 temppos = glm::vec2(cos(tk)*r, r*sin(tk)) + center + *p_PlayerPosition;
		
		float rotation = -atan2(cos(tk), sin(tk)) + glm::pi<float>()/2;
		
		PlayerProjectiles.push_back(std::make_unique<Projectile>(
			temppos,
			glm::vec2(tex.Width,tex.Height),
			tex,
			1,
			glm::vec3(1.0f),
			rotation,
			0.0f,
			glm::vec2(0.0f),
			10
		));
		batch.push_back(PlayerProjectiles.back());
	}

	activeProjectiles.push_back(batch);
}

void OrbitWeapon::Update(float dt)
{
	
	for (int i = 0; i < this->activeProjectiles.size();i++)
	{
		std::vector<std::shared_ptr<Projectile>> pl = this->activeProjectiles[i];
		int k = 0;
		int n = pl.size();
		int r = 100;
		
		for (auto p : pl)
		{
			float lt = p->lifetime;
			float tk = 2 * glm::pi<float>() * k / n;
			float rotation = -atan2(cos(tk-lt), sin(tk-lt)) + glm::pi<float>() / 2;
			p->Position = glm::vec2(cos(tk - lt) * r, r * sin(tk - lt)) + center + *p_PlayerPosition;
			p->Rotation = rotation;
			k++;
		}
	}
}