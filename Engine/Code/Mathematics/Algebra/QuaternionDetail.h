// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 14:16)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H
#define MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H

#include "Quaternion.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_DETAIL)

#include "Vector3DTools.h"
#include "Matrix3.h"
#include "QuaternionSwingTwistDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26426)
template <typename Real>
const Mathematics::Quaternion<Real>	Mathematics::Quaternion<Real>
	::sm_Zero{};

template <typename Real>
const Mathematics::Quaternion<Real>	Mathematics::Quaternion<Real>
	::sm_Identity{ Math::sm_One,Math::sm_Zero,Math::sm_Zero,Math::sm_Zero };

template <typename Real>
Mathematics::Quaternion<Real>
	::Quaternion() noexcept
{
	m_Tuple[0] = Math::sm_Zero;
	m_Tuple[1] = Math::sm_Zero;
	m_Tuple[2] = Math::sm_Zero;
	m_Tuple[3] = Math::sm_Zero;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Quaternion<Real>
	::Quaternion(Real w, Real x, Real y, Real z) noexcept
{
	m_Tuple[0] = w;
	m_Tuple[1] = x;
	m_Tuple[2] = y;
	m_Tuple[3] = z;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Quaternion<Real> 
	::Quaternion(const Quaternion& rhs) noexcept
{
	m_Tuple[0] = rhs.m_Tuple[0];
	m_Tuple[1] = rhs.m_Tuple[1];
	m_Tuple[2] = rhs.m_Tuple[2];
	m_Tuple[3] = rhs.m_Tuple[3];

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Quaternion<Real>
	::Quaternion(const Matrix3& matrix)
	:m_Tuple{}
{
	FromRotationMatrix(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::FromRotationMatrix(const Matrix3& matrix)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	// 算法在Ken Shoemake的文章，在1987年SIGGRAPH课程文章“四元微积分和快速动画”。

	const int next[3]{ 1, 2, 0 };

	auto trace = matrix(0, 0) + matrix(1, 1) + matrix(2, 2);

	if (Math::sm_Zero < trace)
	{
		// |w| > 1/2, 可能选择 w > 1/2
		auto root = Math::Sqrt(trace + Math::sm_One);  // 2w

		m_Tuple[0] = static_cast<Real>(0.5) * root;
		root = static_cast<Real>(0.5) / root;  // 1 / (4w)
		m_Tuple[1] = (matrix(2, 1) - matrix(1, 2)) * root;
		m_Tuple[2] = (matrix(0, 2) - matrix(2, 0)) * root;
		m_Tuple[3] = (matrix(1, 0) - matrix(0, 1)) * root;
	}
	else
	{
		// |w| <= 1/2
		auto i = 0;
		if (matrix(0, 0) < matrix(1, 1))
		{
			i = 1;
		}
		if (matrix(i, i) < matrix(2, 2))
		{
			i = 2;
		}

		auto j = next[i];
		auto k = next[j];

		auto root = Math::Sqrt(matrix(i, i) - matrix(j, j) - matrix(k, k) + Math::sm_One);
		Real* quat[3] = { &m_Tuple[1], &m_Tuple[2], &m_Tuple[3] };
		*quat[i] = static_cast<Real>(0.5) * root;
		root = static_cast<Real>(0.5) / root;
		m_Tuple[0] = (matrix(k, j) - matrix(j, k)) * root;
		*quat[j] = (matrix(j, i) + matrix(i, j)) * root;
		*quat[k] = (matrix(k, i) + matrix(i, k)) * root;
	}
}

template <typename Real>
Mathematics::Quaternion<Real>
	::Quaternion(const Vector3D& axis, Real angle)
	:m_Tuple{}
{
	MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

	FromAxisAngle(axis, angle);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::FromAxisAngle(const Vector3D& axis, Real angle)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(axis.IsNormalize(), "axis必须是单位向量！");

	// 代表旋转的四元数是
	//   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

	auto halfAngle = static_cast<Real>(0.5) * angle;

	auto sinValue = Math::Sin(halfAngle);
	m_Tuple[0] = Math::Cos(halfAngle);

	m_Tuple[1] = sinValue * axis[0];
	m_Tuple[2] = sinValue * axis[1];
	m_Tuple[3] = sinValue * axis[2];
}

template <typename Real>
Mathematics::Quaternion<Real>
	::Quaternion(const std::vector<Vector3D>& rotationColumn)
	:m_Tuple{}
{
	MATHEMATICS_ASSERTION_1(rotationColumn.size() == 3, "数据大小错误！");

	FromRotationColumnVector3D(rotationColumn);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::FromRotationColumnVector3D(const std::vector<Vector3D>& rotationColumn)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(rotationColumn.size() == 3, "数据大小错误！");

	FromRotationMatrix(Matrix3(rotationColumn, MatrixMajorFlags::Column));
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator=(const Quaternion& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = rhs.m_Tuple[0];
	m_Tuple[1] = rhs.m_Tuple[1];
	m_Tuple[2] = rhs.m_Tuple[2];
	m_Tuple[3] = rhs.m_Tuple[3];

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Quaternion<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const Real& Mathematics::Quaternion<Real>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= index && index < 4)
	{
		return m_Tuple[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
	}
}

template <typename Real>
Real& Mathematics::Quaternion<Real>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 4, "索引错误！");

	return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::GetW() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::GetX() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::GetY() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::GetZ() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[3];
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::SetW(Real w) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = w;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::SetX(Real x) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = x;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::SetY(Real y) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = y;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::SetZ(Real z) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[3] = z;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator*=(const Quaternion& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	*this = *this * rhs;

	return *this;
}

template <typename Real>
const  Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::operator-() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Quaternion{ -m_Tuple[0],-m_Tuple[1],-m_Tuple[2],-m_Tuple[3] };
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator+=(const Quaternion& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] += rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator-=(const Quaternion& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] -= rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator*=(Real scalar) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] *= scalar;
	}

	return *this;
}

template <typename Real>
Mathematics::Quaternion<Real>& Mathematics::Quaternion<Real>
	::operator/=(Real scalar) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::FAbs(scalar) <= Math::sm_ZeroTolerance)
	{
		for (auto i = 0; i < 4; ++i)
		{
			m_Tuple[i] = Math::sm_MaxReal;
		}
	}
	else
	{
		for (auto i = 0; i < 4; ++i)
		{
			m_Tuple[i] /= scalar;
		}
	}

	return *this;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::Matrix3 Mathematics::Quaternion<Real>
	::ToRotationMatrix() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto twoX = Math::sm_Two * m_Tuple[1];
	auto twoY = Math::sm_Two * m_Tuple[2];
	auto twoZ = Math::sm_Two * m_Tuple[3];
	auto twoWX = twoX * m_Tuple[0];
	auto twoWY = twoY * m_Tuple[0];
	auto twoWZ = twoZ * m_Tuple[0];
	auto twoXX = twoX * m_Tuple[1];
	auto twoXY = twoY * m_Tuple[1];
	auto twoXZ = twoZ * m_Tuple[1];
	auto twoYY = twoY * m_Tuple[2];
	auto twoYZ = twoZ * m_Tuple[2];
	auto twoZZ = twoZ * m_Tuple[3];

	return Matrix3{ Math::sm_One - (twoYY + twoZZ),twoXY - twoWZ,twoXZ + twoWY,
					twoXY + twoWZ,Math::sm_One - (twoXX + twoZZ),twoYZ - twoWX,
					twoXZ - twoWY,twoYZ + twoWX,Math::sm_One - (twoXX + twoYY) };
}

