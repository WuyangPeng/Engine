///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/21 19:12)

#include "Example/BookCpp/BookBoost/BookBoostExport.h"

#include "BookBoostFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_BOOST_STATIC

DLL_MAIN_FUNCTION(BookBoost);

#else  // BUILDING_BOOK_BOOST_STATIC

CORE_TOOLS_MUTEX_INIT(BookBoost);

#endif  // !BUILDING_BOOK_BOOST_STATIC
