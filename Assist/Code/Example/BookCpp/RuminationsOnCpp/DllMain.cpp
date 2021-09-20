///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#include "Example/BookCpp/RuminationsOnCpp/RuminationsOnCppExport.h"

#include "RuminationsOnCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RUMINATIONS_ON_CPP_STATIC

DLL_MAIN_FUNCTION(RuminationsOnCpp);

#else  // BUILDING_RUMINATIONS_ON_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(RuminationsOnCpp);

#endif  // !BUILDING_RUMINATIONS_ON_CPP_STATIC
