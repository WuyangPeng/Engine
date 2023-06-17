///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:20)

#include "Rendering/RenderingExport.h"

#include "WglDevice.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::WglDevice::WglDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate)
    : ParentType{}, hWnd{ hWnd }, device{ device }, immediate{ immediate }
{
    Init();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::WglDevice::Init()
{
    if (hWnd == nullptr || device == nullptr || immediate == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("wgl环境参数无效"s));
    }

    ResetSize();
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::WglDevice::IsValid() const noexcept
{
    return ParentType::IsValid() && device != nullptr && immediate != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::WglDevice::RenderingDeviceSharedPtr Rendering::WglDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::WglDevice::SwapBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!System::DisplayColorBuffer(device, 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("交换缓冲区失败。"s));
    }
}

void Rendering::WglDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    System::WindowsRect windowsRect{};
    if (!System::GetSystemClientRect(hWnd, windowsRect))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取窗口大小失败。"s));
    }

    SetSize(windowsRect.right - windowsRect.left, windowsRect.bottom - windowsRect.top);
}
