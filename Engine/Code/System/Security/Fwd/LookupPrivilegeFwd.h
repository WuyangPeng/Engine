// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_FWD_H 
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_FWD_H  

#include "System/Security/Using/LookupPrivilegeUsing.h"

namespace System
{
	bool GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept;
	bool GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowDWordPtr nameSize) noexcept;
	bool GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowDWordPtr displayNameSize, WindowDWordPtr languageID) noexcept;
}

#endif // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_FWD_H