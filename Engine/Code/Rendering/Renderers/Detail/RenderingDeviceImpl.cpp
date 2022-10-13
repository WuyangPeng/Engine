///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/14 18:25)

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
