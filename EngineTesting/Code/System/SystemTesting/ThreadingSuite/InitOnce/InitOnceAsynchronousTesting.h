/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:02)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H

#include "InitOnceTestingBase.h"
#include "System/Threading/Using/InitOnceUsing.h"

namespace System
{
    class InitOnceAsynchronousTesting final : public InitOnceTestingBase
    {
    public:
        using ClassType = InitOnceAsynchronousTesting;
        using ParentType = InitOnceTestingBase;

    public:
        explicit InitOnceAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AsynchronousTest();
        void CreateThreadTest();
        void BeginInitializeTest(InitOncePtr initOnce);

        NODISCARD WindowsHandle OpenEventHandleAsync(InitOncePtr initOnce);
        NODISCARD WindowsHandle GetInitOnceCompleteHandle(InitOncePtr initOnce);

        NODISCARD static WindowsHandle GetInitOnceBeginInitializeHandle(InitOncePtr initOnce) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H