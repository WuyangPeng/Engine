///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 15:07)

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

        [[nodiscard]] bool PreCreate(const EnvironmentDirectory& environmentDirectory) final;
        [[nodiscard]] bool Initialize() final;

        [[nodiscard]] bool IsSelectValid(int select) const;
        [[nodiscard]] const String GetEngineeringName(int select) const;

        void PrintEngineering(const String& engineeringName);

    private:
        using ProjectNameUniquePtr = std::unique_ptr<ProjectName>;

    private:
        Directory directory;
        ProjectNameUniquePtr projectName;
    };
}

#endif  // THE_LAST_OVERLORD_RESOURCE_MIDDLE_LAYER_H
