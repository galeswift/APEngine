//
//  System.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 2/27/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "System.h"
#include "GameCommon.h"

void System::Init(GameCommon* owner)
{
    m_owner = owner;
}

GameCommon* System::GetOwner()
{
    return m_owner;
}