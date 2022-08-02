///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/19 16:55)

#ifndef THE_LAST_OVERLORD_RESOURCE_MIDDLE_LAYER_H
#define THE_LAST_OVERLORD_RESOURCE_MIDDLE_LAYER_H

#include "TheLastOverlord/Core/ProjectName.h"
#include "CoreTools/FileManager/Directory.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace TheLastOverlord
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

        NODISCARD bool PreCreate(const EnvironmentDirectory& environmentDirectory) final;
        NODISCARD bool Initialize() final;

        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;

        void PrintEngineering(const String& engineeringName);

    private:
        using ProjectNameUniquePtr = std::unique_ptr<ProjectName>;

    private:
        Directory directory;
        ProjectNameUniquePtr projectName;
    };
}

#endif  // THE_LAST_OVERLORD_RESOURCE_MIDDLE_LAYER_H
