/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:39)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H
#define DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

DATABASE_GENERATE_MIDDLE_LAYER_EXPORT_NON_COPY(SystemManagerImpl);

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager final : public Framework::SystemManagerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(SystemManager);
        using ParentType = SystemManagerInterface;

    public:
        SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        NODISCARD bool Destroy() noexcept override;

        NODISCARD bool Idle(int64_t timeDelta) override;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H
