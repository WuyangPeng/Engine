///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:53)

#ifndef MODERN_CPP_DESIGN_PREFACE_PHYSICAL_H
#define MODERN_CPP_DESIGN_PREFACE_PHYSICAL_H

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace ModernCppDesign
    {
        template <int M, int L, int T>
        class Physical
        {
        public:
            using ClassType = Physical<M, L, T>;

        public:
            explicit Physical(int value) noexcept;

            CLASS_INVARIANT_DECLARE;

            int Value() const noexcept;

            Physical& operator*=(int rhs) noexcept;

            static Physical unit;

        private:
            int value;
        };

        template <int M, int L, int T>
        Physical<M, L, T> operator*(Physical<M, L, T> lhs, int rhs) noexcept;

        template <int M1, int L1, int T1, int M2, int L2, int T2>
        Physical<M1 + M2, L1 + L2, T1 + T2> operator*(Physical<M1, L1, T1> lhs, Physical<M2, L2, T2> rhs) noexcept;
    }
}

#endif  // MODERN_CPP_DESIGN_PREFACE_PHYSICAL_H
