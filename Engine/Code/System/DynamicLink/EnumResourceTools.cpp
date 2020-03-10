// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:48)

#include "System/SystemExport.h"

#include "EnumResourceTools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

bool System
	::EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
									 EnumResourceLanguageProcess enumFunction, WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceLanguages(module, type, name, enumFunction, param) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, EnumResourceLanguageProcess enumFunction,
									 WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceLanguagesEx(module, type, name, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction, WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceNames(module, type, enumFunction, param) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction,
								 WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceNamesEx(module, type, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceTypes(module, enumFunction, param) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param,
								 ResourceEnum flags, const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EnumResourceTypesEx(module, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
