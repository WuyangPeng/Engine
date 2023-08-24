///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 20:33)

#ifndef FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class GLUTApplicationInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GLUTApplicationInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit GLUTApplicationInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void InformationTest();
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H