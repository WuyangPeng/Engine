///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/18 22:33)

#ifndef FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_MOCK_H
#define FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_MOCK_H

#include "Framework/Project/ResourceProjectManager.h"

namespace Framework
{
    class ResourceProjectManagerMock final : public ResourceProjectManager
    {
    public:
        using ClassType = ResourceProjectManagerMock;
        using ParentType = ResourceProjectManager;
        using ResourceProjectManagerSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static ResourceProjectManagerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        ResourceProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool IsSelectValid(int select) const noexcept override;
        NODISCARD String GetEngineeringName(int select) const override;

        void PrintEngineering(const String& engineeringName) const noexcept override;

        void Clear() noexcept;
        NODISCARD int GetPrintEngineering() const noexcept;

    private:
        mutable int printEngineering;
    };
}

#endif  // FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_MOCK_H
