/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 10:34)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// 这个测试不直接测试AppProperties，
    /// 而是通过Document类间接调用AppProperties的相关函数。
    class AppPropertiesTesting final : public UnitTest
    {
    public:
        using ClassType = AppPropertiesTesting;
        using ParentType = UnitTest;

    public:
        explicit AppPropertiesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AppendSheetNameTest();
        void DeleteSheetNameTest();
        void SetSheetNameTest();
        void PropertyTest();

    private:
        std::string docPath;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H