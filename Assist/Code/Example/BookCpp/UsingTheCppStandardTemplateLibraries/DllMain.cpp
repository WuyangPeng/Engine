///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/06 16:29)

#include "Example/BookCpp/UsingTheCppStandardTemplateLibraries/UsingTheCppStandardTemplateLibrariesExport.h"

#include "UsingTheCppStandardTemplateLibrariesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC

DLL_MAIN_FUNCTION(UsingTheCppStandardTemplateLibraries);

#else  // BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC

CORE_TOOLS_MUTEX_INIT(UsingTheCppStandardTemplateLibraries);

#endif  // !BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC
