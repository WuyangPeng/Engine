///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:26)

#include "Example/BookCpp/AlgorithmsFourthEdition/AlgorithmsFourthEditionExport.h"

#include "AlgorithmsFourthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

DLL_MAIN_FUNCTION(AlgorithmsFourthEdition);

#else  // BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmsFourthEdition);

#endif  // !BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC
