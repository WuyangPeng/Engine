///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:58)

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

    protected:
        NODISCARD const char* GetRttiName() const noexcept;

    private:
        void DoRunUnitTest() override;
        void MainTest() override;

        void RttiTest() override;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H