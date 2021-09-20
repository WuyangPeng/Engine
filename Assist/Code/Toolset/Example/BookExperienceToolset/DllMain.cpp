///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/23 22:17)

#include "Toolset/Example/BookExperienceToolset/BookExperienceToolsetExport.h"

#include "BookExperienceToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookExperienceToolset);

#else  // defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookExperienceToolset);

#endif  // !defined(BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC)