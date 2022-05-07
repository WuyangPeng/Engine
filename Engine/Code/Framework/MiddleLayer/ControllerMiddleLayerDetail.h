///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:30)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H

#include "ControllerMiddleLayer.h"
#include "ModelMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait>
Framework::ControllerMiddleLayer<ApplicationTrait>::ControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::KeyDown(key, point))
    {
        if (key == ApplicationTrait::KeyIdentifiers::keyF5)
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
bool Framework::ControllerMiddleLayer<ApplicationTrait>::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H