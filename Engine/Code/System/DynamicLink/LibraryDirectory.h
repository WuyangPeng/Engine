// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:47)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H

#include "System/SystemDll.h" 

#include "Using/LoadLibraryUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 设置动态链接库的载入目录。

	bool SYSTEM_DEFAULT_DECLARE SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetLibraryDirectory(WindowDWord bufferLength, DynamicLinkCharType* buffer) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
