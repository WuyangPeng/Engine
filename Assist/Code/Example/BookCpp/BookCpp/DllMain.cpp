///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/19 21:23)

#include "Example/BookCpp/BookCpp/BookCppExport.h"

#include "BookCppFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_CPP_STATIC)

DLL_MAIN_FUNCTION(BookCpp);

#else  // defined(BUILDING_BOOK_CPP_STATIC)

CORE_TOOLS_MUTEX_INIT(BookCpp);

#endif  // !defined(BUILDING_BOOK_CPP_STATIC)