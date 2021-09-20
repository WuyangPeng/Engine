///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:44)

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLExport.h"

#include "EffectiveSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_STL_STATIC

DLL_MAIN_FUNCTION(EffectiveSTL);

#else  // BUILDING_EFFECTIVE_STL_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveSTL);

#endif  // !BUILDING_EFFECTIVE_STL_STATIC
