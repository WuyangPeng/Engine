///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 9:50)

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
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Mathematics/Base/Float.h"

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector2D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector3D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVector4D& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVariableLengthVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVariableLengthVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVariableLengthVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVariableLengthVector& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatPlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoublePlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoublePlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPolynomial& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatPolynomial& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoublePolynomial& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoublePolynomial& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix2& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix3& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix4& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix4& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix4& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix4& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatVariableMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatVariableMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleVariableMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleVariableMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatBandedMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatBandedMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleBandedMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleBandedMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatBandedMatrixSolve& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatBandedMatrixSolve& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleBandedMatrixSolve& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleBandedMatrixSolve& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatAQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatAQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleAQuaternion& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleAQuaternion& datum);

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
