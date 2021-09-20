///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/DataStructuresWithCppUsingSTL/DataStructuresWithCppUsingSTLExport.h"

#include "DataStructuresWithCppUsingSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

DLL_MAIN_FUNCTION(DataStructuresWithCppUsingSTL);

#else  // BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

CORE_TOOLS_MUTEX_INIT(DataStructuresWithCppUsingSTL);

#endif  // !BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC
