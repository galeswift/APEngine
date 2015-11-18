//
//  Box2DComponent.h
//  RogueLikeBox
//
//  Created by Keith Miron on 2/28/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#pragma once
#include "Components.h"
class RenderComponent : public Component
{
public:
	DECLARE_COMPONENT(RenderComponent);	
	virtual void Init(Entity* entity);
	virtual void Draw(sf::RenderWindow* window);	
};
