///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/23 22:40)

#include "Toolset/Example/BookWindowsAPIToolset/BookWindowsAPIToolsetExport.h"

#include "BookWindowsAPIToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookWindowsAPIToolset);

#else  // defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookWindowsAPIToolset);

#endif  // !defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)