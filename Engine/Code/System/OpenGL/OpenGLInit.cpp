///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:42)

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

    return InitWGL();

#elif defined(SYSTEM_PLATFORM_LINUX)

    return InitGLX();

#else  // !SYSTEM_PLATFORM_WIN32 && !SYSTEM_PLATFORM_LINUX

    return InitGL();

#endif  // SYSTEM_PLATFORM_WIN32
}

namespace System
{
    using FunctiorType = decltype(GetVersionString);
    void PrintOpenGLInfo(FunctiorType function, const char* describe)
    {
        if (function != nullptr)
        {
            const auto result = function();
            if (result != nullptr)
            {
                std::cout << describe << " = " << result << "\n";
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
        std::cout << "    " << GLGetStringi(GL_EXTENSIONS, i) << "\n";
    }

#ifdef SYSTEM_PLATFORM_WIN32

    PrintWglExtensionsInfo();

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::PrintWglExtensionsInfo()
{
    auto wglExtensions = GetWglExtensionString();

    if (wglExtensions != nullptr)
    {
        std::cout << "WGLextensions =\n";

        PrintExtensionsInfo(wglExtensions);
    }
    else
    {
        std::cout << "WGLextensions = <null>\n";
    }
}

std::string System::GetOpenGLVendorString()
{
    auto result = GetVendorString();

    if (result != nullptr)
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
    auto result = GetVersionString();

    if (result != nullptr)
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
    auto result = GetRendererString();

    if (result != nullptr)
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
    auto result = GetShadingLanguageVersion();

    if (result != nullptr)
    {
        return result;
    }
    else
    {
        return "";
    }
}
