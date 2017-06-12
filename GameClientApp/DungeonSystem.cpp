//
//  DungeonSystem.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 3/1/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "DungeonSystem.h"
#include "DungeonComponent.h"
#include "Entity.h"
#include "Game_C.h"

void DungeonSystem::Init(GameCommon* owner)
{
    System::Init(owner);
    
    Entity* dungeonEntity = GetOwner()->CreateEntity();
    DungeonComponent* dungeonComponent = DungeonComponent::Pool.CreateComponent();
    dungeonEntity->AddComponent(dungeonComponent);
}

void DungeonSystem::Update(float dt)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		ComponentPool<DungeonComponent>::Iterator it(&DungeonComponent::Pool);
		for (it.First(); it.Current(); it.Next())
		{
			it.Current()->SetState(new DungeonComponent::DungeonGenerationState_FindMST());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		ComponentPool<DungeonComponent>::Iterator it(&DungeonComponent::Pool);
		for (it.First(); it.Current(); it.Next())
		{
			it.Current()->Reset();
		}
	}

	if (m_owner->IsPaused())
	{
		return;
	}

    ComponentPool<DungeonComponent>::Iterator it(&DungeonComponent::Pool);
    for (it.First() ; it.Current() ; it.Next())
    {
        it.Current()->Update(dt);
    }

}