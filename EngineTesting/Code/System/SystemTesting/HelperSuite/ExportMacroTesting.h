/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 17:37)

#ifndef SYSTEM_TESTING_HELPER_SUITE_EXPORT_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 通过在ExportTest工具中定义，
    /// 来测试TCRE_SYMBOL_EXPORT、TCRE_SYMBOL_IMPORT、TCRE_SYMBOL_NO_EXPORT、TCRE_SYMBOL_NO_IMPORT和TCRE_SYMBOL_VISIBLE。
    class ExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ExportTest() const noexcept;
        void ExportFunctionTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_EXPORT_MACRO_TESTING_H
