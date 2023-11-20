/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#include "MessageClientMiddleLayerExport.h"

#include "MessageClientMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(MessageClientMiddleLayer);

#else  // !BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(MessageClientMiddleLayer);

#endif  // BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC