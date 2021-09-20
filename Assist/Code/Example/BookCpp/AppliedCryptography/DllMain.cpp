///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#include "Example/BookCpp/AppliedCryptography/AppliedCryptographyExport.h"

#include "AppliedCryptographyFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

DLL_MAIN_FUNCTION(AppliedCryptography);

#else  // BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

CORE_TOOLS_MUTEX_INIT(AppliedCryptography);

#endif  // !BUILDING_APPLIED_CRYPTOGRAPHY_STATIC
