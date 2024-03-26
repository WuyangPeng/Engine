/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:14)

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
        void DoRunUnitTest() override;
        void MainTest();

        void VariableTemplateTypeCountTest() const noexcept;
        void VariableTemplateTypeTest() const noexcept;
        void IsScalarTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_VARIABLE_TEMPLATE_TYPE_TESTING_H
