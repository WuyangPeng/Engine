///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:03)

#include "Mathematics/MathematicsExport.h"

#include "QuerySortToolsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1)
    : sortValue{ value0, value1 }, symbol{ NumericalValueSymbol::Zero }
{
    SortValue2();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1, int value2)
    : sortValue{ value0, value1, value2 }, symbol{ NumericalValueSymbol::Zero }
{
    SortValue3();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1, int value2, int value3)
    : sortValue{ value0, value1, value2, value3 }, symbol{ NumericalValueSymbol::Zero }
{
    SortValue4();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, QuerySortToolsImpl)

Mathematics::NumericalValueSymbol Mathematics::QuerySortToolsImpl::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return symbol;
}

int Mathematics::QuerySortToolsImpl::GetValue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sortValue.at(index);
}

void Mathematics::QuerySortToolsImpl::SortValue2()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (sortValue.at(1) < sortValue.at(0))
    {
        std::swap(sortValue.at(0), sortValue.at(1));
        symbol = NumericalValueSymbol::Negative;
    }
    else
    {
        symbol = NumericalValueSymbol::Positive;
    }
}

void Mathematics::QuerySortToolsImpl::SortValue3()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (sortValue.at(0) <= sortValue.at(1))
    {
        if (sortValue.at(2) < sortValue.at(0))
        {
            // 0 1 2 -> 2 0 1
            std::swap(sortValue.at(0), sortValue.at(2));
            std::swap(sortValue.at(1), sortValue.at(2));
            symbol = NumericalValueSymbol::Positive;
        }
        else if (sortValue.at(2) < sortValue.at(1))
        {
            // 0 1 2 -> 0 2 1
            std::swap(sortValue.at(1), sortValue.at(2));
            symbol = NumericalValueSymbol::Negative;
        }
        else
        {
            // 数值不变
            symbol = NumericalValueSymbol::Positive;
        }
    }
    else
    {
        if (sortValue.at(2) < sortValue.at(1))
        {
            // 0 1 2 -> 2 1 0
            std::swap(sortValue.at(0), sortValue.at(2));
            symbol = NumericalValueSymbol::Negative;
        }
        else if (sortValue.at(2) < sortValue.at(0))
        {
            // 0 1 2 -> 1 2 0
            std::swap(sortValue.at(0), sortValue.at(2));
            std::swap(sortValue.at(0), sortValue.at(1));
            symbol = NumericalValueSymbol::Positive;
        }
        else
        {
            // 0 1 2 -> 1 0 2
            std::swap(sortValue.at(0), sortValue.at(1));
            symbol = NumericalValueSymbol::Negative;
        }
    }
}

