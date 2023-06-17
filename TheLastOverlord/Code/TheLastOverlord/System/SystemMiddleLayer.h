///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2023/06/17 15:01)

#ifndef THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H
#define THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace TheLastOverlord
{
    class SystemMiddleLayer final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemMiddleLayer;
        using ParentType = SystemManagerInterface;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;

    public:
        SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Execute(int select);
    };
}

#endif  // THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H
