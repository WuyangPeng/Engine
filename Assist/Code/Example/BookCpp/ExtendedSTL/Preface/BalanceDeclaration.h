///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/02 21:57)

#ifndef EXTENDED_STL_PREFACE_BALANCE_DECLARATION_H
#define EXTENDED_STL_PREFACE_BALANCE_DECLARATION_H

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace ExtendedSTL
    {
        class NonCopyable
        {
        public:  // Member Types
            using ClassType = NonCopyable;

        public:
            NonCopyable() noexcept = default;
            ~NonCopyable() noexcept = default;
            NonCopyable(NonCopyable&&) noexcept = default;
            NonCopyable& operator=(NonCopyable&&) noexcept = default;

        private:  // Not to be implemented
            NonCopyable(const NonCopyable&);
            NonCopyable& operator=(const NonCopyable&);
        };
    }
}

#endif  // EXTENDED_STL_PREFACE_BALANCE_DECLARATION_H
