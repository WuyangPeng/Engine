/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:07)

#ifndef SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 这个类用于测试WglExtensionsMacro头文件。
    /// 通过包含System/Helper/WglExtensionsMacro.h文件来实现测试，
    /// 类本身是空测试。
    class WglExtensionsMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WglExtensionsMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit WglExtensionsMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H
