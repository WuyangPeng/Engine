///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:47)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "EffectiveModernCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_MODERN_CPP_STATIC

DLL_MAIN_FUNCTION(EffectiveModernCpp);

#else  // BUILDING_EFFECTIVE_MODERN_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveModernCpp);

#endif  // !BUILDING_EFFECTIVE_MODERN_CPP_STATIC
