///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 1:02)

#include "Toolset/Example/BookAlgorithmToolset/BookAlgorithmToolsetExport.h"

#include "BookAlgorithmToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookAlgorithmToolset);

#else  // defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookAlgorithmToolset);

#endif  // !defined(BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC)