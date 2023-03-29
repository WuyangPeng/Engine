///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:25)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertiesTesting final : public UnitTest
    {
    public:
        using ClassType = PropertiesTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertiesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PropertiesTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_PROPERTIES_TESTING_H