///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 20:00)

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

void System::PrintOpenGLInfo()
{
    auto version = GetVersionString();
    if (version != nullptr)
    {
        cout << "OpenGL version = " << version << "\n";
    }
    else
    {
        cout << " OpenGL version = <null>\n";
    }

    auto shadingLanguageVersion = GetShadingLanguageVersion();
    if (shadingLanguageVersion != nullptr)
    {
        cout << "GLSL version = " << shadingLanguageVersion << "\n";
    }
    else
    {
        cout << "GLSL version = <null>\n";
    }

    auto vendor = GetVendorString();
    if (vendor != nullptr)
    {
        cout << "vendor = " << vendor << "\n";
    }
    else
    {
        cout << "vendor = <null>\n";
    }

    auto renderer = GetRendererString();
    if (renderer != nullptr)
    {
        cout << "renderer = " << renderer << "\n";
    }
    else
    {
        cout << "renderer = <null>\n";
    }

    const auto numExtensions = GetGLInteger(OpenGLQuery::NumExtensions);

    cout << "extensions = ";
    for (auto i = 0; i < numExtensions; i++)
    {
        cout << GLGetStringi(GL_EXTENSIONS, i) << "\n";
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
