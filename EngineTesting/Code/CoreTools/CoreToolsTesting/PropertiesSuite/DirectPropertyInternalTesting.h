/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/27 19:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DirectPropertyInternalTesting final : public UnitTest
    {
    public:
        using ClassType = DirectPropertyInternalTesting;
        using ParentType = UnitTest;

    public:
        explicit DirectPropertyInternalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetTypeTest();
        void SetValueTest();
        void GetValueTest();

    private:
        std::string getType;
        std::string setType;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H
