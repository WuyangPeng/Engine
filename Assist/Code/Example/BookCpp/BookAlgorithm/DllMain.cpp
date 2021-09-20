///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/25 23:57)

#include "Example/BookCpp/BookAlgorithm/BookAlgorithmExport.h"

#include "BookAlgorithmFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_ALGORITHM_STATIC

DLL_MAIN_FUNCTION(BookAlgorithm);

#else  // !BUILDING_BOOK_ALGORITHM_STATIC

CORE_TOOLS_MUTEX_INIT(BookAlgorithm);

#endif  // BUILDING_BOOK_ALGORITHM_STATIC
