///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/25 23:57)

#include "Example/BookCpp/BookAlgorithm/BookAlgorithmExport.h"

#include "BookAlgorithmFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_ALGORITHM_STATIC

DLL_MAIN_FUNCTION(BookAlgorithm);

#else  // !BUILDING_BOOK_ALGORITHM_STATIC

CORE_TOOLS_MUTEX_INIT(BookAlgorithm);

#endif  // BUILDING_BOOK_ALGORITHM_STATIC