template <typename Real>
const std::vector<typename Mathematics::Quaternion<Real>::Vector3D> Mathematics::Quaternion<Real>
	::ToRotationColumnVector3D() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto matrix = ToRotationMatrix();

	std::vector<Vector3D> columnVector3DVector;

	for (auto column = 0; column < 3; ++column)
	{
		columnVector3DVector.emplace_back(matrix(0, column), matrix(1, column), matrix(2, column));
	}

	MATHEMATICS_ASSERTION_1(columnVector3DVector.size() == 3, "返回的向量大小错误！");

	return columnVector3DVector;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::Vector3D Mathematics::Quaternion<Real>
	::ToAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	// 代表旋转的四元数是 
	//   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

	auto sqrareLength = m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];

	if (Math::sm_ZeroTolerance < sqrareLength)
	{
		auto invLength = Math::InvSqrt(sqrareLength);

		return Vector3D{ m_Tuple[1] * invLength,m_Tuple[2] * invLength,m_Tuple[3] * invLength };
	}
	else
	{
		// 角度是 0 (2 * pi的模), 所以任何轴都行。
		return Vector3D::sm_UnitX;
	}
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::ToAngle() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto sqrareLength = m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];

	if (Math::sm_ZeroTolerance < sqrareLength)
	{
		return Math::sm_Two * Math::ACos(m_Tuple[0]);
	}
	else
	{
		return Math::sm_Zero;
	}
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::Matrix3Extract Mathematics::Quaternion<Real>
	::ToAngleAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix3Extract{ ToAngle(), ToAxis() };
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::Length() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::Quaternion<Real>
	::SquaredLength() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0] * m_Tuple[0] + m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::Normalize(Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto length = Length();

	if (epsilon < length)
	{
		m_Tuple[0] /= length;
		m_Tuple[1] /= length;
		m_Tuple[2] /= length;
		m_Tuple[3] /= length;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "四元数正则化错误！");

		m_Tuple[0] = Math::sm_Zero;
		m_Tuple[1] = Math::sm_Zero;
		m_Tuple[2] = Math::sm_Zero;
		m_Tuple[3] = Math::sm_Zero;
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::Inverse() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	
	CoreTools::DoNothing();

	auto norm = SquaredLength();

	if (Math::sm_ZeroTolerance < norm)
	{
		return Quaternion{ m_Tuple[0] / norm, -m_Tuple[1] / norm, -m_Tuple[2] / norm, -m_Tuple[3] / norm };
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "返回一个无效的结果来标记错误！");

		return Quaternion{};
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::Conjugate() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Quaternion{ m_Tuple[0], -m_Tuple[1], -m_Tuple[2], -m_Tuple[3] };
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::Exp() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_1(Math::FAbs(m_Tuple[0]) <= Math::sm_ZeroTolerance, "四元数w必须等于0！");

	// 如果 q = A * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度，然后
	// exp(q) = cos(A) + sin(A)*(x*i+y*j+z*k)。
	// 如果 sin(A) 是接近为零,
	// 使用 exp(q) = cos(A) + A*(x*i+y*j+z*k) 因为 A/sin(A) 趋向于 1。

	Quaternion result;

	auto angle = Math::Sqrt(m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3]);

	auto sinValue = Math::Sin(angle);
	result.m_Tuple[0] = Math::Cos(angle);

	if (Math::sm_ZeroTolerance <= Math::FAbs(sinValue))
	{
		auto coeff = sinValue / angle;
		for (auto i = 1; i < 4; ++i)
		{
			result.m_Tuple[i] = coeff * m_Tuple[i];
		}
	}
	else
	{
		for (auto i = 1; i < 4; ++i)
		{
			result.m_Tuple[i] = m_Tuple[i];
		}
	}

	return result;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::Log() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// 如果 q = cos(A) + sin(A) * (x*i+y*j+z*k) 这里 (x,y,z) 是单位长度,
	// 然后 log(q) = A * (x*i+y*j+z*k)。 
	// 如果 sin(A) 是接近零，
	// 使用 log(q) = sin(A) * (x*i+y*j+z*k)
	// 因为 A/sin(A) 趋向于 1。

	Quaternion result;
	result.m_Tuple[0] = Math::sm_Zero;

	if (Math::FAbs(m_Tuple[0]) < Math::sm_One)
	{
		auto angle = Math::ACos(m_Tuple[0]);
		auto sinValue = Math::Sin(angle);
		if (Math::sm_ZeroTolerance <= Math::FAbs(sinValue))
		{
			auto coeff = angle / sinValue;
			for (auto i = 1; i < 4; ++i)
			{
				result.m_Tuple[i] = coeff * m_Tuple[i];
			}

			return result;
		}
	}

	for (auto i = 1; i < 4; ++i)
	{
		result.m_Tuple[i] = m_Tuple[i];
	}

	return result;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::Vector3D Mathematics::Quaternion<Real>
	::Rotate(const Vector3D& vector) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// 给定一个向量u = (x0,y0,z0)和单位长度的四元数q = <w,x,y,z>
	// 向量v = (x1,y1,z1)，它代表u使用q旋转为v = q*u*q^{-1}，
	// 其中*表示四元数乘法和其中u被视为四元数<0,x0,y0,z0>。
	// 需要注意的是q^{-1} = <w,-x,-y,-z>，
	// 所以没有真正的工作去取q的逆。

	// 现在
	//   q*u*q^{-1} = q*<0,x0,y0,z0>*q^{-1}
	//     = q*(x0*i+y0*j+z0*k)*q^{-1}
	//     = x0*(q*i*q^{-1})+y0*(q*j*q^{-1})+z0*(q*k*q^{-1})
	//	
	// 是计算在Quaternion<Real>::ToRotationMatrix中旋转矩阵的列。
	// 向量v被获得作为与向量u与旋转矩阵的乘积。
	// 因此，旋转矩阵的四元数表示，
	// 需要比矩阵较少的空间和更多的时间来计算旋转后的向量。
	// 典型的空间——时间权衡……

	auto matrix = ToRotationMatrix();

	return matrix * vector;
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::Slerp(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto cosValue = Dot(firstQuaternion, secondQuaternion);
	auto angle = Math::ACos(cosValue);

	if (Math::sm_ZeroTolerance <= Math::FAbs(angle))
	{
		auto sinValue = Math::Sin(angle);
		auto tAngle = t * angle;
		auto coeff0 = Math::Sin(angle - tAngle) / sinValue;
		auto coeff1 = Math::Sin(tAngle) / sinValue;

		m_Tuple[0] = coeff0 * firstQuaternion.m_Tuple[0] + coeff1 * secondQuaternion.m_Tuple[0];
		m_Tuple[1] = coeff0 * firstQuaternion.m_Tuple[1] + coeff1 * secondQuaternion.m_Tuple[1];
		m_Tuple[2] = coeff0 * firstQuaternion.m_Tuple[2] + coeff1 * secondQuaternion.m_Tuple[2];
		m_Tuple[3] = coeff0 * firstQuaternion.m_Tuple[3] + coeff1 * secondQuaternion.m_Tuple[3];
	}
	else
	{
		*this = firstQuaternion;
	}
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::SlerpExtraSpins(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, int extraSpins)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto cosValue = Dot(firstQuaternion, secondQuaternion);
	auto angle = Math::ACos(cosValue);

	if (Math::sm_ZeroTolerance <= Math::FAbs(angle))
	{
		auto sinValue = Math::Sin(angle);
		auto phase = Math::sm_PI * extraSpins * t;

		auto coeff0 = Math::Sin((Math::sm_One - t) * angle - phase) / sinValue;
		auto coeff1 = Math::Sin(t * angle + phase) / sinValue;

		m_Tuple[0] = coeff0 * firstQuaternion.m_Tuple[0] + coeff1 * secondQuaternion.m_Tuple[0];
		m_Tuple[1] = coeff0 * firstQuaternion.m_Tuple[1] + coeff1 * secondQuaternion.m_Tuple[1];
		m_Tuple[2] = coeff0 * firstQuaternion.m_Tuple[2] + coeff1 * secondQuaternion.m_Tuple[2];
		m_Tuple[3] = coeff0 * firstQuaternion.m_Tuple[3] + coeff1 * secondQuaternion.m_Tuple[3];
	}
	else
	{
		*this = firstQuaternion;
	}
}

