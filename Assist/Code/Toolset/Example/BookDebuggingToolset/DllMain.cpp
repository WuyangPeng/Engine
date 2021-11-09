///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 19:33)

#include "Toolset/Example/BookDebuggingToolset/BookDebuggingToolsetExport.h"

#include "BookDebuggingToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookDebuggingToolset);

#else  // defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookDebuggingToolset);

#endif  // !defined(BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC)