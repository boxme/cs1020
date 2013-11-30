//
//  SGTime.cpp
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "SGTime.h"

int SGTime::Compare(SGTime Time) {
    if (hours > Time.getHours()) {
        return 1;
    }
    if (hours < Time.getHours()) {
        return 0;
    }
    if (minutes > Time.getMintues()) {
        return 1;
    }
    else
        return 0;
}

int SGTime::convert() {
    return hours*60 + minutes;
}