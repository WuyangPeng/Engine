///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/ElementaryNumberTheoryAndItsApplications/ElementaryNumberTheoryAndItsApplicationsExport.h"

#include "ElementaryNumberTheoryAndItsApplicationsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

DLL_MAIN_FUNCTION(ElementaryNumberTheoryAndItsApplications);

#else  // BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

CORE_TOOLS_MUTEX_INIT(ElementaryNumberTheoryAndItsApplications);

#endif  // !BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC
