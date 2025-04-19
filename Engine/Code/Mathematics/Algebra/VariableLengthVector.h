/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/05 09:20)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableLengthVector final : private boost::additive<VariableLengthVector<Real>, boost::multiplicative<VariableLengthVector<Real>, Real, boost::totally_ordered<VariableLengthVector<Real>>>>
    {
    public:
        using ClassType = VariableLengthVector;

        using MathType = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        /// Ԫ��ĳ���Ϊ�㡣
        VariableLengthVector() noexcept;

        /// Ԫ��ĳ���Ϊ��size����
        explicit VariableLengthVector(int size);

        explicit VariableLengthVector(const ContainerType& container);
        explicit VariableLengthVector(ContainerType&& container) noexcept;

        /// ����0<=d<=size��Ԫ��dΪ1����������Ԫ�ؾ�Ϊ�㡣���d��Ч���򴴽�������������ڴ�����׼ŷ����û�������һ�ַ��㣻����μ�MakeUnit��int32_t��int32_t����Unit��int32_t��int32\ut����
        VariableLengthVector(int size, int dimension);

        CLASS_INVARIANT_DECLARE;

        /// ��Ա���ʡ�SetSize(int)δ��ʼ��Ԫ�顣
        /// ��һ�������[]���ص���const���ã�������Realֵ��
        /// ��֧��ͨ����Ҫָ�����ݵĳ���ָ��ı�׼�ļ���������д�롣

        NODISCARD int GetSize() const;

        void SetSize(int size);

        /// �������
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// һԪ���㡣
        NODISCARD VariableLengthVector operator+() const;
        NODISCARD VariableLengthVector operator-() const;

        VariableLengthVector& operator+=(const VariableLengthVector& rhs);
        VariableLengthVector& operator-=(const VariableLengthVector& rhs);
        VariableLengthVector& operator*=(Real scalar) noexcept;
        VariableLengthVector& operator/=(Real scalar) noexcept(gMathematicsAssert < 0);

        /// �������㡣
        /// ��'robust'����Ϊ'false'�ĺ���ʹ�ñ�׼�㷨���������й�һ����
        /// �����ǽ����ȼ���Ϊ����ƽ����ƽ��������������
        /// �������Ϊ�㣬��������������󣨻�NaN����
        /// ��'robust'����Ϊ'true'ʱ�����㷨ּ�ڱ��⸡�������
        /// ���ڳ���Ϊ��ʱ����һ����������Ϊ�㡣
        NODISCARD Real Length(bool robust = false) const;
        NODISCARD Real SquaredLength(bool robust = false) const;
        Real Normalize(Real epsilon = MathType::GetZeroTolerance(), bool robust = false);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(const ContainerType& aContainer);

        NODISCARD ContainerTypeConstIter begin() const noexcept;
        NODISCARD ContainerTypeConstIter end() const noexcept;

        NODISCARD ContainerTypeIter begin() noexcept;
        NODISCARD ContainerTypeIter end() noexcept;

        NODISCARD bool Equal(const VariableLengthVector& rhs) const;
        NODISCARD bool Less(const VariableLengthVector& rhs) const;

        /// ����ʸ����

        /// ���������Ϊ0��
        void MakeZero();

        /// ����dimensionΪ1����������������Ϊ�㡣
        void MakeUnit(int dimension);

        NODISCARD static VariableLengthVector Zero(int size);
        NODISCARD static VariableLengthVector Unit(int size, int dimension);

    private:
        /// �����ݽṹ������MSVC�����õ������[]����Χ���Ϳ��ӻ����ߡ�
        ContainerType container;
    };

    // �Ƚϣ���STL����ʹ�ã���
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD Real Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const VariableLengthVector<Real>& lhs,
                               const VariableLengthVector<Real>& rhs,
                               Real epsilon = Math<Real>::GetZeroTolerance());

    /// Gram-Schmidt������һ�����������޹ص�������������ʸ����
    /// �������ع����м����δ�淶��ʸ������С���ȡ�
    /// �����ֵ����Ϊ�㣬�����������������صģ�����ֵ��������ڣ���
    /// ������ʱ�������ʼ��1<=numElements<=N��vector[0]��vector[numElements-1]��
    /// �����ʱ������vector[0]��vector[numElements-1]�γ���������
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    Real Orthonormalize(int numInputs, std::vector<VariableLengthVector<Real>>& vector, bool robust = false);

    /// ����ʸ���������߽��
    /// ���������Ч�����׳��쳣��
    /// ��û���׳��쳣������£�vectorMin��vectorMax������Чֵ��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    void ComputeExtremes(int numVectors, const std::vector<VariableLengthVector<Real>>& vector, VariableLengthVector<Real>& vectorMin, VariableLengthVector<Real>& vectorMax);

    /// ��nԪ��v���������(n+1)-Ԫ��(v,last)��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> HomogeneousLift(const VariableLengthVector<Real>& vector, Real last);

    /// �����nԪ��v = (u,v[n-1])ͶӰ��(n-1)-Ԫ��u��
    template <typename Real>
    NODISCARD VariableLengthVector<Real> HomogeneousProject(const VariableLengthVector<Real>& vector);

    /// ��nԪ��v = (w0,w1)������(n+1)-Ԫ��u = (w0,u[inject],w1)��
    /// �����ƶϣ�w0��(inject)-Ԫ��[��inject=0ʱ������]��
    /// w1��-Ԫ��[inject=nʱ������]��
    template <typename Real>
    NODISCARD VariableLengthVector<Real> Lift(const VariableLengthVector<Real>& vector, int inject, Real value);

    /// ��nԪ�� v = (w0,v[reject],w1)ͶӰ��(n-1)-Ԫ��u = (w0,w1)��
    /// ͨ���ƶϣ�w0��(reject)-Ԫ��[��reject=0ʱ������]��
    /// w1��(n-1-reject)-Ԫ��[��reject=n-1ʱ������]��
    template <typename Real>
    NODISCARD VariableLengthVector<Real> Project(const VariableLengthVector<Real>& vector, int reject);

    // ���������
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector);

    using VariableLengthVectorF = VariableLengthVector<float>;
    using VariableLengthVectorD = VariableLengthVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
