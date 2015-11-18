//
//  RenderingSystem.h
//  RogueLikeBox
//
//  Created by Keith Miron on 2/28/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#ifndef __RogueLikeBox__RenderingSystem__
#define __RogueLikeBox__RenderingSystem__

#include <stdio.h>
#include <vector>
#include "System.h"

class RenderComponent;

class RenderingSystem : public System
{
public:
    RenderingSystem();
	virtual void Init(GameCommon* owner);
    virtual void Draw(sf::RenderWindow* window);
    virtual void Update(float dt);
	void RegisterRenderObserver(RenderComponent* component);
	void UnregisterRenderObserver(RenderComponent* component);
private:
    bool m_viewInitialized;
    sf::View m_defaultView;
    float m_currentZoom;
	std::vector<RenderComponent*> m_renderObservers;
};

#endif /* defined(__RogueLikeBox__RenderingSystem__) */
