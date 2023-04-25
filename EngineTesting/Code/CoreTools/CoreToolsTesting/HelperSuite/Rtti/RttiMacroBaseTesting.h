///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:58)

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

    protected:
        NODISCARD const char* GetBaseRttiName() const noexcept;

    private:
        void DoRunUnitTest() override;
        virtual void MainTest();

        virtual void RttiTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_BASE_TESTING_H