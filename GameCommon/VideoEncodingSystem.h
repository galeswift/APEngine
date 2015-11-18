//
//  RenderingSystem.h
//  RogueLikeBox
//
//  Created by Keith Miron on 2/28/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#ifndef __RogueLikeBox__VideoEncodingSystem__
#define __RogueLikeBox__VideoEncodingSystem__

#include <stdio.h>
#include "System.h"

class VideoEncodingSystem : public System
{
public:
	VideoEncodingSystem();
	virtual void Init(GameCommon* owner);
    virtual void Draw(sf::RenderWindow* window);
    virtual void Update(float dt);
};

#endif /* defined(__RogueLikeBox__VideoEncodingSystem__) */
