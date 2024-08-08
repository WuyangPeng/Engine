/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/08 22:38)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_FILE_ENVIRONMENT_DIRECTORY_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_FILE_ENVIRONMENT_DIRECTORY_TESTING_H

#include "EnvironmentDirectoryTesting.h"

namespace Framework
{
    class FileEnvironmentDirectoryTesting final : public EnvironmentDirectoryTesting
    {
    public:
        using ClassType = FileEnvironmentDirectoryTesting;
        using ParentType = EnvironmentDirectoryTesting;

    public:
        explicit FileEnvironmentDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_FILE_ENVIRONMENT_DIRECTORY_TESTING_H