template <typename Real>
bool Mathematics::Quaternion<Real>
	::IsNormalize(Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto length = Length();

	if (epsilon < length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::Intermediate(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, const Quaternion& thirdQuaternion)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(firstQuaternion.IsNormalize() && secondQuaternion.IsNormalize() && thirdQuaternion.IsNormalize(), "firstQuaternion、secondQuaternion、thirdQuaternion必须都是单位长度！");

	const auto secondQuaternionConjugate = secondQuaternion.Conjugate();
	const auto p0 = secondQuaternionConjugate * firstQuaternion;
	const auto p2 = secondQuaternionConjugate * thirdQuaternion;

	auto arg = -static_cast<Real>(0.25) * (p0.Log() + p2.Log());

	*this = secondQuaternion * arg.Exp();
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto slerpT = Math::sm_Two * t * (Math::sm_One - t);

	Quaternion slerpP;
	slerpP.Slerp(t, q0, q1);

	Quaternion slerpQ;
	slerpQ.Slerp(t, a0, a1);

	Slerp(slerpT, slerpP, slerpQ);
}

template <typename Real>
void Mathematics::Quaternion<Real>
	::Align(const Vector3D& firstVector, const Vector3D& secondVector, Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(firstVector.IsNormalize(epsilon) && secondVector.IsNormalize(epsilon), "firstVector和secondVector必须是单位向量！");

	// 如果firstVector和secondVector是不平行的，
	// 旋转的轴是单位长度的向量
	// U = Cross(firstVector,secondVector)/Length(Cross(firstVector,secondVector))。
	// 旋转角度A为firstVector和secondVector之间的角度。
	// 旋转的四元数为q = cos(A/2) + sin(A/2)*(ux*i+uy*j+uz*k)，
	// 其中U = (ux,uy,uz)。
	//
	// (1) 与其提取A = acos(Dot(firstVector,secondVector))，
	//     乘以1/2，然后计算sin(A/2)和cos(A/2)，
	//     我们减少计算成本去计算平分线
	//     B = (firstVector+secondVector)/Length(firstVector+secondVector)，
	//     从而cos(A/2) =  Dot(firstVector,B)。
	//
	// (2) 旋转轴为U = Cross(firstVector,B)/Length(Cross(firstVector,B))，
	//     但 Length(Cross(firstVector,B)) = 
	//     Length(firstVector)*Length(B)*sin(A/2) = sin(A/2)，
	//     在这种情况下，sin(A/2)*(ux*i+uy*j+uz*k) = (cx*i+cy*j+cz*k)，
	//     其中C = Cross(firstVector,B)。
	//	
	// 如果firstVector = secondVector，
	// 则B = firstVector， cos(A/2) = 1, and U = (0,0,0)。
	// 如果firstVector = -secondVector，则B = 0。	
	// 在这种情况下，A = pi和垂直于firstVector的任何轴都可以被用作旋转轴。

	auto bisector = firstVector + secondVector;
	if (Math::Approximate(Vector3DTools::VectorMagnitude(bisector), Math::sm_Zero, epsilon))
	{
		bisector.ZeroOut();
	}
	else
	{
		bisector.Normalize(epsilon);
	}

	auto cosHalfAngle = Vector3DTools::DotProduct(firstVector, bisector);

	m_Tuple[0] = cosHalfAngle;

	if (!Math::Approximate(cosHalfAngle, Math::sm_Zero, epsilon))
	{
		const  auto cross = Vector3DTools::CrossProduct(firstVector, bisector);
		m_Tuple[1] = cross.GetXCoordinate();
		m_Tuple[2] = cross.GetYCoordinate();
		m_Tuple[3] = cross.GetZCoordinate();
	}
	else
	{
		if (Math::FAbs(firstVector[1]) <= Math::FAbs(firstVector[0]))
		{
			// V1.x或V1.z是最大规模的组成部分。
			auto invLength = Math::InvSqrt(firstVector[0] * firstVector[0] + firstVector[2] * firstVector[2]);
			m_Tuple[1] = -firstVector[2] * invLength;
			m_Tuple[2] = Math::sm_Zero;
			m_Tuple[3] = +firstVector[0] * invLength;
		}
		else
		{
			// V1.y或V1.z是最大规模的组成部分。	
			auto invLength = Math::InvSqrt(firstVector[1] * firstVector[1] + firstVector[2] * firstVector[2]);
			m_Tuple[1] = Math::sm_Zero;
			m_Tuple[2] = +firstVector[2] * invLength;
			m_Tuple[3] = -firstVector[1] * invLength;
		}
	}
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>
	::DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const  auto v2 = Rotate(vector);
	Quaternion swing;
	swing.Align(vector, v2, epsilon);
	const auto twist = (*this) * swing.Conjugate();

	return QuaternionSwingTwist(swing, twist);
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionSwingTwist Mathematics::Quaternion<Real>
	::DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto v2 = Rotate(vector);
	Quaternion swing;
	swing.Align(vector, v2, epsilon);
	const auto twist = swing.Conjugate() * (*this);

	return QuaternionSwingTwist(swing, twist);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::X);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::Y);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::Z);
}

