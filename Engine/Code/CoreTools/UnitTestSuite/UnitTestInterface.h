//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 13:27)

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

        [[nodiscard]] virtual const std::string GetName() const = 0;
        [[nodiscard]] virtual int GetPassedNumber() const noexcept = 0;
        [[nodiscard]] virtual int GetFailedNumber() const noexcept = 0;
        [[nodiscard]] virtual int GetErrorNumber() const noexcept = 0;
        virtual void PrintReport() = 0;

        virtual void ResetTestData() = 0;
        virtual void RunUnitTest() = 0;

        virtual void PrintRunUnitTest() = 0;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H
