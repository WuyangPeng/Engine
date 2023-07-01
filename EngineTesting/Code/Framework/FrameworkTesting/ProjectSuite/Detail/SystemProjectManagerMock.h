///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:10)

#ifndef FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_MOCK_H
#define FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_MOCK_H

#include "Framework/Project/SystemProjectManager.h"

namespace Framework
{
    class SystemProjectManagerMock final : public SystemProjectManager
    {
    public:
        using ClassType = SystemProjectManagerMock;
        using ParentType = SystemProjectManager;
        using SystemProjectManagerSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static SystemProjectManagerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        SystemProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Execute(int select) noexcept override;

        NODISCARD int GetExecute() const noexcept;
        void Clear() noexcept;

    private:
        int execute;
    };
}

#endif  // FRAMEWORK_PROJECT_SYSTEM_PROJECT_MANAGER_MOCK_H
