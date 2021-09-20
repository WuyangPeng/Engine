///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/31 21:48)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H
#define SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeAppGlueTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeAppGlueTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeAppGlueTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void VirtualAndroidNativeAppGlueTest();
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H