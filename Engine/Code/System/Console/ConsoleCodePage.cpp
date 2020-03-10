// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:36)

#include "System/SystemExport.h"

#include "ConsoleCodePage.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::CodePage System
	::GetConsoleCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<CodePage>(::GetConsoleCP());
#else // !SYSTEM_PLATFORM_WIN32
	return CodePage::UTF8;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetConsoleCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleCP(EnumCastUnderlying(codePage)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(codePage);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::CodePage System
	::GetConsoleOutputCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<CodePage>(::GetConsoleOutputCP());
#else // !SYSTEM_PLATFORM_WIN32
	return CodePage::UTF8;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetConsoleOutputCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleOutputCP(EnumCastUnderlying(codePage)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(codePage);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
