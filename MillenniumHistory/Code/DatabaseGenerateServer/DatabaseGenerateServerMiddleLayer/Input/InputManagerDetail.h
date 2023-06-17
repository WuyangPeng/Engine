///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/12 22:24)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "InputManager.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
DatabaseGenerateServerMiddleLayer::InputManager<ApplicationTrait>::InputManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool DatabaseGenerateServerMiddleLayer::InputManager<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_DETAIL_H
