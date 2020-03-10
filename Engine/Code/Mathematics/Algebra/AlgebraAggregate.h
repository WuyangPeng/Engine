// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 09:46)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
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
#include "AlgebraStreamSize.h"
#include "Mathematics/Base/Float1.h"
#include "Mathematics/Base/Float2.h"
#include "Mathematics/Base/Float3.h"
#include "Mathematics/Base/Float4.h"

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::HomogeneousPoint<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::HomogeneousPoint<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::HomogeneousPoint<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::HomogeneousPoint<double>& datum);


template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector2D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector2D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector2D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector2D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector3D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector3D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector3D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector3D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector4D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector4D<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Vector4D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Vector4D<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AVector<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::AVector<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AVector<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::AVector<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::APoint<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::APoint<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::APoint<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::APoint<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableLengthVector<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::VariableLengthVector<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableLengthVector<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::VariableLengthVector<double>& datum);


template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Plane<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Plane<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Plane<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Plane<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Polynomial<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Polynomial<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Polynomial<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Polynomial<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix2<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix2<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix2<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix2<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix3<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix3<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix3<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix3<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix2<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix4<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix4<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix4<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix4<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Matrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Matrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableMatrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::VariableMatrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::VariableMatrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::VariableMatrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::BandedMatrix<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::BandedMatrix<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrixSolve<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::BandedMatrixSolve<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::BandedMatrixSolve<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::BandedMatrixSolve<double>& datum);
 
template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Quaternion<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Quaternion<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Quaternion<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Quaternion<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AQuaternion<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::AQuaternion<float>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::AQuaternion<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::AQuaternion<double>& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float1& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Float1& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float2& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Float2& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float3& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Float3& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferSource
	::ReadAggregate(Mathematics::Float4& datum);

template <> 
MATHEMATICS_DEFAULT_DECLARE void CoreTools::BufferTarget
	::WriteAggregate (const Mathematics::Float4& datum);

#endif // MATHEMATICS_ALGEBRA_ALGEBRA_AGGREGATE_H
