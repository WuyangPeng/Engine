///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/14 22:04)

#include "Rendering/RenderingExport.h"

#include "NullDevice.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::NullDevice::NullDevice() noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NullDevice)

Rendering::NullDevice::RenderingDeviceSharedPtr Rendering::NullDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::NullDevice::SwapBuffers() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::ResetSize() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::InitDevice() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}
