///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 23:41)

#include "Example/BookCpp/BookTemplate/BookTemplateExport.h"

#include "BookTemplateFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_TEMPLATE_STATIC

DLL_MAIN_FUNCTION(BookTemplate);

#else  // !BUILDING_BOOK_TEMPLATE_STATIC

CORE_TOOLS_MUTEX_INIT(BookTemplate);

#endif  // BUILDING_BOOK_TEMPLATE_STATIC
