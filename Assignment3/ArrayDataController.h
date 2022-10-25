//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array) {
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout << "[";
    for (int i = 0; i < array.size; i++) {
        std::cout << array.arr[i].ID << " ";
    }
    std::cout << "]"<<endl;
}

void initArray(Array& array, int cap) {
    //Init a new array with capacity equals to cap
    //TODO
    if (cap == 0) {
        array.size = 0;
        array.arr = new Soldier[1];
        array.capacity = -1;
    }
    else {
        array.size = 0;
        array.arr = new Soldier[cap];
        array.capacity = cap;
    } 
}

bool insertAt(Array& array, Soldier element, int pos) {
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos == 0 && array.capacity == -1) {
        initArray(array, 10);
        array.arr[0] = element;
        array.size++;
        return true;
    }
    if (pos < 0 || pos >= array.capacity) return false; //out-range position
    else {
        if (pos == 0 || array.arr[pos - 1].HP != -1) {
            if (array.arr[pos].HP == -1) //blank slot -> fill
            {
                array.arr[pos] = element;
                array.size++;
                return true;
            }
            else {// filled slot -> expand ->  push -> fill
                if(array.size == array.capacity) 
                {
                    int cap = array.capacity;
                    Soldier* newCapArr = array.arr;
                    array.arr = new Soldier[int((array.capacity + 1) * 1.5)];
                    for (int i = 0; i < cap; i++) {
                        array.arr[i] = newCapArr[i];
                    }
                    delete[] newCapArr;
                    array.capacity = int((cap+1) * 1.5);
                }// expand

                for (int i = array.capacity - 1; i > pos; i--) 
                    array.arr[i] = array.arr[i - 1];             
                array.arr[pos].HP = -1;
                 // push
                array.arr[pos] = element;
                array.size++;
                return true;
            }
        }
        else return false;
    }
}

bool removeAt(Array& array, int idx) {
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= array.capacity) return false;
    else {
        if (array.arr[idx].HP == -1) return false;
        else {
            if (idx == array.size - 1) {
                array.arr[idx].HP = -1;
                array.arr[idx].ID = "";
                array.arr[idx].isSpecial = false;
                array.size--;
                return true;
            }
            else {
                int size = array.size;
                for (int i = idx; i < size - 1; i++) {
                    array.arr[i].HP = array.arr[i + 1].HP;
                    array.arr[i].ID = array.arr[i + 1].ID;
                    array.arr[i].isSpecial = array.arr[i + 1].isSpecial;
                }
                array.arr[size-1].HP = -1;
                array.arr[size-1].ID = "";
                array.arr[size-1].isSpecial = false;
                array.size--;
                return true;
            }
        }
    }
    return false;
}

bool removeFirstItemWithHP(Array& array, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    Soldier blank = Soldier(-1, false, "");
    for (int i = 0; i < array.capacity; i++) {
        if (array.arr[i].HP == HP) {
            if (i == array.size - 1) {
                array.arr[i].HP = -1;
                array.arr[i].ID = "";
                array.arr[i].isSpecial = false;
                array.size--;
                return true;
            }
            else {
                int size = array.size;
                for (int j = i; j < size - 1; j++) {
                    array.arr[j].HP = array.arr[j + 1].HP;
                    array.arr[j].ID = array.arr[j + 1].ID;
                    array.arr[j].isSpecial = array.arr[j + 1].isSpecial;
                }
                array.arr[size - 1].HP = -1;
                array.arr[size - 1].ID = "";
                array.arr[size - 1].isSpecial = false;
                array.size--;
                return true;
            }     
        }
    }
    return false;
}



int indexOf(Array& array, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for (int i = 0; i < array.capacity; i++) {
        if (array.arr[i].HP == soldier.HP
            && array.arr[i].ID == soldier.ID
            && array.arr[i].isSpecial == soldier.isSpecial)
            return i;
    }
    return -1;
}

int size(Array& array) {
    //Return size of the array
    //TODO
    return array.size;
}

bool empty(Array& array) {
    //Check whether the array is empty
    //TODO
    if (array.size == 0) return true; else return false;
}

string getIDAt(Array& array, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= array.capacity) return "-1";
    if (array.arr[pos].ID == "") return "-1";
    else return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= array.capacity) return -1;
    else return array.arr[pos].HP;
}

bool setHPAt(Array& array, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos >= array.size) return false;
    if (array.arr[pos].HP == -1) return false;
    else {
        array.arr[pos].HP = HP;
        return true;
    }
}

void clear(Array& array) {
    //Delete all of the elements in array
    //TODO
    array.capacity = 0;
    array.size = 0;
    array.arr = NULL;
}

bool contains(Array& array, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    for (int i = 0; i < array.capacity; i++) {
        if (array.arr[i].HP == soldier.HP
            && array.arr[i].ID == soldier.ID
            && array.arr[i].isSpecial == soldier.isSpecial)
            return true;
    }
    return false;
}

//You can write your own functions here
void ensureCapacity(Array& array, int newCap) {
    //Extend the capacity of the array
    //TODO
    
}

//End your own functions

#endif /* ArrayDataController_h */
