//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier) {
    //Return true if push successfully, false otherwise
    //TODO
    int pos = array.size;
    if (array.capacity == 0) initArray(array, 10);
    if(array.size == array.capacity) {
        int cap = array.capacity;
        Soldier* newCapArr = array.arr;
        array.arr = new Soldier[int(array.capacity * 1.5)];
        for (int i = 0; i < cap; i++) {
            array.arr[i] = newCapArr[i];
        }
        delete[] newCapArr;
        array.capacity = int(cap * 1.5);
    }
    if (insertAt(array, soldier, pos) == true) return true; else return false;
}

bool pop(Array& array) {
    //Return true if pop successfully, false otherwise
    //TODO
    int pos = array.size - 1;
    if (removeAt(array, pos) == true) return true;
    else return false;
}

Soldier top(Array& array) {
    //TODO
    return array.arr[array.size - 1];
    return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier) {
    //Return true if enqueue successfully, false otherwise
    //TODO
    SLinkedList* tempL = &list;
    SoldierNode* temp = new SoldierNode(soldier, NULL);
    if (list.head == NULL) { 
        tempL->head = temp;
        tempL->size++;
        temp = NULL;
        delete temp;
        return true;
    }
    else {
        SoldierNode* p = tempL->head;
        while (p->next != NULL) p = p->next;
        p->next = temp;
        tempL->size++;
        p = NULL;
        delete p;
        return true;
    }
}

bool dequeue(SLinkedList& list) {
    //Return true if dequeue successfully, false otherwise
    //TODO
    SLinkedList* tempL = &list;
    if (tempL->head == NULL) return false; 
    tempL->head = tempL->head->next;
    tempL->size--;
    return true;
}

Soldier front(SLinkedList& list) {
    //TODO
    return list.head->data;
    return Soldier();
    //Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list) {
    //TODO
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SLinkedList* tempL = &list;
    SoldierNode* cur = tempL->head;
    SoldierNode* pre = NULL, * next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    tempL->head = pre;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2) {
    //TODO
    SoldierNode* head1 = list1.head;
    SoldierNode* head2 = list2.head;
    SoldierNode* a1 = head1; SoldierNode* a2 = head2;
    SLinkedList newList;
    for (int i = 1; i <= list1.size + list2.size; i++) {
        if (a1->data.HP == a2->data.HP) { //so sanh hp
            if (a1->data.isSpecial == a2->data.isSpecial) { // so sanh Sp
                if (a1->data.ID <= a2->data.ID) { // so sanh id
                    enqueue(newList, a1->data);
                    a1 = a1->next;
                    if (a1 == NULL) {
                        while (a2 != NULL) {
                            enqueue(newList, a2->data);
                            a2 = a2->next;
                        }
                        break;
                    }
                }
                else {
                    enqueue(newList, a2->data);
                    a2 = a2->next;
                    if (a2 == NULL) {
                        while (a1 != NULL) {
                            enqueue(newList, a1->data);
                            a1 = a1->next;
                        }
                        break;
                    }
                }
            }
            else if (a1->data.isSpecial == true && a2->data.isSpecial == false) {
                enqueue(newList, a2->data);
                a2 = a2->next;
                if (a2 == NULL) {
                    while (a1 != NULL) {
                        enqueue(newList, a1->data);
                        a1 = a1->next;
                    }
                    break;
                }
            }
            else if (a1->data.isSpecial == false && a2->data.isSpecial == true) {
                enqueue(newList, a1->data);
                a1 = a1->next;
                if (a1 == NULL) {
                    while (a2 != NULL) {
                        enqueue(newList, a2->data);
                        a2 = a2->next;
                    }
                    break;
                }
            }
        }
        else if(a1->data.HP > a2->data.HP){
            enqueue(newList, a2->data);
            a2 = a2->next;
            if (a2 == NULL) {
                while (a1 != NULL) {
                    enqueue(newList, a1->data);
                    a1 = a1->next;
                }
                break;
            }
        }
        else if (a1->data.HP < a2->data.HP) {
            enqueue(newList, a1->data);
            a1 = a1->next;
            if (a1 == NULL) {
                while (a2 != NULL) {
                    enqueue(newList, a2->data);
                    a2 = a2->next;
                }
                break;
            }
        }
    }
    return newList;
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
