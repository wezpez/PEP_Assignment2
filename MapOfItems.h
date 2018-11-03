#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

// TODO: your code goes here

class MapOfItems {

private:
    vector<Item> items;

public:

    void addItem (const Item & item){
        items.push_back(item);
    }

    int size(){
        return items.size();
    }

    const vector<Item>& getItems (){
        return items;
    }

    const vector<Item*> getTour (const double walkingSpeed){

        vector<Item*> tour;

        //if there are no items return an empty tour vector
        if (items.empty()){
            return tour;
        }

        //setting the current time to the first available item's time
        double currentTime = items[0].getTime();

        //sets currentLocation to the first available item
        Item* currentLocation = &items[0];

        //add the first item to the tour
        tour.push_back(&items[0]);

        //set the first item travelled bool to true
        items[0].setTravelled(true);


        while (currentTime < 3600 && (tour.size() != items.size())){

            Item* nextLocation = nullptr;
            double bestTime = 10000; //start with a huge number


            for (int i = 0; i < items.size(); i++){

                if (!items[i].getTravelled()){

                    double distance = currentLocation->distanceTo(items[i]);

                    double visitTime = (distance/walkingSpeed);

                    //check to see if we will be able to reach the item in time
                    if ((currentTime + visitTime) < (items[i].getTime() + 900)) {

                        //if we arrive early we have to wait for the item to become available
                        if ((currentTime + visitTime) < (items[i].getTime())){
                            visitTime = items[i].getTime() - currentTime;
                        }

                        //if this new time is the smallest then make it the new best time
                        if (visitTime < bestTime){
                            nextLocation = &items[i];
                            bestTime = visitTime;
                        }
                    }
                }
            }

            if (nextLocation != nullptr && currentTime + bestTime < 3600){
                tour.push_back(nextLocation);
                nextLocation->setTravelled(true);
                currentLocation = nextLocation;
            }

            //if it doesnt find any possible nextLocation then it will add 10000 to the currentTime and finish the while loop
            currentTime = currentTime + bestTime;


        }

        for (int i = 0; i < items.size(); i++){
            items[i].setTravelled(false);
        }

        return tour;

    }




};



// don't write any code below this line

#endif

