/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:39)

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