void Mathematics::QuerySortToolsImpl::SortValue4()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (sortValue.at(0) <= sortValue.at(1))
    {
        if (sortValue.at(2) <= sortValue.at(3))
        {
            if (sortValue.at(1) <= sortValue.at(2))
            {
                // 数值不变
                symbol = NumericalValueSymbol::Positive;
            }
            else if (sortValue.at(3) < sortValue.at(0))
            {
                // 0 1 2 3 -> 2 3 0 1
                std::swap(sortValue.at(0), sortValue.at(2));
                std::swap(sortValue.at(1), sortValue.at(3));
                symbol = NumericalValueSymbol::Positive;
            }
            else if (sortValue.at(2) < sortValue.at(0))
            {
                if (sortValue.at(3) < sortValue.at(1))
                {
                    // 0 1 2 3 -> 2 0 3 1
                    std::swap(sortValue.at(0), sortValue.at(1));
                    std::swap(sortValue.at(0), sortValue.at(3));
                    std::swap(sortValue.at(0), sortValue.at(2));
                    symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 2 0 1 3
                    std::swap(sortValue.at(0), sortValue.at(1));
                    std::swap(sortValue.at(0), sortValue.at(2));
                    symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (sortValue.at(3) < sortValue.at(1))
                {
                    // 0 1 2 3 -> 0 2 3 1
                    std::swap(sortValue.at(1), sortValue.at(2));
                    std::swap(sortValue.at(2), sortValue.at(3));
                    symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 0 2 1 3
                    std::swap(sortValue.at(1), sortValue.at(2));
                    symbol = NumericalValueSymbol::Negative;
                }
            }
        }
        else
        {
            if (sortValue.at(1) <= sortValue.at(3))
            {
                // 0 1 2 3 -> 0 1 3 2
                std::swap(sortValue.at(2), sortValue.at(3));
                symbol = NumericalValueSymbol::Negative;
            }
            else if (sortValue.at(2) < sortValue.at(0))
            {
                // 0 1 2 3 -> 3 2 0 1
                std::swap(sortValue.at(0), sortValue.at(2));
                std::swap(sortValue.at(0), sortValue.at(1));
                std::swap(sortValue.at(0), sortValue.at(3));
                symbol = NumericalValueSymbol::Negative;
            }
            else if (sortValue.at(3) < sortValue.at(0))
            {
                if (sortValue.at(2) < sortValue.at(1))
                {
                    // 0 1 2 3 -> 3 0 2 1
                    std::swap(sortValue.at(0), sortValue.at(1));
                    std::swap(sortValue.at(0), sortValue.at(3));
                    symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 3 0 1 2
                    std::swap(sortValue.at(0), sortValue.at(1));
                    std::swap(sortValue.at(0), sortValue.at(2));
                    std::swap(sortValue.at(0), sortValue.at(3));
                    symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (sortValue.at(2) < sortValue.at(1))
                {
                    // 0 1 2 3 -> 0 3 2 1
                    std::swap(sortValue.at(1), sortValue.at(3));
                    symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 0 3 1 2
                    std::swap(sortValue.at(1), sortValue.at(2));
                    std::swap(sortValue.at(1), sortValue.at(3));
                    symbol = NumericalValueSymbol::Positive;
                }
            }
        }
    }
    else
    {
        if (sortValue.at(2) <= sortValue.at(3))
        {
            if (sortValue.at(0) <= sortValue.at(2))
            {
                // 0 1 2 3 -> 1 0 2 3
                std::swap(sortValue.at(0), sortValue.at(1));
                symbol = NumericalValueSymbol::Negative;
            }
            else if (sortValue.at(3) < sortValue.at(1))
            {
                // 0 1 2 3 -> 2 3 1 0
                std::swap(sortValue.at(0), sortValue.at(3));
                std::swap(sortValue.at(0), sortValue.at(1));
                std::swap(sortValue.at(0), sortValue.at(2));
                symbol = NumericalValueSymbol::Negative;
            }
            else if (sortValue.at(2) < sortValue.at(1))
            {
                if (sortValue.at(3) < sortValue.at(0))
                {
                    // 0 1 2 3 -> 2 1 3 0
                    std::swap(sortValue.at(0), sortValue.at(3));
                    std::swap(sortValue.at(0), sortValue.at(2));
                    symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 2 1 0 3
                    std::swap(sortValue.at(0), sortValue.at(2));
                    symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (sortValue.at(3) < sortValue.at(0))
                {
                    // 0 1 2 3 -> 1 2 3 0
                    std::swap(sortValue.at(0), sortValue.at(3));
                    std::swap(sortValue.at(0), sortValue.at(2));
                    std::swap(sortValue.at(0), sortValue.at(1));
                    symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 1 2 0 3
                    std::swap(sortValue.at(0), sortValue.at(2));
                    std::swap(sortValue.at(0), sortValue.at(1));
                    symbol = NumericalValueSymbol::Positive;
                }
            }
        }
        else
        {
            if (sortValue.at(0) <= sortValue.at(3))
            {
                // 0 1 2 3 -> 1 0 3 2
                std::swap(sortValue.at(0), sortValue.at(1));
                std::swap(sortValue.at(2), sortValue.at(3));
                symbol = NumericalValueSymbol::Positive;
            }
            else if (sortValue.at(2) < sortValue.at(1))
            {
                // 0 1 2 3 -> 3 2 1 0
                std::swap(sortValue.at(0), sortValue.at(3));
                std::swap(sortValue.at(1), sortValue.at(2));
                symbol = NumericalValueSymbol::Positive;
            }
            else if (sortValue.at(3) < sortValue.at(1))
            {
                if (sortValue.at(2) < sortValue.at(0))
                {
                    // 0 1 2 3 -> 3 1 2 0
                    std::swap(sortValue.at(0), sortValue.at(3));
                    symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 3 1 0 2
                    std::swap(sortValue.at(0), sortValue.at(2));
                    std::swap(sortValue.at(0), sortValue.at(3));
                    symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (sortValue.at(2) < sortValue.at(0))
                {
                    // 0 1 2 3 -> 1 3 2 0
                    std::swap(sortValue.at(0), sortValue.at(3));
                    std::swap(sortValue.at(0), sortValue.at(1));
                    symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 1 3 0 2
                    std::swap(sortValue.at(0), sortValue.at(2));
                    std::swap(sortValue.at(0), sortValue.at(3));
                    std::swap(sortValue.at(0), sortValue.at(1));
                    symbol = NumericalValueSymbol::Negative;
                }
            }
        }
    }
}
