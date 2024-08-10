/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 13:26)

#ifndef FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/EngineConfiguration/GlobalConfig.h"
#include "CoreTools/FileManager/Environment.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SystemManagerImpl
    {
    public:
        using ClassType = SystemManagerImpl;

        using Environment = CoreTools::Environment;
        using GlobalConfig = CoreTools::GlobalConfig;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        explicit SystemManagerImpl(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        using GlobalConfigSharedPtr = std::shared_ptr<GlobalConfig>;

    private:
        // 支持访问环境变量和路径。
        Environment environment;

        GlobalConfigSharedPtr globalConfig;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
