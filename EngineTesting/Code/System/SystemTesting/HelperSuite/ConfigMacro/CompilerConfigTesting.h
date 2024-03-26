/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:33)

#ifndef SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 测试编译器配置
    /// 测试SelectCompilerConfig.h
    /// TCRE_COMPILER_VERSION、TCRE_SYSTEM_COMPILER和SYSTEM_CPP_STANDARD宏必须存在。
    /// 测试VisualC.h
    /// MSVC_VERSION、TCRE_USE_MSVC、MSVC_FULL_VERSION和TCRE_COMPILER_VERSION宏必须存在。
    class CompilerConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CompilerConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit CompilerConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CompilerTest();
        void VisualCTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
