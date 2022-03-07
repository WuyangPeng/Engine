///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 14:45)

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