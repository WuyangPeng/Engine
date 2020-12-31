//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/26 15:32)

#include "System/SystemExport.h"

#include "OpenGLUtility.h"
#include "Flags/GLExtensionsFlags.h"
#include "Detail/GLExtensions.h"
#include "Detail/GLUtility.h"
#include "Detail/WglExtensions.h"
#include "System/CharacterString/FormatString.h"

using std::string;
using namespace std::literals;

System::OpenGLSystemVersion System::GetOpenGLVersion() noexcept
{
    auto token = GetVersionString();
    if (token != nullptr)
    {
        const auto major = *token;
        if (major != '\0')
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++token;
            if (token != nullptr && *token == '.')
            {
                ++token;
                if (token != nullptr)
                {
                    const auto minor = *token;

                    return GetOpenGLVersion(major, minor);
                }
            }
#include STSTEM_WARNING_POP
        }
    }

    return OpenGLSystemVersion::VersionNone;
}

bool System::IsOpenGLSupportsExtension(const char* extension)
{
    if (extension == nullptr)
    {
        return false;
    }

    auto extensionString = GetExtensionString();
    if (extensionString == nullptr)
    {
        return false;
    }

    string glExtension{ extensionString };

    const auto pos = glExtension.find(extension);

    if (pos == string::npos)
    {
        return false;
    }

    const auto endPos = pos + Strlen(extension);

    if (endPos >= glExtension.size())
    {
        return true;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto end = glExtension[endPos];
#include STSTEM_WARNING_POP

    // 扩展被发现,但确保它不是另一个扩展的合适子串。

    return end == ' ' || end == 0 || end == '\t' || end == '\n';
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
