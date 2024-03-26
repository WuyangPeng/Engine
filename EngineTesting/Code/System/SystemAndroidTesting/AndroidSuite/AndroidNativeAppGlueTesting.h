/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:08)

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
        explicit AndroidNativeAppGlueTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void VirtualAndroidNativeAppGlueTest();

    private:
        int index;
    };
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_SUITE_ANDROID_NATIVE_APP_GLUE_TESTING_H