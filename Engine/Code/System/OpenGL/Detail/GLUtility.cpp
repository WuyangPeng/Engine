//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/26 14:33)

#include "System/SystemExport.h"

#include "GLExtensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/Platform.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/UserInterface/OpenGLWglPrototypes.h"

#include <array>

using std::array;
using namespace std::literals;

constexpr auto g_Major = 4;
constexpr auto g_Minor = 6;
constexpr auto g_VersionSize = (g_Major + 1) * (g_Minor + 1);

constexpr array<System::OpenGLSystemVersion, g_VersionSize> g_Version{
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,

    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::Version11,
    System::OpenGLSystemVersion::Version12,
    System::OpenGLSystemVersion::Version13,
    System::OpenGLSystemVersion::Version14,
    System::OpenGLSystemVersion::Version15,
    System::OpenGLSystemVersion::VersionNone,

    System::OpenGLSystemVersion::Version20,
    System::OpenGLSystemVersion::Version21,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,

    System::OpenGLSystemVersion::Version30,
    System::OpenGLSystemVersion::Version31,
    System::OpenGLSystemVersion::Version32,
    System::OpenGLSystemVersion::Version33,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,
    System::OpenGLSystemVersion::VersionNone,

    System::OpenGLSystemVersion::Version40,
    System::OpenGLSystemVersion::Version41,
    System::OpenGLSystemVersion::Version42,
    System::OpenGLSystemVersion::Version43,
    System::OpenGLSystemVersion::Version44,
    System::OpenGLSystemVersion::Version45,
    System::OpenGLSystemVersion::Version46,
};

System::OpenGLSystemVersion System::GetOpenGLVersion(char major, char minor) noexcept
{
    const auto majorIndex = ToIndex(major);
    const auto minorIndex = ToIndex(minor);

    const auto index = majorIndex * (g_Minor + 1) + minorIndex;

    if (0 <= index && index < g_VersionSize)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        return g_Version[index];
#include STSTEM_WARNING_POP
    }
    else if (g_Major < majorIndex || (g_Major == majorIndex && g_Minor < minorIndex))
    {
        return OpenGLSystemVersion::VersionUnkownMax;
    }
    else
    {
        return OpenGLSystemVersion::VersionNone;
    }
}

int System::ToIndex(char index) noexcept
{
    switch (index)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return 0;
    }
}

namespace System
{
    // 支持错误检查。
    constexpr auto g_ErrorStringSize = 7;

    constexpr array<const char*, g_ErrorStringSize> g_ErrorString{
        "GL_INVALID_ENUM",
        "GL_INVALID_VALUE",
        "GL_INVALID_OPERATION",
        "GL_STACK_OVERFLOW",
        "GL_STACK_UNDERFLOW",
        "GL_OUT_OF_MEMORY",
        "GL_UNKNOWN_ERROR_CODE"
    };
}

const char* System::GetOpenGLErrorString(OpenGLErrorCode code) noexcept
{
    const auto index = EnumCastUnderlying(code) - EnumCastUnderlying(OpenGLErrorCode::InvalidEnum);

    if (0 <= index && index < g_ErrorStringSize)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        return g_ErrorString[index];
#include STSTEM_WARNING_POP
    }
    else
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        return g_ErrorString[g_ErrorStringSize - 1];
#include STSTEM_WARNING_POP
    }
}

#if defined(SYSTEM_PLATFORM_MACOS)

    #include <mach-o/dyld.h>
    #include <cstdlib>
    #include <cstring>

extern "C"
{
    void* GetOpenGLFunctionPointer(const char* glFunction) noexcept
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

#elif defined(SYSTEM_PLATFORM_LINUX)

    #include <X11/Xlib.h>
    #include <X11/Xmd.h>
    #include <X11/Xutil.h>

void* GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    return reinterpret_cast<void*>((*glXGetProcAddressARB)(reinterpret_cast<const GLubyte*>(glFunction)));
}

#elif defined(SYSTEM_PLATFORM_WIN32)

void* GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    return System::GetWglProcAddress(glFunction);
}

#else  // !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_WIN32

void* GetOpenGLFunctionPointer([[maybe_unused]] const char* glFunction) noexcept
{
    return nullptr;
}

#endif  // SYSTEM_PLATFORM_MACOS