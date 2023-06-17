///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.9.0.12 (2023/06/17 15:03)

#ifndef THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DETAIL_H
#define THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DETAIL_H

#include "InputMiddleLayer.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"
#include "TheLastOverlord/System/SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
TheLastOverlord::InputMiddleLayer<ApplicationTrait>::InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, lastKey{ -1 }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool TheLastOverlord::InputMiddleLayer<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool TheLastOverlord::InputMiddleLayer<ApplicationTrait>::KeyDown(int key, [[maybe_unused]] const WindowPoint& point)
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

    constexpr auto keyCode0 = ApplicationTrait::KeyIdentifiers::keyCode0;
    constexpr auto keyCode9 = ApplicationTrait::KeyIdentifiers::keyCode9;

    if (keyCode0 <= key && key <= keyCode9)
    {
        const auto difference = key - keyCode0;
        if (0 <= lastKey)
        {
            const auto value = lastKey * 10 + difference - 1;
            lastKey = -1;

            auto system = boost::polymorphic_pointer_downcast<SystemMiddleLayer>(this->GetSystemManager());
            system->Execute(value);
        }
        else
        {
            lastKey = difference;
        }
    }

    return true;
}

#endif  // THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DETAIL_H
