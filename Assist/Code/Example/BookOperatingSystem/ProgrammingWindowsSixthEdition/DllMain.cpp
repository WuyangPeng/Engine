///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/03 15:36)

#include "Example/BookOperatingSystem/ProgrammingWindowsSixthEdition/ProgrammingWindowsSixthEditionExport.h"

#include "ProgrammingWindowsSixthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROGRAMMING_WINDOWS_SIXTH_EDITION_STATIC

DLL_MAIN_FUNCTION(ProgrammingWindowsSixthEdition);

#else  // !BUILDING_PROGRAMMING_WINDOWS_SIXTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(ProgrammingWindowsSixthEdition);

#endif  // BUILDING_PROGRAMMING_WINDOWS_SIXTH_EDITION_STATIC
