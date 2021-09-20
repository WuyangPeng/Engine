// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:47)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "InputManager.h" 
#include "MessageClient/MessageClientMiddleLayer/Macro/MessageClientMiddleLayerClassInvariantMacro.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

template <typename ApplicationTrait>
MessageClientMiddleLayer::InputManager<ApplicationTrait>
	::InputManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

template <typename ApplicationTrait>
MessageClientMiddleLayer::InputManager<ApplicationTrait>
	::~InputManager()
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool MessageClientMiddleLayer::InputManager<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

#endif / /MESSAGE_CLIENT_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
 