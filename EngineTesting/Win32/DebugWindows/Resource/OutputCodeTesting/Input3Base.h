/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT3_BASE_H
#define OUTPUT_C_S_V_TESTING_INPUT3_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace OutputCSVTesting
{
    class Input3Base
    {
    public:
        using ClassType = Input3Base;

        using Char = System::TChar;
        using String = System::String;

    public:
        Input3Base() noexcept = default;
        explicit Input3Base(int key) noexcept;

        virtual ~Input3Base() noexcept = default;
        Input3Base(const Input3Base& rhs) noexcept = default;
        Input3Base& operator=(const Input3Base& rhs) noexcept = default;
        Input3Base(Input3Base&& rhs) noexcept = default;
        Input3Base& operator=(Input3Base&& rhs) noexcept = default;

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

#endif  // OUTPUT_C_S_V_TESTING_INPUT3_BASE_H