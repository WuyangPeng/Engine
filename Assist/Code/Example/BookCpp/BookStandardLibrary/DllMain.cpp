///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/25 20:44)

#include "Example/BookCpp/BookStandardLibrary/BookStandardLibraryExport.h"

#include "BookStandardLibraryFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_STANDARD_LIBRARY_STATIC

DLL_MAIN_FUNCTION(BookStandardLibrary);

#else  // !BUILDING_BOOK_STANDARD_LIBRARY_STATIC

CORE_TOOLS_MUTEX_INIT(BookStandardLibrary);

#endif  // BUILDING_BOOK_STANDARD_LIBRARY_STATIC
