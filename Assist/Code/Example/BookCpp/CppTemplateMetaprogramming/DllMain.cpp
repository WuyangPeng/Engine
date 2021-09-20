///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/07 18:48)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "CppTemplateMetaprogrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC

DLL_MAIN_FUNCTION(CppTemplateMetaprogramming);

#else  // BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(CppTemplateMetaprogramming);

#endif  // !BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC
