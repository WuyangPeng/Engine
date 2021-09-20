///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 14:50)

#ifndef CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H

#include "RttiMacroTesting.h"

namespace CoreTools
{
    class RttiMacroFinalTesting final : public RttiMacroTesting
    {
    public:
        using ClassType = RttiMacroFinalTesting;
        using ParentType = RttiMacroTesting;

    public:
        explicit RttiMacroFinalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RttiTest();

        CORE_TOOLS_RTTI_FINAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H