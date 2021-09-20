///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 15:10)

#ifndef THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DEATIL_H
#define THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DEATIL_H

#include "InputMiddleLayer.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"
#include "TheLastOverlord/System/SystemMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
TheLastOverlord::InputMiddleLayer<ApplicationTrait>::InputMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, lastKey{ -1 }
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

    constexpr auto keyCode0 = ApplicationTrait::KeyIdentifiers::sm_KeyCode0;
    constexpr auto keyCode9 = ApplicationTrait::KeyIdentifiers::sm_KeyCode9;

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

#endif  // THE_LAST_OVERLORD_INPUT_MIDDLE_LAYER_DEATIL_H
