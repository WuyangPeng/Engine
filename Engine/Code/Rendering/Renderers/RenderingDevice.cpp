///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/04 21:53)

#include "Rendering/RenderingExport.h"

#include "RenderingDevice.h"
#include "Detail/RenderingDeviceFactory.h"
#include "Detail/RenderingDeviceImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, RenderingDevice)

Rendering::RenderingDevice::RenderingDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hWnd, device, immediate }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RenderingDevice::RenderingDevice(DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDevice)

void Rendering::RenderingDevice::SwapBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SwapBuffers();
}

void Rendering::RenderingDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->ResetSize();
}

void Rendering::RenderingDevice::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->InitDevice();
}
