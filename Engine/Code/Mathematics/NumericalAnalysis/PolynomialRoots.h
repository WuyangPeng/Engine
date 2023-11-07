///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 13:24)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector3.h"

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
    class PolynomialRoots final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialRoots<Real>;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Polynomial = Polynomial<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using Container = std::vector<Real>;
        using ContainerConstIter = typename Container::const_iterator;

    public:
        explicit PolynomialRoots(Real epsilon);

        CLASS_INVARIANT_DECLARE;

        void SetMaxIterations(int newMaxIterations) noexcept;

        NODISCARD int GetCount() const noexcept;
        NODISCARD Real GetRoot(int index) const;
        NODISCARD ContainerConstIter GetBegin() const noexcept;
        NODISCARD ContainerConstIter GetEnd() const;

        // һ�η���:  once * x + constant = 0
        NODISCARD bool FindAlgebraic(Real constant, Real once);
        NODISCARD Real GetBound(Real constant, Real once);

        // ���η���:  secondary * x^2 + once * x + constant = 0
        NODISCARD bool FindAlgebraic(Real constant, Real once, Real secondary);
        NODISCARD Real GetBound(Real constant, Real once, Real secondary);

        // ���η���: thrice * x^3 + secondary * x^2+ once * x + constant = 0
        NODISCARD bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice);
        NODISCARD bool FindEigenvalues(Real constant,
                                       Real once,
                                       Real secondary,
                                       Real thrice,
                                       bool doBalancing,
                                       Real tolerance = static_cast<Real>(0.001),
                                       bool isUseCompanion = true);
        NODISCARD Real GetBound(Real constant, Real once, Real secondary, Real thrice);

        // �� thrice * r^3 + once * r = constant ������thrice > 0��once > 0�����������Զ��ֻ��һ��ʵ������
        NODISCARD Real SpecialCubic(Real thrice, Real once, Real constant) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // �Ĵη���: quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0
        NODISCARD bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
        NODISCARD bool FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, Real quartic, bool doBalancing, Real tolerance = static_cast<Real>(0.001));
        NODISCARD Real GetBound(Real constant, Real once, Real secondary, Real thrice, Real quartic);

        // һ�㷽��: sum_{i=0}^{degree} c(i) * x^i = 0
        NODISCARD bool FindBisection(const Polynomial& polynomial, int digits);
        NODISCARD Real GetBound(const Polynomial& polynomial);

        // ����Ҫ��ָ���ļ����
        NODISCARD bool FindBisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits);

        NODISCARD bool AllRealPartsNegative(const Polynomial& polynomial);
        NODISCARD bool AllRealPartsPositive(const Polynomial& polynomial);

        // ����[begin,end]�и�����Ŀ��
        // ����Sturm������������������ͨ���� -Math<Real>::sm_MaxReal�� end = Math<Real>::sm_MaxReal��
        // m_Epsilon��ֵ���������յ��ϵ�Sturm����ʽ��ֵ����ֵ��
        // �����С�����ֵ������Ϊ�㡣����ֵ�Ǹ�������������������򷵻�-1��
        NODISCARD int GetRootCount(const Polynomial& polynomial, Real begin, Real end);

    private:
        void BalanceCompanion3(VariableMatrix& matrix, Real tolerance);

        NODISCARD bool IsBalancedCompanion3(Real a10, Real a21, Real a02, Real a12, Real a22, Real tolerance) noexcept;

        NODISCARD bool QRIteration3(VariableMatrix& matrix);

        void FrancisQRStep(VariableMatrix& hessenbergMatrix, VariableLengthVector& vector);

        // ֧��FindE.
        NODISCARD Vector3 GetHouseholderVector(int size, const Vector3& uVector);

        void PremultiplyHouseholder(VariableMatrix& mat,
                                    VariableLengthVector& variableLengthVector,
                                    int rowMin,
                                    int rowMax,
                                    int columnMin,
                                    int columnMax,
                                    int vSize,
                                    const Vector3& vVector);

        void PostmultiplyHouseholder(VariableMatrix& mat,
                                     VariableLengthVector& variableLengthVector,
                                     int rowMin,
                                     int rowMax,
                                     int columnMin,
                                     int columnMax,
                                     int vSize,
                                     const Vector3& vVector);

        void BalanceCompanion4(VariableMatrix& matrix, Real tolerance);
        NODISCARD bool IsBalancedCompanion4(Real a10,
                                            Real a21,
                                            Real a32,
                                            Real a03,
                                            Real a13,
                                            Real a23,
                                            Real a33,
                                            Real tolerance) noexcept;
        NODISCARD bool QRIteration4(VariableMatrix& matrix);

        // ֧�� FindB.
        NODISCARD bool Bisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits, Real& root) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ֧�ֲ��ԣ�������и����и�ʵ����
        NODISCARD bool AllRealPartsNegative(int degree, Container& coeff);

        void Balance3(VariableMatrix& matrix, Real tolerance);
        NODISCARD bool IsBalanced3(VariableMatrix& matrix, Real tolerance);
        NODISCARD Real GetRowNorm(int row, VariableMatrix& matrix);
        NODISCARD Real GetColumnNorm(int column, VariableMatrix& matrix);
        void ScaleRow(int row, Real scale, VariableMatrix& matrix);
        void ScaleColumn(int column, Real scale, VariableMatrix& matrix);

        void SetRoot(int index, Real value);

    private:
        static constexpr auto balanceCompanionIterationMax = 16;
        static constexpr auto balanceIterationMax = 16;

        int count;
        int maxRoot;
        Container root;
        Real epsilon;

        // ��FindEigenvalues������Ĭ����128.
        int maxIterations;
    };

    using PolynomialRootsF = PolynomialRoots<float>;
    using PolynomialRootsD = PolynomialRoots<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
