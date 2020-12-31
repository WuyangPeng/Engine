///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 14:09)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H

#include "VariableLengthVector.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_LENGTH_VECTOR_ACHIEVE)

    #include "VariableLengthVectorAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_LENGTH_VECTOR_ACHIEVE)

template <typename Real>
bool Mathematics::operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
        return false;
    else
        return lhs.GetContainer() == rhs.GetContainer();
}

template <typename Real>
bool Mathematics::operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    return lhs.GetContainer() < rhs.GetContainer();
}

template <typename Real>
Real Mathematics::Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������С��ͬ��"s));
    }

    auto dotProduct = Math<Real>::GetValue(0);

    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        dotProduct += lhs[i] * rhs[i];
    }

    return dotProduct;
}

template <typename Real>
bool Mathematics::Approximate(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs, const Real epsilon)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������С��ͬ��"s));
    }

    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        if (epsilon < Math<Real>::FAbs(lhs[i] - rhs[i]))
        {
            return false;
        }
    }

    return true;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector)
{
    for (auto i = 0; i < vector.GetSize(); ++i)
    {
        outFile << "(" << i << ")=" << vector[i] << "��";
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
