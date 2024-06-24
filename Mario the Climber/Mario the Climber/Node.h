#pragma once
#include "Includes&usings.h"

class Node
{
private:

	friend class Stack;
	friend class Tail;

	Vector2f _position;
	Sprite* _sprite;
	Texture* _texture;
	string _colorNode;
	Node* _next;

public:

	Node(Vector2f pos, string color);

	void Draw(RenderWindow& window);
	void InitNode();
	Sprite GetSprite(); 
	void Move(int vel); 
	float GetPosX(); 
	void SetTexture(string texture); 
	void SetPosition(Vector2f pos);
	String GetColor(); 
};