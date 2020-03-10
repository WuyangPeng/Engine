// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "LookupPrivilege.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::LookupPrivilegeValue(systemName, name, luid)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(systemName);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(luid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowDWordPtr nameSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::LookupPrivilegeName(systemName, luid, name, nameSize)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(systemName);
	SYSTEM_UNUSED_ARG(luid);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(nameSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowDWordPtr displayNameSize, WindowDWordPtr languageID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::LookupPrivilegeDisplayName(systemName, name, displayName, displayNameSize, languageID)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(systemName);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(displayName);
	SYSTEM_UNUSED_ARG(displayNameSize);
	SYSTEM_UNUSED_ARG(languageId);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
