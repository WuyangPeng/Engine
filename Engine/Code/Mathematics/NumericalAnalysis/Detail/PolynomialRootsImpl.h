///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 11:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector3D.h"

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
    class MATHEMATICS_HIDDEN_DECLARE PolynomialRootsImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialRootsImpl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Polynomial = Polynomial<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

        using Container = std::vector<Real>;
        using ContainerConstIter = typename Container::const_iterator;

    public:
        explicit PolynomialRootsImpl(Real epsilon);

        CLASS_INVARIANT_DECLARE;

        void SetMaxIterations(int maxIterations) noexcept;

        [[nodiscard]] int GetCount() const noexcept;
        [[nodiscard]] Real GetRoot(int index) const;
        [[nodiscard]] const ContainerConstIter GetBegin() const noexcept;
        [[nodiscard]] const ContainerConstIter GetEnd() const noexcept;

        // һ�η���:  once * x + constant = 0
        [[nodiscard]] bool FindAlgebraic(Real constant, Real once);
        [[nodiscard]] Real GetBound(Real constant, Real once);

        // ���η���:  secondary * x^2 + once * x + constant = 0
        [[nodiscard]] bool FindAlgebraic(Real constant, Real once, Real secondary);
        [[nodiscard]] Real GetBound(Real constant, Real once, Real secondary);

        // ���η���: thrice * x^3 + secondary * x^2+ once * x + constant = 0
        [[nodiscard]] bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice);
        [[nodiscard]] bool FindEigenvalues(Real constant, Real once, Real secondary, Real thrice,
                                           bool doBalancing, Real tolerance = static_cast<Real>(0.001), bool isUseCompanion = true);
        [[nodiscard]] Real GetBound(Real constant, Real once, Real secondary, Real thrice);

        // �� thrice * r^3 + once * r = constant ������thrice > 0��once > 0�����������Զ��ֻ��һ��ʵ������
        [[nodiscard]] Real SpecialCubic(Real thrice, Real once, Real constant) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // �Ĵη���: quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0
        [[nodiscard]] bool FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
        [[nodiscard]] bool FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, Real quartic, bool doBalancing, Real tolerance = static_cast<Real>(0.001));
        [[nodiscard]] Real GetBound(Real constant, Real once, Real secondary, Real thrice, Real quartic);

        // һ�㷽��: sum_{i=0}^{degree} c(i) * x^i = 0
        [[nodiscard]] bool FindBisection(const Polynomial& polynomial, int digits);
        [[nodiscard]] Real GetBound(const Polynomial& polynomial);

        // ����Ҫ��ָ���ļ����
        [[nodiscard]] bool FindBisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits);

        [[nodiscard]] bool AllRealPartsNegative(const Polynomial& polynomial);
        [[nodiscard]] bool AllRealPartsPositive(const Polynomial& polynomial);

        // ����[begin,end]�и�����Ŀ��
        // ����Sturm������������������ͨ���� -Math<Real>::sm_MaxReal�� end = Math<Real>::sm_MaxReal��
        // m_Epsilon��ֵ���������յ��ϵ�Sturm����ʽ��ֵ����ֵ��
        // �����С�����ֵ������Ϊ�㡣����ֵ�Ǹ�������������������򷵻�-1��
        [[nodiscard]] int GetRootCount(const Polynomial& polynomial, Real begin, Real end);

    private:
        void BalanceCompanion3(VariableMatrix& matrix, Real tolerance);

        [[nodiscard]] bool IsBalancedCompanion3(Real a10, Real a21, Real a02, Real a12, Real a22, Real tolerance) noexcept;

        [[nodiscard]] bool QRIteration3(VariableMatrix& matrix);

        void FrancisQRStep(VariableMatrix& hessenbergMatrix, VariableLengthVector& vector);

        // ֧��FindE.
        [[nodiscard]] const Vector3D GetHouseholderVector(int size, const Vector3D& uVector);

        void PremultiplyHouseholder(VariableMatrix& mat, VariableLengthVector& variableLengthVector, int rowMin, int rowMax,
                                    int colunmMin, int colunmMax, int vSize, const Vector3D& vVector);

        void PostmultiplyHouseholder(VariableMatrix& mat, VariableLengthVector& variableLengthVector, int rowMin, int rowMax,
                                     int colunmMin, int colunmMax, int vSize, const Vector3D& vVector);

        void BalanceCompanion4(VariableMatrix& matrix, Real tolerance);
        [[nodiscard]] bool IsBalancedCompanion4(Real a10, Real a21, Real a32, Real a03,
                                                Real a13, Real a23, Real a33, Real tolerance) noexcept;
        [[nodiscard]] bool QRIteration4(VariableMatrix& matrix);

        // ֧�� FindB.
        [[nodiscard]] bool Bisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits, Real& root);

        // ֧�ֲ��ԣ�������и����и�ʵ����
        [[nodiscard]] bool AllRealPartsNegative(int degree, Container& coeff);

        void Balance3(VariableMatrix& matrix, Real tolerance);
        [[nodiscard]] bool IsBalanced3(VariableMatrix& matrix, Real tolerance);
        [[nodiscard]] Real GetRowNorm(int row, VariableMatrix& matrix);
        [[nodiscard]] Real GetColomnNorm(int colomn, VariableMatrix& matrix);
        void ScaleRow(int row, Real scale, VariableMatrix& matrix);
        void ScaleColomn(int colomn, Real scale, VariableMatrix& matrix);

        void SetRoot(int index, Real value);

    private:
        static constexpr auto sm_BalanceCompanionIterationMax = 16;
        static constexpr auto sm_BalanceIterationMax = 16;

        int m_Count;
        int m_MaxRoot;
        Container m_Root;
        Real m_Epsilon;

        // ��FindEigenvalues������Ĭ����128.
        int m_MaxIterations;
    }; 
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_H
