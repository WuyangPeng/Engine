///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/05 0:32)

#include "Example/BookCpp/BookIntermediate/BookIntermediateExport.h"

#include "BookIntermediateFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_INTERMEDIATE_STATIC

DLL_MAIN_FUNCTION(BookIntermediate);

#else  // !BUILDING_BOOK_INTERMEDIATE_STATIC

CORE_TOOLS_MUTEX_INIT(BookIntermediate);

#endif  // BUILDING_BOOK_INTERMEDIATE_STATIC
