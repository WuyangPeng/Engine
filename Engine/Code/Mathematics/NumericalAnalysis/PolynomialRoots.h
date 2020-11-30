///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 11:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H

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
    class PolynomialRootsImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialRoots final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using PolynomialRootsImpl = PolynomialRootsImpl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialRoots, DESTRUCTOR_DEFAULT);

        using Vector3D = Vector3D<Real>;
        using Polynomial = Polynomial<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

        using Container = std::vector<Real>;
        using ContainerConstIter = typename Container::const_iterator;

    public:
        explicit PolynomialRoots(Real epsilon);

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
        IMPL_TYPE_DECLARE(PolynomialRoots);
    };

    using FloatPolynomialRoots = PolynomialRoots<float>;
    using DoublePolynomialRoots = PolynomialRoots<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_H
