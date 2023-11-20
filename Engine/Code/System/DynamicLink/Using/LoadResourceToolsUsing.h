///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:30)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H

#include "LoadLibraryUsing.h"
#include "System/Helper/Platform.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DynamicLinkResource = HRSRC;
    using DynamicLinkGlobal = HGLOBAL;

    // 预定义资源类型，指针只能用来传递给LoadResourceTools中定义的函数，指针不能进行解引用和打印。
    static const DynamicLinkCharType* predefinedResourceTypesCursor = RT_CURSOR;
    static const DynamicLinkCharType* predefinedResourceTypesBitmap = RT_BITMAP;
    static const DynamicLinkCharType* predefinedResourceTypesIcon = RT_ICON;
    static const DynamicLinkCharType* predefinedResourceTypesMenu = RT_MENU;
    static const DynamicLinkCharType* predefinedResourceTypesDialog = RT_DIALOG;
    static const DynamicLinkCharType* predefinedResourceTypesString = RT_STRING;
    static const DynamicLinkCharType* predefinedResourceTypesFontDir = RT_FONTDIR;
    static const DynamicLinkCharType* predefinedResourceTypesFont = RT_FONT;
    static const DynamicLinkCharType* predefinedResourceTypesAccelerator = RT_ACCELERATOR;
    static const DynamicLinkCharType* predefinedResourceTypesRcData = RT_RCDATA;
    static const DynamicLinkCharType* predefinedResourceTypesMessageTable = RT_MESSAGETABLE;
    static const DynamicLinkCharType* predefinedResourceTypesGroupCursor = RT_GROUP_CURSOR;
    static const DynamicLinkCharType* predefinedResourceTypesGroupIcon = RT_GROUP_ICON;
    static const DynamicLinkCharType* predefinedResourceTypesVersion = RT_VERSION;
    static const DynamicLinkCharType* predefinedResourceTypesDlgInclude = RT_DLGINCLUDE;
    static const DynamicLinkCharType* predefinedResourceTypesPlugPlay = RT_PLUGPLAY;
    static const DynamicLinkCharType* predefinedResourceTypesVxd = RT_VXD;
    static const DynamicLinkCharType* predefinedResourceTypesAniCursor = RT_ANICURSOR;
    static const DynamicLinkCharType* predefinedResourceTypesAniIcon = RT_ANIICON;
    static const DynamicLinkCharType* predefinedResourceTypesHtml = RT_HTML;
    static const DynamicLinkCharType* predefinedResourceTypesManifest = RT_MANIFEST;
    static const DynamicLinkCharType* createProcessManifestResourceId = CREATEPROCESS_MANIFEST_RESOURCE_ID;
    static const DynamicLinkCharType* isolationAwareManifestResourceId = ISOLATIONAWARE_MANIFEST_RESOURCE_ID;
    static const DynamicLinkCharType* isolationAwareNoStaticImportManifestResourceId = ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID;
    static const DynamicLinkCharType* minimumReservedManifestResourceId = MINIMUM_RESERVED_MANIFEST_RESOURCE_ID;
    static const DynamicLinkCharType* maximumReservedManifestResourceId = MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID;

#else  // !SYSTEM_PLATFORM_WIN32

    using DynamicLinkResource = void*;
    using DynamicLinkGlobal = void*;

    constexpr auto predefinedResourceTypesDifference = 11;

    static const DynamicLinkCharType* predefinedResourceTypesCursor = MakeIntreSource(1);
    static const DynamicLinkCharType* predefinedResourceTypesBitmap = MakeIntreSource(2);
    static const DynamicLinkCharType* predefinedResourceTypesIcon = MakeIntreSource(3);
    static const DynamicLinkCharType* predefinedResourceTypesMenu = MakeIntreSource(4);
    static const DynamicLinkCharType* predefinedResourceTypesDialog = MakeIntreSource(5);
    static const DynamicLinkCharType* predefinedResourceTypesString = MakeIntreSource(6);
    static const DynamicLinkCharType* predefinedResourceTypesFontDir = MakeIntreSource(7);
    static const DynamicLinkCharType* predefinedResourceTypesFont = MakeIntreSource(8);
    static const DynamicLinkCharType* predefinedResourceTypesAccelerator = MakeIntreSource(9);
    static const DynamicLinkCharType* predefinedResourceTypesRcData = MakeIntreSource(10);
    static const DynamicLinkCharType* predefinedResourceTypesMessageTable = MakeIntreSource(11);
    static const DynamicLinkCharType* predefinedResourceTypesGroupCursor = MakeIntreSource(reinterpret_cast<WindowsULongPtrSizeType>(predefinedResourceTypesCursor) + predefinedResourceTypesDifference);
    static const DynamicLinkCharType* predefinedResourceTypesGroupIcon = MakeIntreSource(reinterpret_cast<WindowsULongPtrSizeType>(predefinedResourceTypesIcon) + predefinedResourceTypesDifference);
    static const DynamicLinkCharType* predefinedResourceTypesVersion = MakeIntreSource(16);
    static const DynamicLinkCharType* predefinedResourceTypesDlgInclude = MakeIntreSource(17);
    static const DynamicLinkCharType* predefinedResourceTypesPlugPlay = MakeIntreSource(19);
    static const DynamicLinkCharType* predefinedResourceTypesVxd = MakeIntreSource(20);
    static const DynamicLinkCharType* predefinedResourceTypesAniCursor = MakeIntreSource(21);
    static const DynamicLinkCharType* predefinedResourceTypesAniIcon = MakeIntreSource(22);
    static const DynamicLinkCharType* predefinedResourceTypesHtml = MakeIntreSource(23);
    static const DynamicLinkCharType* predefinedResourceTypesManifest = MakeIntreSource(24);
    static const DynamicLinkCharType* createProcessManifestResourceId = MakeIntreSource(1);
    static const DynamicLinkCharType* isolationAwareManifestResourceId = MakeIntreSource(2);
    static const DynamicLinkCharType* isolationAwareNoStaticImportManifestResourceId = MakeIntreSource(3);
    static const DynamicLinkCharType* minimumReservedManifestResourceId = MakeIntreSource(1);
    static const DynamicLinkCharType* maximumReservedManifestResourceId = MakeIntreSource(16);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_USING_H
