///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 0:13)

#include "Example/BookCpp/ExceptionalCppStyle/ExceptionalCppStyleExport.h"

#include "ExceptionalCppStyleFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

DLL_MAIN_FUNCTION(ExceptionalCppStyle);

#else  // BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

CORE_TOOLS_MUTEX_INIT(ExceptionalCppStyle);

#endif  // !BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC
