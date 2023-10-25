///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 13:46)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestInterface
    {
    public:
        using ClassType = UnitTestInterface;

    public:
        UnitTestInterface() noexcept;
        virtual ~UnitTestInterface() noexcept = default;

        UnitTestInterface(const UnitTestInterface& rhs) = default;
        UnitTestInterface& operator=(const UnitTestInterface& rhs) = default;
        UnitTestInterface(UnitTestInterface&& rhs) noexcept = default;
        UnitTestInterface& operator=(UnitTestInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual std::string GetName() const = 0;
        NODISCARD virtual int GetPassedNumber() const noexcept = 0;
        NODISCARD virtual int GetFailedNumber() const noexcept = 0;
        NODISCARD virtual int GetErrorNumber() const noexcept = 0;

        virtual void PrintReport() = 0;
        virtual void ResetTestData() = 0;
        virtual void RunUnitTest() = 0;
        virtual void PrintRunUnitTest() = 0;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H
