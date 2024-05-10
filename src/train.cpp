// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    Cage{ false, nullptr, nullptr };
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool lamp) {
    if (!first) {
        first = new Cage;
        first->light = lamp;
        first->prev = first;
        first->next = first;
    } else {
        Cage* temp = new Cage;
        temp->prev = first->prev;
        temp->next = first;
        first->prev->next = temp;
        first->prev = temp;
    }
}
int Train::getOpCount() {
    return countOp;
}
int Train::getLength() {
    int glav = 0;
    int schet1 = 0;
    int schet2 = 0;
    Cage* q = first;
    if (q->light == false) {
        q->light = true;
        while (true) {
            q->light = true;
            q = q->next;
            schet1++;
            while (true) {
                while (q->light != true) {
                    schet1++;
                    q = q->next;
                }
                q = q->prev;
                schet2++;
                while (q->light != true) {
                    schet2++;
                    q = q->prev;
                }
                if (schet2 == schet1) {
                    countOp = schet1 * 2;
                    return schet1;
                }
            }
        }
    } else {
        do {
            q = q->next;
            schet1++;
            glav++;
            if (q->light) {
                q->light = false;
                for (int j = schet1; j > 0; j--) {
                    q = q->prev;
                    glav++;
                }
                if (!q->light) {
                    countOp = glav;
                    return schet1;
                } else {
                    schet1 = 0;
                }
            }
        } while (true);
    }
}

