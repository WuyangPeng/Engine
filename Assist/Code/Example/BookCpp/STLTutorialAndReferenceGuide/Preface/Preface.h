///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:02)

#ifndef STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_H
#define STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_H

#include "Example/BookCpp/STLTutorialAndReferenceGuide/STLTutorialAndReferenceGuideDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace STLTutorialAndReferenceGuide
    {
        class STL_TUTORIAL_AND_REFERENCE_GUIDE_DEFAULT_DECLARE Preface final
        {
        public:
            using ClassType = Preface;

        public:
            Preface() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const;

            template <typename T>
            T Gcd0(T m, T n) const noexcept;

            template <typename T>
            T Gcd1(T m, T n) const noexcept;
        };
    }
}

#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_H
