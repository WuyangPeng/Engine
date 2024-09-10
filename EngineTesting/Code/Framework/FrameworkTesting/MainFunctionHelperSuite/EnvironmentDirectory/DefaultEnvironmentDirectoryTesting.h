/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/08/08 22:38)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DEFAULT_ENVIRONMENT_DIRECTORY_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DEFAULT_ENVIRONMENT_DIRECTORY_TESTING_H

#include "EnvironmentDirectoryTesting.h"

namespace Framework
{
    class DefaultEnvironmentDirectoryTesting final : public EnvironmentDirectoryTesting
    {
    public:
        using ClassType = DefaultEnvironmentDirectoryTesting;
        using ParentType = EnvironmentDirectoryTesting;

    public:
        explicit DefaultEnvironmentDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DEFAULT_ENVIRONMENT_DIRECTORY_TESTING_H