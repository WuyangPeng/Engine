///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/20 11:01)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreFwd.h"

#ifndef BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

DLL_MAIN_FUNCTION(DistanceAlignedBoxesCore);

#else  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DistanceAlignedBoxesCore);

#endif  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC
