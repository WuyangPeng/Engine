///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 10:18)

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
        void DoRunUnitTest() override;
        void MainTest() override;

        void RttiTest() override;

        CORE_TOOLS_RTTI_FINAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H