/*
 * File:          Game.cpp
 * Project:       CMSC 202 Project 2, Spring 2021
 * Author:        Alex Strong
 * Date:          3/10/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Game class
 *                in order to run the Game functions
 *                and Game variables
 *
 */

#include "Game.h"

//Game Constructor
Game::Game() {
    string tempName;

    GameTitle();
    LoadMaterials();

    cout << "What would you like your ship to be called?" << endl;
    getline(cin, tempName, '\n');
    m_myShip.SetName(tempName);

    for (int i = 0; i < PROJ2_SIZE; i++) {
        m_myShip.AddMaterial(m_materials[i]);
    }
}


void Game::LoadMaterials() {
    string name, type, materialOne, materialTwo;
    const char DELIMITER = ',';
    int count = 0;
    int quantity = 0;

    ifstream infile("proj2_data.txt");
    if (infile.is_open()){
        while (count < PROJ2_SIZE){
            getline(infile, name, DELIMITER);
            getline(infile, type, DELIMITER);
            getline(infile, materialOne, DELIMITER);
            getline(infile, materialTwo);
            m_materials[count] = Material(name, type, materialOne, materialTwo, quantity);

            count++;
        }
    }else{
        cout << "Error opening file." << endl;
    }
}


void Game::StartGame() {
    int menuSelector = 0;
    bool gameDone = false;

    if (m_myShip.GetRank() == 'S')
        gameDone = true;

    do {
        menuSelector = MainMenu();
        switch (menuSelector) {
            case 1:
                DisplayMaterials();
                break;
            case 2:
                SearchMaterials();
                break;
            case 3:
                CombineMaterials();
                break;
            case 4:
                CalcScore();
                break;
            case 5:
                break;
            default:
                cout << "Unknown entry!" << endl;
                break;
        }
    }while(menuSelector != 5 || gameDone);

    if (m_myShip.GetRank() == 'S')
        cout << "Congrats you have won the game and made it off the asteroid!" << endl;
    else
        cout << "You have quit the game. Bye!" << endl;

}


void Game::DisplayMaterials() {
    int tempCounter = 1;

    for (int i = 0; i < PROJ2_SIZE; i++){
        cout << tempCounter << ". ";
        cout << m_myShip.GetMaterial(i).m_name << " " << m_myShip.GetMaterial(i).m_quantity << endl;
        tempCounter++;
    }
}


int Game::MainMenu() {
    int userInput = 0;

    do {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Display your Ship's materials." << endl;
        cout << "2. Search for raw materials." << endl;
        cout << "3. Attempt to merge materials." << endl;
        cout << "4. See score." << endl;
        cout << "5. Quit." << endl;
        cin >> userInput;
    } while (userInput > 5 || userInput < 1);

    if (m_myShip.GetRank() == 'S')
        userInput = 5;

    return  userInput;
}


void Game::SearchMaterials() {
    int indexLastRawMaterial = 0;
    int randomIndexRawMaterial = 0;

    //Finds the number of raw material in the list
    for(int i = 0; i < PROJ2_SIZE; i++){
        if (m_materials[i].m_type == "raw")
            indexLastRawMaterial = i;
    }
    //Increments for later use in conjunction with the rand() line
    indexLastRawMaterial++;

    //Picks a random number from 0-(Number of raw materials)
    randomIndexRawMaterial = rand() % indexLastRawMaterial;

    m_myShip.IncrementQuantity(m_materials[randomIndexRawMaterial]);
    cout << m_materials[randomIndexRawMaterial].m_name << " found!" << endl;
}


void Game::CombineMaterials() {
    int choiceOne = 1;
    int choiceTwo = 1;
    int recipeValueHolder = -1;

    RequestMaterial(choiceOne);
    RequestMaterial(choiceTwo);

    //Confirms there is enough quantity of both materials on the ship
    if (m_myShip.CheckQuantity(m_materials[choiceOne], m_materials[choiceTwo])){
        recipeValueHolder = SearchRecipes(m_materials[choiceOne].m_name, m_materials[choiceTwo].m_name);
        //Tries to find recipe. If no recipe found value will be a negative
        if (recipeValueHolder >= 0){
            //Checks to see if unique item has already been crafted
            if ((m_materials[recipeValueHolder].m_type == "unique") && (m_myShip.GetMaterial(recipeValueHolder).m_quantity > 0)) {
                cout << "You have already crafted the unique item of " << m_materials[recipeValueHolder].m_name << "." << endl;
            }else{
                m_myShip.DecrementQuantity(m_materials[choiceOne]);
                m_myShip.DecrementQuantity(m_materials[choiceTwo]);
                m_myShip.IncrementQuantity(m_materials[recipeValueHolder]);

                cout << m_materials[choiceOne].m_name << " combined with " << m_materials[choiceTwo].m_name;
                cout << " to make " << m_materials[recipeValueHolder].m_name << "! (";
                cout << m_myShip.GetMaterial(recipeValueHolder).m_type << ")" << endl;

                if (m_materials[recipeValueHolder].m_type == "unique") {
                    m_myShip.IncRank();
                    cout << "Your rank has now increased to " << m_myShip.GetRank() << "!" << endl;
                }
            }
        }else{
            cout << "There is no recipe for these two materials." << endl;
        }
    }else{
        cout << "You do not have enough materials to use for crafting." << endl;
    }

}


void Game::RequestMaterial(int &choice) {
    cout << "Enter the number of the material you would like to merge." << endl;
    cout << "To list known materials enter -1" << endl;
    cin >> choice;

    //INPUT VALIDATION
    while(choice <= 0 || choice > PROJ2_SIZE) {
        if (choice == -1){
            DisplayMaterials();
            cout << "Enter the number of the material you would like to merge." << endl;
            cout << "To list known materials enter -1" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }else {
            cout << "Please enter a valid number:" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
    }
    //Decrements to account for index values which starts at 0 rather than 1
    choice--;
}


int Game::SearchRecipes(string stringOne, string stringTwo) {
    for (int i = 0; i < PROJ2_SIZE; i++) {
        //Double if statements to account for the recipe ingredients being in either the first or second spot
        if ((m_materials[i].m_material1 == stringOne) || (m_materials[i].m_material1 == stringTwo)) {
            if (m_materials[i].m_material2 == stringOne || m_materials[i].m_material2 == stringTwo) {
                return i;
            }
        }
    }
    //If no recipe found, returns a negative which is interpreted in RequestMaterials function
    return -1;
}

void Game::CalcScore() {
    cout << "*** The Ship ***" << endl;
    cout << m_myShip.GetName() << endl;
    cout << "Ship Rank " << m_myShip.GetRank() << endl;
}

