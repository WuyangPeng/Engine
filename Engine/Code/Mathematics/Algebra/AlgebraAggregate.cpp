///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 19:17)

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

    using ValueType = Mathematics::FloatHomogeneousPoint::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::FloatHomogeneousPoint::sm_PointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

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

    using ValueType = Mathematics::DoubleHomogeneousPoint::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::DoubleHomogeneousPoint::sm_PointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleHomogeneousPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector2D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatVector2D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::FloatVector2D::sm_PointSize;

    const auto vector2D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector2D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector2D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector2D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleVector2D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::DoubleVector2D::sm_PointSize;

    const auto vector2D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector2D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector2D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector3D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatVector3D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::FloatVector3D::sm_PointSize;

    const auto vector3D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector3D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector3D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector3D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleVector3D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::DoubleVector3D::sm_PointSize;

    const auto vector3D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector3D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector3D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector4D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatVector4D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::FloatVector4D::sm_PointSize;

    const auto vector4D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector4D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector4D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector4D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleVector4D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::DoubleVector4D::sm_PointSize;

    const auto vector4D = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector4D);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector4D& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatAVector::ArrayType::value_type;
    constexpr auto vectorSize = Mathematics::FloatAVector::sm_AVectorSize;

    const auto homogeneousPoint = ReadContainer<ValueType, vectorSize>();

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

    using ValueType = Mathematics::DoubleAVector::ArrayType::value_type;
    constexpr auto vectorSize = Mathematics::DoubleAVector::sm_AVectorSize;

    const auto homogeneousPoint = ReadContainer<ValueType, vectorSize>();

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

    using ValueType = Mathematics::FloatAPoint::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::FloatAPoint::sm_APointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

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

    using ValueType = Mathematics::DoubleAPoint::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::DoubleAPoint::sm_APointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAPoint& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVariableLengthVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatVariableLengthVector::ContainerType::value_type;

    auto container = ReadVectorWithoutNumber<ValueType>();

    datum.SetContainer(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVariableLengthVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVariableLengthVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleVariableLengthVector::ContainerType::value_type;

    auto container = ReadVectorWithoutNumber<ValueType>();

    datum.SetContainer(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVariableLengthVector& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPlane& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ElementType = Mathematics::FloatPlane::ElementType;
    using AVector = Mathematics::FloatPlane::AVector;

    auto epsilon = Read<ElementType>();
    datum.SetEpsilon(epsilon);

    auto normal = ReadAggregate<AVector>();
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    auto constant = Read<ElementType>();
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

    using ElementType = Mathematics::DoublePlane::ElementType;
    using AVector = Mathematics::DoublePlane::AVector;

    auto epsilon = Read<ElementType>();
    datum.SetEpsilon(epsilon);

    auto normal = ReadAggregate<AVector>();
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    auto constant = Read<ElementType>();
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
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPolynomial& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatPolynomial::ContainerType::value_type;

    auto container = ReadVectorWithoutNumber<ValueType>();

    datum.SetValue(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatPolynomial& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoublePolynomial& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoublePolynomial::ContainerType::value_type;

    auto container = ReadVectorWithoutNumber<ValueType>();

    datum.SetValue(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoublePolynomial& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatMatrix2::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::FloatMatrix2::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleMatrix2::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::DoubleMatrix2::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatMatrix3::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::FloatMatrix3::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleMatrix3::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::DoubleMatrix3::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatMatrix4::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::FloatMatrix4::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleMatrix4::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::DoubleMatrix4::sm_MatrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatMatrix::EntryType::value_type;
    constexpr auto matrixSize = Mathematics::FloatMatrix::sm_EntrySize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
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

    using ValueType = Mathematics::DoubleMatrix::EntryType::value_type;
    constexpr auto matrixSize = Mathematics::DoubleMatrix::sm_EntrySize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetRowMajor());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVariableMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatVariableMatrix::ContainerType::value_type;

    const auto rowsNumber = Read<int32_t>();
    const auto columnsNumber = Read<int32_t>();
    auto container = ReadVectorWithNumber<ValueType>(rowsNumber * columnsNumber);

    datum.SetContainer(rowsNumber, columnsNumber, container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVariableMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetRowsNumber());
    Write(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVariableMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleVariableMatrix::ContainerType::value_type;

    const auto rowsNumber = Read<int32_t>();
    const auto columnsNumber = Read<int32_t>();
    auto container = ReadVectorWithNumber<ValueType>(rowsNumber * columnsNumber);

    datum.SetContainer(rowsNumber, columnsNumber, container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVariableMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(datum.GetRowsNumber());
    Write(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatBandedMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatBandedMatrix::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

    auto container = ReadVectorWithNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorWithNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorWithNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatBandedMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleBandedMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleBandedMatrix::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

    auto container = ReadVectorWithNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorWithNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorWithNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleBandedMatrix& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatBandedMatrixSolve& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatBandedMatrixSolve::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();
    const auto epsilon = Read<ValueType>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    auto container = ReadVectorWithNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorWithNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorWithNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatBandedMatrixSolve& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleBandedMatrixSolve& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleBandedMatrixSolve::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();
    const auto epsilon = Read<ValueType>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    auto container = ReadVectorWithNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorWithNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorWithNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleBandedMatrixSolve& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write(size);
    Write(lowerBandsNumber);
    Write(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(i));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(i));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatQuaternion::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::FloatQuaternion::sm_EntrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.SetCoordinate(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleQuaternion::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::DoubleQuaternion::sm_EntrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.SetCoordinate(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::FloatAQuaternion::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::FloatAQuaternion::sm_EntrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::DoubleAQuaternion::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::DoubleAQuaternion::sm_EntrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAQuaternion& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float1& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::Float1::TupleType;

    auto value = Read<ValueType>();

    datum[0] = value;
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float1& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum[0];

    Write(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::Float1::TupleType;
    constexpr auto dimension = Mathematics::Float2::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float2& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    constexpr auto dimension = Mathematics::Float2::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        Write(datum[i]);
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::Float3::TupleType;
    constexpr auto dimension = Mathematics::Float3::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float3& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    constexpr auto dimension = Mathematics::Float3::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        Write(datum[i]);
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using ValueType = Mathematics::Float4::TupleType;
    constexpr auto dimension = Mathematics::Float4::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float4& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    constexpr auto dimension = Mathematics::Float4::TupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        Write(datum[i]);
    }
}
