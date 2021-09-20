///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/06 23:41)

#include "Example/BookCpp/BookTemplate/BookTemplateExport.h"

#include "BookTemplateFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_TEMPLATE_STATIC

DLL_MAIN_FUNCTION(BookTemplate);

#else  // !BUILDING_BOOK_TEMPLATE_STATIC

CORE_TOOLS_MUTEX_INIT(BookTemplate);

#endif  // BUILDING_BOOK_TEMPLATE_STATIC
