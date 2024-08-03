#include "GameObject.h"

GameObject::GameObject()
	: Position(0.0f,0.0f), Size(1.0f,1.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color,float rotation, glm::vec2 velocity)
	: Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(rotation), Sprite(sprite), IsSolid(false), Destroyed(false) { }

void GameObject::Draw(SpriteRenderer& renderer)
{
	renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
void GameObject::Draw(SpriteRenderer& renderer, glm::vec2 PlayerPosition)
{
	renderer.DrawSprite(this->Sprite, this->Position - PlayerPosition, this->Size, this->Rotation, this->Color);
}
void GameObject::UpdatePosition(float dt)
{
	Position += Velocity * dt;
}