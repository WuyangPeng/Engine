///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H

#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RttiTestingBase : public UnitTest
    {
    public:
        using ClassType = RttiTestingBase;
        using ParentType = UnitTest;

    public:
        explicit RttiTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;

    private:
        void MainTest();
        void RttiTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H