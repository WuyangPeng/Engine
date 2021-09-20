///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/05 0:32)

#include "Example/BookCpp/BookIntermediate/BookIntermediateExport.h"

#include "BookIntermediateFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_INTERMEDIATE_STATIC

DLL_MAIN_FUNCTION(BookIntermediate);

#else  // !BUILDING_BOOK_INTERMEDIATE_STATIC

CORE_TOOLS_MUTEX_INIT(BookIntermediate);

#endif  // BUILDING_BOOK_INTERMEDIATE_STATIC
