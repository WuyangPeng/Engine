///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/29 22:10)

#include "Example/BookOperatingSystem/BookWindowsAPI/BookWindowsAPIExport.h"

#include "BookWindowsAPIFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_WINDOWS_API_STATIC

DLL_MAIN_FUNCTION(BookWindowsAPI);

#else  // !BUILDING_BOOK_WINDOWS_API_STATIC

CORE_TOOLS_MUTEX_INIT(BookWindowsAPI);

#endif  // BUILDING_BOOK_WINDOWS_API_STATIC
