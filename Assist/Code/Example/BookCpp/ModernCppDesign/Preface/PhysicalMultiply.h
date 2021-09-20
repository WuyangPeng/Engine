///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:53)

#ifndef MODERN_CPP_DESIGN_PREFACE_PHYSICAL_MULTIPLY_H
#define MODERN_CPP_DESIGN_PREFACE_PHYSICAL_MULTIPLY_H

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace ModernCppDesign
    {
        class MODERN_CPP_DESIGN_DEFAULT_DECLARE PhysicalMultiply
        {
        public:
            using ClassType = PhysicalMultiply;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            PhysicalMultiply() noexcept;

            int Multiply(int lhs, int rhs) const noexcept;
        };
    }
}

#endif  // MODERN_CPP_DESIGN_PREFACE_PHYSICAL_MULTIPLY_H
