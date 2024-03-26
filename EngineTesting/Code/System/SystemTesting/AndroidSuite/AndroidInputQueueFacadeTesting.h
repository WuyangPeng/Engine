/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:10)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// SystemAndroidTesting��Android�����Ĳ��ԡ�
    /// �����ǿղ��ԡ�
    class AndroidInputQueueFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputQueueFacadeTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputQueueFacadeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_INPUT_QUEUE_FACADE_TESTING_H