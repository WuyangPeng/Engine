///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.2 (2022/09/11 22:00)

#ifndef RISE_OF_HISTORY_SYSTEM_MIDDLE_LAYER_H
#define RISE_OF_HISTORY_SYSTEM_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace RiseOfHistory
{
    class SystemMiddleLayer final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemMiddleLayer;
        using ParentType = SystemManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Execute(int select);

        NODISCARD int GetContainerPrintWidth() const;
    };
}

#endif  // RISE_OF_HISTORY_SYSTEM_MIDDLE_LAYER_H