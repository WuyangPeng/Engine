// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:53)

#include "Relation/RelationExport.h"

#include "RelationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_RELATION_STATIC

	DLL_MAIN_FUNCTION(Relation);

#else // !BUILDING_RELATION_STATIC

	CORE_TOOLS_MUTEX_INIT(Relation);

#endif // BUILDING_RELATION_STATIC
