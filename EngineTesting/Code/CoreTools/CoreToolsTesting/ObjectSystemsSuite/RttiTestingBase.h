///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:13)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H

#include "CoreTools/Helper/RttiMacro.h"
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
        virtual void RttiTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H