///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/13 14:26)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AppPropertiesTesting final : public UnitTest
    {
    public:
        using ClassType = AppPropertiesTesting;
        using ParentType = UnitTest;

    public:
        explicit AppPropertiesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AppendSheetNameTest();
        void DeleteSheetNameTest();
        void SetSheetNameTest();
        void PropertyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_APP_PROPERTIES_TESTING_H