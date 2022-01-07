///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:10)

#include "System/SystemExport.h"

#include "OpenGLAPI.h"
#include "OpenGLUtility.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GLExtensions.h"
#include "Detail/GLUtility.h"
#include "Detail/WglExtensions.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning.h"

using std::string;
using namespace std::literals;

System::OpenGLSystemVersion System::GetOpenGLVersion() noexcept
{
    const auto major = GetGLInteger(OpenGLQuery::MajorVersion);
    const auto minor = GetGLInteger(OpenGLQuery::MinorVersion);

    return GetOpenGLVersion(major, minor);
}

bool System::IsOpenGLSupportsExtension(const string& extension)
{
    const auto numExtensions = GetGLInteger(OpenGLQuery::NumExtensions);

    for (auto index = 0; index < numExtensions; ++index)
    {
        const auto openglExtension = GLGetStringi(GL_EXTENSIONS, index);

        if (openglExtension != nullptr)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
            if (extension == reinterpret_cast<const char*>(openglExtension))
#include STSTEM_WARNING_POP
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

string System::GetOpenGLErrorDescription(OpenGLErrorCode code)
{
    auto description = GetOpenGLErrorString(code);

    if (description != nullptr)
    {
        return description;
    }
    else
    {
        return ""s;
    }
}

bool System::IsWglSupportsExtension(const char* wglExtension)
{
    return SupportsWglExtension(wglExtension);
}
