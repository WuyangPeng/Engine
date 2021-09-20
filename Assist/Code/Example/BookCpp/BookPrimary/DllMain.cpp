///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/21 20:48)

#include "Example/BookCpp/BookPrimary/BookPrimaryExport.h"

#include "BookPrimaryFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_PRIMARY_STATIC

DLL_MAIN_FUNCTION(BookPrimary);

#else  // BUILDING_BOOK_PRIMARY_STATIC

CORE_TOOLS_MUTEX_INIT(BookPrimary);

#endif  // !BUILDING_BOOK_PRIMARY_STATIC
