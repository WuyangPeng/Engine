// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:49)

#include "System/SystemExport.h"

#include "OpenGLUtility.h" 
#include "Detail/GLUtility.h"
#include "Detail/GLExtensions.h"
#include "Detail/WglExtensions.h"
#include "Flags/GLExtensionsFlags.h"
#include "System/CharacterString/FormatString.h"

using std::string;
using namespace std::literals;

System::OpenGLSystemVersion System
	::GetOpenGLVersion() noexcept
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

bool System
	::IsOpenGLSupportsExtension(const char* extension) noexcept
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

	auto begin = Strstr(extensionString, extension);
	if (begin == nullptr)
	{
		return false;
	}

	// 扩展被发现,但确保它不是另一个扩展的合适子串。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
	const auto end = *(begin + Strlen(extension));
#include STSTEM_WARNING_POP

	return end == ' ' || end == 0 || end == '\t' || end == '\n';
}

void* System
	::GetFunctionPointer(const char* glFunction) noexcept
{
	return GetOpenGLFunctionPointer(glFunction);
}

string System
	::GetOpenGLErrorDescription(OpenGLErrorCode code)
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

bool System
	::IsWglSupportsExtension(const char* wglExtension) noexcept
{
	return SupportsWglExtension(wglExtension);
}
