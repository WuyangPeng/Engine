///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/ElementaryNumberTheoryAndItsApplications/ElementaryNumberTheoryAndItsApplicationsExport.h"

#include "ElementaryNumberTheoryAndItsApplicationsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

DLL_MAIN_FUNCTION(ElementaryNumberTheoryAndItsApplications);

#else  // BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

CORE_TOOLS_MUTEX_INIT(ElementaryNumberTheoryAndItsApplications);

#endif  // !BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC
