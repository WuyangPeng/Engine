///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/31 21:43)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidLooperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidLooperTesting;
        using ParentType = UnitTest;

    public:
        AndroidLooperTesting(const OStreamShared& streamShared, AndroidApp* androidApp);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AndroidLooperTest();

    private:
        AndroidApp* androidApp;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_LOOPER_TESTING_H