///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:18)

#ifndef CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_BASE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_BASE_TESTING_H

#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RttiMacroBaseTesting : public UnitTest
    {
    public:
        using ClassType = RttiMacroBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit RttiMacroBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RttiTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_BASE_TESTING_H