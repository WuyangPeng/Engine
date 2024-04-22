/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_INPUT2_BASE_H
#define CSV_OUTPUT_INPUT2_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace CsvOutput
{
    class Input2Base
    {
    public:
        using ClassType = Input2Base;

        using Char = System::TChar;
        using String = System::String;

    public:
        Input2Base() noexcept = default;
        explicit Input2Base(int key) noexcept;

        virtual ~Input2Base() noexcept = default;
        Input2Base(const Input2Base& rhs) noexcept = default;
        Input2Base& operator=(const Input2Base& rhs) noexcept = default;
        Input2Base(Input2Base&& rhs) noexcept = default;
        Input2Base& operator=(Input2Base&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual bool IsTest0() const noexcept;

        NODISCARD virtual Char GetTest1() const noexcept;

        NODISCARD virtual double GetTest2() const noexcept;

        NODISCARD virtual int GetTest4() const noexcept;

        NODISCARD virtual String GetTest5() const;

    private:
        int key{};
    };
}

#endif  // CSV_OUTPUT_INPUT2_BASE_H