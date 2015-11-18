//
//  Game.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 2/18/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "Game_C.h"
#include "Box2DSystem.h"
#include "DungeonSystem.h"
#include "RenderingSystem.h"
#include "VideoEncodingSystem.h"

void Game_C::Init()
{
	GameCommon::Init();

    RegisterSystem(new Box2DSystem());
    RegisterSystem(new DungeonSystem());
	RegisterSystem(new VideoEncodingSystem());

}

