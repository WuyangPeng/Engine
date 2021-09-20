///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 23:51)

#include "Example/BookCpp/BookExperience/BookExperienceExport.h"

#include "BookExperienceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_EXPERIENCE_STATIC

DLL_MAIN_FUNCTION(BookExperience);

#else  // !BUILDING_BOOK_EXPERIENCE_STATIC

CORE_TOOLS_MUTEX_INIT(BookExperience);

#endif  // BUILDING_BOOK_EXPERIENCE_STATIC
