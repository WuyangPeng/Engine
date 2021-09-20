///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:47)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "EffectiveModernCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_MODERN_CPP_STATIC

DLL_MAIN_FUNCTION(EffectiveModernCpp);

#else  // BUILDING_EFFECTIVE_MODERN_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveModernCpp);

#endif  // !BUILDING_EFFECTIVE_MODERN_CPP_STATIC
