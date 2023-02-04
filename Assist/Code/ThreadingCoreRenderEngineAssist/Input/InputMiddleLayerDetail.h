///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 14:02)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_DEATIL_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_DEATIL_H

#include "InputMiddleLayer.h"
#include "ThreadingCoreRenderEngineAssist/Helper/AssistClassInvariantMacro.h"
#include "ThreadingCoreRenderEngineAssist/System/SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
ThreadingCoreRenderEngineAssist::InputMiddleLayer<ApplicationTrait>::InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, lastKey{ -1 }
{
    ASSIST_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool ThreadingCoreRenderEngineAssist::InputMiddleLayer<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool ThreadingCoreRenderEngineAssist::InputMiddleLayer<ApplicationTrait>::KeyDown(int key, [[maybe_unused]] const WindowPoint& point)
{
    ASSIST_CLASS_IS_VALID_1;

    constexpr auto keyCode0 = ApplicationTrait::KeyIdentifiers::keyCode0;
    constexpr auto keyCode9 = ApplicationTrait::KeyIdentifiers::keyCode9;

    if (keyCode0 <= key && key <= keyCode9)
    {
        const auto difference = key - keyCode0;
        if (0 <= lastKey)
        {
            const auto select = lastKey * 10 + difference - 1;
            lastKey = -1;

            auto system = boost::polymorphic_pointer_downcast<SystemMiddleLayer>(this->GetSystemManager());
            system->Execute(select);
        }
        else
        {
            lastKey = difference;
        }
    }

    return true;
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_INPUT_MIDDLE_LAYER_DEATIL_H