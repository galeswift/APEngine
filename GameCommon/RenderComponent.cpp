//
//  Box2DComponent.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 2/28/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "GameCommon.h"
#include "RenderComponent.h"

IMPLEMENT_COMPONENT(RenderComponent);

void RenderComponent::Init(Entity* entity)
{
	g_clientGame->GetRenderSystem()->RegisterRenderObserver(this);
}

void RenderComponent::Draw(sf::RenderWindow* window)
{

}