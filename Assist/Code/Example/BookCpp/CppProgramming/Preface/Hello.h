///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2020/12/31 23:06)

#ifndef CPP_PROGRAMMING_PREFACE_HELLO_H
#define CPP_PROGRAMMING_PREFACE_HELLO_H

#include "Example/BookCpp/CppProgramming/CppProgrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookPrimary
{
    namespace CppProgramming
    {
        class CPP_PROGRAMMING_DEFAULT_DECLARE Hello final
        {
        public:
            using ClassType = Hello;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Hello() noexcept;

            [[nodiscard]] int Main() const;
        };
    }
}

#endif  // CPP_PROGRAMMING_PREFACE_HELLO_H
