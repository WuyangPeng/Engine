///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/12 0:06)

#include "Toolset/Example/BookACEToolset/BookACEToolsetExport.h"

#include "BookACEToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_ACE_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookACEToolset);

#else  // defined(BUILDING_BOOK_ACE_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookACEToolset);

#endif  // !defined(BUILDING_BOOK_ACE_TOOLSET_STATIC)