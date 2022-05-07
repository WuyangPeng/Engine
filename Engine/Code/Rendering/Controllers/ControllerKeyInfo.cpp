///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 17:11)

#include "Rendering/RenderingExport.h"

#include "ControllerKeyInfo.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ControllerKeyInfo::ControllerKeyInfo(float normTime, int firstIndex, int secondIndex) noexcept
    : normTime{ normTime }, firstIndex{ firstIndex }, secondIndex{ secondIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ControllerKeyInfo::ControllerKeyInfo() noexcept
    : normTime{ 0.0f }, firstIndex{ 0 }, secondIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ControllerKeyInfo)

float Rendering::ControllerKeyInfo::GetNormTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normTime;
}

int Rendering::ControllerKeyInfo::GetFirstIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return firstIndex;
}

int Rendering::ControllerKeyInfo::GetSecondIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return secondIndex;
}