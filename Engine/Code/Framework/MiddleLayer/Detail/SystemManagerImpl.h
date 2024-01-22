/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 22:58)

#ifndef FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/FileManager/Environment.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SystemManagerImpl
    {
    public:
        using ClassType = SystemManagerImpl;

        using Environment = CoreTools::Environment;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        explicit SystemManagerImpl(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    private:
        // 支持访问环境变量和路径。
        Environment environment;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
