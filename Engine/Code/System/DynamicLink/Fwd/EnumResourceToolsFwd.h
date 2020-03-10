// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:45)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FWD_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FWD_H

#include "DynamicLinkDataFwd.h"
#include "DynamicLinkFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Using/EnumResourceToolsUsing.h"

namespace System
{
	bool EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
										EnumResourceLanguageProcess enumFunction, WindowPtrLong param) noexcept;
	bool EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name,EnumResourceLanguageProcess enumFunction, 
										WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

	bool EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction, WindowPtrLong param) noexcept;
	bool EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction,
									WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

	bool EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param) noexcept;
	bool EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param,
									ResourceEnum flags, const LanguageIDData& language) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FWD_H
