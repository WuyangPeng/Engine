///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#ifndef CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_FIBONACCI_H
#define CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_FIBONACCI_H

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CrossPlatformDevelopmentInCpp
    {
        class CROSS_PLATFORM_DEVELOPMENT_IN_CPP_DEFAULT_DECLARE Fibonacci final
        {
        public:
            using ClassType = Fibonacci;

        public:
            Fibonacci() noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int F(const int n) const noexcept;
        };
    }
}

#endif  // CROSS_PLATFORM_DEVELOPMENT_IN_CPP_PREFACE_FIBONACCI_H
