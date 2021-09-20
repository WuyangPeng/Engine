///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:02)

#ifndef STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_DETAIL_H
#define STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_DETAIL_H

#include "Preface.h"
#include "Example/BookCpp/STLTutorialAndReferenceGuide/Helper/STLTutorialAndReferenceGuideClassInvariantMacro.h"

template <typename T>
T BookStandardLibrary::STLTutorialAndReferenceGuide::Preface::Gcd0(T m, T n) const noexcept
{
    STL_TUTORIAL_AND_REFERENCE_GUIDE_CLASS_IS_VALID_CONST_9;

    while (n != 0)
    {
        T t = m % n;
        m = n;
        n = t;
    }

    return m;
}

template <typename T>
T BookStandardLibrary::STLTutorialAndReferenceGuide::Preface::Gcd1(T m, T n) const noexcept
{
    STL_TUTORIAL_AND_REFERENCE_GUIDE_CLASS_IS_VALID_CONST_9;

    while (n != 0)
    {
        T t = m % n;
        m = n;
        n = t;
    }

    return m < 0 ? -m : m;
}

#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_PREFACE_DETAIL_H
