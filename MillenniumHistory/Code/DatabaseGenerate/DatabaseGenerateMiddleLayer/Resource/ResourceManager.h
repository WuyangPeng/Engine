/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:38)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_H
#define DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksFwd.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

DATABASE_GENERATE_MIDDLE_LAYER_EXPORT_NON_COPY(ResourceManagerImpl);

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager final : public Framework::ResourceManagerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceManager);
        using ParentType = ResourceManagerInterface;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;
        using ConstAncientBooksContainerSharedPtr = std::shared_ptr<const AncientBooks::AncientBooksContainer>;

    public:
        ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        NODISCARD bool Destroy() noexcept override;

        NODISCARD ConstAncientBooksContainerSharedPtr GetAncientBooksContainer();

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_RESOURCE_RESOURCE_MANAGER_H
