//
//  main.cpp
//  RabbitJourney
//
//  Created by 許佑任 on 2015/6/30.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include "RabbitChallenge.h"

using namespace std;

const char * const WELCOME_MSG = "The rabbit starts its journey.";

Rabbit g_rabbit;

int main(int argc, const char * argv[]) {
  RabbitChallenge::greeting(WELCOME_MSG);
  RabbitChallenge()
    .input(g_rabbit)
    .climbUpTheWell()
    .eat()
    .acrossTheCreek()
    .foxTest()
    .finalJudgment();
  return EXIT_SUCCESS;
}



