// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H

#include "System/SystemDll.h" 

#include "Using/LookupPrivilegeUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 查找权限

	bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowDWordPtr nameSize) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowDWordPtr displayNameSize, WindowDWordPtr languageID) noexcept;
}

#endif // SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H