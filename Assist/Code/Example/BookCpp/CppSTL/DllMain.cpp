///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/CppSTL/CppSTLExport.h"

#include "CppSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_STL_STATIC

DLL_MAIN_FUNCTION(CppSTL);

#else  // BUILDING_CPP_STL_STATIC

CORE_TOOLS_MUTEX_INIT(CppSTL);

#endif  // !BUILDING_CPP_STL_STATIC
