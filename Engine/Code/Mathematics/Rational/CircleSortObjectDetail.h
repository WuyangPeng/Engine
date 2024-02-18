///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/24 16:36)

#ifndef MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_DETAIL_H
#define MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_DETAIL_H

#include "CircleSortObject.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::CircleSortObject<T>::CircleSortObject() noexcept
    : w{}, index{ 0 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
Mathematics::CircleSortObject<T>::CircleSortObject(const Vector2& w, int index) noexcept
    : w{ w }, index{ index }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::CircleSortObject<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename Mathematics::CircleSortObject<T>::Vector2 Mathematics::CircleSortObject<T>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w;
}

template <typename T>
T Mathematics::CircleSortObject<T>::GetW(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w.at(i);
}

template <typename T>
int Mathematics::CircleSortObject<T>::GetIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index;
}

#endif  // MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_DETAIL_H
