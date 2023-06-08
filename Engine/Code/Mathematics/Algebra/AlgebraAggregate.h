///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:35)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H

#include "Mathematics/MathematicsDll.h"

#include "APoint.h"
#include "AQuaternion.h"
#include "AVector.h"
#include "AlgebraStreamSize.h"
#include "BandedMatrix.h"
#include "BandedMatrixSolve.h"
#include "HomogeneousPoint.h"
#include "Matrix.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Plane.h"
#include "Polynomial.h"
#include "Quaternion.h"
#include "VariableLengthVector.h"
#include "VariableMatrix.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Mathematics/Base/Float.h"

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::HomogeneousPointF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::HomogeneousPointF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::HomogeneousPointD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::HomogeneousPointD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AVectorF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AVectorF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AVectorD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AVectorD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::APointF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::APointF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::APointD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::APointD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::PlaneF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PlaneF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::PlaneD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PlaneD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::PolynomialF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PolynomialF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::PolynomialD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::PolynomialD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4F& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::MatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::MatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::MatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::MatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolveF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolveF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolveD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolveD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::QuaternionF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::QuaternionF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::QuaternionD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::QuaternionD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionF& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionD& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Float1& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float1& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Float2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Float3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Float4& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Float4& datum);

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H
