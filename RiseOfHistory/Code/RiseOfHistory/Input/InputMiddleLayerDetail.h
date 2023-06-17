///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:42)

#ifndef RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_DEATIL_H
#define RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_DEATIL_H

#include "InputMiddleLayer.h"
#include "RiseOfHistory/Helper/RiseOfHistoryClassInvariantMacro.h"
#include "RiseOfHistory/System/SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
RiseOfHistory::InputMiddleLayer<ApplicationTrait>::InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, lastKey{ -1 }, keyCount{ 0 }
{
    RISE_OF_HISTORY_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool RiseOfHistory::InputMiddleLayer<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool RiseOfHistory::InputMiddleLayer<ApplicationTrait>::KeyDown(int key, [[maybe_unused]] const WindowPoint& point)
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

    constexpr auto keyCode0 = ApplicationTrait::KeyIdentifiers::keyCode0;
    constexpr auto keyCode9 = ApplicationTrait::KeyIdentifiers::keyCode9;

    if (keyCode0 <= key && key <= keyCode9)
    {
        auto system = boost::polymorphic_pointer_downcast<SystemMiddleLayer>(this->GetSystemManager());
        const auto containerPrintWidth = system->GetContainerPrintWidth();

        const auto difference = key - keyCode0;

        if (containerPrintWidth <= 1)
        {
            system->Execute(difference - 1);
        }
        else if (containerPrintWidth <= keyCount + 1)
        {
            const auto select = lastKey * 10 + difference - 1;
            lastKey = -1;
            keyCount = 0;

            system->Execute(select);
        }
        else
        {
            lastKey = lastKey * 10 + difference;
            ++keyCount;
        }
    }

    return true;
}

#endif  // RISE_OF_HISTORY_INPUT_MIDDLE_LAYER_DEATIL_H
