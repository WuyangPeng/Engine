///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/17 21:35)

#ifndef FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_DETAIL_H
#define FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_DETAIL_H

#include "InputProjectManager.h"
#include "SystemProjectManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
Framework::InputProjectManager<ApplicationTrait>::InputProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, lastKey{ 0 }, keyCount{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::InputProjectManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::InputProjectManager<ApplicationTrait>::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (keyCode0 <= key && key <= keyCode9)
    {
        KeyDown(key);
    }

    System::UnusedFunction(point);

    return true;
}

template <typename ApplicationTrait>
void Framework::InputProjectManager<ApplicationTrait>::KeyDown(int key)
{
    const auto system = this->template GetSystemManager<SystemProjectManager>();
    const auto containerPrintWidth = system->GetContainerPrintWidth();

    const auto difference = key - keyCode0;

    if (containerPrintWidth <= 1)
    {
        system->Execute(difference - 1);
    }
    else if (containerPrintWidth <= keyCount + 1)
    {
        const auto select = lastKey * 10 + difference - 1;
        lastKey = 0;
        keyCount = 0;

        system->Execute(select);
    }
    else
    {
        lastKey = lastKey * 10 + difference;
        ++keyCount;
    }
}

#endif  // FRAMEWORK_PROJECT_INPUT_PROJECT_MANAGER_DETAIL_H
