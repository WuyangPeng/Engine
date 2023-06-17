///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:39)

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
        explicit MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetEngineInstallationDirectory() const;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    private:
        EnvironmentDirectory environmentDirectory;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H