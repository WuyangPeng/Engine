/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/22 10:05)

#include "Rendering/RenderingExport.h"

#include "WglDevice.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::WglDevice::WglDevice(WindowsHWnd hWnd, WindowsHdc device, OpenGLRcHandle immediate)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, hWnd{ hWnd }, device{ device }, immediate{ immediate }
{
    Init();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::WglDevice::Init()
{
    if (hWnd == nullptr || device == nullptr || immediate == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("wgl����������Ч"s))
    }

    System::WindowsRect windowsRect{};
    if (!System::GetSystemClientRect(hWnd, windowsRect))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ڴ�Сʧ�ܡ�"s))
    }

    SetSize(windowsRect.right - windowsRect.left, windowsRect.bottom - windowsRect.top);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::WglDevice::IsValid() const noexcept
{
    return ParentType::IsValid() && hWnd != nullptr && device != nullptr && immediate != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::WglDevice::RenderingDeviceSharedPtr Rendering::WglDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::WglDevice::DisplayColorBuffer(int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!System::DisplayColorBuffer(device, syncInterval))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����������ʧ�ܡ�"s))
    }
}

void Rendering::WglDevice::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Resize(width, height);

    SetSize(width, height);
}
