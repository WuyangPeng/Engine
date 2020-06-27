// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:42)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H

#include "ControllerMiddleLayer.h" 
#include "ModelMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename ApplicationTrait>
Framework::ControllerMiddleLayer<ApplicationTrait>
	::ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT 

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::KeyDown(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (ParentType::KeyDown(key, point))
	{
		if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF5)
		{
			auto modelMiddleLayer = boost::polymorphic_pointer_cast<ModelMiddleLayer>(GetModelMiddleLayer());

			modelMiddleLayer->ResetTime();
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Paint()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ParentType::Paint();
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Move(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ParentType::Move(point);
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return ParentType::Resize(windowDisplay,size);
}

#endif // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H