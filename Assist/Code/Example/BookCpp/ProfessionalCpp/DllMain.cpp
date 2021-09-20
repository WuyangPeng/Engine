///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/ProfessionalCpp/ProfessionalCppExport.h"

#include "ProfessionalCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROFESSIONAL_CPP_STATIC

DLL_MAIN_FUNCTION(ProfessionalCpp);

#else  // BUILDING_PROFESSIONAL_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(ProfessionalCpp);

#endif  // !BUILDING_PROFESSIONAL_CPP_STATIC
