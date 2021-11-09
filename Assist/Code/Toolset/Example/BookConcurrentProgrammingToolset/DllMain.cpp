///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/02 22:35)

#include "Toolset/Example/BookConcurrentProgrammingToolset/BookConcurrentProgrammingToolsetExport.h"

#include "BookConcurrentProgrammingToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookConcurrentProgrammingToolset);

#else  // defined(BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookConcurrentProgrammingToolset);

#endif  // !defined(BUILDING_BOOK_CONCURRENT_PROGRAMMING_TOOLSET_STATIC)