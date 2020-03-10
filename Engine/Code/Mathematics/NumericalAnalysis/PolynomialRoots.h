// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 16:19)

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
    // ��������
    //
    // Algebraic������ʹ�÷����ʽ�����٣�ͨ������׳��
    // Bisection�����ַ������߽�󣬻�������׳��
    // Newton��ţ��/�ȷֻ�ϣ����߽���ж���׳��
    // Eigenvalues��ͬ����������ֵ�����ٽ�׳��

    // �����ޣ�
    //
    // ����һ����һ����ʽ
    // x^n + a[n-1]*x^{n-1} + ... + a[1]*x + a[0]
    // �Ŀ���Լ��ΪM = 1 + max{|a[0]|,...,|a[n-1]|}��
    // ����ʵ��������λ������[-M,M]��
    // ���ڷ���һ����ʽ��
    // b[n]*x^n + b[n-1]*x^{n-1} + ... + b[1]*x + b[0]��
    // ��b[n]Ϊ��Ϊ�㣬ͨ�������������������Լ����
    // 1 + max{|b[0]/b[n]|,...,|b[n-1]/b[n]|}�� 

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
        
        // һ�η���:  once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once);
        Real GetBound (Real constant, Real once);

        // ���η���:  secondary * x^2 + once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once, Real secondary);
        Real GetBound (Real constant, Real once, Real secondary);

        // ���η���: thrice * x^3 + secondary * x^2+ once * x + constant = 0
        bool FindAlgebraic (Real constant, Real once,Real secondary, Real thrice);
        bool FindEigenvalues (Real constant, Real once,Real secondary, Real thrice,
                              bool doBalancing,Real tolerance = static_cast<Real>(0.001),bool isUseCompanion = true);
        Real GetBound (Real constant, Real once, Real secondary, Real thrice);

		// �� thrice * r^3 + once * r = constant ������thrice > 0��once > 0�����������Զ��ֻ��һ��ʵ������
		Real SpecialCubic(Real thrice, Real once, Real constant);

        // �Ĵη���: quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0
		bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
		bool FindEigenvalues(Real constant, Real once, Real secondary,Real thrice, Real quartic,  bool doBalancing, Real tolerance = static_cast<Real>(0.001));
		Real GetBound(Real constant, Real once, Real secondary,Real thrice, Real quartic);

        // һ�㷽��: sum_{i=0}^{degree} c(i) * x^i = 0
        bool FindBisection (const Polynomial& polynomial,int digits);        
        Real GetBound (const Polynomial& polynomial);
		// TODO : bool FindNewton(const Polynomial& polynomial, int digits);
		// TODO : bool FindEigenvalues(const Polynomial& polynomial, bool doBalancing);

		// ����Ҫ��ָ���ļ����
		bool FindBisection(const Polynomial& polynomial, Real xMin, Real xMax,int digits);

		// TODO : bool FindNewton(const Polynomial& polynomial, Real xMin, Real xMax,int digits);

		bool AllRealPartsNegative(const Polynomial& polyomial);
		bool AllRealPartsPositive(const Polynomial& polyomial);

  		// ����[begin,end]�и�����Ŀ��
		// ����Sturm������������������ͨ���� -Math<Real>::sm_MaxReal�� end = Math<Real>::sm_MaxReal��
		// m_Epsilon��ֵ���������յ��ϵ�Sturm����ʽ��ֵ����ֵ��
		// �����С�����ֵ������Ϊ�㡣����ֵ�Ǹ�������������������򷵻�-1��
		int GetRootCount(const Polynomial& polynomial, Real begin, Real end);

    private: 
		void BalanceCompanion3(VariableMatrix& matrix, Real tolerance);
        
        bool IsBalancedCompanion3 (Real a10, Real a21,Real a02, Real a12,Real a22, Real tolerance);
        
		bool QRIteration3(VariableMatrix& matrix);

		void FrancisQRStep(VariableMatrix& hessenbergMatrix,VariableLengthVector& vector);

		// ֧��FindE.
		const Vector3D GetHouseholderVector(int size, const Vector3D& uVector);                                

        void PremultiplyHouseholder (VariableMatrix& mat,VariableLengthVector& variableLengthVector,int rowMin, int rowMax,
									 int colunmMin, int colunmMax,int vSize,const Vector3D& vVector);

        void PostmultiplyHouseholder (VariableMatrix& mat,VariableLengthVector& variableLengthVector,int rowMin, int rowMax,
									  int colunmMin, int colunmMax,int vSize,const Vector3D& vVector);

		void BalanceCompanion4 (VariableMatrix& matrix,Real tolerance);
        bool IsBalancedCompanion4 (Real a10, Real a21,Real a32, Real a03,
                                   Real a13, Real a23,Real a33, Real tolerance);
        bool QRIteration4 (VariableMatrix& matrix);
        
        // ֧�� FindB.
		bool Bisection(const Polynomial& polynomial, Real xMin, Real xMax,int digits, Real& root);  	

		// ֧�ֲ��ԣ�������и����и�ʵ����
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
        
        // ��FindEigenvalues������Ĭ����128.
        int m_MaxIterations;	
    };	

    using PolynomialRootsf = PolynomialRoots<float>;
    using PolynomialRootsd = PolynomialRoots<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
