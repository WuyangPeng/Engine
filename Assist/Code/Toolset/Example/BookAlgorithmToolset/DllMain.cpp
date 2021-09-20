///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/15 1:02)

#include "Toolset/Example/BookAlgorithmToolset/BookAlgorithmToolsetExport.h"

#include "BookAlgorithmToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookAlgorithmToolset);

#else  // defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookAlgorithmToolset);

#endif  // !defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)