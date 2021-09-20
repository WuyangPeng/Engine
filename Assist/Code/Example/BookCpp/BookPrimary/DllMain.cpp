///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/21 20:48)

#include "Example/BookCpp/BookPrimary/BookPrimaryExport.h"

#include "BookPrimaryFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_PRIMARY_STATIC

DLL_MAIN_FUNCTION(BookPrimary);

#else  // BUILDING_BOOK_PRIMARY_STATIC

CORE_TOOLS_MUTEX_INIT(BookPrimary);

#endif  // !BUILDING_BOOK_PRIMARY_STATIC
