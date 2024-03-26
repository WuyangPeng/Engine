/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:13)

#include "System/SystemExport.h"

#include "OpenGLBase.h"
#include "OpenGLUtility.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GLUtility.h"
#include "Detail/WglExtensions.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning.h"

System::OpenGLSystemVersion System::GetOpenGLVersion() noexcept
{
    const auto major = GetGLInteger(OpenGLQuery::MajorVersion);
    const auto minor = GetGLInteger(OpenGLQuery::MinorVersion);

    return GetOpenGLVersion(major, minor);
}

bool System::IsOpenGLSupportsExtension(const std::string& extension) noexcept
{
    const auto numExtensions = GetGLInteger(OpenGLQuery::NumExtensions);

    for (auto index = 0; index < numExtensions; ++index)
    {
        if (const auto openglExtension = GLGetStringI(GL_EXTENSIONS, index);
            openglExtension != nullptr)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

            if (extension == reinterpret_cast<const char*>(openglExtension))

#include SYSTEM_WARNING_POP
            {
                return true;
            }
        }
    }

    return false;
}

void* System::GetFunctionPointer(const char* glFunction) noexcept
{
    return GetOpenGLFunctionPointer(glFunction);
}

std::string System::GetOpenGLErrorDescription(OpenGLErrorCode code)
{
    if (const auto description = GetOpenGLErrorString(code);
        description != nullptr)
    {
        return description;
    }
    else
    {
        return "";
    }
}

bool System::IsWglSupportsExtension(const char* wglExtension)
{
    return SupportsWglExtension(wglExtension);
}
