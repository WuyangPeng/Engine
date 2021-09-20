///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/CppForTheImpatient/CppForTheImpatientExport.h"

#include "CppForTheImpatientFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

DLL_MAIN_FUNCTION(CppForTheImpatient);

#else  // BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

CORE_TOOLS_MUTEX_INIT(CppForTheImpatient);

#endif  // !BUILDING_CPP_FOR_THE_IMPATIENT_STATIC
