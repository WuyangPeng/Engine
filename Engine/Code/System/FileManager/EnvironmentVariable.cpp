// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:55)

#include "System/SystemExport.h"

#include "EnvironmentVariable.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"

#ifdef SYSTEM_PLATFORM_WIN32
#include <tchar.h>
#endif // SYSTEM_PLATFORM_WIN32

bool System
	::GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept
{
#if defined(SYSTEM_PLATFORM_ANDROID)
	environmentVariable = nullptr;

	SYSTEM_UNUSED_ARG(variableName);

	return false;
#elif defined(TCRE_USE_GCC)
	#ifdef UNICODE
		environmentVariable = ::_wgetenv(variableName.c_str());
	#else // !UNICODE
		environmentVariable = ::getenv(variableName.c_str());
	#endif // UNICODE

	if (environmentVariable == nullptr)
		return false;
	else
		return true;
#else // !TCRE_USE_GCC && !SYSTEM_PLATFORM_ANDROID
	size_t length{ 0 };

	const auto error = _tdupenv_s(&environmentVariable, &length, variableName.c_str());
	if (error != 0)
		return false;
	else
		return true;
#endif // ANDROID
}

void System
	::FreeEnvironment(TChar*& environmentVariable) noexcept
{
#if defined(SYSTEM_PLATFORM_ANDROID)
	environmentVariable = nullptr;
#else // !SYSTEM_PLATFORM_ANDROID

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26408)
	::free(environmentVariable);
	#include STSTEM_WARNING_POP

	environmentVariable = nullptr;
#endif // SYSTEM_PLATFORM_ANDROID
}

