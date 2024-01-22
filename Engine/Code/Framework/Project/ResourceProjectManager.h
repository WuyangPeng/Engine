/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:50)

#ifndef FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_H
#define FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ResourceProjectManagerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ResourceProjectManager : public ResourceManagerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ResourceProjectManager);
        using ParentType = ResourceManagerInterface;

        using String = System::String;

    public:
        explicit ResourceProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;

        NODISCARD virtual bool IsSelectValid(int select) const;
        NODISCARD virtual String GetEngineeringName(int select) const;

        virtual void PrintEngineering(const String& engineeringName) const;

        NODISCARD int GetContainerPrintWidth() const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_H
