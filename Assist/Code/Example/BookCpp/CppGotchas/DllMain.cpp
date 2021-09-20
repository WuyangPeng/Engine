///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/CppGotchas/CppGotchasExport.h"

#include "CppGotchasFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_GOTCHAS_STATIC

DLL_MAIN_FUNCTION(CppGotchas);

#else  // BUILDING_CPP_GOTCHAS_STATIC

CORE_TOOLS_MUTEX_INIT(CppGotchas);

#endif  // !BUILDING_CPP_GOTCHAS_STATIC
