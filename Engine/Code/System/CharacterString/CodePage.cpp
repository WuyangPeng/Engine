// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:23)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::IsCodePageValid(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsValidCodePage(EnumCastUnderlying(codePage)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::CodePage System
	::GetANSICodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<CodePage>(::GetACP());
#else // !SYSTEM_PLATFORM_WIN32
	return CodePage::UTF8;
#endif // SYSTEM_PLATFORM_WIN32
}

System::CodePage System
	::GetOEMCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<CodePage>(::GetOEMCP());
#else // !SYSTEM_PLATFORM_WIN32
	return CodePage::UTF8;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetCodePageInfo(CodePage codePage, CodePageInfoPtr codePageInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetCPInfo(EnumCastUnderlying(codePage), codePageInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetCodePageInfo(CodePage codePage, CodePageInfoExPtr codePageInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetCPInfoEx(EnumCastUnderlying(codePage), 0, codePageInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
