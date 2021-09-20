///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#ifndef DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_X_H
#define DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_X_H

#include "Example/BookCpp/DesigningAndCodingReusableCpp/DesigningAndCodingReusableCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iosfwd>

namespace BookAdvanced
{
    namespace DesigningAndCodingReusableCpp
    {
        class Z
        {
            void F() noexcept;
        };

        template <typename T>
        class X0
        {
            void F() noexcept
            {
            }
        };

        class X1
        {
            class Y
            {
            };
        };

        template <typename T>
        class X2
        {
        };

        template <typename T>
        class X3
        {
        };

        template <>
        class X3<int>
        {
        };
    }
}

#endif  // DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_X_H
