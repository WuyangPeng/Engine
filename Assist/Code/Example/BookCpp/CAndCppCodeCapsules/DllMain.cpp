///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/CAndCppCodeCapsules/CAndCppCodeCapsulesExport.h"

#include "CAndCppCodeCapsulesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

DLL_MAIN_FUNCTION(CAndCppCodeCapsules);

#else  // BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

CORE_TOOLS_MUTEX_INIT(CAndCppCodeCapsules);

#endif  // !BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC
