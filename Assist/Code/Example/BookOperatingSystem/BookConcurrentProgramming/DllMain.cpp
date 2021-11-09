///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/26 23:04)

#include "Example/BookOperatingSystem/BookConcurrentProgramming/BookConcurrentProgrammingExport.h"

#include "BookConcurrentProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(BookConcurrentProgramming);

#else  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(BookConcurrentProgramming);

#endif  // BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC
