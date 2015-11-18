//
//  Game.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 2/18/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "GameCommon.h"
#include "Components.h"
#include "Entity.h"
#include "System.h"
#include <stdio.h>
#include <random>

std::random_device Random::s_rd;
std::linear_congruential_engine<uint_fast32_t, 48271, 0, 2147483647> Random::s_re(Random::s_rd());

GameCommon::GameCommon()
{};

GameCommon::~GameCommon()
{
	for (std::vector<Entity*>::iterator it = m_objects.begin(); it != m_objects.end(); it++)
	{
		delete *it;
	}
}

void GameCommon::Init()
{
	RenderingSystem* renderSystem = new RenderingSystem();
	SetRenderSystem(renderSystem);
	RegisterSystem(renderSystem);
}

void GameCommon::Draw(sf::RenderWindow* window)
{
	for (std::vector<System*>::iterator it = m_systems.begin(); it != m_systems.end(); it++)
	{
		(*it)->Draw(window);
	}
}

void GameCommon::Update(float dt)
{
	for (std::vector<System*>::iterator it = m_systems.begin(); it != m_systems.end(); it++)
	{
		(*it)->Update(dt);
	}
}

Entity* GameCommon::CreateEntity()
{
	Entity* newEntity = new Entity();
	m_objects.push_back(newEntity);
	return newEntity;
}

void GameCommon::RegisterSystem(System* system)
{
	m_systems.push_back(system);
	system->Init(this);
}

