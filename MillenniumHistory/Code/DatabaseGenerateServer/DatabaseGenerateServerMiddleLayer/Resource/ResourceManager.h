///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/12 21:56)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

EXPORT_SHARED_PTR(DatabaseGenerateServerMiddleLayer, ResourceManagerImpl, DATABASE_GENERATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE);
EXPORT_NON_COPY(DatabaseGenerateServerMiddleLayer, ResourceManagerImpl, DATABASE_GENERATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE);

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceManager);
        using ParentType = Framework::ResourceManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RESOURCE_MANAGER_H
