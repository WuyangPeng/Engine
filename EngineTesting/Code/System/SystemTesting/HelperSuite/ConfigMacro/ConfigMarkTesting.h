/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 17:33)

#ifndef SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConfigMarkTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConfigMarkTesting;
        using ParentType = UnitTest;

    public:
        explicit ConfigMarkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void UnusedTest() const noexcept;
        void MaybeNullptrTest();
        void NodiscardTest();
        NODISCARD int FallthroughTest() const noexcept;
        NODISCARD int NoReturnTest() const;

        SYSTEM_DEPRECATED("�ú����ѱ�����")
        void Deprecate() const noexcept;

        MAYBE_NULLPTR const int* GetNullptr() const noexcept;
        SYSTEM_NORETURN static void NoReturn();

        void ArchitectureTypeTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_CONFIG_MARK_TESTING_H
