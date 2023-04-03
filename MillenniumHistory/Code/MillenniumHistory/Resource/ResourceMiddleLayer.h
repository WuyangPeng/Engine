///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:28)

#ifndef MILLENNIUM_HISTORY_RESOURCE_MIDDLE_LAYER_H
#define MILLENNIUM_HISTORY_RESOURCE_MIDDLE_LAYER_H

#include "MillenniumHistory/Core/ProjectName.h"
#include "MillenniumHistory/GUI/GUIFwd.h"
#include "CoreTools/FileManager/Directory.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace MillenniumHistory
{
    class ResourceMiddleLayer final : public Framework::ResourceManagerInterface
    {
    public:
        using ClassType = ResourceMiddleLayer;
        using ParentType = ResourceManagerInterface;

        using String = System::String;
        using Directory = CoreTools::Directory;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using GUIMiddleLayerSharedPtr = std::shared_ptr<GUIMiddleLayer>;

    public:
        explicit ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;

        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;

        void PrintEngineering(const String& engineeringName);

        NODISCARD int GetContainerPrintWidth() const;

    private:
        using ProjectNameUniquePtr = std::unique_ptr<ProjectName>;

    private:
        NODISCARD GUIMiddleLayerSharedPtr GetGUIMiddleLayer();
        void CheckProjectName() const;

    private:
        Directory directory;
        ProjectNameUniquePtr projectName;
    };
}

#endif  // MILLENNIUM_HISTORY_RESOURCE_MIDDLE_LAYER_H
