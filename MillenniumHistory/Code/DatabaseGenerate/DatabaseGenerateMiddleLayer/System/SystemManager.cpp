/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/28 22:39)

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/DatabaseGenerateMiddleLayerClassInvariantMacro.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Resource/ResourceManager.h"
#include "SystemManager.h"
#include "Detail/SystemManagerImpl.h"

DatabaseGenerateMiddleLayer::SystemManager::SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayer, SystemManager)

bool DatabaseGenerateMiddleLayer::SystemManager::Idle(int64_t timeDelta)
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    System::UnusedFunction(timeDelta);

    const auto resource = GetResourceManager<ResourceManager>();

    if (const auto ancientBooksContainer = resource->GetAncientBooksContainer();
        ancientBooksContainer != nullptr)
    {
        return impl->Idle(*ancientBooksContainer);
    }

    return true;
}

bool DatabaseGenerateMiddleLayer::SystemManager::Initialize()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Initialize();
}

bool DatabaseGenerateMiddleLayer::SystemManager::Destroy() noexcept
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Destroy();
}
