//
//  RabbitChallenge.cpp
//  RabbitJourney
//
//  Created by 許佑任 on 2015/6/30.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include "RabbitChallenge.h"

using std::cout;
using std::endl;
using std::cin;

void RabbitChallenge::greeting(const char *msg) {
 fprintf(stdout, "%s\n", msg);
}


RabbitChallenge & RabbitChallenge::input(Rabbit rabbit) {
  cout << "initial input data" << endl;
  cin >> rabbit.depth;
  cin >> rabbit.K_meter;
  cin >> rabbit.M_meter;
  cin >> rabbit.energy;
  cin >> rabbit.calories;
  cin >> rabbit.creek_width;
  cin >> rabbit.factor;
  cin >> rabbit.high_threshold;
  cin >> rabbit.low_threshold;
  fprintf(stdout,
          "d = %f, k = %f, m = %f, e = %f, c = %f, w = %f, f = %f, ht = %f, lt = %f\n",
          rabbit.depth, rabbit.K_meter, rabbit.M_meter, rabbit.energy, rabbit.calories,
          rabbit.creek_width, rabbit.factor, rabbit.high_threshold, rabbit.low_threshold);
  
  mRabbit = rabbit;
  return *this;
}


RabbitChallenge & RabbitChallenge::climbUpTheWell() {
  while (true) {
    int current_depth = mRabbit.depth * -1;
    if (current_depth > 0 || mRabbit.energy < 0) break;
    int max_climbing = mRabbit.energy / mRabbit.calories;
    int hour_climbing = mRabbit.K_meter;
    int slide_climbing = mRabbit.M_meter;

    if (max_climbing < hour_climbing) {
      mRabbit.depth -= max_climbing;
      mRabbit.energy -= max_climbing * mRabbit.calories;
    } else {
      mRabbit.depth -= (hour_climbing + slide_climbing);
      mRabbit.energy -= hour_climbing * mRabbit.calories;
    }
  }
  fprintf(stdout, "d = %f, k = %f, m = %f, e = %f, c = %f\n",
          mRabbit.depth, mRabbit.K_meter, mRabbit.M_meter, mRabbit.energy, mRabbit.calories);
  return *this;
}


RabbitChallenge & RabbitChallenge::eat() {
  cout << "What to eat? Energize." << endl;
  cout << "case 0: spinach\n" <<
          "case 1: potato\n" <<
          "case 2: carrot"   << endl;
  int food;
  cin >> food;
  int add_energy;
  switch (food) {
    case RabbitChallenge::Vegetable::SPINACH:
      add_energy = 300;
      break;
    case RabbitChallenge::Vegetable::POTATO:
      add_energy = 600;
      break;
    case RabbitChallenge::Vegetable::CARROT:
      add_energy = 800;
      break;
    default:
      cout << "Fatel Error Input" << endl;
      exit(EXIT_FAILURE);
  }
  mRabbit.energy += add_energy;
  cout << mRabbit.energy << endl;
  return *this;
}

RabbitChallenge & RabbitChallenge::acrossTheCreek() {
  cout << "percentage p(0.0 ~ 1.0) of current energy to be used in the jump" << endl;
  float p;
  cin >> p;
  float jump_distance = p * mRabbit.energy * mRabbit.factor;
  if (jump_distance == mRabbit.creek_width) mRabbit.energy += 500;
  cin.get();
  return *this;
}


RabbitChallenge & RabbitChallenge::foxTest() {
  std::string sky_height;
  std::string go_where;
  int correct_count = 0;

  fprintf(stdout, "How high is the sky?\n");
  std::getline(std::cin, sky_height);

  fprintf(stdout, "Where will you go?\n");
  std::getline(std::cin, go_where);

  if (sky_height == "As high as you can see.")
      correct_count ++;

  if (go_where == "home" || "school")
      correct_count++;


  switch (correct_count) {
    case 2:
      mRabbit.energy *= 2;
      break;
    case 1:
      mRabbit.energy *= 1.5;
    default:
      mRabbit.energy *= 0.5;
      break;
  }
  cout << correct_count << endl;
  return *this;
}

RabbitChallenge & RabbitChallenge::finalJudgment() {
  if (mRabbit.energy >= mRabbit.high_threshold) {
    cout << "Good rabbit!" << endl;
  } else if (mRabbit.energy >= mRabbit.low_threshold &&
             mRabbit.energy < mRabbit.high_threshold) {
    cout << "Keep going, Bunny." << endl;
  } else if (mRabbit.energy < mRabbit.low_threshold) {
    cout << "Poor little Bunny." << endl;
  }
  return *this;
}


