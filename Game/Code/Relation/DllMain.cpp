///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:11)

#include "Relation/RelationExport.h"

#include "RelationFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RELATION_STATIC

DLL_MAIN_FUNCTION(Relation);

#else  // !BUILDING_RELATION_STATIC

CORE_TOOLS_MUTEX_INIT(Relation);

#endif  // BUILDING_RELATION_STATIC
