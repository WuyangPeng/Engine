///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 22:33)

#ifndef FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_MOCK_H
#define FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_MOCK_H

#include "Framework/Project/GUIProjectManager.h"

namespace Framework
{
    class GUIProjectManagerMock final : public GUIProjectManager
    {
    public:
        using ClassType = GUIProjectManagerMock;
        using ParentType = GUIProjectManager;
        using GUIProjectManagerSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static GUIProjectManagerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        GUIProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintSelect(const ProjectName& projectName) const noexcept override;
        void PrintEngineering(const String& engineeringName) const noexcept override;

        void Clear() noexcept;
        NODISCARD int GetPrintSelect() const noexcept;
        NODISCARD int GetPrintEngineering() const noexcept;

    private:
        mutable int printSelect;
        mutable int printEngineering;
    };
}

#endif  // FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_MOCK_H