// private
template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosest(QuaternionClosestAxis axis) const
{

	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto axisIndex = System::EnumCastUnderlying(axis);

	// 适当的非零分量将在后面进行设置。
	Quaternion quaternion;
	const auto p0 = m_Tuple[0];
	const auto p1 = m_Tuple[axisIndex];
	const auto sqrLength = p0 * p0 + p1 * p1;
	if (Math::sm_ZeroTolerance < sqrLength)
	{
		// 唯一的最近点。
		auto invLength = Math::InvSqrt(sqrLength);
		quaternion[0] = p0 * invLength;
		quaternion[axisIndex] = p1 * invLength;
	}
	else
	{
		// 无穷多解，选择theta = 0。
		quaternion[0] = Math::sm_One;
		quaternion[axisIndex] = Math::sm_Zero;
	}

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestXY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto det = m_Tuple[0] * m_Tuple[3] - m_Tuple[1] * m_Tuple[2];

	if (Math::FAbs(det) < static_cast<Real>(0.5) - Math::sm_ZeroTolerance)
	{
		auto discr = Math::sm_One - static_cast<Real>(4) * det * det;
		discr = Math::Sqrt(Math::FAbs(discr));

		const auto a = m_Tuple[0] * m_Tuple[1] + m_Tuple[2] * m_Tuple[3];
		const auto b = m_Tuple[0] * m_Tuple[0] - m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] - m_Tuple[3] * m_Tuple[3];

		auto c0 = Math::sm_Zero;
		auto s0 = Math::sm_Zero;

		if (Math::sm_Zero <= b)
		{
			c0 = static_cast<Real>(0.5) * (discr + b);
			s0 = a;
		}
		else
		{
			c0 = a;
			s0 = static_cast<Real>(0.5) * (discr - b);
		}

		auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
		c0 *= invLength;
		s0 *= invLength;

		auto c1 = m_Tuple[0] * c0 + m_Tuple[1] * s0;
		auto s1 = m_Tuple[2] * c0 + m_Tuple[3] * s0;
		invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
		c1 *= invLength;
		s1 *= invLength;

		return Quaternion{ c0 * c1,s0 * c1,c0 * s1,s0 * s1 };
	}
	else
	{
		const auto invLength = Math::InvSqrt(Math::FAbs(det));

		return Quaternion{ m_Tuple[0] * invLength,m_Tuple[1] * invLength,Math::sm_Zero,Math::sm_Zero };
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestYX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[1], m_Tuple[2], -m_Tuple[3] };

	auto quaternion = alt.GetClosestXY();
	quaternion[3] = -quaternion[3];

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[1], m_Tuple[3], m_Tuple[2] };

	auto quaternion = alt.GetClosestXY();
	const auto save = quaternion[2];
	quaternion[2] = quaternion[3];
	quaternion[3] = save;

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestXZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[1], -m_Tuple[3], m_Tuple[2] };

	auto quaternion = alt.GetClosestXY();

	const auto save = quaternion[2];
	quaternion[2] = quaternion[3];
	quaternion[3] = -save;

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestYZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[2], m_Tuple[3], m_Tuple[1] };

	auto quaternion = alt.GetClosestXY();
	const auto save = quaternion[3];
	quaternion[3] = quaternion[2];
	quaternion[2] = quaternion[1];
	quaternion[1] = save;

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[2], m_Tuple[3], -m_Tuple[1] };

	auto quaternion = alt.GetClosestXY();
	const auto save = quaternion[3];
	quaternion[3] = quaternion[2];
	quaternion[2] = quaternion[1];
	quaternion[1] = -save;

	return quaternion;
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorXYZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::XYZ };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorXZY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::XZY };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorYZX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::YZX };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorYXZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::YXZ };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorZXY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::ZXY };
}

