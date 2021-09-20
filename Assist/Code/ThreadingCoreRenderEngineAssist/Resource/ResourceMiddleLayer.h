///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 10:47)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_RESOURCE_MIDDLE_LAYER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_RESOURCE_MIDDLE_LAYER_H

#include "ThreadingCoreRenderEngineAssist/Core/ProjectName.h"
#include "ThreadingCoreRenderEngineAssist/GUI/GUIFwd.h"
#include "CoreTools/FileManager/Directory.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace ThreadingCoreRenderEngineAssist
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

    public:
        explicit ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool PreCreate(const EnvironmentDirectory& environmentDirectory) final;
        [[nodiscard]] bool Initialize() final;

        [[nodiscard]] bool IsSelectValid(int select) const;
        [[nodiscard]] const String GetEngineeringNameOrEmpty(int select) const;

        void PrintEngineering(const String& engineeringName);

    private:
        using ProjectNameUniquePtr = std::unique_ptr<ProjectName>;
        using GUIMiddleLayerSharedPtr = std::shared_ptr<GUIMiddleLayer>;

    private:
        GUIMiddleLayerSharedPtr GetGUIMiddleLayer();

    private:
        Directory directory;
        ProjectNameUniquePtr projectName;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_RESOURCE_MIDDLE_LAYER_H
