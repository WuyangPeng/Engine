///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/15 23:05)

#ifndef MILLENNIUM_HISTORY_INPUT_MANAGER_DETAIL_H
#define MILLENNIUM_HISTORY_INPUT_MANAGER_DETAIL_H

#include "InputManager.h"
#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"
#include "MillenniumHistory/System/SystemManager.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
MillenniumHistory::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, lastKey{ -1 }, keyCount{ 0 }
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool MillenniumHistory::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool MillenniumHistory::InputManager<ApplicationTrait>::KeyDown(int key, const WindowPoint& point)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    if (keyCode0 <= key && key <= keyCode9)
    {
        KeyDown(key);
    }

    System::UnusedFunction(point);

    return true;
}

template <typename ApplicationTrait>
void MillenniumHistory::InputManager<ApplicationTrait>::KeyDown(int key)
{
    const auto system = this->GetSystemManager<SystemManager>();
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

#endif  // MILLENNIUM_HISTORY_INPUT_MANAGER_DETAIL_H
