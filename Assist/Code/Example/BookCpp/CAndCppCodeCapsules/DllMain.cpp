///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/CAndCppCodeCapsules/CAndCppCodeCapsulesExport.h"

#include "CAndCppCodeCapsulesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

DLL_MAIN_FUNCTION(CAndCppCodeCapsules);

#else  // BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

CORE_TOOLS_MUTEX_INIT(CAndCppCodeCapsules);

#endif  // !BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC
