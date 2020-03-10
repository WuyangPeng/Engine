// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 09:47)

#ifndef MATHEMATICS_ALGEBRA_FWD_H
#define MATHEMATICS_ALGEBRA_FWD_H

namespace Mathematics
{
	template <typename T>
	class HomogeneousPoint;

	template<typename Traits>
	struct AlgebraTraits;

	template <typename Real,int WindowSize>
	class BarycentricCoordinates;

	template <typename Real>
	class Vector2D;

	template <typename Real>
	class Vector3D;

	template <typename Real>
	class Vector4D;

	template <typename Real>
	class Vector2DOrthonormalize;

	template <typename Real>
	class Vector2DOrthonormalBasis;

	template <typename Real>
	class Vector3DOrthonormalize;

	template <typename Real>
	class Vector3DOrthonormalBasis;

	template <typename T>
	class AxesAlignBoundingBox2D;

	template <typename T>
	class AxesAlignBoundingBox3D;

	template <typename T>
	class AxesAlignBoundingBox4D;

	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class Vector4DTools;		

	template <typename Real>
	class Vector2DInformation;

	template <typename Real>
	class Vector3DInformation;

	template <typename T>
	class APoint;

	template <typename Real>
	class AVectorOrthonormalize;

	template <typename T>
	class AVectorOrthonormalBasis;

	template <typename T>
	class AVector;

	template <typename Real>
	class VariableLengthVector;

	template <typename T>
	class Plane;

	template <typename Real>
	class Polynomial;

	template <typename Real>
	class PolynomialDivide;

	template <typename Real>
	class Matrix2;

	template <typename Real>
	class Matrix2EigenDecomposition; 

	template <typename Real>
	class Matrix3;

	template <typename Real>
	class Matrix3Extract;

	template <typename Real>
	class Matrix3EigenDecomposition;

	template <typename Real>
	class Euler;

	template <typename Real>
	class Matrix4;

	template <typename Real>
	class Matrix;

	template <typename Real>
	class VariableMatrix;

	template <typename Real>
	class BandedMatrix;

	template <typename Real>
	class BandedMatrixSolve;

	template <typename Real>
	class Quaternion;

	template <typename Real>
	class QuaternionFactor;

	template <typename Real>
	class QuaternionConstraints;

	template <typename Real>
	class QuaternionSwingTwist;

	template <typename Real>
	class AQuaternion;
}

#endif // MATHEMATICS_ALGEBRA_FWD_H