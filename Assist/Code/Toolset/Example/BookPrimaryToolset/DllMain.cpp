///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/04 23:11)

#include "Toolset/Example/BookPrimaryToolset/BookPrimaryToolsetExport.h"

#include "BookPrimaryToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookPrimaryToolset);

#else  // defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookPrimaryToolset);

#endif  // !defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)