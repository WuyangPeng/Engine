///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/26 23:58)

#ifndef APPLIED_CPP_CHAPTER2_MAIN_H
#define APPLIED_CPP_CHAPTER2_MAIN_H

#include "Example/BookCpp/AppliedCpp/AppliedCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        class APPLIED_CPP_DEFAULT_DECLARE Chapter2Main final
        {
        public:
            using ClassType = Chapter2Main;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Chapter2Main() noexcept;

            [[nodiscard]] int Main() const;

            void ArbitraryAlgorithm() const;
        };
    }
}

#endif  // APPLIED_CPP_CHAPTER2_MAIN_H
