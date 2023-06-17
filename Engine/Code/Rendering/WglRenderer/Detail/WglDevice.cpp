///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:20)

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
        THROW_EXCEPTION(SYSTEM_TEXT("wgl����������Ч"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("����������ʧ�ܡ�"s));
    }
}

void Rendering::WglDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    System::WindowsRect windowsRect{};
    if (!System::GetSystemClientRect(hWnd, windowsRect))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ڴ�Сʧ�ܡ�"s));
    }

    SetSize(windowsRect.right - windowsRect.left, windowsRect.bottom - windowsRect.top);
}
