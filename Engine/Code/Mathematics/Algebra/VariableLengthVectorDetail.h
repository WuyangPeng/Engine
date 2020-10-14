// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 15:03)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H

#include "VariableLengthVector.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_LENGTH_VECTOR_DETAIL)

#include "System/Helper/PragmaWarning/NumericCast.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26434)

 
    #include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableLengthVector<Real>
	::VariableLengthVector(int size)
	:m_Size{ size }, m_Tuple{ 0 < size ? NEW1<Real>(size) : nullptr }
{
	if (0 < m_Size)
	{
		const auto numBytes = m_Size * sizeof(Real);
		memset(m_Tuple, 0, numBytes);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>
	::VariableLengthVector(const std::vector<Real>& tuple)
	:m_Size{ boost::numeric_cast<int>(tuple.size()) }, m_Tuple{ 0 < m_Size ? NEW1<Real>(m_Size) : nullptr }
{
	if (0 < m_Size)
	{
		const auto numBytes = m_Size * sizeof(Real);
		memcpy(m_Tuple, &tuple[0], numBytes);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>
	::VariableLengthVector(int size, const Real* data)
	:m_Size{ size }, m_Tuple{ 0 < m_Size ? NEW1<Real>(m_Size) : nullptr }
{
	if (0 < m_Size)
	{
		const auto numBytes = m_Size * sizeof(Real);
		memcpy(m_Tuple, data, numBytes);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>
	::VariableLengthVector(const VariableLengthVector& rhs)
	:m_Size{ rhs.GetSize() }, m_Tuple{ 0 < m_Size ? NEW1<Real>(m_Size) : nullptr }
{
	if (0 < m_Size)
	{
		const auto numBytes = m_Size * sizeof(Real);
		memcpy(m_Tuple, rhs.m_Tuple, numBytes);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>
	::operator=(const VariableLengthVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	VariableLengthVector<Real> result{ rhs };

	Swap(result);

	return *this;
}

// private
template <typename Real>
void Mathematics::VariableLengthVector<Real>
	::Swap(VariableLengthVector& rhs) noexcept
{
	std::swap(m_Size, rhs.m_Size);
	std::swap(m_Tuple, rhs.m_Tuple);
}

template <typename Real>
Mathematics::VariableLengthVector<Real>
	::~VariableLengthVector()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
	
	EXCEPTION_TRY
    {
        #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26447)
        DELETE1<Real>(m_Tuple);
        #include STSTEM_WARNING_POP
    }
    EXCEPTION_ALL_CATCH(Mathematics)	
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableLengthVector<Real>
	::IsValid() const noexcept
{
	if (0 < m_Size && m_Tuple != nullptr)
		return true;
	else if (m_Size == 0 && m_Tuple == nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::VariableLengthVector<Real>
	::GetSize() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Size;
}

template <typename Real>
const Real* Mathematics::VariableLengthVector<Real>
	::GetElements() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(m_Tuple != nullptr, "������СΪ�㣡");

	return m_Tuple;
}

template <typename Real>
Real* Mathematics::VariableLengthVector<Real>
	::GetElements()
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(m_Tuple != nullptr, "������СΪ�㣡");

	return m_Tuple;
}

template <typename Real>
const Real& Mathematics::VariableLengthVector<Real>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	#ifdef MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��������");
	#endif // MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE	

	return m_Tuple[index];
}

template <typename Real>
Real& Mathematics::VariableLengthVector<Real>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	#ifdef MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "��������");
	#endif // MATHEMATICS_ASSERT_VARIABLE_VECTOR_OUT_OF_RANGE	

	return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
void Mathematics::VariableLengthVector<Real>
	::ResetSize(int size)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	VariableLengthVector<Real> temp{ size };

	Swap(temp);
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>
	::operator-() const 
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	VariableLengthVector<Real> result{ m_Size };

	for (auto i = 0; i < m_Size; ++i)
	{
		result.m_Tuple[i] = -m_Tuple[i];
	}

	return result;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>
	::operator+=(const VariableLengthVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(m_Size == rhs.GetSize(), "������С��ͬ��");
	
	CoreTools::DisableNoexcept();

	for (auto i = 0; i < m_Size; ++i)
	{
		m_Tuple[i] += rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>
	::operator-=(const VariableLengthVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_1(m_Size == rhs.GetSize(), "������С��ͬ��");
	
	CoreTools::DisableNoexcept();

	for (auto i = 0; i < m_Size; ++i)
	{
		m_Tuple[i] -= rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>
	::operator*=(Real scalar) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_1;

	for (auto i = 0; i < m_Size; ++i)
	{
		m_Tuple[i] *= scalar;
	}

	return *this;
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>
	::operator/=(Real scalar)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	
	CoreTools::DisableNoexcept();

	if (Math::sm_Epsilon < Math::FAbs(scalar))
	{
		for (auto i = 0; i < m_Size; ++i)
		{
			m_Tuple[i] /= scalar;
		}
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "�������");

		for (auto i = 0; i < m_Size; ++i)
		{
			m_Tuple[i] = Math::sm_MaxReal;
		}
	}

	return *this;
}

template <typename Real>
Real Mathematics::VariableLengthVector<Real>
	::Length() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::VariableLengthVector<Real>
	::SquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	CoreTools::DisableNoexcept();

	auto squaredLength = Math::GetValue(0);

	for (auto i = 0; i < m_Size; ++i)
	{
		squaredLength += m_Tuple[i] * m_Tuple[i];
	}

	MATHEMATICS_ASSERTION_2(0 <= squaredLength, "����ֵ����Ϊ������");

	return squaredLength;
}

template <typename Real>
void Mathematics::VariableLengthVector<Real>
	::Normalize(Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	auto length = Length();

	if (epsilon < length)
	{
		for (auto i = 0; i < m_Size; ++i)
		{
			m_Tuple[i] /= length;
		}
	}
	else
	{
		MATHEMATICS_ASSERTION_2(false, "�������������򻯣�");

		for (auto i = 0; i < m_Size; ++i)
		{
			m_Tuple[i] = Math::GetValue(0);
		}
	}
}

template <typename Real>
const std::vector<Real> Mathematics::VariableLengthVector<Real>
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	std::vector<Real> result(m_Tuple, m_Tuple + m_Size);

	return result;
}

#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_LENGTH_VECTOR_DETAIL)

template <typename Real>
bool Mathematics
	::operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
	MATHEMATICS_ASSERTION_1(lhs.GetSize() == rhs.GetSize(), "������С��ͬ��");

	if (lhs.GetSize() == 0)
		return true;
	else if (memcmp(&lhs[0], &rhs[0], sizeof(Real) * lhs.GetSize()) == 0)
		return true;
	else
		return false;
}

template <typename Real>
bool Mathematics
	::operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
	MATHEMATICS_ASSERTION_1(lhs.GetSize() == rhs.GetSize(), "������С��ͬ��");

	if (lhs.GetSize() == 0)
		return false;
	else if (memcmp(&lhs[0], &rhs[0], sizeof(Real) * lhs.GetSize()) < 0)
		return true;
	else
		return false;
}


template <typename Real>
Real Mathematics
	::Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
	MATHEMATICS_ASSERTION_1(lhs.GetSize() == rhs.GetSize(), "������С��ͬ��");

	auto dotProduct = Math<Real>::GetValue(0);

	for (auto i = 0; i < lhs.GetSize(); ++i)
	{
		dotProduct += lhs[i] * rhs[i];
	}

	return dotProduct;
}

template <typename Real>
bool Mathematics
	::Approximate(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs, const Real epsilon)
{
	MATHEMATICS_ASSERTION_1(lhs.GetSize() == rhs.GetSize(), "������С��ͬ��");

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
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector)
{
	for (auto i = 0; i < vector.GetSize(); ++i)
	{
		outFile << "(" << i << ")=" << vector[i] << "��";
	}

	return outFile;
}

#endif // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
