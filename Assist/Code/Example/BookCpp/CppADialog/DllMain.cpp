///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/27 18:42)

#include "Example/BookCpp/CppADialog/CppADialogExport.h"

#include "CppADialogFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_A_DIALOG_STATIC

DLL_MAIN_FUNCTION(CppADialog);

#else  // !BUILDING_CPP_A_DIALOG_STATIC

CORE_TOOLS_MUTEX_INIT(CppADialog);

#endif  // BUILDING_CPP_A_DIALOG_STATIC
