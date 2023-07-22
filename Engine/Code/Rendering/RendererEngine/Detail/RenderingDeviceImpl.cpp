///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 15:04)

#include "Rendering/RenderingExport.h"

#include "RenderingDeviceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingDeviceImpl::RenderingDeviceImpl() noexcept
    : xSize{ 0 }, ySize{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDeviceImpl)

void Rendering::RenderingDeviceImpl::SetSize(int x, int y) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    xSize = x;
    ySize = y;
}

int Rendering::RenderingDeviceImpl::GetXSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return xSize;
}

int Rendering::RenderingDeviceImpl::GetYSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ySize;
}