///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <string>
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PropertyExternalTesting : public UnitTest
    {
    public:
        using ClassType = PropertyExternalTesting;
        using ParentType = UnitTest;

    public:
        explicit PropertyExternalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void GetSetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H
