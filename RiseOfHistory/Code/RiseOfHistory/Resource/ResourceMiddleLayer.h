///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:41)

#ifndef RISE_OF_HISTORY_RESOURCE_MIDDLE_LAYER_H
#define RISE_OF_HISTORY_RESOURCE_MIDDLE_LAYER_H

#include "RiseOfHistory/Core/ProjectName.h"
#include "RiseOfHistory/GUI/GUIFwd.h"
#include "CoreTools/FileManager/Directory.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace RiseOfHistory
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

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) final;
        NODISCARD bool Initialize() final;

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

#endif  // RISE_OF_HISTORY_RESOURCE_MIDDLE_LAYER_H
