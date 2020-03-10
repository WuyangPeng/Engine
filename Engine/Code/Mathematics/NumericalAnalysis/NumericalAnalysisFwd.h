// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H

namespace Mathematics
{	
	template <typename ResultConstIter>
	class EquationResultConstIterator;

	class Equation;

	template <typename Real>
	class Bisect1Root;

	template <typename Real>
	class Bisect1;	

	template <typename Real>
	class Bisect2Root;

	template <typename Real>
	class Bisect2Node;

	template <typename Real>
	class Bisect2Storage;

	template <typename Real>
	class Bisect2Calculate;

	template <typename Real>
	class Bisect2;

	template <typename Real>
	class Bisect3Root;

	template <typename Real>
	class Bisect3Node;

	template <typename Real>
	class Bisect3Storage;

	template <typename Real>
	class Bisect3Calculate;

	template <typename Real>
	class Bisect3;

	template <typename Real>
	class BrentsMethodRoot;

	template <typename Real,typename UserDataType>
	class BrentsMethodCalculate;

	template <typename Real,typename UserDataType>
	class BrentsMethod;

	template <typename Real>
	class EigenDecomposition;

	template <typename Real, typename UserDataType>
	class  GaussianQuadrature;

	template <typename Real>
	class LinearSystemInverse;

	template <typename Real, template <typename> class Matrix>
	class SolveSymmetricConjugateGradient;

	class SparseMatrixIndex;

	template <typename Real>
	class SparseMatrix;

	template <typename Real>
	class SolveBanded;

	template <typename Real>
	class  LinearSystem;

	template <typename Real>
	class Minimize1Data;

	template <typename Real,typename UserDataType>
	class Minimize1;

	template <typename Real>
	class MinimizeNData;

	template <typename Real,typename UserDataType>
	class MinimizeN;

	template <typename Real>
	class NoniterativeEigen3x3;

	template <typename Real, typename UserDataType>
	class OdeSolver;

	template <typename Real, typename UserDataType>
	class OdeEuler;

	template <typename Real, typename UserDataType>
	class OdeImplicitEuler;

	template <typename Real, typename UserDataType>
	class OdeMidpoint;

	template <typename Real, typename UserDataType>
	class OdeRungeKutta4;

	template <typename Real>
	class PolynomialRoots;

	template <typename Real>
	class PolynomialRootsRational;

	template <typename Real, typename UserDataType>
	class  RombergIntegral;

	template <typename Real, typename UserDataType>
	class  TrapezoidRule;

	template <typename Real>
	class SingularValueDecomposition;

	template <typename Real>
	class Matrix3Tools;

	template <typename Real>
	class SingularValue;

	template <typename Real>
	class PolarDecompositionValue;

	template <typename Real>
	class QDUDecompositionValue;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H