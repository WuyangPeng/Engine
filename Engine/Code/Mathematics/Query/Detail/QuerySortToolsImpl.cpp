///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 13:06)

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

void Mathematics::QuerySortToolsImpl::SortValue2() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (m_SortValue[1] < m_SortValue[0])
    {
        swap(m_SortValue[0], m_SortValue[1]);
        m_Symbol = NumericalValueSymbol::Negative;
    }
    else
    {
        m_Symbol = NumericalValueSymbol::Positive;
    }

#include STSTEM_WARNING_POP
}

void Mathematics::QuerySortToolsImpl::SortValue3() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (m_SortValue[0] <= m_SortValue[1])
    {
        if (m_SortValue[2] < m_SortValue[0])
        {
            // 0 1 2 -> 2 0 1
            swap(m_SortValue[0], m_SortValue[2]);
            swap(m_SortValue[1], m_SortValue[2]);
            m_Symbol = NumericalValueSymbol::Positive;
        }
        else if (m_SortValue[2] < m_SortValue[1])
        {
            // 0 1 2 -> 0 2 1
            swap(m_SortValue[1], m_SortValue[2]);
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
        if (m_SortValue[2] < m_SortValue[1])
        {
            // 0 1 2 -> 2 1 0
            swap(m_SortValue[0], m_SortValue[2]);
            m_Symbol = NumericalValueSymbol::Negative;
        }
        else if (m_SortValue[2] < m_SortValue[0])
        {
            // 0 1 2 -> 1 2 0
            swap(m_SortValue[0], m_SortValue[2]);
            swap(m_SortValue[0], m_SortValue[1]);
            m_Symbol = NumericalValueSymbol::Positive;
        }
        else
        {
            // 0 1 2 -> 1 0 2
            swap(m_SortValue[0], m_SortValue[1]);
            m_Symbol = NumericalValueSymbol::Negative;
        }
    }

#include STSTEM_WARNING_POP
}

void Mathematics::QuerySortToolsImpl::SortValue4() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (m_SortValue[0] <= m_SortValue[1])
    {
        if (m_SortValue[2] <= m_SortValue[3])
        {
            if (m_SortValue[1] <= m_SortValue[2])
            {
                // 数值不变
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue[3] < m_SortValue[0])
            {
                // 0 1 2 3 -> 2 3 0 1
                swap(m_SortValue[0], m_SortValue[2]);
                swap(m_SortValue[1], m_SortValue[3]);
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue[2] < m_SortValue[0])
            {
                if (m_SortValue[3] < m_SortValue[1])
                {
                    // 0 1 2 3 -> 2 0 3 1
                    swap(m_SortValue[0], m_SortValue[1]);
                    swap(m_SortValue[0], m_SortValue[3]);
                    swap(m_SortValue[0], m_SortValue[2]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 2 0 1 3
                    swap(m_SortValue[0], m_SortValue[1]);
                    swap(m_SortValue[0], m_SortValue[2]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (m_SortValue[3] < m_SortValue[1])
                {
                    // 0 1 2 3 -> 0 2 3 1
                    swap(m_SortValue[1], m_SortValue[2]);
                    swap(m_SortValue[2], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 0 2 1 3
                    swap(m_SortValue[1], m_SortValue[2]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
        }
        else
        {
            if (m_SortValue[1] <= m_SortValue[3])
            {
                // 0 1 2 3 -> 0 1 3 2
                swap(m_SortValue[2], m_SortValue[3]);
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue[2] < m_SortValue[0])
            {
                // 0 1 2 3 -> 3 2 0 1
                swap(m_SortValue[0], m_SortValue[2]);
                swap(m_SortValue[0], m_SortValue[1]);
                swap(m_SortValue[0], m_SortValue[3]);
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue[3] < m_SortValue[0])
            {
                if (m_SortValue[2] < m_SortValue[1])
                {
                    // 0 1 2 3 -> 3 0 2 1
                    swap(m_SortValue[0], m_SortValue[1]);
                    swap(m_SortValue[0], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 3 0 1 2
                    swap(m_SortValue[0], m_SortValue[1]);
                    swap(m_SortValue[0], m_SortValue[2]);
                    swap(m_SortValue[0], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (m_SortValue[2] < m_SortValue[1])
                {
                    // 0 1 2 3 -> 0 3 2 1
                    swap(m_SortValue[1], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 0 3 1 2
                    swap(m_SortValue[1], m_SortValue[2]);
                    swap(m_SortValue[1], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
        }
    }
    else
    {
        if (m_SortValue[2] <= m_SortValue[3])
        {
            if (m_SortValue[0] <= m_SortValue[2])
            {
                // 0 1 2 3 -> 1 0 2 3
                swap(m_SortValue[0], m_SortValue[1]);
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue[3] < m_SortValue[1])
            {
                // 0 1 2 3 -> 2 3 1 0
                swap(m_SortValue[0], m_SortValue[3]);
                swap(m_SortValue[0], m_SortValue[1]);
                swap(m_SortValue[0], m_SortValue[2]);
                m_Symbol = NumericalValueSymbol::Negative;
            }
            else if (m_SortValue[2] < m_SortValue[1])
            {
                if (m_SortValue[3] < m_SortValue[0])
                {
                    // 0 1 2 3 -> 2 1 3 0
                    swap(m_SortValue[0], m_SortValue[3]);
                    swap(m_SortValue[0], m_SortValue[2]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 2 1 0 3
                    swap(m_SortValue[0], m_SortValue[2]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
            else
            {
                if (m_SortValue[3] < m_SortValue[0])
                {
                    // 0 1 2 3 -> 1 2 3 0
                    swap(m_SortValue[0], m_SortValue[3]);
                    swap(m_SortValue[0], m_SortValue[2]);
                    swap(m_SortValue[0], m_SortValue[1]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 1 2 0 3
                    swap(m_SortValue[0], m_SortValue[2]);
                    swap(m_SortValue[0], m_SortValue[1]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
        }
        else
        {
            if (m_SortValue[0] <= m_SortValue[3])
            {
                // 0 1 2 3 -> 1 0 3 2
                swap(m_SortValue[0], m_SortValue[1]);
                swap(m_SortValue[2], m_SortValue[3]);
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue[2] < m_SortValue[1])
            {
                // 0 1 2 3 -> 3 2 1 0
                swap(m_SortValue[0], m_SortValue[3]);
                swap(m_SortValue[1], m_SortValue[2]);
                m_Symbol = NumericalValueSymbol::Positive;
            }
            else if (m_SortValue[3] < m_SortValue[1])
            {
                if (m_SortValue[2] < m_SortValue[0])
                {
                    // 0 1 2 3 -> 3 1 2 0
                    swap(m_SortValue[0], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
                else
                {
                    // 0 1 2 3 -> 3 1 0 2
                    swap(m_SortValue[0], m_SortValue[2]);
                    swap(m_SortValue[0], m_SortValue[3]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
            }
            else
            {
                if (m_SortValue[2] < m_SortValue[0])
                {
                    // 0 1 2 3 -> 1 3 2 0
                    swap(m_SortValue[0], m_SortValue[3]);
                    swap(m_SortValue[0], m_SortValue[1]);
                    m_Symbol = NumericalValueSymbol::Positive;
                }
                else
                {
                    // 0 1 2 3 -> 1 3 0 2
                    swap(m_SortValue[0], m_SortValue[2]);
                    swap(m_SortValue[0], m_SortValue[3]);
                    swap(m_SortValue[0], m_SortValue[1]);
                    m_Symbol = NumericalValueSymbol::Negative;
                }
            }
        }
    }

#include STSTEM_WARNING_POP
}
