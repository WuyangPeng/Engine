/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:03)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H

#include "CoreTools/Exception/Error.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ErrorTesting final : public UnitTest
    {
    public:
        using ClassType = ErrorTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit ErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NormalErrorTest();
        void WindowsErrorTest();
        void OpenFileErrorTest();
        void ComErrorTest();
        void ThrowExceptionTest();
        void ThrowLastExceptionTest();

        void FunctionDescribedTest(const FunctionDescribed& functionDescribed, const Error& error);

        NODISCARD static Error::Format GetOpenFileError(const String& fileName);
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_ERROR_TESTING_H
