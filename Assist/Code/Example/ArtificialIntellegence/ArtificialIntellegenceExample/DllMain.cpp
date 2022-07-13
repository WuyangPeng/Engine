///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 18:42)

#include "Example/ArtificialIntellegence/ArtificialIntellegenceExample/ArtificialIntellegenceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/ArtificialIntellegence/ArtificialIntellegenceExample/ArtificialIntellegenceExampleFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntellegenceExample);

#else  // !BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntellegenceExample);

#endif  // !BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC
