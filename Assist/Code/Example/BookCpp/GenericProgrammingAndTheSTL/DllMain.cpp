///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/GenericProgrammingAndTheSTL/GenericProgrammingAndTheSTLExport.h"

#include "GenericProgrammingAndTheSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

DLL_MAIN_FUNCTION(GenericProgrammingAndTheSTL);

#else  // BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

CORE_TOOLS_MUTEX_INIT(GenericProgrammingAndTheSTL);

#endif  // !BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC
