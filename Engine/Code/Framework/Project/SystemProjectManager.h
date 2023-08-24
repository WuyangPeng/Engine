///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 16:13)

#ifndef FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_H
#define FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE SystemProjectManager : public SystemManagerInterface
    {
    public:
        using ClassType = SystemProjectManager;
        using ParentType = SystemManagerInterface;

    public:
        SystemProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void Execute(int select);

        NODISCARD int GetContainerPrintWidth() const;
    };
}

#endif  // FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_H
