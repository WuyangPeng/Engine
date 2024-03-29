/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:50)

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
