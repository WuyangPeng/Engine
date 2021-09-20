///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/23 22:17)

#include "Toolset/Example/BookExperienceToolset/BookExperienceToolsetExport.h"

#include "BookExperienceToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookExperienceToolset);

#else  // defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookExperienceToolset);

#endif  // !defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)