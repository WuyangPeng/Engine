// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:07)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegence/ArtificialIntellegenceFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	DLL_MAIN_FUNCTION(ArtificialIntellegence);

#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	CORE_TOOLS_MUTEX_INIT(ArtificialIntellegence);

#endif // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC