/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_INPUT1_BASE_H
#define CSV_OUTPUT_INPUT1_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <vector>

namespace CsvOutput
{
    class Input1Base
    {
    public:
        using ClassType = Input1Base;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;

    public:
        Input1Base() noexcept = default;
        explicit Input1Base(int key) noexcept;

        virtual ~Input1Base() noexcept = default;
        Input1Base(const Input1Base& rhs) noexcept = default;
        Input1Base& operator=(const Input1Base& rhs) noexcept = default;
        Input1Base(Input1Base&& rhs) noexcept = default;
        Input1Base& operator=(Input1Base&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual bool IsTest0() const noexcept;

        NODISCARD virtual System::TChar GetTest1() const noexcept;

        NODISCARD virtual double GetTest2() const noexcept;

        NODISCARD virtual int GetTest4() const noexcept;

        NODISCARD virtual String GetTest5() const;

        NODISCARD virtual StringContainer GetTest6() const;
        NODISCARD virtual int GetTest6Count() const;
        NODISCARD virtual String GetTest6(int index) const;
        NODISCARD virtual StringContainerConstIter GetTest6Begin() const;
        NODISCARD virtual StringContainerConstIter GetTest6End() const;

    private:
        int key{};
    };
}

#endif  // CSV_OUTPUT_INPUT1_BASE_H
