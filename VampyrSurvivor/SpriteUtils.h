#pragma once
#include <string>
#include "Animation.h"

#pragma region Assault
#define ASSAULT_W1_0 new Assault(vector<Mob*> {MULTI_MOB(MOB_WOLF,5)});
#define ASSAULT_W1_1 new Assault(vector<Mob*> {MULTI_MOB(MOB_WOLF,6)});
#define ASSAULT_W1_2 new Assault(vector<Mob*> {MULTI_MOB(MOB_WOLF,7)});
#pragma endregion Assault

#pragma region Player
#define CURRENT_MONEY_POS Vector2f(1280 * 90 / 100, 720 * 5 / 100)
#define SCORE_POS Vector2f(1280 * 90 / 100, 720 * 15 / 100)
#pragma region Player

#define RANDOM_POS Vector2f(Random(1000,0),Random(1000,0))
#define ALL_ASSAULT new Assault({MobID::M_WOLF,MobID::M_WOLF},{5,5},3)


#pragma region Wolf
#define MOB_WOLF(pos,speed) new Mob(STRING_ID("mob"), ShapeData(pos, Vector2f(30,30),"Enemis\\Wolf_anim.png"), CollisionType::CT_NONE, 100, speed, 20);

#define WOLF_WALK_ANIM AnimationData(STRING_ID("Wolf_Walk"),Vector2f(0,43),Vector2f(64,32),ReadDirection::READ_RIGHT,true,5,0.15f);
#define WOLF_ATTACK_ANIM AnimationData(STRING_ID("Wolf_Attack"),Vector2f(0,0),Vector2f(100,100),ReadDirection::READ_RIGHT,true,6,0.2f);
#define WOLF_DEATH_ANIM AnimationData(STRING_ID("Wolf_Death"),Vector2f(0,120),Vector2f(100,100),ReadDirection::READ_RIGHT,true,6,0.2f);
#pragma endregion Wolf
