///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 15:19)

#include "Example/BookCpp/CppEffectiveObjectOrientedSoftwareConstruction/CppEffectiveObjectOrientedSoftwareConstructionExport.h"

#include "CppEffectiveObjectOrientedSoftwareConstructionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC

DLL_MAIN_FUNCTION(CppEffectiveObjectOrientedSoftwareConstruction);

#else  // BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC

CORE_TOOLS_MUTEX_INIT(CppEffectiveObjectOrientedSoftwareConstruction);

#endif  // !BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC
