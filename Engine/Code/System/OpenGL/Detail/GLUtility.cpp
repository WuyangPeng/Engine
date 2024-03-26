/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:20)

#include "System/SystemExport.h"

#include "GLUtility.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

#include <array>
#include <iostream>
#include <vector>

using namespace std::literals;

constexpr auto majorCount = 4;
constexpr auto minorCount = 6;
constexpr auto versionSize = (majorCount + 1) * (minorCount + 1);

constexpr std::array version{ System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,
                              System::OpenGLSystemVersion::VersionNone,

                              System::OpenGLSystemVersion::Version10,
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
                              System::OpenGLSystemVersion::Version46 };

System::OpenGLSystemVersion System::GetOpenGLVersion(int major, int minor) noexcept
{
    if (const auto index = major * (minorCount + 1) + minor;
        0 <= index && index < versionSize)
    {
        return version.at(index);
    }
    else if (majorCount < major || (major == majorCount && minorCount < minor))
    {
        return OpenGLSystemVersion::VersionUnknownMax;
    }
    else
    {
        return OpenGLSystemVersion::VersionNone;
    }
}

namespace System
{
    /// 支持错误检查。
    constexpr auto errorStringSize = 9;

    constexpr std::array errorString{ "GL_INVALID_ENUM",
                                      "GL_INVALID_VALUE",
                                      "GL_INVALID_OPERATION",
                                      "GL_STACK_OVERFLOW",
                                      "GL_STACK_UNDERFLOW",
                                      "GL_OUT_OF_MEMORY",
                                      "GL_INVALID_FRAMEBUFFER_OPERATION",
                                      "GL_CONTEXT_LOST",
                                      "GL_UNKNOWN_ERROR_CODE" };
}

const char* System::GetOpenGLErrorString(OpenGLErrorCode code) noexcept
{
    if (const auto index = EnumCastUnderlying(code) - EnumCastUnderlying(OpenGLErrorCode::InvalidEnum);
        0 <= index && index < errorStringSize)
    {
        return errorString.at(index);
    }
    else
    {
        return errorString.at(errorStringSize - 1);
    }
}

void System::PrintExtensionsInfo(const char* extensions)
{
    TokenSplitType token{};
    split(token, extensions, boost::is_any_of(" \t\n"), boost::token_compress_on);
    for (const auto& element : token)
    {
        std::cout << "    " << element << "\n";
    }
}
