///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:44)

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLExport.h"

#include "EffectiveSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_STL_STATIC

DLL_MAIN_FUNCTION(EffectiveSTL);

#else  // BUILDING_EFFECTIVE_STL_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveSTL);

#endif  // !BUILDING_EFFECTIVE_STL_STATIC
