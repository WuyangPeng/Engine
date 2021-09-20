///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/IntroductionToAlgorithmsSecondEdition/IntroductionToAlgorithmsSecondEditionExport.h"

#include "IntroductionToAlgorithmsSecondEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC

DLL_MAIN_FUNCTION(IntroductionToAlgorithmsSecondEdition);

#else  // BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(IntroductionToAlgorithmsSecondEdition);

#endif  // !BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC
