///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 14:50)

#ifndef CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H

#include "RttiMacroBaseTesting.h"

namespace CoreTools
{
    class RttiMacroTesting : public RttiMacroBaseTesting
    {
    public:
        using ClassType = RttiMacroTesting;
        using ParentType = RttiMacroBaseTesting;

    public:
        explicit RttiMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RttiTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H