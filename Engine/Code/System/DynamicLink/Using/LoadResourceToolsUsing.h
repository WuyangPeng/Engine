// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 13:39)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H

#include "LoadLibraryUsing.h"
#include "System/Helper/Platform.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using DynamicLinkResource = HRSRC;
	using DynamicLinkGlobal = HGLOBAL;

	// 预定义资源类型，指针只能用来传递给LoadResourceTools中定义的函数，指针不能进行解引用和打印。
	static const DynamicLinkCharType* g_PredefinedResourceTypesCursor = RT_CURSOR;
	static const DynamicLinkCharType* g_PredefinedResourceTypesBitmap = RT_BITMAP;
	static const DynamicLinkCharType* g_PredefinedResourceTypesIcon = RT_ICON;
	static const DynamicLinkCharType* g_PredefinedResourceTypesMenu = RT_MENU;
	static const DynamicLinkCharType* g_PredefinedResourceTypesDialog = RT_DIALOG;
	static const DynamicLinkCharType* g_PredefinedResourceTypesString = RT_STRING;
	static const DynamicLinkCharType* g_PredefinedResourceTypesFontDir = RT_FONTDIR;
	static const DynamicLinkCharType* g_PredefinedResourceTypesFont = RT_FONT;
	static const DynamicLinkCharType* g_PredefinedResourceTypesAccelerator = RT_ACCELERATOR;
	static const DynamicLinkCharType* g_PredefinedResourceTypesRcData = RT_RCDATA;
	static const DynamicLinkCharType* g_PredefinedResourceTypesMessageTable = RT_MESSAGETABLE;
	static const DynamicLinkCharType* g_PredefinedResourceTypesGroupCursor = RT_GROUP_CURSOR;
	static const DynamicLinkCharType* g_PredefinedResourceTypesGroupIcon = RT_GROUP_ICON;
	static const DynamicLinkCharType* g_PredefinedResourceTypesVersion = RT_VERSION;
	static const DynamicLinkCharType* g_PredefinedResourceTypesDlgInclude = RT_DLGINCLUDE;
	static const DynamicLinkCharType* g_PredefinedResourceTypesPlugplay = RT_PLUGPLAY;
	static const DynamicLinkCharType* g_PredefinedResourceTypesVxd = RT_VXD;
	static const DynamicLinkCharType* g_PredefinedResourceTypesAniCursor = RT_ANICURSOR;
	static const DynamicLinkCharType* g_PredefinedResourceTypesAniIcon = RT_ANIICON;
	static const DynamicLinkCharType* g_PredefinedResourceTypesHtml = RT_HTML;
	static const DynamicLinkCharType* g_PredefinedResourceTypesManifest = RT_MANIFEST;
	static const DynamicLinkCharType* g_CreateProcessManifestResourceID = CREATEPROCESS_MANIFEST_RESOURCE_ID;
	static const DynamicLinkCharType* g_IsolationawareManifestResourceID = ISOLATIONAWARE_MANIFEST_RESOURCE_ID;
	static const DynamicLinkCharType* g_IsolationawareNoStaticImportManifestResourceID = ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID;
	static const DynamicLinkCharType* g_MinimumReservedManifestResourceID = MINIMUM_RESERVED_MANIFEST_RESOURCE_ID;
	static const DynamicLinkCharType* g_MaximumReservedManifestResourceID = MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID;

#else // !SYSTEM_PLATFORM_WIN32		

	using DynamicLinkResource = void*;
	using DynamicLinkGlobal = void*;

	static const DynamicLinkCharType* g_PredefinedResourceTypesCursor = MakeIntreSource(1);
	static const DynamicLinkCharType* g_PredefinedResourceTypesBitmap = MakeIntreSource(2);
	static const DynamicLinkCharType* g_PredefinedResourceTypesIcon = MakeIntreSource(3);
	static const DynamicLinkCharType* g_PredefinedResourceTypesMenu = MakeIntreSource(4);
	static const DynamicLinkCharType* g_PredefinedResourceTypesDialog = MakeIntreSource(5);
	static const DynamicLinkCharType* g_PredefinedResourceTypesString = MakeIntreSource(6);
	static const DynamicLinkCharType* g_PredefinedResourceTypesFontDir = MakeIntreSource(7);
	static const DynamicLinkCharType* g_PredefinedResourceTypesFont = MakeIntreSource(8);
	static const DynamicLinkCharType* g_PredefinedResourceTypesAccelerator = MakeIntreSource(9);
	static const DynamicLinkCharType* g_PredefinedResourceTypesRcData = MakeIntreSource(10);
	static const DynamicLinkCharType* g_PredefinedResourceTypesMessageTable = MakeIntreSource(11);
	static const DynamicLinkCharType* g_PredefinedResourceTypesGroupCursor = MakeIntreSource(reinterpret_cast<WindowPtrULong>(g_PredefinedResourceTypesCursor) + 11);
	static const DynamicLinkCharType* g_PredefinedResourceTypesGroupIcon = MakeIntreSource(reinterpret_cast<WindowPtrULong>(g_PredefinedResourceTypesIcon) + 11);
	static const DynamicLinkCharType* g_PredefinedResourceTypesVersion = MakeIntreSource(16);
	static const DynamicLinkCharType* g_PredefinedResourceTypesDlgInclude = MakeIntreSource(17);
	static const DynamicLinkCharType* g_PredefinedResourceTypesPlugplay = MakeIntreSource(19);
	static const DynamicLinkCharType* g_PredefinedResourceTypesVxd = MakeIntreSource(20);
	static const DynamicLinkCharType* g_PredefinedResourceTypesAniCursor = MakeIntreSource(21);
	static const DynamicLinkCharType* g_PredefinedResourceTypesAniIcon = MakeIntreSource(22);
	static const DynamicLinkCharType* g_PredefinedResourceTypesHtml = MakeIntreSource(23);
	static const DynamicLinkCharType* g_PredefinedResourceTypesManifest = MakeIntreSource(24);
	static const DynamicLinkCharType* g_CreateProcessManifestResourceID = MakeIntreSource(1);
	static const DynamicLinkCharType* g_IsolationawareManifestResourceID = MakeIntreSource(2);
	static const DynamicLinkCharType* g_IsolationawareNoStaticImportManifestResourceID = MakeIntreSource(3);
	static const DynamicLinkCharType* g_MinimumReservedManifestResourceID = MakeIntreSource(1);
	static const DynamicLinkCharType* g_MaximumReservedManifestResourceID = MakeIntreSource(16);

#endif // SYSTEM_PLATFORM_WIN32 
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H
