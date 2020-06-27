// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 09:54)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H

#include "HomogeneousPoint.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "AVector.h"
#include "APoint.h"
#include "VariableLengthVector.h"
#include "Plane.h"
#include "Polynomial.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Matrix.h"
#include "VariableMatrix.h"
#include "BandedMatrix.h"
#include "BandedMatrixSolve.h"
#include "Quaternion.h"
#include "AQuaternion.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "Mathematics/Base/Float1.h"
#include "Mathematics/Base/Float2.h"
#include "Mathematics/Base/Float3.h"
#include "Mathematics/Base/Float4.h"

template <typename Real>
struct CoreTools::StreamSize<Mathematics::HomogeneousPoint<Real>>
{
	using HomogeneousPoint = Mathematics::HomogeneousPoint<Real>;

	static int GetStreamSize(const HomogeneousPoint& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * HomogeneousPoint::GetPointSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector2D<Real>>
{
	static int GetStreamSize(const Mathematics::Vector2D<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 2;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector3D<Real>>
{
	static int GetStreamSize(const Mathematics::Vector3D<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 3;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector4D<Real>>
{
	static int GetStreamSize(const Mathematics::Vector4D<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 4;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AVector<Real>>
{
	static int GetStreamSize(const Mathematics::AVector<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 3;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::APoint<Real>>
{
	static int GetStreamSize(const Mathematics::APoint<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 3;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableLengthVector<Real>>
{
	static int GetStreamSize(const Mathematics::VariableLengthVector<Real>& value)
	{
		return StreamSize<Real>::GetStreamSize() * value.GetSize() + StreamSize<int32_t>::GetStreamSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Plane<Real>>
{
	static int GetStreamSize(const Mathematics::Plane<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 4 + StreamSize<Real>::GetStreamSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Polynomial<Real>>
{
	static int GetStreamSize(const Mathematics::Polynomial<Real>& value)
	{	 
		return StreamSize<Real>::GetStreamSize() * (value.GetDegree() + 1) + StreamSize<int32_t>::GetStreamSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix2<Real>>
{
	static int GetStreamSize(const Mathematics::Matrix2<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 4;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix3<Real>>
{
	static int GetStreamSize(const Mathematics::Matrix3<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 9;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix4<Real>>
{
	static int GetStreamSize(const Mathematics::Matrix4<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 16;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix<Real>>
{
	static int GetStreamSize(const Mathematics::Matrix<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 16;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableMatrix<Real>>
{
	static int GetStreamSize(const Mathematics::VariableMatrix<Real>& value)
	{
		return StreamSize<Real>::GetStreamSize() * value.GetElementsNumber() + StreamSize<int32_t>::GetStreamSize() * 2;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrix<Real>>
{
	static int GetStreamSize(const Mathematics::BandedMatrix<Real>& value)
	{
		return value.GetStreamSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrixSolve<Real>>
{
	static int GetStreamSize(const Mathematics::BandedMatrixSolve<Real>& value)
	{
		return value.GetStreamSize();
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Quaternion<Real>>
{
	static int GetStreamSize(const Mathematics::Quaternion<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 4;
	}
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AQuaternion<Real>>
{
	static int GetStreamSize(const Mathematics::AQuaternion<Real>& value)
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<Real>::GetStreamSize() * 4;
	}
};

template <>
struct CoreTools::StreamSize<Mathematics::Float1>
{
	static int GetStreamSize(const Mathematics::Float1& value) noexcept
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<float>::GetStreamSize();
	}
};

template <>
struct CoreTools::StreamSize<Mathematics::Float2>
{
	static int GetStreamSize(const Mathematics::Float2& value) noexcept
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<float>::GetStreamSize() * 2;
	}
};

template <>
struct CoreTools::StreamSize<std::vector<Mathematics::Float2> >
{
	static int GetStreamSize(const std::vector<Mathematics::Float2>& value)
	{
		const auto elementsSize = value.size();

		return StreamSize<int32_t>::GetStreamSize() + StreamSize<float>::GetStreamSize() * 2 * boost::numeric_cast<int>(elementsSize);
	}
};

template <>
struct CoreTools::StreamSize<Mathematics::Float3>
{
	static int GetStreamSize(const Mathematics::Float3& value) noexcept
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<float>::GetStreamSize() * 3;
	}
};

template <>
struct CoreTools::StreamSize<Mathematics::Float4>
{
	static int GetStreamSize(const Mathematics::Float4& value) noexcept
	{
		SYSTEM_UNUSED_ARG(value);

		return StreamSize<float>::GetStreamSize() * 4;
	}
};

namespace Mathematics
{
	template <typename T>
	int GetStreamSize(T value)
	{
		return CoreTools::StreamSize<T>::GetStreamSize(value);
	}
}

// MATHEMATICS_STREAM_SIZE宏被流系统使用。
#define MATHEMATICS_STREAM_SIZE(value) Mathematics::GetStreamSize(value)

#endif // MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H
