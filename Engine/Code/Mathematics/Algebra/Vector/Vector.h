/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/27 15:29)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics::Algebra
{
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class Vector
    {
    public:
        using ClassType = Vector<N, Real>;

        using Container = std::array<Real, N>;
        using Math = Math<Real>;

    public:
        Vector() noexcept;

        /// Ԫ����������ȫ��ʼ����
        explicit Vector(const Container& container) noexcept;

        Vector(Real x, Real y) noexcept requires(N == 2);
        Vector(Real x, Real y, Real z) noexcept requires(N == 3);
        Vector(Real x, Real y, Real z, Real w) noexcept requires(N == 4);

        /// ����0 <= direction < N��Ԫ��direction��1����������Ԫ�ض���0��
        /// ���direction��Ч���򴴽���������
        /// ����ڴ�����׼ŷ����û�������һ�ַ��㣻
        /// ����μ�MakeUnit(int) and Unit(int).��
        explicit Vector(int direction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static constexpr int GetSize() noexcept
        {
            return N;
        }

        /// ��Ա���ʡ���һ�������[]���ص���const���ã�������Realֵ��
        /// ��֧��ͨ����Ҫָ�����ݵĳ���ָ��ı�׼�ļ���������д�롣
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// ���������ͼ�������ıȽϡ�
        NODISCARD bool operator==(const Vector& rhs) const noexcept;
        NODISCARD bool operator!=(const Vector& rhs) const noexcept;

        NODISCARD bool operator<(const Vector& rhs) const noexcept;
        NODISCARD bool operator<=(const Vector& rhs) const noexcept;
        NODISCARD bool operator>(const Vector& rhs) const noexcept;
        NODISCARD bool operator>=(const Vector& rhs) const noexcept;

        /// ����ʸ����

        /// ���������Ϊ0��
        void MakeZero();

        /// ���������Ϊ1��
        void MakeOnes();

        /// ����directionΪ1����������������Ϊ�㡣
        void MakeUnit(int direction);

        NODISCARD static Vector GetZero() noexcept;
        NODISCARD static Vector GetOnes();
        NODISCARD static Vector GetUnit(int direction);

        /// һԪ���㡣
        NODISCARD Vector operator+() noexcept;
        NODISCARD Vector operator-();

        /// ���Դ������㡣
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        Vector& operator*=(Real scalar);
        Vector& operator/=(Real scalar);

        /// ����������㡣
        Vector& operator*=(const Vector& rhs);
        Vector& operator/=(const Vector& rhs);

        NODISCARD Real GetMaxComponent() const;

    private:
        // �����ݽṹ������MSVC�����õ������[]����Χ���Ϳ��ӻ����ߡ�
        Container container;
    };

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator+(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator-(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(const Vector<N, Real>& lhs, Real scalar);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(Real scalar, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator/(const Vector<N, Real>& lhs, Real scalar);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator/(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    /// �������㡣����robust������Ϊ��false���ĺ���ʹ�ñ�׼�㷨���������й�һ����
    /// �����ǽ����ȼ���Ϊ����ƽ����ƽ��������������
    /// �������Ϊ�㣬��������������󣨻�NaN����
    /// ����robust������Ϊ��true��ʱ��
    /// ���㷨ּ�ڱ��⸡����������ڳ���Ϊ��ʱ����һ����������Ϊ�㡣
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Dot(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Length(const Vector<N, Real>& vector, bool robust = false);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    Real Normalize(Vector<N, Real>& vector, bool robust = false);

    /// Gram-Schmidt������һ�����������޹ص�������������ʸ����
    /// �������ع����м����δ�淶��ʸ������С���ȡ�
    /// �����ֵ����Ϊ�㣬�����������������صģ�����ֵ��������ڣ���
    /// ������ʱ�������ʼ��1 <= numElements <= N��v[0]��v[numElements-1]��
    /// �����ʱ������v[0]��v[numElements-1]�γ���������
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    Real Orthonormalize(int numInputs, std::vector<Vector<N, Real>>& vector, bool robust = false);

    /// ����������������������ĵ���������
    /// ��������Է�������������i����
    /// ����������U����u[i] = v[i+1], u[i+1] = -v[i]������������������Ϊ�㡣
    /// �������i+1����NΪģ����ġ�
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> GetOrthogonal(const Vector<N, Real>& vector, bool unitLength);

    /// ����ʸ���������߽�����������Ч���򷵻�ֵΪ��true��������������£�vectorMin��vectorMax������Чֵ��
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool ComputeExtremes(int numVectors, std::vector<Vector<N, Real>>& vector, Vector<N, Real>& vectorMin, Vector<N, Real>& vectorMax);

    /// ��nԪ��vector���������(n+1)-Ԫ��(v,last)��
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N + 1, Real> HomogeneousLift(const Vector<N, Real>& vector, Real last);

    /// �����nԪ��v = (u,v[n-1])ͶӰ��(n-1)-Ԫ��u��
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N - 1, Real> HomogeneousProject(const Vector<N, Real>& vector);

    /// ��nԪ��v = (w0,w1) ������(n+1)-Ԫ��u = (w0,u[inject],w1)��
    /// �����ƶϣ�w0�� (inject)-Ԫ��[��inject=0ʱ������]��
    /// w1��(n-inject)-Ԫ��[��inject=nʱ������]��
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N + 1, Real> Lift(const Vector<N, Real>& vector, int inject, Real value);

    /// ��nԪ��v = (w0,v[reject],w1) ͶӰ�� (n-1)-Ԫ��u = (w0,w1)��
    /// ͨ���ƶϣ�w0��(reject)-Ԫ��[��reject=0ʱ������]��
    /// w1��(n-1-reject)-Ԫ�飨��reject=n-1ʱ�����ڣ���
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N - 1, Real> Project(const Vector<N, Real>& vector, int reject);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H
