// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 13:40)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H

#include "System/SystemDll.h" 

#include "Fwd/DynamicLinkDataFwd.h"
#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "Using/EnumResourceToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"

namespace System
{
	// 枚举动态链接库中的资源。

	bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
															   EnumResourceLanguageProcess enumFunction, WindowPtrLong param) noexcept;
	bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, EnumResourceLanguageProcess enumFunction,
															   WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

	bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type,
														   EnumResourceNameProcess enumFunction, WindowPtrLong param) noexcept;
	bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction,
														   WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

	bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param) noexcept;
	bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param,
														   ResourceEnum flags, const LanguageIDData& language) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
