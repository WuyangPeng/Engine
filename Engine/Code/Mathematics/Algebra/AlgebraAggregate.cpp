// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:08)

#include "Mathematics/MathematicsExport.h"

#include "AlgebraAggregate.h"
#include "HomogeneousPointDetail.h"
#include "Vector2DDetail.h"
#include "Vector3DDetail.h"
#include "Vector4DDetail.h"
#include "AVectorDetail.h"
#include "APointDetail.h"
#include "VariableLengthVectorDetail.h"
#include "PlaneDetail.h"
#include "PolynomialDetail.h"
#include "Matrix2Detail.h"
#include "Matrix3Detail.h"
#include "Matrix4Detail.h"
#include "MatrixDetail.h"
#include "VariableMatrixDetail.h"
#include "BandedMatrixDetail.h"
#include "BandedMatrixSolveDetail.h"
#include "QuaternionDetail.h"
#include "AQuaternionDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::HomogeneousPoint<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::HomogeneousPoint<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::HomogeneousPoint<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::HomogeneousPoint<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector2D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(2, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector2D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(2, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector2D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(2, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector2D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(2, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector3D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector3D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector3D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector3D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector4D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector4D<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector4D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Vector4D<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AVector<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::AVector<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AVector<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::AVector<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::APoint<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::APoint<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::APoint<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(3, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::APoint<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(3, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableLengthVector<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);
	datum.ResetSize(size);

	Read(size, datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::VariableLengthVector<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithNumber(datum.GetSize(), datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableLengthVector<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);
	datum.ResetSize(size);

	Read(size, datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::VariableLengthVector<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithNumber(datum.GetSize(), datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Plane<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, datum.GetElements());

	float epsilon{ 0.0f };
	Read(epsilon);
	datum.SetEpsilon(epsilon);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Plane<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, datum.GetElements());
	Write(datum.GetEpsilon());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Plane<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, datum.GetElements());

	double epsilon{ 0.0 };
	Read(epsilon);
	datum.SetEpsilon(epsilon);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Plane<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, datum.GetElements());
	Write(datum.GetEpsilon());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Polynomial<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t degree{ 0 };
	Read(degree);
	datum.ResetDegree(degree - 1);

	Read(degree, datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Polynomial<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithNumber(datum.GetDegree() + 1, datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Polynomial<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t degree{ 0 };
	Read(degree);
	datum.ResetDegree(degree - 1);

	Read(degree, datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Polynomial<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithNumber(datum.GetDegree() + 1, datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix2<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix2<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix2<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix2<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix3<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(9, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix3<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(9, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix3<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(9, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix3<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(9, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix4<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(16, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix4<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(16, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix4<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(16, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix4<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(16, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(16, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(16, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(16, datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Matrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(16, datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableMatrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t rowsNumber{ 0 };
	Read(rowsNumber);

	int32_t columnsNumber{ 0 };
	Read(columnsNumber);
	datum.ResetSize(rowsNumber, columnsNumber);

	Read(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::VariableMatrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Write(datum.GetRowsNumber());
	Write(datum.GetColumnsNumber());
	WriteWithoutNumber(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableMatrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t rowsNumber{ 0 };
	Read(rowsNumber);

	int32_t columnsNumber{ 0 };
	Read(columnsNumber);
	datum.ResetSize(rowsNumber, columnsNumber);

	Read(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::VariableMatrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Write(datum.GetRowsNumber());
	Write(datum.GetColumnsNumber());
	WriteWithoutNumber(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);

	int32_t lowerBandsNumber{ 0 };
	Read(lowerBandsNumber);

	int32_t upperBandsNumber{ 0 };
	Read(upperBandsNumber);

	datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

	Read(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		Read(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		Read(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::BandedMatrix<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	auto size = datum.GetSize();
	auto lowerBandsNumber = datum.GetLowerBandsNumber();
	auto upperBandsNumber = datum.GetUpperBandsNumber();

	Write(size);
	Write(lowerBandsNumber);
	Write(upperBandsNumber);

	WriteWithoutNumber(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		WriteWithoutNumber(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		WriteWithoutNumber(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);

	int32_t lowerBandsNumber{ 0 };
	Read(lowerBandsNumber);

	int32_t upperBandsNumber{ 0 };
	Read(upperBandsNumber);

	datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

	Read(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		Read(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		Read(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::BandedMatrix<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	auto size = datum.GetSize();
	auto lowerBandsNumber = datum.GetLowerBandsNumber();
	auto upperBandsNumber = datum.GetUpperBandsNumber();

	Write(size);
	Write(lowerBandsNumber);
	Write(upperBandsNumber);

	WriteWithoutNumber(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		WriteWithoutNumber(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		WriteWithoutNumber(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrixSolve<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);

	int32_t lowerBandsNumber{ 0 };
	Read(lowerBandsNumber);

	int32_t upperBandsNumber{ 0 };
	Read(upperBandsNumber);

	float epsilon{ 0.0f };
	Read(epsilon);

	datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

	Read(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		Read(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		Read(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::BandedMatrixSolve<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	auto size = datum.GetSize();
	auto lowerBandsNumber = datum.GetLowerBandsNumber();
	auto upperBandsNumber = datum.GetUpperBandsNumber();

	Write(size);
	Write(lowerBandsNumber);
	Write(upperBandsNumber);
	Write(datum.GetEpsilon());

	WriteWithoutNumber(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		WriteWithoutNumber(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		WriteWithoutNumber(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrixSolve<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	int32_t size{ 0 };
	Read(size);

	int32_t lowerBandsNumber{ 0 };
	Read(lowerBandsNumber);

	int32_t upperBandsNumber{ 0 };
	Read(upperBandsNumber);

	double epsilon{ 0.0 };
	Read(epsilon);

	datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

	Read(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		Read(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		Read(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::BandedMatrixSolve<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	auto size = datum.GetSize();
	auto lowerBandsNumber = datum.GetLowerBandsNumber();
	auto upperBandsNumber = datum.GetUpperBandsNumber();

	Write(size);
	Write(lowerBandsNumber);
	Write(upperBandsNumber);
	Write(datum.GetEpsilon());

	WriteWithoutNumber(size, datum.GetDiagonalBand());

	for (auto i = 0; i < lowerBandsNumber; ++i)
	{
		auto lowerSize = size - 1 - i;
		WriteWithoutNumber(lowerSize, datum.GetLowerBand(i));
	}

	for (auto i = 0; i < upperBandsNumber; ++i)
	{
		auto upperSize = size - 1 - i;
		WriteWithoutNumber(upperSize, datum.GetUpperBand(i));
	}
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Quaternion<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Quaternion<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Quaternion<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Quaternion<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AQuaternion<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::AQuaternion<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AQuaternion<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	Read(4, &datum[0]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::AQuaternion<double>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	WriteWithoutNumber(4, &datum[0]);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float1& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value{ 0.0f };

	Read(value);

	datum.SetValue(value);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Float1& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	auto value = datum.GetValue();

	Write(value);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float2& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[2]{};

	Read(2, value);

	datum.SetFirstValue(value[0]);
	datum.SetSecondValue(value[1]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Float2& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[2]{ datum.GetFirstValue() ,datum.GetSecondValue() };

	WriteWithoutNumber(2, value);
}

template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float3& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[3]{ 0.0f ,0.0f ,0.0f };

	Read(3, value);

	datum.SetFirstValue(value[0]);
	datum.SetSecondValue(value[1]);
	datum.SetThirdValue(value[2]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Float3& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[3]{ datum.GetFirstValue() ,datum.GetSecondValue(),datum.GetThirdValue() };

	WriteWithoutNumber(3, value);
}


template <>
void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float4& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[4]{ 0.0f ,0.0f ,0.0f ,0.0f };

	Read(4, value);

	datum.SetFirstValue(value[0]);
	datum.SetSecondValue(value[1]);
	datum.SetThirdValue(value[2]);
	datum.SetFourthValue(value[3]);
}

template <>
void CoreTools::BufferTarget
	::WriteAggregate(const Mathematics::Float4& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	MATHEMATICS_CLASS_IS_VALID_9;

	float value[4]{ datum.GetFirstValue() ,datum.GetSecondValue(),datum.GetThirdValue() ,datum.GetFourthValue() };

	WriteWithoutNumber(4, value);
}