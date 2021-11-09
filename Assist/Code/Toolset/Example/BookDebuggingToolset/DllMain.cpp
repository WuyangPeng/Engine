///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 19:33)

#include "Toolset/Example/BookDebuggingToolset/BookDebuggingToolsetExport.h"

#include "BookDebuggingToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookDebuggingToolset);

#else  // defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookDebuggingToolset);

#endif  // !defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)