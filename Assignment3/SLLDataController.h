//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list) {
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head) {
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL" << endl;
}

bool insertAt(SLinkedList& list, Soldier element, int pos) {
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    SLinkedList* tempL = &list;
    SoldierNode *head = list.head;
    SoldierNode* temp = new SoldierNode(element, NULL);
    if (pos == 0) {
        temp->next = tempL->head;
        tempL->head = temp;
        tempL->size++;
        return true;
    }
    if (pos < 0 || pos > list.size) return false;
    int i = 1;
    SoldierNode* p = head;
    if (pos == list.size) {
        while (p->next != NULL) p = p->next;
        p->next = temp;
        list.head = head;
        list.size++;
        return true;
    }
    else {
        while (p != NULL && i != pos) {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
        list.head = head;
        list.size++;
        return true;
    }
}

bool removeAt(SLinkedList& list, int idx) {
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= list.size) return false;
        SoldierNode* head = list.head;
        if (head == NULL) return false; 
        if (idx == 0 || head->next == NULL) {
            head = head->next;
            list.head = head;
            list.size--;
            return true;
        }
        SoldierNode* p = head;
        if (idx == list.size - 1) {
            while (p->next->next != NULL) {
                p = p->next;
            }
            p->next = NULL;
            list.size--;
            return true;
        }
        int i = 1;
        while (i != idx) {
            p = p->next;
            i++;
        }
        p->next = p->next->next; 
        list.head = head;
        list.size--;
        return true;
}

bool removeFirstItemWithHP(SLinkedList& list, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO

    SoldierNode* head = list.head;
    SoldierNode* p = head;
    for (int i = 0; i < list.size; i++) {
        if (p->data.HP == HP) {
            removeAt(list, i);
            return true;
        }
        else p = p->next;
    }

    return false;


}

int indexOf(SLinkedList& list, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    SoldierNode* head = list.head;
    SoldierNode* p = head;
    SoldierNode* temp = new SoldierNode(soldier, NULL);
    for (int i = 0; i < list.size; i++) {
        if ((p->data.HP == temp->data.HP)
            && (p->data.ID == temp->data.ID)
            && (p->data.isSpecial == temp->data.isSpecial)
            ) {
            return i;
        }
        else
            p = p->next;
    }
    return -1;
}

int size(SLinkedList& list) {
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list) {
    //Check whether the list is empty
    //TODO
    if (list.size == 0) return true; else return false;
}

void clear(SLinkedList& list) {
    //Delete all of the elements in list
    //TODO
    list.head = NULL;
    list.size = 0;
}

string getIDAt(SLinkedList& list, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= list.size) return "-1";
    else {
        SoldierNode* p = list.head;
        int i = 0;
        while (i != pos) {
            p = p->next;
            i++;
        }
        string a = p->data.ID;
        p = NULL; delete p;
        return a;
    }
}

int getHPAt(SLinkedList& list, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= list.size) return -1;
    else {
        SoldierNode* p = list.head;
        int i = 0;
        while (i != pos) {
            p = p->next;
            i++;
        }
        int hp = p->data.HP;
        p = NULL; delete p;
        return hp;
    }
}

bool setHPAt(SLinkedList& list, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos >= list.size) return false;
    else {
        SoldierNode* head = list.head;
        SoldierNode* p = head;
        int i = 0;
        while (i != pos) {
            p = p->next;
            i++;
        }
        p->data.HP = HP;
        list.head = head;
        return true;
    }
}

bool contains(SLinkedList& list, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    SoldierNode* p = list.head;
    SoldierNode* temp = new SoldierNode(soldier, NULL);
    for (int i = 0; i < list.size; i++) {
        if ((p->data.HP == temp->data.HP)
            && (p->data.ID == temp->data.ID)
            && (p->data.isSpecial == temp->data.isSpecial)
            ) {
            p = NULL; delete p;
             delete temp;      
            return true;
        }
        else
            p = p->next;
    }
    p = NULL;  delete p;
    delete temp;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
