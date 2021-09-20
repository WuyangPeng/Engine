///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:06)

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
