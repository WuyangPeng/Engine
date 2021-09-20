///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/GrokkingAlgorithms/GrokkingAlgorithmsExport.h"

#include "GrokkingAlgorithmsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GROKKING_ALGORITHMS_STATIC

DLL_MAIN_FUNCTION(GrokkingAlgorithms);

#else  // BUILDING_GROKKING_ALGORITHMS_STATIC

CORE_TOOLS_MUTEX_INIT(GrokkingAlgorithms);

#endif  // !BUILDING_GROKKING_ALGORITHMS_STATIC
