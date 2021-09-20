///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/GenericProgrammingAndTheSTL/GenericProgrammingAndTheSTLExport.h"

#include "GenericProgrammingAndTheSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

DLL_MAIN_FUNCTION(GenericProgrammingAndTheSTL);

#else  // BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

CORE_TOOLS_MUTEX_INIT(GenericProgrammingAndTheSTL);

#endif  // !BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC
