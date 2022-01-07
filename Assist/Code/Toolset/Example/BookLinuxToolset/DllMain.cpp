///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/24 20:50)

#include "Toolset/Example/BookLinuxToolset/BookLinuxToolsetExport.h"

#include "BookLinuxToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookLinuxToolset);

#else  // defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookLinuxToolset);

#endif  // !defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)