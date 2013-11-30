//
//  Airline.cpp
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "Airline.h"

int Airline::diffCompare(){
    int diffHour = (arrivalTime.getHours() - departureTime.getHours()) + arrivalDay*24;
    int diffMins = arrivalTime.getMintues() - departureTime.getMintues();
    
    if (diffMins < 0) {
        diffHour--;
        diffMins += 60;
    } else if (diffMins >= 60) {
        diffHour++;
        diffMins -= 60;
    }
    int totalDiff = diffHour*60 + diffMins;
    return totalDiff;
}

int Airline::waitTime(SGTime currentTime) {
    int diffHour = departureTime.getHours() - currentTime.getHours();
    int diffMins = departureTime.getMintues() - currentTime.getMintues();
    
    if (diffHour < 0) {
        diffHour += 24;
    }
    
    if (diffMins < 0) {
        diffHour--;
        diffMins += 60;
    } else if (diffMins >= 60) {
        diffHour++;
        diffMins -= 60;
    }
    int totalWait = diffHour*60 + diffMins;
    
    if (totalWait < 60) {
        totalWait += 24*60;
    }
    return totalWait;
}


