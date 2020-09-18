//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/10 15:23)

#include "Mathematics/MathematicsExport.h"

#include "APointDetail.h"
#include "AQuaternionDetail.h"
#include "AVectorDetail.h"
#include "AlgebraAggregate.h"
#include "BandedMatrixDetail.h"
#include "BandedMatrixSolveDetail.h"
#include "HomogeneousPointDetail.h"
#include "Matrix2Detail.h"
#include "Matrix3Detail.h"
#include "Matrix4Detail.h"
#include "MatrixDetail.h"
#include "PlaneDetail.h"
#include "PolynomialDetail.h"
#include "QuaternionDetail.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrixDetail.h"
#include "Vector2DDetail.h"
#include "Vector3DDetail.h"
#include "Vector4DDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

#include <array>

using std::array;

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatHomogeneousPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::FloatHomogeneousPoint::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatHomogeneousPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleHomogeneousPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::DoubleHomogeneousPoint::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleHomogeneousPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector2Df::ArrayType vector2D{};

    Read(vector2D);

    datum.SetCoordinate(vector2D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector2Dd::ArrayType vector2D{};

    Read(vector2D);

    datum.SetCoordinate(vector2D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector3Df::ArrayType vector3D{};

    Read(vector3D);

    datum.SetCoordinate(vector3D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector3Dd::ArrayType vector3D{};

    Read(vector3D);

    datum.SetCoordinate(vector3D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector4Df::ArrayType vector4D{};

    Read(vector4D);

    datum.SetCoordinate(vector4D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4Df& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Vector4Dd::ArrayType vector4D{};

    Read(vector4D);

    datum.SetCoordinate(vector4D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4Dd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::FloatAVector::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::DoubleAVector::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::FloatAPoint::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::DoubleAPoint::ArrayType homogeneousPoint{};

    Read(homogeneousPoint);

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);
    datum.ResetSize(size);

    Read(size, datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectord& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);
    datum.ResetSize(size);

    Read(size, datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectord& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPlane& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto epsilon = 0.0f;
    Read(epsilon);
    datum.SetEpsilon(epsilon);

    Mathematics::FloatPlane::AVector normal{};
    ReadAggregate(normal);
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    auto constant = 0.0f;
    Read(constant);
    datum.SetConstant(constant);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatPlane& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetEpsilon());
    WriteAggregate(datum.GetNormal());
    Write(datum.GetConstant());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoublePlane& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto epsilon = 0.0;
    Read(epsilon);
    datum.SetEpsilon(epsilon);

    Mathematics::DoublePlane::AVector normal{};
    ReadAggregate(normal);
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    auto constant = 0.0f;
    Read(constant);
    datum.SetConstant(constant);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoublePlane& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetEpsilon());
    WriteAggregate(datum.GetNormal());
    Write(datum.GetConstant());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Polynomialf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t degree{ 0 };
    Read(degree);
    datum.ResetDegree(degree - 1);

    Read(degree, datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Polynomialf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Polynomiald& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t degree{ 0 };
    Read(degree);
    datum.ResetDegree(degree - 1);

    Read(degree, datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Polynomiald& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix2f::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix2d::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix3f::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix3d::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix4f::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4f& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Matrix4d::ArrayType matrix{};

    Read(matrix);

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4d& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::FloatMatrix::EntryType data{};

    Read(data);

    datum.Set(data);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetRowMajor());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::DoubleMatrix::EntryType data{};

    Read(data);

    datum.Set(data);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetRowMajor());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t rowsNumber{ 0 };
    Read(rowsNumber);
    int32_t columnsNumber{ 0 };
    Read(columnsNumber);

    datum.ResetSize(rowsNumber, columnsNumber);

    Read(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetRowsNumber());
    Write(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t rowsNumber{ 0 };
    Read(rowsNumber);
    int32_t columnsNumber{ 0 };
    Read(columnsNumber);

    datum.ResetSize(rowsNumber, columnsNumber);

    Read(datum.GetElementsNumber(), datum.GetElements());
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetRowsNumber());
    Write(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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
        const auto lowerSize = size - 1 - i;
        Read(lowerSize, datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        Read(upperSize, datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBandValue());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBandValue(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBandValue(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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
        const auto lowerSize = size - 1 - i;
        Read(lowerSize, datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        Read(upperSize, datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixd& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBandValue());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBandValue(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBandValue(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolvef& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);

    int32_t lowerBandsNumber{ 0 };
    Read(lowerBandsNumber);

    int32_t upperBandsNumber{ 0 };
    Read(upperBandsNumber);

    auto epsilon = 0.0f;
    Read(epsilon);

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    Read(size, datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        Read(lowerSize, datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        Read(upperSize, datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolvef& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBandValue());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBandValue(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBandValue(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolved& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t size{ 0 };
    Read(size);

    int32_t lowerBandsNumber{ 0 };
    Read(lowerBandsNumber);

    int32_t upperBandsNumber{ 0 };
    Read(upperBandsNumber);

    auto epsilon = 0.0;
    Read(epsilon);

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    Read(size, datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        Read(lowerSize, datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        Read(upperSize, datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolved& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBandValue());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBandValue(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBandValue(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Quaternionf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Quaternionf::ArrayType quaternion{};

    Read(quaternion);

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Quaternionf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Quaterniond& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::Quaterniond::ArrayType quaternion{};

    Read(quaternion);

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Quaterniond& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::AQuaternionf::ArrayType quaternion{};

    Read(quaternion);

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionf& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaterniond& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Mathematics::AQuaterniond::ArrayType quaternion{};

    Read(quaternion);

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaterniond& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float1& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto value = 0.0f;

    Read(value);

    datum.SetValue(value);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float1& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum.GetValue();

    Write(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<float, 2> value{};

    Read(2, value.data());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    datum.SetFirstValue(value[0]);
    datum.SetSecondValue(value[1]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const std::array<float, 2> value{ datum.GetFirstValue(), datum.GetSecondValue() };

    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<float, 3> value{ 0.0f, 0.0f, 0.0f };

    Read(3, value.data());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    datum.SetFirstValue(value[0]);
    datum.SetSecondValue(value[1]);
    datum.SetThirdValue(value[2]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const std::array<float, 3> value{ datum.GetFirstValue(), datum.GetSecondValue(), datum.GetThirdValue() };

    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::array<float, 4> value{ 0.0f, 0.0f, 0.0f, 0.0f };

    Read(4, value.data());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    datum.SetFirstValue(value[0]);
    datum.SetSecondValue(value[1]);
    datum.SetThirdValue(value[2]);
    datum.SetFourthValue(value[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const std::array<float, 4> value{ datum.GetFirstValue(), datum.GetSecondValue(), datum.GetThirdValue(), datum.GetFourthValue() };

    WriteContainer(value);
}
