///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/AdvancedQtProgramming/AdvancedQtProgrammingExport.h"

#include "AdvancedQtProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(AdvancedQtProgramming);

#else  // BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedQtProgramming);

#endif  // !BUILDING_ADVANCED_QT_PROGRAMMING_STATIC
