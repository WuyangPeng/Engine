///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 0:13)

#include "Example/BookCpp/ExceptionalCppStyle/ExceptionalCppStyleExport.h"

#include "ExceptionalCppStyleFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

DLL_MAIN_FUNCTION(ExceptionalCppStyle);

#else  // BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

CORE_TOOLS_MUTEX_INIT(ExceptionalCppStyle);

#endif  // !BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC
