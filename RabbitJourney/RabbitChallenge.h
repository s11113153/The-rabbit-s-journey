//
//  RabbitChallenge.h
//  RabbitJourney
//
//  Created by 許佑任 on 2015/6/30.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#ifndef __RabbitJourney__RabbitChallenge__
#define __RabbitJourney__RabbitChallenge__

#include <stdio.h>
#include "Rabbit.h"
#include <iostream>
#include <cstring>

#endif /* defined(__RabbitJourney__RabbitChallenge__) */

class RabbitChallenge {
private:
  Rabbit mRabbit;
  enum Vegetable {
    SPINACH = 0,
    POTATO = 1,
    CARROT = 2
  };

public:
  static void greeting(const char * msg);
  RabbitChallenge & input(Rabbit rabbit);
  RabbitChallenge & climbUpTheWell();
  RabbitChallenge & eat();
  RabbitChallenge & acrossTheCreek();
  RabbitChallenge & foxTest();
  RabbitChallenge & finalJudgment();
};

