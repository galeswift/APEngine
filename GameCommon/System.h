//
//  System.h
//  RogueLikeBox
//
//  Created by Keith Miron on 2/27/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#ifndef __RogueLikeBox__System__
#define __RogueLikeBox__System__

#include <stdio.h>
#include <SFML/Graphics.hpp>
class GameCommon;

class System
{
public:
	virtual void Init(GameCommon* owner);
    virtual void Draw(sf::RenderWindow* window) {};
    virtual void Update(float f32){};
	GameCommon* GetOwner();
    
protected:
    GameCommon* m_owner;
};

#endif /* defined(__RogueLikeBox__System__) */
