///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H

#include "RttiTestingBase.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class RttiTesting : public RttiTestingBase
    {
    public:
        using ClassType = RttiTesting;
        using ParentType = RttiTestingBase;

    public:
        explicit RttiTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void RttiTest();

        void DoRunUnitTest() override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H