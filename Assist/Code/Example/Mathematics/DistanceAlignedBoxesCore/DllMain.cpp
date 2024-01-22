/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:33)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreFwd.h"

#ifndef BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

DLL_MAIN_FUNCTION(DistanceAlignedBoxesCore);

#else  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DistanceAlignedBoxesCore);

#endif  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC
