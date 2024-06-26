/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:15)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE MainFunctionHelperBaseImpl
    {
    public:
        using ClassType = MainFunctionHelperBaseImpl;

        using String = System::String;

    public:
        explicit MainFunctionHelperBaseImpl(EnvironmentDirectory environmentDirectory) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetEngineInstallationDirectory() const;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    private:
        EnvironmentDirectory environmentDirectory;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H