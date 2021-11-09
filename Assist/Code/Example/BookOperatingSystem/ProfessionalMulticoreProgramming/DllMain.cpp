///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ProfessionalMulticoreProgramming/ProfessionalMulticoreProgrammingExport.h"

#include "ProfessionalMulticoreProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(ProfessionalMulticoreProgramming);

#else  // !BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(ProfessionalMulticoreProgramming);

#endif  // BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC
