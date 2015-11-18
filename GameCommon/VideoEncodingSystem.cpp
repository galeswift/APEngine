//
//  VideoEncodingSystem.cpp
//  RogueLikeBox
//
//  Created by Keith Miron on 2/28/15.
//  Copyright (c) 2015 Acoustic Games. All rights reserved.
//

#include "VideoEncodingSystem.h"
#include "Components.h"
#include "GameCommon.h"

VideoEncodingSystem::VideoEncodingSystem()
{
}

void VideoEncodingSystem::Init(GameCommon* owner)
{
	System::Init(owner);
}

void VideoEncodingSystem::Draw(sf::RenderWindow* window)
{
}

#define SCENE_TEXT_LENGTH (2048)
const char sceneString[SCENE_TEXT_LENGTH] = "\
scenes : {\n\
Scene: {\n\
class : Scene\n\
	sources : {\n\
OverwatchPersonalPOTG: {\n\
render: 1\n\
	class : WindowCaptureSource\n\
		data : {\n\
	captureType: 1\n\
		monitor : 0\n\
		window : SFML window\n\
		windowClass : SFML_Window\n\
		innerWindow : 1\n\
		regionCapture : 0\n\
		captureMouse : 1\n\
		captureLayered : 1\n\
		compatibilityMode : 1\n\
		usePointFiltering : 0\n\
		captureX : 0\n\
		captureY : 0\n\
		captureCX : 1024\n\
		captureCY : 584\n\
		useColorKey : 0\n\
		keyColor : -1\n\
		keySimilarity : 10\n\
		keyBlend : 0\n\
		opacity : 100\n\
		gamma : 100\n\
	}\n\
cx: 1024\n\
	cy : 584\n\
	crop.left : 0\n\
	crop.top : 0\n\
	crop.right : 0\n\
	crop.bottom : 0\n\
}\n\
}\n\
}\n\
}\n";

void VideoEncodingSystem::Update(float dt)
{	
	using namespace std;
	FILE* outputFile = NULL;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
    {
		outputFile = fopen("scenes.xconfig", "w");		
		fwrite((void*)sceneString, sizeof(char), SCENE_TEXT_LENGTH, outputFile);
    }

	if (outputFile)
	{
		fclose(outputFile);
	}
}