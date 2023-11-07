///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:02)

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
#include "Vector2Detail.h"
#include "Vector3Detail.h"
#include "Vector4Detail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

#include <array>

using std::array;

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::HomogeneousPointF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::HomogeneousPointF::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::HomogeneousPointF::pointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::HomogeneousPointF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::HomogeneousPointD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::HomogeneousPointD::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::HomogeneousPointD::pointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::HomogeneousPointD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector2F::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector2F::pointSize;

    const auto vector2 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector2);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector2D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector2D::pointSize;

    const auto vector2 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector2);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector3F::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector3F::pointSize;

    const auto vector3 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector3);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector3D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector3D::pointSize;

    const auto vector3 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector3);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector4F::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector4F::pointSize;

    const auto vector4 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector4);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Vector4D::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::Vector4D::pointSize;

    const auto vector4 = ReadContainer<ValueType, pointSize>();

    datum.SetCoordinate(vector4);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AVectorF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::AVectorF::ArrayType::value_type;
    constexpr auto vectorSize = Mathematics::AVectorF::vectorSize;

    const auto homogeneousPoint = ReadContainer<ValueType, vectorSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AVectorF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AVectorD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::AVectorD::ArrayType::value_type;
    constexpr auto vectorSize = Mathematics::AVectorD::vectorSize;

    const auto homogeneousPoint = ReadContainer<ValueType, vectorSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AVectorD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::APointF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::APointF::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::APointF::pointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::APointF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::APointD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::APointD::ArrayType::value_type;
    constexpr auto pointSize = Mathematics::APointD::pointSize;

    const auto homogeneousPoint = ReadContainer<ValueType, pointSize>();

    datum.Set(homogeneousPoint);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::APointD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::VariableLengthVectorF::ContainerType::value_type;

    const auto container = ReadVectorNotUseNumber<ValueType>();

    datum.SetContainer(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainerWithNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::VariableLengthVectorD::ContainerType::value_type;

    const auto container = ReadVectorNotUseNumber<ValueType>();

    datum.SetContainer(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainerWithNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::PlaneF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ElementType = Mathematics::PlaneF::ElementType;
    using AVector = Mathematics::PlaneF::AVector;

    const auto epsilon = Read<ElementType>();
    datum.SetEpsilon(epsilon);

    auto normal = ReadAggregate<AVector>();
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    const auto constant = Read<ElementType>();
    datum.SetConstant(constant);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PlaneF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    Write(datum.GetEpsilon());
    WriteAggregate(datum.GetNormal());
    Write(datum.GetConstant());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::PlaneD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ElementType = Mathematics::PlaneD::ElementType;
    using AVector = Mathematics::PlaneD::AVector;

    const auto epsilon = Read<ElementType>();
    datum.SetEpsilon(epsilon);

    auto normal = ReadAggregate<AVector>();
    normal.Normalize(epsilon);
    datum.SetNormal(normal);

    const auto constant = Read<ElementType>();
    datum.SetConstant(constant);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PlaneD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    Write(datum.GetEpsilon());
    WriteAggregate(datum.GetNormal());
    Write(datum.GetConstant());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::PolynomialF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::PolynomialF::ContainerType::value_type;

    const auto container = ReadVectorNotUseNumber<ValueType>();

    datum.SetValue(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PolynomialF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::PolynomialD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::PolynomialD::ContainerType::value_type;

    const auto container = ReadVectorNotUseNumber<ValueType>();

    datum.SetValue(container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PolynomialD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainerWithNumber(datum.GetValue());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix2F::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix2F::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix2D::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix2D::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix3F::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix3F::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix3D::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix3D::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix4F::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix4F::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4F& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Matrix4D::ArrayType::value_type;
    constexpr auto matrixSize = Mathematics::Matrix4D::matrixSize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4D& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::MatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::MatrixF::EntryType::value_type;
    constexpr auto matrixSize = Mathematics::MatrixF::entrySize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::MatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetRowMajor());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::MatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::MatrixD::EntryType::value_type;
    constexpr auto matrixSize = Mathematics::MatrixD::entrySize;

    const auto matrix = ReadContainer<ValueType, matrixSize>();

    datum.Set(matrix);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::MatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetRowMajor());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::VariableMatrixF::ContainerType::value_type;

    const auto rowsNumber = Read<int32_t>();
    const auto columnsNumber = Read<int32_t>();
    const auto container = ReadVectorUseNumber<ValueType>(rowsNumber * columnsNumber);

    datum.SetContainer(rowsNumber, columnsNumber, container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    Write<int32_t>(datum.GetRowsNumber());
    Write<int32_t>(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::VariableMatrixD::ContainerType::value_type;

    const auto rowsNumber = Read<int32_t>();
    const auto columnsNumber = Read<int32_t>();
    const auto container = ReadVectorUseNumber<ValueType>(rowsNumber * columnsNumber);

    datum.SetContainer(rowsNumber, columnsNumber, container);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    Write<int32_t>(datum.GetRowsNumber());
    Write<int32_t>(datum.GetColumnsNumber());
    WriteContainerWithoutNumber(datum.GetContainer());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::BandedMatrixF::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

    const auto container = ReadVectorUseNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        const auto lowerBand = ReadVectorUseNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        const auto upperBand = ReadVectorUseNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write<int32_t>(size);
    Write<int32_t>(lowerBandsNumber);
    Write<int32_t>(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(lowerSize));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(upperSize));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::BandedMatrixD::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber);

    const auto container = ReadVectorUseNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        const auto lowerBand = ReadVectorUseNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        const auto upperBand = ReadVectorUseNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write<int32_t>(size);
    Write<int32_t>(lowerBandsNumber);
    Write<int32_t>(upperBandsNumber);

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(lowerSize));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(upperSize));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolveF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::BandedMatrixSolveF::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();
    const auto epsilon = Read<ValueType>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    const auto container = ReadVectorUseNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorUseNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorUseNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolveF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write<int32_t>(size);
    Write<int32_t>(lowerBandsNumber);
    Write<int32_t>(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(lowerSize));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(upperSize));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolveD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::BandedMatrixSolveD::ContainerType::value_type;

    const auto size = Read<int32_t>();
    const auto lowerBandsNumber = Read<int32_t>();
    const auto upperBandsNumber = Read<int32_t>();
    const auto epsilon = Read<ValueType>();

    datum.ResetSize(size, lowerBandsNumber, upperBandsNumber, epsilon);

    const auto container = ReadVectorUseNumber<ValueType>(size);
    datum.SetDiagonalBand(container);

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        auto lowerBand = ReadVectorUseNumber<ValueType>(lowerSize);
        datum.SetLowerBand(lowerSize, lowerBand);
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        auto upperBand = ReadVectorUseNumber<ValueType>(upperSize);
        datum.SetLowerBand(upperSize, upperBand);
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolveD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    const auto size = datum.GetSize();
    const auto lowerBandsNumber = datum.GetLowerBandsNumber();
    const auto upperBandsNumber = datum.GetUpperBandsNumber();

    Write<int32_t>(size);
    Write<int32_t>(lowerBandsNumber);
    Write<int32_t>(upperBandsNumber);
    Write(datum.GetEpsilon());

    WriteContainerWithoutNumber(datum.GetDiagonalBand());

    for (auto i = 0; i < lowerBandsNumber; ++i)
    {
        const auto lowerSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetLowerBand(lowerSize));
    }

    for (auto i = 0; i < upperBandsNumber; ++i)
    {
        const auto upperSize = size - 1 - i;
        WriteContainerWithoutNumber(datum.GetUpperBand(upperSize));
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::QuaternionF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::QuaternionF::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::QuaternionF::entrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.SetCoordinate(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::QuaternionF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::QuaternionD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::QuaternionD::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::QuaternionD::entrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.SetCoordinate(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::QuaternionD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::AQuaternionF::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::AQuaternionF::entrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionF& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::AQuaternionD::ArrayType::value_type;
    constexpr auto entrySize = Mathematics::AQuaternionD::entrySize;

    const auto quaternion = ReadContainer<ValueType, entrySize>();

    datum.Set(quaternion);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionD& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    WriteContainer(datum.GetCoordinate());
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float1& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Float1::TupleType;

    const auto value = Read<ValueType>();

    datum[0] = value;
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float1& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    for (const auto element : datum)
    {
        Write(element);
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float2& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Float1::TupleType;
    constexpr auto dimension = Mathematics::Float2::tupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        const auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float2& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    for (const auto element : datum)
    {
        Write(element);
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float3& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Float3::TupleType;
    constexpr auto dimension = Mathematics::Float3::tupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        const auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float3& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    for (const auto element : datum)
    {
        Write(element);
    }
}

template <>
void CoreTools::BufferSource::ReadAggregate(Mathematics::Float4& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    using ValueType = Mathematics::Float4::TupleType;
    constexpr auto dimension = Mathematics::Float4::tupleDimension;

    for (auto i = 0; i < dimension; ++i)
    {
        const auto value = Read<ValueType>();

        datum[i] = value;
    }
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float4& datum)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;

    for (const auto element : datum)
    {
        Write(element);
    }
}
