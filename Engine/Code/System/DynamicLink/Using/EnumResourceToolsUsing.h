// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:45)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using EnumResourceLanguageProcess = ENUMRESLANGPROC;
	using EnumResourceNameProcess = ENUMRESNAMEPROC;
	using EnumResourceTypeProcess = ENUMRESTYPEPROC;

#else // !SYSTEM_PLATFORM_WIN32		

	using EnumResourceLanguageProcess = WindowBool(*)(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowWord language, WindowPtrLong param);
	using EnumResourceNameProcess = WindowBool(*)(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowPtrLong param);
	using EnumResourceTypeProcess = WindowBool(*)(DynamicLinkModule module, DynamicLinkCharType* type, WindowPtrLong param);

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H
