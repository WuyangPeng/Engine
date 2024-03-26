/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 17:34)

#ifndef SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ���Թ̶���С����int8_t��int16_t��int32_t��int64_t��uint8_t��uint16_t��uint32_t��uint64_t����Сֵ�����ֵ��
    class FixedSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FixedSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit FixedSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerSizeTest() const noexcept;
        void IntegerMinCriticalTest();
        void IntegerMaxCriticalTest();
        void Integer64Test() const noexcept;

        template <typename T>
        void DoIntegerMinCriticalTest(T oldValue, T newValue);

        template <typename T>
        void DoIntegerMaxCriticalTest(T oldValue, T newValue);
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_H
