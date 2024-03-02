/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:23)

#include "System/SystemExport.h"

#include "OpenGLBase.h"
#include "OpenGLInit.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GLExtensions.h"
#include "Detail/GLUtility.h"
#include "Detail/GlxExtensions.h"
#include "Detail/WglExtensions.h"

#include <iostream>

bool System::OpenGLInit()
{
#ifdef SYSTEM_PLATFORM_WIN32

    return InitWgl();

#elif defined(SYSTEM_PLATFORM_LINUX)

    return InitGlx();

#else  // !SYSTEM_PLATFORM_WIN32 && !SYSTEM_PLATFORM_LINUX

    return InitGL();

#endif  // SYSTEM_PLATFORM_WIN32
}

namespace System
{
    using FunctionType = decltype(GetVersionString);
    void PrintOpenGLInfo(FunctionType function, const char* describe)
    {
        if (function != nullptr)
        {
            if (const auto result = function();
                result != nullptr)
            {
                std::cout << describe << " = " << result << '\n';
            }
            else
            {
                std::cout << describe << " = <null>\n";
            }
        }
    }
}

void System::PrintOpenGLInfo()
{
    PrintOpenGLInfo(GetVersionString, "OpenGL version");
    PrintOpenGLInfo(GetShadingLanguageVersion, "GLSL version");
    PrintOpenGLInfo(GetVendorString, "vendor");
    PrintOpenGLInfo(GetRendererString, "renderer");

    const auto numExtensions = GetGLInteger(OpenGLQuery::NumExtensions);

    std::cout << "extensions =\n";
    for (auto i = 0; i < numExtensions; i++)
    {
        std::cout << "    " << GLGetStringI(GL_EXTENSIONS, i) << '\n';
    }

#ifdef SYSTEM_PLATFORM_WIN32

    PrintWglExtensionsInfo();

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::PrintWglExtensionsInfo()
{
    if (const auto wglExtensions = GetWglExtensionString();
        wglExtensions != nullptr)
    {
        std::cout << "WGLExtensions =\n";

        PrintExtensionsInfo(wglExtensions);
    }
    else
    {
        std::cout << "WGLExtensions = <null>\n";
    }
}

std::string System::GetOpenGLVendorString()
{
    if (const auto result = GetVendorString();
        result != nullptr)
    {
        return result;
    }
    else
    {
        return "";
    }
}

std::string System::GetOpenGLVersionString()
{
    if (const auto result = GetVersionString();
        result != nullptr)
    {
        return result;
    }
    else
    {
        return "";
    }
}

std::string System::GetOpenGLRendererString()
{
    if (const auto result = GetRendererString();
        result != nullptr)
    {
        return result;
    }
    else
    {
        return "";
    }
}

std::string System::GetOpenGLShadingLanguageVersion()
{
    if (const auto result = GetShadingLanguageVersion();
        result != nullptr)
    {
        return result;
    }
    else
    {
        return "";
    }
}
