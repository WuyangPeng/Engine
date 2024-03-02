/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:38)

#include "System/SystemExport.h"

#include "GLUtility.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/Tools.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"

#if defined(SYSTEM_PLATFORM_MACOS)

    #include <mach-o/dyld.h>
    #include <cstdlib>
    #include <cstring>

#elif defined(SYSTEM_PLATFORM_LINUX)

    #include <GL/glx.h>
    #include <GL/glxext.h>

#endif  //  defined(SYSTEM_PLATFORM_MACOS)

#if defined(SYSTEM_PLATFORM_MACOS)

namespace System
{
    using namespace std::literals;

    void* DoGetOpenGLFunctionPointer(const char* glFunction)
    {
        // 前面加上一个'_'为Unix C符号识别编码约定。
        auto symbolName = "_"s + glFunction;

        NSSymbol symbol{ 0 };
        if (NSIsSymbolNameDefined(symbolName.c_str()))
        {
            symbol = NSLookupAndBindSymbol(symbolName.c_str());
        }

        return (symbol != 0) ? NSAddressOfSymbol(symbol) : nullptr;
    }
}

void* System::GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    return System::Noexcept<void*>(DoGetOpenGLFunctionPointer, glFunction, nullptr);
}

#elif defined(SYSTEM_PLATFORM_LINUX)

void* System::GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    return reinterpret_cast<void*>((*glXGetProcAddress)(reinterpret_cast<const GLubyte*>(glFunction)));
}

#elif defined(SYSTEM_PLATFORM_WIN32)

void* System::GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    return GetWglProcAddress(glFunction);
}

#else  // !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_WIN32

void* System::GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    UnusedFunction(glFunction);

    return nullptr;
}

#endif  // SYSTEM_PLATFORM_MACOS
