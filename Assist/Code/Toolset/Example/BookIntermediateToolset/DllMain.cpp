///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/24 16:24)

#include "Toolset/Example/BookIntermediateToolset/BookIntermediateToolsetExport.h"

#include "BookIntermediateToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookIntermediateToolset);

#else  // defined(BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookIntermediateToolset);

#endif  // !defined(BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC)