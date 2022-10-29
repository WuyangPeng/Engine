///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/03 11:49)

#ifndef SYSTEM_TESTING_HELPER_SUITE_VARIABLE_TEMPLATE_TYPE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_VARIABLE_TEMPLATE_TYPE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class VariableTemplateTypeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VariableTemplateTypeTesting;
        using ParentType = UnitTest;

    public:
        explicit VariableTemplateTypeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void VariableTemplateTypeCountTest() noexcept;
        void VariableTemplateTypeTest() noexcept;
        void IsScalarTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_VARIABLE_TEMPLATE_TYPE_TESTING_H
