///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/21 19:12)

#include "Example/BookCpp/BookBoost/BookBoostExport.h"

#include "BookBoostFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_BOOST_STATIC

DLL_MAIN_FUNCTION(BookBoost);

#else  // BUILDING_BOOK_BOOST_STATIC

CORE_TOOLS_MUTEX_INIT(BookBoost);

#endif  // !BUILDING_BOOK_BOOST_STATIC
