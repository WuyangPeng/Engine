///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/16 21:34)

#ifndef MILLENNIUM_HISTORY_SYSTEM_MANAGER_H
#define MILLENNIUM_HISTORY_SYSTEM_MANAGER_H

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace MillenniumHistory
{
    class SystemManager final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemManager;
        using ParentType = SystemManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Execute(int select);

        NODISCARD int GetContainerPrintWidth() const;
    };
}

#endif  // MILLENNIUM_HISTORY_SYSTEM_MANAGER_H
