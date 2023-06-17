///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:44)

#include "Rendering/RenderingExport.h"

#include "NullDevice.h"
#include "RenderingDeviceFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/WglRenderer/Detail/WglDevice.h"

Rendering::RenderingDeviceFactory::RenderingDeviceFactory() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDeviceFactory)

Rendering::RenderingDeviceFactory::RenderingDeviceSharedPtr Rendering::RenderingDeviceFactory::Create(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return std::make_shared<WglDevice>(hWnd, device, immediate);

#else  // !SYSTEM_PLATFORM_WIN32

    return std::make_shared<NullDevice>();

#endif  // SYSTEM_PLATFORM_WIN32
}

Rendering::RenderingDeviceFactory::RenderingDeviceSharedPtr Rendering::RenderingDeviceFactory::Create()
{
    return std::make_shared<NullDevice>();
}
