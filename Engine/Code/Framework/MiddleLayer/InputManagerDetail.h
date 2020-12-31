// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:44)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H

#include "InputManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait>
Framework::InputManager<ApplicationTrait>
	::InputManager(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	 

#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H

