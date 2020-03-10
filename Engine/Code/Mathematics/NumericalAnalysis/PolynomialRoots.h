// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 16:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Polynomial.h"

#include <vector>

namespace Mathematics
{
    // 方法名是
    //
    // Algebraic：代数使用封闭形式表达（快速，通常不健壮）
    // Bisection：二分法（根边界后，缓慢而健壮）
    // Newton：牛顿/等分混合（根边界后，中而健壮）
    // Eigenvalues：同伴矩阵的特征值（快速健壮）

    // 根界限：
    //
    // 对于一个首一多项式
    // x^n + a[n-1]*x^{n-1} + ... + a[1]*x + a[0]
    // 的柯西约束为M = 1 + max{|a[0]|,...,|a[n-1]|}。
    // 所有实数根必须位于区间[-M,M]。
    // 对于非首一多项式，
    // b[n]*x^n + b[n-1]*x^{n-1} + ... + b[1]*x + b[0]，
    // 在b[n]为不为零，通过除以它，并计算柯西约束：
    // 1 + max{|b[0]/b[n]|,...,|b[n-1]/b[n]|}。 

    template <typename Real>
    class PolynomialRoots
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialRoots<Real>;
        using VariableMatrix = VariableMatrix<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
        using Vector3D = Vector3D<Real>;
        using Polynomial = Polynomial<Real>;
		using RealVector = std::vector<Real>;
		using RealVectorConstIter = typename RealVector::const_iterator;
        
    public:
        explicit PolynomialRoots (Real epsilon);

        CLASS_INVARIANT_DECLARE;

		void SetMaxIterations(int maxIterations);
        
        int GetCount () const;
        Real GetRoot (int index) const;
		const RealVectorConstIter GetBegin() const;
		const RealVectorConstIter GetEnd() const;
        
        // 一次方程:  once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once);
        Real GetBound (Real constant, Real once);

        // 二次方程:  secondary * x^2 + once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once, Real secondary);
        Real GetBound (Real constant, Real once, Real secondary);

        // 三次方程: thrice * x^3 + secondary * x^2+ once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once,Real secondary, Real thrice);
        bool FindEigenvalues (Real constant, Real once,Real secondary, Real thrice,
                              bool doBalancing,Real tolerance = static_cast<Real>(0.001),bool isUseCompanion = true);
        Real GetBound (Real constant, Real once, Real secondary, Real thrice);

		// 解 thrice * r^3 + once * r = constant ，其中thrice > 0和once > 0，这个方程永远都只有一个实数根。
		Real SpecialCubic(Real thrice, Real once, Real constant);

        // 四次方程: quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0
		bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
		bool FindEigenvalues(Real constant, Real once, Real secondary,Real thrice, Real quartic,  bool doBalancing, Real tolerance = static_cast<Real>(0.001));
		Real GetBound(Real constant, Real once, Real secondary,Real thrice, Real quartic);

        // 一般方程: sum_{i=0}^{degree} c(i) * x^i = 0
        bool FindBisection (const Polynomial& polynomial,int digits);        
        Real GetBound (const Polynomial& polynomial);
		// TODO : bool FindNewton(const Polynomial& polynomial, int digits);
		// TODO : bool FindEigenvalues(const Polynomial& polynomial, bool doBalancing);

		// 查找要在指定的间隔。
		bool FindBisection(const Polynomial& polynomial, Real xMin, Real xMax,int digits);

		// TODO : bool FindNewton(const Polynomial& polynomial, Real xMin, Real xMax,int digits);

		bool AllRealPartsNegative(const Polynomial& polyomial);
		bool AllRealPartsPositive(const Polynomial& polyomial);

  		// 计算[begin,end]中根的数目。
		// 利用Sturm序列做计数。它允许通过在 -Math<Real>::sm_MaxReal或 end = Math<Real>::sm_MaxReal。
		// m_Epsilon的值被用作在终点上的Sturm多项式的值的阈值。
		// 如果更小，则该值被假设为零。返回值是根数。如果有无穷多个，则返回-1。
		int GetRootCount(const Polynomial& polynomial, Real begin, Real end);

    private: 
		void BalanceCompanion3(VariableMatrix& matrix, Real tolerance);
        
        bool IsBalancedCompanion3 (Real a10, Real a21,Real a02, Real a12,Real a22, Real tolerance);
        
		bool QRIteration3(VariableMatrix& matrix);

		void FrancisQRStep(VariableMatrix& hessenbergMatrix,VariableLengthVector& vector);

		// 支持FindE.
		const Vector3D GetHouseholderVector(int size, const Vector3D& uVector);                                

        void PremultiplyHouseholder (VariableMatrix& mat,VariableLengthVector& variableLengthVector,int rowMin, int rowMax,
									 int colunmMin, int colunmMax,int vSize,const Vector3D& vVector);

        void PostmultiplyHouseholder (VariableMatrix& mat,VariableLengthVector& variableLengthVector,int rowMin, int rowMax,
									  int colunmMin, int colunmMax,int vSize,const Vector3D& vVector);

		void BalanceCompanion4 (VariableMatrix& matrix,Real tolerance);
        bool IsBalancedCompanion4 (Real a10, Real a21,Real a32, Real a03,
                                   Real a13, Real a23,Real a33, Real tolerance);
        bool QRIteration4 (VariableMatrix& matrix);
        
        // 支持 FindB.
		bool Bisection(const Polynomial& polynomial, Real xMin, Real xMax,int digits, Real& root);  	

		// 支持测试，如果所有根具有负实部。
		bool AllRealPartsNegative(int degree, RealVector& coeff);

		void Balance3(VariableMatrix& matrix, Real tolerance);
		bool IsBalanced3(VariableMatrix& matrix, Real tolerance);
		Real GetRowNorm(int row, VariableMatrix& matrix);
		Real GetColomnNorm(int colomn, VariableMatrix& matrix);
		void ScaleRow(int row, Real scale, VariableMatrix& matrix);
		void ScaleColomn(int colomn, Real scale, VariableMatrix& matrix);

    private:
		static constexpr auto sm_BalanceCompanionIterationMax = 16;
		static constexpr auto sm_BalanceIterationMax = 16;

        int m_Count;
        int m_MaxRoot;
        RealVector m_Root;
        Real m_Epsilon;
        
        // 对FindEigenvalues函数，默认是128.
        int m_MaxIterations;	
    };	

    using PolynomialRootsf = PolynomialRoots<float>;
    using PolynomialRootsd = PolynomialRoots<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
