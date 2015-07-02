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
const char * const PLEASE_INPUT_RABBIT_NAME = "input the rabbit's name";
const int LOOP_TIMES = 1;

void doLoopInput(int);

int main(int argc, const char * argv[]) {
  RabbitChallenge::greeting(WELCOME_MSG);
  doLoopInput(LOOP_TIMES);
  return EXIT_SUCCESS;
}

void doLoopInput(int times) {
  Rabbit *rabbits = new Rabbit[times];
  for (int i = 0; i < times; i++) {
    RabbitChallenge().input(rabbits[i], PLEASE_INPUT_RABBIT_NAME)
    .climbUpTheWell()
    .eat()
    .acrossTheCreek()
    .foxTest()
    .finalJudgment();
  }

  for (int i = 0; i < times; i++) {
    fprintf(stdout, "rabbit's name = %s, maximum energy level = %f\n",
            rabbits[i].name.c_str(), rabbits[i].energy);
  }

  delete [] rabbits;
}




