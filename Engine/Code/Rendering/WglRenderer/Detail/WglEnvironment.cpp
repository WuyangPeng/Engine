///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/06 14:29)

#include "Rendering/RenderingExport.h"

#include "WglEnvironment.h"
#include "System/OpenGL/Flags/OpenGLWglPrototypesFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsFontInformation.h"
#include "System/Windows/WindowsUser.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::WglEnvironment::WglEnvironment(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : ParentType{ rendererParameter },
      environmentParameter{ environmentParameter },
      handle{ environmentParameter.GetWindowsHWnd() },
      device{ nullptr },
      immediate{ nullptr }
{
    if (handle == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的窗口句柄。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::WglEnvironment::~WglEnvironment() noexcept
{
    Release();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::WglEnvironment::Release() noexcept
{
    if (device != nullptr)
    {
        if (immediate != nullptr)
        {
            if (!System::MakeWglCurrent(device, nullptr))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering)
                    << SYSTEM_TEXT("WglMakeCurrent失败！")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }

            if (!System::DeleteWglContext(immediate))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering)
                    << SYSTEM_TEXT("WglDeleteContext失败！")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }

            immediate = nullptr;
        }

        if (!System::ReleaseSystemDC(handle, device))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering)
                << SYSTEM_TEXT("释放设备上下文失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }

        device = nullptr;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::WglEnvironment::IsValid() const noexcept
{
    return ParentType::IsValid() && handle != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::WglEnvironment::RenderingEnvironmentSharedPtr Rendering::WglEnvironment::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::WglEnvironment::InitEnvironment()
{
    RENDERING_CLASS_IS_VALID_9;

    CreateDevice();

    const auto pixelFormatDescriptor = GetPixelFormatDescriptor();
    SetWindowPixelFormat(pixelFormatDescriptor);

    CreateContext();

    ParentType::InitEnvironment();
}

void Rendering::WglEnvironment::CreateDevice()
{
    device = System::GetSystemDC(handle);
    if (device == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的设备上下文。"s));
    }
}

System::PixelFormatDescriptor Rendering::WglEnvironment::GetPixelFormatDescriptor() noexcept
{
    PixelFormatDescriptor pixelFormatDescriptor{};

    pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
    pixelFormatDescriptor.nVersion = 1;
    pixelFormatDescriptor.dwFlags = System::EnumCastUnderlying(System::PixelFormatDescriptorFlags::DrawToWindow |
                                                               System::PixelFormatDescriptorFlags::SupportOpengl |
                                                               System::PixelFormatDescriptorFlags::GenericAccelerated |
                                                               System::PixelFormatDescriptorFlags::DoubleBuffer);

    pixelFormatDescriptor.iPixelType = System::EnumCastUnderlying<System::WindowsByte>(System::PixelTypes::TypeRGBA);
    pixelFormatDescriptor.cColorBits = 32;

    const auto depthStencilForma = GetDepthStencilFormat();

    if (depthStencilForma == DataFormatType::D24UNormS8UInt)
    {
        pixelFormatDescriptor.cDepthBits = 24;
        pixelFormatDescriptor.cStencilBits = 8;
    }
    else
    {
        pixelFormatDescriptor.cDepthBits = 32;
        pixelFormatDescriptor.cStencilBits = 0;
    }

    return pixelFormatDescriptor;
}

void Rendering::WglEnvironment::SetWindowPixelFormat(const System::PixelFormatDescriptor& pixelFormatDescriptor)
{
    const auto pixelFormat = System::ChooseWindowPixelFormat(device, &pixelFormatDescriptor);
    if (pixelFormat == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ChoosePixelFormat失败。"));
    }

    if (!System::SetWindowPixelFormat(device, pixelFormat, &pixelFormatDescriptor))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("SetPixelFormat失败。"));
    }
}

void Rendering::WglEnvironment::CreateContext()
{
    immediate = System::CreateWglContext(device);
    if (immediate == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("wglCreateContext失败。"));
    }

    if (!System::MakeWglCurrent(device, immediate))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("wglMakeCurrent失败。"));
    }
}

Rendering::RenderingDevice Rendering::WglEnvironment::GetRenderingDevice() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RenderingDevice{ handle, device, immediate };
}