///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:01)

#include "Example/BookCpp/STLTutorialAndReferenceGuide/STLTutorialAndReferenceGuideExport.h"

#include "STLTutorialAndReferenceGuideFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC

DLL_MAIN_FUNCTION(STLTutorialAndReferenceGuide);

#else  // BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC

CORE_TOOLS_MUTEX_INIT(STLTutorialAndReferenceGuide);

#endif  // !BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC
