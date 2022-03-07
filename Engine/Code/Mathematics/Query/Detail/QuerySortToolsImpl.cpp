///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 15:56)

#include "Mathematics/MathematicsExport.h"

#include "QuerySortToolsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::swap;

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1)
    : m_SortValue{ value0, value1 }, m_Symbol{ NumericalValueSymbol::Zero }
{
    SortValue2();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1, int value2)
    : m_SortValue{ value0, value1, value2 }, m_Symbol{ NumericalValueSymbol::Zero }
{
    SortValue3();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::QuerySortToolsImpl::QuerySortToolsImpl(int value0, int value1, int value2, int value3)
    : m_SortValue{ value0, value1, value2, value3 }, m_Symbol{ NumericalValueSymbol::Zero }
{
    SortValue4();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, QuerySortToolsImpl)

Mathematics::NumericalValueSymbol Mathematics::QuerySortToolsImpl::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Symbol;
}

int Mathematics::QuerySortToolsImpl::GetValue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SortValue.at(index);
}

void Mathematics::QuerySortToolsImpl::SortValue2()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (m_SortValue.at(1) < m_SortValue.at(0))
    {
        swap(m_SortValue.at(0), m_SortValue.at(1));
        m_Symbol = NumericalValueSymbol::Negative;
    }
    else
    {
        m_Symbol = NumericalValueSymbol::Positive;
    }
}

void Mathematics::QuerySortToolsImpl::SortValue3()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (m_SortValue.at(0) <= m_SortValue.at(1))
    {
        if (m_SortValue.at(2) < m_SortValue.at(0))
        {
            // 0 1 2 -> 2 0 1
            swap(m_SortValue.at(0), m_SortValue.at(2));
            swap(m_SortValue.at(1), m_SortValue.at(2));
            m_Symbol = NumericalValueSymbol::Positive;
        }
        else if (m_SortValue.at(2) < m_SortValue.at(1))
        {
            // 0 1 2 -> 0 2 1
            swap(m_SortValue.at(1), m_SortValue.at(2));
            m_Symbol = NumericalValueSymbol::Negative;
        }
        else
        {
            // 数值不变
            m_Symbol = NumericalValueSymbol::Positive;
        }
    }
    else
    {
        if (m_SortValue.at(2) < m_SortValue.at(1))
        {
            // 0 1 2 -> 2 1 0
            swap(m_SortValue.at(0), m_SortValue.at(2));
            m_Symbol = NumericalValueSymbol::Negative;
        }
        else if (m_SortValue.at(2) < m_SortValue.at(0))
        {
            // 0 1 2 -> 1 2 0
            swap(m_SortValue.at(0), m_SortValue.at(2));
            swap(m_SortValue.at(0), m_SortValue.at(1));
            m_Symbol = NumericalValueSymbol::Positive;
        }
        else
        {
            // 0 1 2 -> 1 0 2
            swap(m_SortValue.at(0), m_SortValue.at(1));
            m_Symbol = NumericalValueSymbol::Negative;
        }
    }
}

void Mathematics::QuerySortToolsImpl::SortValue4()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (m_SortValue.at(0) <= m_SortValue.at(1))
    {
        if (m_SortValue.at(2) <= m_SortValue.at(3))
        {
            if (m_SortValue.at(1) <= m_SortValue.at(2))
            {
                // 数值不变
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue.at(3) < m_SortValue.at(0))
            {
                // 0 1 2 3 -> 2 3 0 1
                swap(m_SortValue.at(0), m_SortValue.at(2));
                swap(m_SortValue.at(1), m_SortValue.at(3));
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue.at(2) < m_SortValue.at(0))
            {
                if (m_SortValue.at(3) < m_SortValue.at(1))
                {
                    // 0 1 2 3 -> 2 0 3 1
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 2 0 1 3
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (m_SortValue.at(3) < m_SortValue.at(1))
                {
                    // 0 1 2 3 -> 0 2 3 1
                    swap(m_SortValue.at(1), m_SortValue.at(2));
                    swap(m_SortValue.at(2), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 0 2 1 3
                    swap(m_SortValue.at(1), m_SortValue.at(2));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
        }
        else
        {
            if (m_SortValue.at(1) <= m_SortValue.at(3))
            {
                // 0 1 2 3 -> 0 1 3 2
                swap(m_SortValue.at(2), m_SortValue.at(3));
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue.at(2) < m_SortValue.at(0))
            {
                // 0 1 2 3 -> 3 2 0 1
                swap(m_SortValue.at(0), m_SortValue.at(2));
                swap(m_SortValue.at(0), m_SortValue.at(1));
                swap(m_SortValue.at(0), m_SortValue.at(3));
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue.at(3) < m_SortValue.at(0))
            {
                if (m_SortValue.at(2) < m_SortValue.at(1))
                {
                    // 0 1 2 3 -> 3 0 2 1
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 3 0 1 2
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (m_SortValue.at(2) < m_SortValue.at(1))
                {
                    // 0 1 2 3 -> 0 3 2 1
                    swap(m_SortValue.at(1), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 0 3 1 2
                    swap(m_SortValue.at(1), m_SortValue.at(2));
                    swap(m_SortValue.at(1), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
        }
    }
    else
    {
        if (m_SortValue.at(2) <= m_SortValue.at(3))
        {
            if (m_SortValue.at(0) <= m_SortValue.at(2))
            {
                // 0 1 2 3 -> 1 0 2 3
                swap(m_SortValue.at(0), m_SortValue.at(1));
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue.at(3) < m_SortValue.at(1))
            {
                // 0 1 2 3 -> 2 3 1 0
                swap(m_SortValue.at(0), m_SortValue.at(3));
                swap(m_SortValue.at(0), m_SortValue.at(1));
                swap(m_SortValue.at(0), m_SortValue.at(2));
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue.at(2) < m_SortValue.at(1))
            {
                if (m_SortValue.at(3) < m_SortValue.at(0))
                {
                    // 0 1 2 3 -> 2 1 3 0
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 2 1 0 3
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (m_SortValue.at(3) < m_SortValue.at(0))
                {
                    // 0 1 2 3 -> 1 2 3 0
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 1 2 0 3
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
        }
        else
        {
            if (m_SortValue.at(0) <= m_SortValue.at(3))
            {
                // 0 1 2 3 -> 1 0 3 2
                swap(m_SortValue.at(0), m_SortValue.at(1));
                swap(m_SortValue.at(2), m_SortValue.at(3));
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue.at(2) < m_SortValue.at(1))
            {
                // 0 1 2 3 -> 3 2 1 0
                swap(m_SortValue.at(0), m_SortValue.at(3));
                swap(m_SortValue.at(1), m_SortValue.at(2));
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue.at(3) < m_SortValue.at(1))
            {
                if (m_SortValue.at(2) < m_SortValue.at(0))
                {
                    // 0 1 2 3 -> 3 1 2 0
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 3 1 0 2
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (m_SortValue.at(2) < m_SortValue.at(0))
                {
                    // 0 1 2 3 -> 1 3 2 0
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 1 3 0 2
                    swap(m_SortValue.at(0), m_SortValue.at(2));
                    swap(m_SortValue.at(0), m_SortValue.at(3));
                    swap(m_SortValue.at(0), m_SortValue.at(1));
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
        }
    }
}
