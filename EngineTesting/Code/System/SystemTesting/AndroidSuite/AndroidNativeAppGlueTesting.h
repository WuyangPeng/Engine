///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:54)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeAppGlueTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeAppGlueTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeAppGlueTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H