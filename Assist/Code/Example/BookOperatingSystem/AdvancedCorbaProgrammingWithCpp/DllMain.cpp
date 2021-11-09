///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/AdvancedCorbaProgrammingWithCpp/AdvancedCorbaProgrammingWithCppExport.h"

#include "AdvancedCorbaProgrammingWithCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

DLL_MAIN_FUNCTION(AdvancedCorbaProgrammingWithCpp);

#else  // !BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedCorbaProgrammingWithCpp);

#endif  // BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC
