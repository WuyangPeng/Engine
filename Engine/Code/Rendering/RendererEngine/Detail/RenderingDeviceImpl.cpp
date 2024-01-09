/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 16:14)

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
