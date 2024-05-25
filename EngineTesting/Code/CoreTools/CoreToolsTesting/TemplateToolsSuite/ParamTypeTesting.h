/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 11:07)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H

#include "CoreTools/TemplateTools/ParamType.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ParamTypeTesting final : public UnitTest
    {
    public:
        using ClassType = ParamTypeTesting;
        using ParentType = UnitTest;

    public:
        explicit ParamTypeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ParamTypeTest(ParamType<int>::type integer, ParamType<std::string>::type characterString) noexcept;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H