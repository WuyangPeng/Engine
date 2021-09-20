///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/AdvancedQtProgramming/AdvancedQtProgrammingExport.h"

#include "AdvancedQtProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(AdvancedQtProgramming);

#else  // BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedQtProgramming);

#endif  // !BUILDING_ADVANCED_QT_PROGRAMMING_STATIC
