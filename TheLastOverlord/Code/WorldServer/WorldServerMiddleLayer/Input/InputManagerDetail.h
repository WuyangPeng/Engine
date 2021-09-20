// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:10)

#ifndef WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "InputManager.h" 
#include "WorldServer/WorldServerMiddleLayer/Macro/WorldServerMiddleLayerClassInvariantMacro.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

template <typename ApplicationTrait>
WorldServerMiddleLayer::InputManager<ApplicationTrait>
	::InputManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

template <typename ApplicationTrait>
WorldServerMiddleLayer::InputManager<ApplicationTrait>
	::~InputManager()
{
	WORLD_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool WorldServerMiddleLayer::InputManager<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

#endif / /WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
 