/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:28)

#ifndef CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// 宏MAIN_FUNCTION、CORE_TOOLS_MUTEX_INIT和CORE_TOOLS_MUTEX_EXTERN使用Toolset中的MainFunction测试。
    /// 宏DLL_MAIN_FUNCTION使用Toolset中的DllMainFunction测试。
    /// 这里为空测试。
    class MainFunctionMacroTesting final : public UnitTest
    {
    public:
        using ClassType = MainFunctionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MainFunctionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H