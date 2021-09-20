///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/23 22:40)

#include "Toolset/Example/BookWindowsAPIToolset/BookWindowsAPIToolsetExport.h"

#include "BookWindowsAPIToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookWindowsAPIToolset);

#else  // defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookWindowsAPIToolset);

#endif  // !defined(BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC)