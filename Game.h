//Title: Game.h
//Author: Alex Strong
//Date: 3/10/2021
//Description: This is part of the No Man's Alchemy Project in CMSC 202 @ UMBC

#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard
#include <fstream>
#include "Material.h"
#include "Ship.h"

//Constants (additional constants allowed)
const string PROJ2_DATA = "proj2_data.txt"; //File constant

//No additional variables or functions allowed

class Game{
public:
  /* Name: Game() Default Constructor
  // Desc - Builds a new game by: 
  // 1. Loads all materials and their recipes into m_materials
  // 2. Asks user for their Ship's name (store in m_myShip as m_myName)
  // 3. Copies all materials from m_materials into the Ship's material array
  // Preconditions - None
  // Postconditions - m_materials is populated
  */ 
  Game(); //Default Constructor
  // Name: LoadMaterials
  // Desc - Loads each material into m_materials from file
  // Preconditions - Requires file with valid material data
  // Postconditions - m_material is populated with material structs
  void LoadMaterials();
  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu 
  // Preconditions - Player is placed in game
  // Postconditions - Continually checks to see if player has entered 5
  void StartGame();
  // Name: DisplayMyMaterials()
  // Desc - Displays the Ship's materials (Uses GetMaterial)
  // Preconditions - Player's Ship has materials
  // Postconditions - Displays a numbered list of materials
  void DisplayMaterials();
  // Name: MainMenu()
  // Desc - Displays and manages menu. Also checks win condition (Ship reaches S rank).
  // Preconditions - Player has a Ship
  // Postconditions - Returns number including exit
  int MainMenu();
  // Name: SearchMaterials()
  // Desc - Attempts to search for raw materials (must be type "raw")
  // Preconditions - Raw materials loaded
  // Postconditions - Increases quantity in Ship's possession of materials
  void SearchMaterials();
  // Name: CombineMaterials()
  // Desc - Attempts to combine known materials. If combined, quantity of material decreased
  // Preconditions - Ship is populated with materials
  // Postconditions - Increments quantity of item "made", decreases quantity of source items
  void CombineMaterials();
  // Name: RequestMaterial()
  // Desc - Requests material to use to merge
  // Preconditions - Ship has materials to try and merge
  // Postconditions - Returns integer of item selected by user
  void RequestMaterial(int &choice);
  // Name: SearchRecipes()
  // Desc - Searches recipes for two strings (name of item)
  // Preconditions - m_materials is populated
  // Postconditions - Returns int index of matching recipe
  int SearchRecipes(string, string);
  // Name: CalcScore()
  // Desc - Displays current score for Ship
  // Preconditions - Ship is populated with materials
  // Postconditions - Displays total
  void CalcScore();
  // Name: GameTitle()
  // Desc - Title for Game (Do not edit)
  // Preconditions - None
  // Postconditions - None
  void GameTitle(){
    cout << "N   N OOO   M   M  AA  N   N '' SSS    AA  L   CCC H  H EEE M   M Y   Y" << endl;
    cout << "NN  N O O   MM MM A  A NN  N    S     A  A L   C   H  H E   MM MM  Y Y " << endl;
    cout << "N N N O O   M M M AAAA N N N    SSS   AAAA L   C   HHHH EEE M M M   Y  " << endl;
    cout << "N  NN O O   M   M A  A N  NN      S   A  A L   C   H  H E   M   M   Y  " << endl;
    cout << "N   N OOO   M   M A  A N   N    SSS   A  A LLL CCC H  H EEE M   M   Y  " << endl;
  }
private:
  Ship m_myShip; //Player's Ship for the game
  Material m_materials[PROJ2_SIZE]; //All materials in the game (loaded from file)
};

#endif //Exit Header Guard
