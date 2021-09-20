///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/29 22:10)

#include "Example/BookOperatingSystem/BookWindowsAPI/BookWindowsAPIExport.h"

#include "BookWindowsAPIFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_WINDOWS_API_STATIC

DLL_MAIN_FUNCTION(BookWindowsAPI);

#else  // !BUILDING_BOOK_WINDOWS_API_STATIC

CORE_TOOLS_MUTEX_INIT(BookWindowsAPI);

#endif  // BUILDING_BOOK_WINDOWS_API_STATIC
