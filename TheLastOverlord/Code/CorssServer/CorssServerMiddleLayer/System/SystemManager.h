/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define CORSS_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "CorssServer/CorssServerMiddleLayer/CorssServerMiddleLayerDll.h"

#include "CorssServer/CorssServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace CorssServerMiddleLayer
{
    class CORSS_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemManager;
        using ParentType = SystemManagerInterface;

    public:
        SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORSS_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
