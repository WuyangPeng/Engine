//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/09 17:58)

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
#include "Mathematics/Base/Float1.h"
#include "Mathematics/Base/Float2.h"
#include "Mathematics/Base/Float3.h"
#include "Mathematics/Base/Float4.h"

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleHomogeneousPoint& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector2Dd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector2Dd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector3Dd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector3Dd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4Df& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Vector4Dd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Vector4Dd& datum);

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
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectorf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectorf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableLengthVectord& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableLengthVectord& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatPlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatPlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoublePlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoublePlane& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Polynomialf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Polynomialf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Polynomiald& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Polynomiald& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix2d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix2d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix3d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix3d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4f& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Matrix4d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Matrix4d& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::FloatMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::FloatMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::DoubleMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::DoubleMatrix& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::VariableMatrixd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::VariableMatrixd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixd& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolvef& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolvef& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::BandedMatrixSolved& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::BandedMatrixSolved& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Quaternionf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Quaternionf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::Quaterniond& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::Quaterniond& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaternionf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaternionf& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Mathematics::AQuaterniond& datum);

template <>
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Mathematics::AQuaterniond& datum);

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
