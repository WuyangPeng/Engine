///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/SecureCodingInCAndCpp/SecureCodingInCAndCppExport.h"

#include "SecureCodingInCAndCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SECURE_CODING_IN_C_AND_CPP_STATIC

DLL_MAIN_FUNCTION(SecureCodingInCAndCpp);

#else  // BUILDING_SECURE_CODING_IN_C_AND_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(SecureCodingInCAndCpp);

#endif  // !BUILDING_SECURE_CODING_IN_C_AND_CPP_STATIC
