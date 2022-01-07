///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:08)

#include "System/SystemExport.h"

#include "OpenGLAPI.h"
#include "OpenGLInit.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GLExtensions.h"
#include "Detail/GLUtility.h"
#include "Detail/GlxExtensions.h"
#include "Detail/WglExtensions.h"

#include <iostream>

using std::cout;

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
            auto result = function();
            if (result != nullptr)
            {
                cout << describe << " = " << result << "\n";
            }
            else
            {
                cout << describe << " = <null>\n";
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

    cout << "extensions =\n";
    for (auto i = 0; i < numExtensions; i++)
    {
        cout << "    " << GLGetStringi(GL_EXTENSIONS, i) << "\n";
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
        cout << "WGLextensions =\n";

        PrintExtensionsInfo(wglExtensions);
    }
    else
    {
        cout << "WGLextensions = <null>\n";
    }
}
