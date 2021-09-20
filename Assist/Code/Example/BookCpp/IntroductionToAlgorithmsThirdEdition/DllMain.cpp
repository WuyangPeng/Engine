///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/IntroductionToAlgorithmsThirdEdition/IntroductionToAlgorithmsThirdEditionExport.h"

#include "IntroductionToAlgorithmsThirdEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC

DLL_MAIN_FUNCTION(IntroductionToAlgorithmsThirdEdition);

#else  // BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(IntroductionToAlgorithmsThirdEdition);

#endif  // !BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC
