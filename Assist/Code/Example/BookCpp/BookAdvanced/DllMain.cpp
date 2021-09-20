///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/09 22:11)

#include "Example/BookCpp/BookAdvanced/BookAdvancedExport.h"

#include "BookAdvancedFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_ADVANCED_STATIC

DLL_MAIN_FUNCTION(BookAdvanced);

#else  // !BUILDING_BOOK_ADVANCED_STATIC

CORE_TOOLS_MUTEX_INIT(BookAdvanced);

#endif  // BUILDING_BOOK_ADVANCED_STATIC
