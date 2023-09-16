///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:41)

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

        void VariableTemplateTypeCountTest() noexcept;
        void VariableTemplateTypeTest() noexcept;
        void IsScalarTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_VARIABLE_TEMPLATE_TYPE_TESTING_H
