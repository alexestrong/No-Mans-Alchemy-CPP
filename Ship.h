//Title: Ship.h
//Author: Alex Strong
//Date: 3/10/2021
//Description: This is part of the No Man's Alchemy Project in CMSC 202 @ UMBC

// The Ship class should have no cout statements

#ifndef SHIP_H //Include/Header Guard
#define SHIP_H //Include/Header Guard

#include "Material.h" //Include for the material struct
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Constants (allowed to add more as needed)
const int PROJ2_SIZE = 62;

// class - allowed to add HELPER functions only
class Ship{
 public:
  // Name: Ship() - Default Constructor
  // Desc: Used to build a new Player Ship
  // Preconditions - Requires default values
  // Postconditions - Creates a new Player Ship
  Ship();
  // Name: Ship(name) - Overloaded constructor
  // Desc - Used to build a new Player Ship
  // Preconditions - Requires name
  // Postconditions - Creates a new Player Ship
  Ship(string name);
  // Name: GetName()
  // Desc - Getter for the Player Ship's name
  // Preconditions - Player Ship exists
  // Postconditions - Returns the name of the Player Ship
  string GetName();
  // Name: SetName(string)
  // Desc - Allows the user to change the name of the Player Ship
  // Preconditions - Player Ship exists
  // Postconditions - Sets name of Player Ship
  void SetName(string name);
  // Name: CheckMaterial(Material)
  // Desc - Checks to see if the Ship has a material
  // Preconditions - Ship already has materials
  // Postconditions - Returns index of material if the Ship has it else -1
  int CheckMaterial(Material);
  // Name: AddMaterial(string)
  // Desc - Inserts a material into the Ship's list of materials
  // Preconditions - Ship exists
  // Postconditions - Add a material to the Ship's m_myMaterials with a quantity of 0
  void AddMaterial(Material);
  // Name: IncrementQuantity(Material)
  // Desc - Adds quantity to list of materials the Ship knows
  // Preconditions - Ship exists
  // Postconditions - Increases quantity of material for the Ship
  void IncrementQuantity(Material);
  // Name: DecrementQuantity(Material)
  // Desc - Reduces quantity from the Ship's inventory with true, if no quantity false
  // Preconditions - A Ship exists
  // Postconditions - Reduces quantity of material for the Ship
  bool DecrementQuantity(Material);
  // Name: CheckQuantity(Material)
  // Desc - Checks to see if quantity of two merge materials are available
  // Preconditions - Ship exists with materials
  // Postconditions - Returns true if both are available (including two of same material)
  bool CheckQuantity(Material, Material);
  // Name: GetMaterial(int)
  // Desc - Checks to see if the Ship has any materials
  // Preconditions - The Ship already has materials
  // Postconditions - Returns material at specific index
  Material GetMaterial(int);
  // Name: IncRank()
  // Desc - Increments the rank of the ship to the next rank.
  // Preconditions - Ship exists and has a rank
  // Postconditions - m_shipRank will move to the next character
  void IncRank();
  // Name: GetRank()
  // Desc - Checks to see what the current ship's rank is
  // Preconditions - The ship exists
  // Postconditions - Returns the character indicating the rank of the ship
  char GetRank();

private:
  string m_shipName; //Name of the Ship
  char m_shipRank; // Rank of the Ship, can be (D, C, B, A, or S)
  int m_numMaterials; //Current number of items in m_myMaterials known to the Player Ship
  Material m_myMaterials[PROJ2_SIZE] = {}; //List of materials known to this Ship
};

#endif //Exit Header Guard
