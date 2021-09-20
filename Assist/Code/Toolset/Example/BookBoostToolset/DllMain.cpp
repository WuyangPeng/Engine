///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 20:45)

#include "Toolset/Example/BookBoostToolset/BookBoostToolsetExport.h"

#include "BookBoostToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_BOOST_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookBoostToolset);

#else  // defined(BUILDING_BOOK_BOOST_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookBoostToolset);

#endif  // !defined(BUILDING_BOOK_BOOST_TOOLSET_STATIC)