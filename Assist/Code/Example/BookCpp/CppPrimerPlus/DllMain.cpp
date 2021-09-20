///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/28 20:44)

#include "Example/BookCpp/CppPrimerPlus/CppPrimerPlusExport.h"

#include "CppPrimerPlusFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_PRIMER_PLUS_STATIC

DLL_MAIN_FUNCTION(CppPrimerPlus);

#else  // BUILDING_CPP_PRIMER_PLUS_STATIC

CORE_TOOLS_MUTEX_INIT(CppPrimerPlus);

#endif  // !BUILDING_CPP_PRIMER_PLUS_STATIC
