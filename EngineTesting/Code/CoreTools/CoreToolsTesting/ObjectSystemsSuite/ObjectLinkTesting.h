///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectLinkTesting : public UnitTest
    {
    public:
        using ClassType = ObjectLinkTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectLinkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InsertObjectPtrTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H