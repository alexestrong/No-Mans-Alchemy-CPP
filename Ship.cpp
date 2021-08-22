/*
 * File:          Ship.cpp
 * Project:       CMSC 202 Project 2, Spring 2021
 * Author:        Alex Strong
 * Date:          3/10/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Ship class
 *                in order to run the Ship functions
 *                and Ship variables
 *
 */


#include "Ship.h"

//Default constructor
Ship::Ship() {
    m_shipName = "Unknown";
    m_shipRank = 'D';
    m_numMaterials = 0;
}


//Overloaded Constructor
Ship::Ship(string name) {
    m_shipName = name;
    m_shipRank = 'D';
    m_numMaterials = 0;
}


//Getter Ship Name
string Ship::GetName() {
    return m_shipName;
}


//Setter Ship Name
void Ship::SetName(string name) {
    m_shipName = name;
}


int Ship::CheckMaterial(Material material) {
    int foundAtIndex = -1;
    for (int i = 0; i < PROJ2_SIZE; i++){
        if (m_myMaterials[i].m_name == material.m_name){
            foundAtIndex = i;
        }
    }
    return foundAtIndex;
}


void Ship::AddMaterial(Material material) {
    material.m_quantity = 0;
    //if (material.m_type != "unique")
        //material.m_quantity = 100;
    m_myMaterials[m_numMaterials] = material;
    m_numMaterials++;
}


void Ship::IncrementQuantity(Material material) {
    m_myMaterials[CheckMaterial(material)].m_quantity++;
}


bool Ship::DecrementQuantity(Material material) {
    if (m_myMaterials[CheckMaterial(material)].m_quantity > 0){
        m_myMaterials[CheckMaterial(material)].m_quantity--;
        return true;
    }else{
        return false;
    }
}


bool Ship::CheckQuantity(Material materialOne, Material materialTwo) {
    if ((m_myMaterials[CheckMaterial(materialOne)].m_quantity > 0) && (m_myMaterials[CheckMaterial(materialTwo)].m_quantity > 0))
        return true;
    else
        return false;
}


Material Ship::GetMaterial(int specificIndex) {
    return m_myMaterials[specificIndex];
}


void Ship::IncRank() {
    //Bool to make sure rank only upgrades once per call
    bool completedUpgrade = false;

    if(m_shipRank == 'D'){
        m_shipRank = 'C';
        completedUpgrade = true;
    }
    if((m_shipRank == 'C' && !completedUpgrade)){
        m_shipRank = 'B';
        completedUpgrade = true;
    }
    if((m_shipRank == 'B' && !completedUpgrade)){
        m_shipRank = 'A';
        completedUpgrade = true;
    }
    if((m_shipRank == 'A' && !completedUpgrade)){
        m_shipRank = 'S';
        completedUpgrade = true;
    }
}


char Ship::GetRank() {
    return m_shipRank;
}