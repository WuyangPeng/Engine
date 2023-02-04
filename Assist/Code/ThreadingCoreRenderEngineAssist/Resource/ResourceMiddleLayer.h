///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 14:00)

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
        ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool PreCreate() final;
        NODISCARD bool Initialize() final;

        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD const String GetEngineeringNameOrEmpty(int select) const;

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
