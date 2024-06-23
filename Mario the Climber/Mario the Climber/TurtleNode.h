#pragma once
#include "Includes&usings.h"
#include "Turtle.h"

class TurtleNode 
{
public:

public:
    Turtle* turtle;
    TurtleNode* next;
    bool isActive;

    TurtleNode(Turtle* t) : turtle(t), next(nullptr), isActive(false) {}
};