template <typename Real>
typename const Mathematics::Quaternion<Real>::QuaternionFactor Mathematics::Quaternion<Real>
	::FactorZYX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return QuaternionFactor{ *this,QuaternionFactorFlags::ZYX };
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestX(const QuaternionConstraints& xCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::X, xCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestY(const QuaternionConstraints& yCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::Y, yCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZ(const QuaternionConstraints& zCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetClosest(QuaternionClosestAxis::Z, zCon);
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// 各元素初始化为零
	Quaternion quaternion;

	auto p0 = m_Tuple[0];
	auto p1 = m_Tuple[System::EnumCastUnderlying(axis)];
	const auto sqrLength = p0 * p0 + p1 * p1;
	if (Math::sm_ZeroTolerance < sqrLength)
	{
		const auto invLength = Math::InvSqrt(sqrLength);
		p0 *= invLength;
		p1 *= invLength;
		if (con.IsValid(p0, p1))
		{
			// 最大值出现在内部点
			quaternion[0] = p0;
			quaternion[System::EnumCastUnderlying(axis)] = p1;
		}
		else
		{
			// 最大值出现在边界点
			auto cosValueMin = con.GetCosMinAngle();
			auto sinValueMin = con.GetSinMinAngle();
			auto dotMinAngle = p0 * cosValueMin + p1 * sinValueMin;
			if (dotMinAngle < Math::sm_Zero)
			{
				cosValueMin = -cosValueMin;
				sinValueMin = -sinValueMin;
				dotMinAngle = -dotMinAngle;
			}

			auto cosValueMax = con.GetCosMaxAngle();
			auto sinValueMax = con.GetSinMaxAngle();
			auto dotMaxAngle = p0 * cosValueMax + p1 * sinValueMax;
			if (dotMaxAngle < Math::sm_Zero)
			{
				cosValueMax = -cosValueMax;
				sinValueMax = -sinValueMax;
				dotMaxAngle = -dotMaxAngle;
			}

			if (dotMinAngle <= dotMaxAngle)
			{
				quaternion[0] = cosValueMax;
				quaternion[System::EnumCastUnderlying(axis)] = sinValueMax;
			}
			else
			{
				quaternion[0] = cosValueMin;
				quaternion[System::EnumCastUnderlying(axis)] = sinValueMin;
			}
		}
	}
	else
	{
		// 无穷多解，选择一个满足的角度约束。
		quaternion[0] = con.GetCosAvrAngle();
		quaternion[System::EnumCastUnderlying(axis)] = con.GetSinAvrAngle();
	}

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto det = m_Tuple[0] * m_Tuple[3] - m_Tuple[1] * m_Tuple[2];

	if (Math::FAbs(det) < static_cast<Real>(0.5) - Math::sm_ZeroTolerance)
	{
		const auto discr = Math::Sqrt(Math::FAbs(Math::sm_One - (static_cast<Real>(4)) * det * det));
		const auto a = m_Tuple[0] * m_Tuple[1] + m_Tuple[2] * m_Tuple[3];
		const auto b = m_Tuple[0] * m_Tuple[0] - m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] - m_Tuple[3] * m_Tuple[3];

		Real c0{ };
		Real s0{ };

		if (Math::sm_Zero <= b)
		{
			c0 = static_cast<Real>(0.5) * (discr + b);
			s0 = a;
		}
		else
		{
			c0 = a;
			s0 = static_cast<Real>(0.5) * (discr - b);
		}

		auto invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
		c0 *= invLength;
		s0 *= invLength;

		auto c1 = m_Tuple[0] * c0 + m_Tuple[1] * s0;
		auto s1 = m_Tuple[2] * c0 + m_Tuple[3] * s0;
		invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
		c1 *= invLength;
		s1 *= invLength;

		if (xCon.IsValid(c0, s0) && yCon.IsValid(c1, s1))
		{
			// 最大值发生在内部点。
			return Quaternion(c0 * c1, s0 * c1, c0 * s1, s0 * s1);
		}
		else
		{
			// 最大值出现在边界点。
			Quaternion r{ xCon.GetCosMinAngle(), xCon.GetSinMinAngle(),Math::sm_Zero, Math::sm_Zero };
			Quaternion rInv{ xCon.GetCosMinAngle(), -xCon.GetSinMinAngle(),Math::sm_Zero, Math::sm_Zero };
			auto prod = rInv * (*this);
			auto tmp = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
			auto dotOptAngle = Dot(prod, tmp);
			auto quaternion = r * tmp;

			r = Quaternion(xCon.GetCosMaxAngle(), xCon.GetSinMaxAngle(), Math::sm_Zero, Math::sm_Zero);
			rInv = Quaternion(xCon.GetCosMaxAngle(), -xCon.GetSinMaxAngle(), Math::sm_Zero, Math::sm_Zero);
			prod = rInv * (*this);
			tmp = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
			auto dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = r * tmp;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ yCon.GetCosMinAngle(), Math::sm_Zero,yCon.GetSinMinAngle(), Math::sm_Zero };
			rInv = Quaternion{ yCon.GetCosMinAngle(), Math::sm_Zero,-yCon.GetSinMinAngle(), Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::X, xCon);
			dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ yCon.GetCosMaxAngle(), Math::sm_Zero,yCon.GetSinMaxAngle(), Math::sm_Zero };
			rInv = Quaternion{ yCon.GetCosMaxAngle(), Math::sm_Zero,-yCon.GetSinMaxAngle(), Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::X, xCon);
			dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			return quaternion;
		}
	}
	else
	{
		// 无穷多解，选择一个满足约束的角度。
		auto c0 = Math::sm_Zero;
		auto s0 = Math::sm_Zero;
		auto c1 = Math::sm_Zero;
		auto s1 = Math::sm_Zero;

		if (Math::sm_Zero < det)
		{
			const auto minAngle = xCon.GetMinAngle() - yCon.GetMaxAngle();
			const auto maxAngle = xCon.GetMaxAngle() - yCon.GetMinAngle();
			const QuaternionConstraints con{ minAngle, maxAngle };

			const auto tmp = GetClosest(QuaternionClosestAxis::X, con);

			auto angle = Math::ATan2(tmp[1], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[1] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (angle <= xCon.GetMaxAngle() - yCon.GetMaxAngle())
			{
				c1 = yCon.GetCosMaxAngle();
				s1 = yCon.GetSinMaxAngle();
				angle = yCon.GetMaxAngle() + angle;
				c0 = Math::Cos(angle);
				s0 = Math::Sin(angle);
			}
			else
			{
				c0 = xCon.GetCosMaxAngle();
				s0 = xCon.GetSinMaxAngle();
				angle = xCon.GetMaxAngle() - angle;
				c1 = Math::Cos(angle);
				s1 = Math::Sin(angle);
			}
		}
		else
		{
			const auto minAngle = xCon.GetMinAngle() + yCon.GetMinAngle();
			const auto maxAngle = xCon.GetMaxAngle() + yCon.GetMaxAngle();
			 const QuaternionConstraints con{ minAngle, maxAngle };

			const auto tmp = GetClosest(QuaternionClosestAxis::X, con);

			auto angle = Math::ATan2(tmp[1], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[1] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (xCon.GetMinAngle() + yCon.GetMaxAngle() <= angle)
			{
				c1 = yCon.GetCosMaxAngle();
				s1 = yCon.GetSinMaxAngle();
				angle = angle - yCon.GetMaxAngle();
				c0 = Math::Cos(angle);
				s0 = Math::Sin(angle);
			}
			else
			{
				c0 = xCon.GetCosMaxAngle();
				s0 = xCon.GetSinMaxAngle();
				angle = angle - xCon.GetMaxAngle();
				c1 = Math::Cos(angle);
				s1 = Math::Sin(angle);
			}
		}

		Quaternion quaternion{ c0 * c1,s0 * c1,c0 * s1,s0 * s1 };

		if (Dot(*this, quaternion) < Math::sm_Zero)
		{
			quaternion = -quaternion;
		}

		return quaternion;
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[1], m_Tuple[2], -m_Tuple[3] };

	auto quaternion = alt.GetClosestXY(xCon, yCon);
	quaternion[3] = -quaternion[3];

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto det = m_Tuple[0] * m_Tuple[2] - m_Tuple[1] * m_Tuple[3];

	if (Math::FAbs(det) < static_cast<Real>(0.5) - Math::sm_ZeroTolerance)
	{
		const auto discr = Math::Sqrt(Math::FAbs(Math::sm_One - (static_cast<Real>(4)) * det * det));

		const auto a = m_Tuple[0] * m_Tuple[3] + m_Tuple[1] * m_Tuple[2];
		const auto b = m_Tuple[0] * m_Tuple[0] + m_Tuple[1] * m_Tuple[1] - m_Tuple[2] * m_Tuple[2] - m_Tuple[3] * m_Tuple[3];

		auto c2 = Math::sm_Zero;
		auto s2 = Math::sm_Zero;

		if (Math::sm_Zero <= b)
		{
			c2 = static_cast<Real>(0.5) * (discr + b);
			s2 = a;
		}
		else
		{
			c2 = a;
			s2 = static_cast<Real>(0.5) * (discr - b);
		}

		auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
		c2 *= invLength;
		s2 *= invLength;

		auto c0 = m_Tuple[0] * c2 + m_Tuple[3] * s2;
		auto s0 = m_Tuple[1] * c2 + m_Tuple[2] * s2;
		invLength = Math::InvSqrt(c0 * c0 + s0 * s0);
		c0 *= invLength;
		s0 *= invLength;

		if (zCon.IsValid(c2, s2) && xCon.IsValid(c0, s0))
		{
			// 最大值发生在内部点。
			return Quaternion{ c2 * c0,c2 * s0,s2 * s0,s2 * c0 };
		}
		else
		{
			// 最大值出现在边界点。
			Quaternion r{ zCon.GetCosMinAngle(), Math::sm_Zero, Math::sm_Zero,zCon.GetSinMinAngle() };
			Quaternion rInv{ zCon.GetCosMinAngle(), Math::sm_Zero, Math::sm_Zero,-zCon.GetSinMinAngle() };
			auto prod = rInv * (*this);
			auto tmp = prod.GetClosest(QuaternionClosestAxis::X, xCon);
			auto dotOptAngle = Dot(prod, tmp);
			auto quaternion = r * tmp;

			r = Quaternion{ zCon.GetCosMaxAngle(), Math::sm_Zero, Math::sm_Zero,zCon.GetSinMaxAngle() };
			rInv = Quaternion{ zCon.GetCosMaxAngle(), Math::sm_Zero, Math::sm_Zero,-zCon.GetSinMaxAngle() };
			prod = rInv * (*this);
			tmp = prod.GetClosest(QuaternionClosestAxis::X, xCon);
			auto dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = r * tmp;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ xCon.GetCosMinAngle(), xCon.GetSinMinAngle(),Math::sm_Zero, Math::sm_Zero };
			rInv = Quaternion{ xCon.GetCosMinAngle(), -xCon.GetSinMinAngle(), Math::sm_Zero,  Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
			dotAngle = Dot(prod, tmp);
			if (dotAngle > dotOptAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ xCon.GetCosMaxAngle(), xCon.GetSinMaxAngle(), Math::sm_Zero, Math::sm_Zero };
			rInv = Quaternion{ xCon.GetCosMaxAngle(), -xCon.GetSinMaxAngle(), Math::sm_Zero,  Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
			dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			return quaternion;
		}
	}
	else
	{
		// 无穷多解，选择一个满足约束的角度。
		auto c0 = Math::sm_Zero;
		auto s0 = Math::sm_Zero;
		auto c2 = Math::sm_Zero;
		auto s2 = Math::sm_Zero;

		if (Math::sm_Zero < det)
		{
			const auto minAngle = xCon.GetMinAngle() - zCon.GetMaxAngle();
			const auto maxAngle = xCon.GetMaxAngle() - zCon.GetMinAngle();
			const QuaternionConstraints con{ minAngle, maxAngle };

			const auto tmp = GetClosest(QuaternionClosestAxis::X, con);

			auto angle = Math::ATan2(tmp[1], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[1] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (angle <= xCon.GetMaxAngle() - zCon.GetMaxAngle())
			{
				c2 = zCon.GetCosMaxAngle();
				s2 = zCon.GetSinMaxAngle();
				angle = zCon.GetMaxAngle() + angle;
				c0 = Math::Cos(angle);
				s0 = Math::Sin(angle);
			}
			else
			{
				c0 = xCon.GetCosMaxAngle();
				s0 = xCon.GetSinMaxAngle();
				angle = xCon.GetMaxAngle() - angle;
				c2 = Math::Cos(angle);
				s2 = Math::Sin(angle);
			}
		}
		else
		{
			const auto minAngle = xCon.GetMinAngle() + zCon.GetMinAngle();
			const auto maxAngle = xCon.GetMaxAngle() + zCon.GetMaxAngle();
			const QuaternionConstraints con{ minAngle, maxAngle };

			const auto tmp = GetClosest(QuaternionClosestAxis::X, con);

			auto angle = Math::ATan2(tmp[1], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[1] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (xCon.GetMinAngle() + zCon.GetMaxAngle() <= angle)
			{
				c2 = zCon.GetCosMaxAngle();
				s2 = zCon.GetSinMaxAngle();
				angle = angle - zCon.GetMaxAngle();
				c0 = Math::Cos(angle);
				s0 = Math::Sin(angle);
			}
			else
			{
				c0 = xCon.GetCosMaxAngle();
				s0 = xCon.GetSinMaxAngle();
				angle = angle - xCon.GetMaxAngle();
				c2 = Math::Cos(angle);
				s2 = Math::Sin(angle);
			}
		}

		Quaternion quaternion{ c2 * c0,c2 * s0, s2 * s0,s2 * c0 };

		if (Dot(*this, quaternion) < Math::sm_Zero)
		{
			quaternion = -quaternion;
		}

		return quaternion;
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], m_Tuple[1], -m_Tuple[2], m_Tuple[3] };

	auto quaternion = alt.GetClosestZX(zCon, xCon);
	quaternion[2] = -quaternion[2];

	return quaternion;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const auto det = m_Tuple[0] * m_Tuple[1] + m_Tuple[2] * m_Tuple[3];

	if (Math::FAbs(det) < static_cast<Real>(0.5) - Math::sm_ZeroTolerance)
	{
		const auto discr = Math::Sqrt(Math::FAbs(Math::sm_One - (static_cast<Real>(4)) * det * det));

		const auto a = m_Tuple[0] * m_Tuple[3] - m_Tuple[1] * m_Tuple[2];
		const auto b = m_Tuple[0] * m_Tuple[0] - m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] - m_Tuple[3] * m_Tuple[3];

		auto c2 = Math::sm_Zero;
		auto s2 = Math::sm_Zero;

		if (Math::sm_Zero <= b)
		{
			c2 = static_cast<Real>(0.5) * (discr + b);
			s2 = a;
		}
		else
		{
			c2 = a;
			s2 = static_cast<Real>(0.5) * (discr - b);
		}
		auto invLength = Math::InvSqrt(c2 * c2 + s2 * s2);
		c2 *= invLength;
		s2 *= invLength;

		auto c1 = m_Tuple[0] * c2 + m_Tuple[3] * s2;
		auto s1 = m_Tuple[2] * c2 - m_Tuple[1] * s2;
		invLength = Math::InvSqrt(c1 * c1 + s1 * s1);
		c1 *= invLength;
		s1 *= invLength;

		if (zCon.IsValid(c2, s2) && yCon.IsValid(c1, s1))
		{
			// 最大值发生在内部点。
			return Quaternion{ c2 * c1,-s2 * s1,c2 * s1,s2 * c1 };
		}
		else
		{
			// 最大值出现在边界点。
			Quaternion r{ zCon.GetCosMinAngle(), Math::sm_Zero, Math::sm_Zero, zCon.GetSinMinAngle() };
			Quaternion rInv{ zCon.GetCosMinAngle(), Math::sm_Zero, Math::sm_Zero,-zCon.GetSinMinAngle() };
			auto prod = rInv * (*this);
			auto tmp = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
			auto dotOptAngle = Dot(prod, tmp);
			auto quaternion = r * tmp;

			r = Quaternion{ zCon.GetCosMaxAngle(), Math::sm_Zero, Math::sm_Zero, zCon.GetSinMaxAngle() };
			rInv = Quaternion{ zCon.GetCosMaxAngle(), Math::sm_Zero, Math::sm_Zero, -zCon.GetSinMaxAngle() };
			prod = rInv * (*this);
			tmp = prod.GetClosest(QuaternionClosestAxis::Y, yCon);
			auto dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = r * tmp;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ yCon.GetCosMinAngle(), Math::sm_Zero,yCon.GetSinMinAngle(), Math::sm_Zero };
			rInv = Quaternion{ yCon.GetCosMinAngle(), Math::sm_Zero,-yCon.GetSinMinAngle(), Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
			dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			r = Quaternion{ yCon.GetCosMaxAngle(), Math::sm_Zero,yCon.GetSinMaxAngle(), Math::sm_Zero };
			rInv = Quaternion{ yCon.GetCosMaxAngle(), Math::sm_Zero,-yCon.GetSinMaxAngle(), Math::sm_Zero };
			prod = (*this) * rInv;
			tmp = prod.GetClosest(QuaternionClosestAxis::Z, zCon);
			dotAngle = Dot(prod, tmp);
			if (dotOptAngle < dotAngle)
			{
				quaternion = tmp * r;
				dotOptAngle = dotAngle;
			}

			return quaternion;
		}
	}
	else
	{
		/// 无穷多解，选择一个满足约束的角度。
		auto c1 = Math::sm_Zero;
		auto s1 = Math::sm_Zero;
		auto c2 = Math::sm_Zero;
		auto s2 = Math::sm_Zero;

		if (det < Math::sm_Zero)
		{
			const auto minAngle = yCon.GetMinAngle() - zCon.GetMaxAngle();
			const auto maxAngle = yCon.GetMaxAngle() - zCon.GetMinAngle();
			const QuaternionConstraints con{ minAngle, maxAngle };

			auto tmp = GetClosest(QuaternionClosestAxis::Y, con);

			auto angle = Math::ATan2(tmp[2], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[2] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (angle <= yCon.GetMaxAngle() - zCon.GetMaxAngle())
			{
				c2 = zCon.GetCosMaxAngle();
				s2 = zCon.GetSinMaxAngle();
				angle = zCon.GetMaxAngle() + angle;
				c1 = Math::Cos(angle);
				s1 = Math::Sin(angle);
			}
			else
			{
				c1 = yCon.GetCosMaxAngle();
				s1 = yCon.GetSinMaxAngle();
				angle = yCon.GetMaxAngle() - angle;
				c2 = Math::Cos(angle);
				s2 = Math::Sin(angle);
			}
		}
		else
		{
			const auto minAngle = yCon.GetMinAngle() + zCon.GetMinAngle();
			const auto maxAngle = yCon.GetMaxAngle() + zCon.GetMaxAngle();
			const QuaternionConstraints con{ minAngle, maxAngle };

			auto tmp = GetClosest(QuaternionClosestAxis::Y, con);

			auto angle = Math::ATan2(tmp[2], tmp[0]);
			if (angle < minAngle || maxAngle < angle)
			{
				angle -= (Math::sm_Zero <= tmp[2] ? Math::sm_PI : -Math::sm_PI);

				MATHEMATICS_ASSERTION_1(minAngle <= angle && angle <= maxAngle, "angle的值必须在minAngle和maxAngle之间！");
			}

			if (yCon.GetMinAngle() + zCon.GetMaxAngle() <= angle)
			{
				c2 = zCon.GetCosMaxAngle();
				s2 = zCon.GetSinMaxAngle();
				angle = angle - zCon.GetMaxAngle();
				c1 = Math::Cos(angle);
				s1 = Math::Sin(angle);
			}
			else
			{
				c1 = yCon.GetCosMaxAngle();
				s1 = yCon.GetSinMaxAngle();
				angle = angle - yCon.GetMaxAngle();
				c2 = Math::Cos(angle);
				s2 = Math::Sin(angle);
			}
		}

		Quaternion quaternion{ c2 * c1,-s2 * s1, c2 * s1,s2 * c1 };

		if (Dot(*this, quaternion) < Math::sm_Zero)
		{
			quaternion = -quaternion;
		}

		return quaternion;
	}
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics::Quaternion<Real>
	::GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	const Quaternion alt{ m_Tuple[0], -m_Tuple[1], m_Tuple[2], m_Tuple[3] };

	auto quaternion = alt.GetClosestZY(zCon, yCon);
	quaternion[1] = -quaternion[1];

	return quaternion;
}

#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_DETAIL)

template <typename Real>
bool Mathematics
	::operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) < 0;
}

template <typename Real>
const Mathematics::Quaternion<Real> Mathematics
	::operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs)
{
	// 注意:  乘法一般不是可交换的，所以在大多数情况下，
	// p * q != q * p

	return  Quaternion<Real>{ lhs[0] * rhs[0] - lhs[1] * rhs[1] - lhs[2] * rhs[2] - lhs[3] * rhs[3],
							  lhs[0] * rhs[1] + lhs[1] * rhs[0] + lhs[2] * rhs[3] - lhs[3] * rhs[2],
							  lhs[0] * rhs[2] + lhs[2] * rhs[0] + lhs[3] * rhs[1] - lhs[1] * rhs[3],
							  lhs[0] * rhs[3] + lhs[3] * rhs[0] + lhs[1] * rhs[2] - lhs[2] * rhs[1] };
}

template <typename Real>
Real Mathematics
	::Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs)
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2] + lhs[3] * rhs[3];
}

template <typename Real>
bool Mathematics
	::Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, const Real epsilon)
{
	return Math<Real>::FAbs(lhs[0] - rhs[0]) <= epsilon && Math<Real>::FAbs(lhs[1] - rhs[1]) <= epsilon &&
		   Math<Real>::FAbs(lhs[2] - rhs[2]) <= epsilon && Math<Real>::FAbs(lhs[3] - rhs[3]) <= epsilon;
}

template <typename Real>
bool Mathematics
	::Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs)
{
	return Approximate(lhs, rhs, Math::sm_ZeroTolerance);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Quaternion<Real>& quaternion)
{
	return outFile << "w = " << quaternion.GetW()
				   << " x = " << quaternion.GetX()
				   << " y = " << quaternion.GetY()
				   << " z = " << quaternion.GetZ();
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H

