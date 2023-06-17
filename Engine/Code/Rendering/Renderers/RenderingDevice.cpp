///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:51)

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
