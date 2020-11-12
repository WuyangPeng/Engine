///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/02 13:00)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_H
#define MATHEMATICS_ALGEBRA_A_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "HomogeneousPoint.h"
#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = APoint<T>;
        using Math = Math<T>;
        using AVector = AVector<T>;
        using Vector3D = Vector3D<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto sm_APointSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);
        using ArrayType = std::array<T, sm_APointSize>;

    public:
        // APoint��ʾ�������� (x,y,z,1)�� Ĭ�� (0,0,0,1)
        constexpr APoint() noexcept
            : APoint{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }
        {
        }

        constexpr APoint(T x, T y, T z) noexcept
            : m_HomogeneousPoint{ x, y, z, Math::GetValue(1) }
        {
        }

        explicit APoint(const Vector3D& rhs) noexcept;
        explicit APoint(const ArrayType& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] T GetX() const noexcept;
        void SetX(T x) noexcept;
        [[nodiscard]] T GetY() const noexcept;
        void SetY(T y) noexcept;
        [[nodiscard]] T GetZ() const noexcept;
        void SetZ(T y) noexcept;

        [[nodiscard]] const Vector3D GetVector3D() const noexcept;
        [[nodiscard]] const HomogeneousPoint GetHomogeneousPoint() const noexcept;

        [[nodiscard]] const T& operator[](int index) const;
        [[nodiscard]] T& operator[](int index);

        // ��������֧�ַ��������

        // һ����ӻ��һ�������Ľ����һ����
        APoint& operator+=(const AVector& rhs);
        APoint& operator-=(const AVector& rhs);

        APoint& operator+=(const APoint& rhs);
        APoint& operator-=(const APoint& rhs);
        APoint& operator*=(T scalar);
        APoint& operator/=(T scalar);
        [[nodiscard]] const APoint operator-() const noexcept;

        [[nodiscard]] T GetNorm() const noexcept;

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        [[nodiscard]] static constexpr APoint GetOrigin() noexcept
        {
            return APoint{};
        }

    private:
        HomogeneousPoint m_HomogeneousPoint;
    };

    // ���������Ϊһ������
    template <typename T>
    [[nodiscard]] const AVector<T> operator-(const APoint<T>& lhs, const APoint<T>& rhs) noexcept;

    // һ�������ӻ��Сһ�������Ľ����һ����
    template <typename T>
    [[nodiscard]] const APoint<T> operator+(const APoint<T>& lhs, const AVector<T>& rhs);
    template <typename T>
    [[nodiscard]] const APoint<T> operator-(const APoint<T>& lhs, const AVector<T>& rhs);

    // �ڷ���������㲻������Ӽ���Ȼ��������ͺͷ����������ġ���������ȷ�����ڼ�����һ����

    // һ�������������
    // r = s1 * p1 + s2 * p2 + ... + sn * pn
    // ����p1��pn���������ĵ㣨wֵ��1���� s1��sn�Ǳ�������s1 + s2 + ... + sn = 1������r���������㡣

    // һ�������������
    // r = d1 * p1 + d2 * p2 + ... + dn * pn
    // ����p1��pn���������ĵ㣨wֵ��1���� d1��dn�Ǳ�������d1 + d2 + ... + dn = 0������r���������㡣

    // ע�⣺�������㷨��������APoint���󣬵��������Ҫ����һ��AVector����
    // ����Ĵ�����ʾ�����ʵ����һ�㣺
    // APoint p1, p2, p3;  // ��ʼ��Ϊ�κ�ֵ
    // APoint difference = 1.5f * p1 + (-0.2f) * p2 + (-0.3f) * p3;
    // AVector r { difference.GetHomogeneousPoint() };
    // r������x��y��z����������w��������Ϊ�㡣
    template <typename T>
    [[nodiscard]] const APoint<T> operator+(const APoint<T>& lhs, const APoint<T>& rhs);

    template <typename T>
    [[nodiscard]] const APoint<T> operator*(const APoint<T>& lhs, T scalar);

    template <typename T>
    [[nodiscard]] const APoint<T> operator/(const APoint<T>& lhs, T scalar);

    template <typename T>
    [[nodiscard]] const APoint<T> operator*(T scalar, const APoint<T>& rhs);

    // �ڷ�������ǲ��������һ�����һ���������ڻ��� Ȼ����������ƽ��ʱ������һ������Ķ��塣
    // ������ԣ�ƽ����Dot(N,X-P) = 0������N��һ��������P��ƽ����һ���ض��ĵ㣬��X����ƽ���ϵ�����㡣
    // ��X - P��һ����������ôDot(N,X - P)���ܺõض��塣���ƽ�汻��дΪDot(N,X) = Dot(N,P)�����ڷ���������ǲ�֧�ֵģ�
    // �������磬������ʱ��Ҫ����Dot(N,P)���������У�APoint��w���������ԣ�����ζ��APoint����Ϊ������
    template <typename T>
    [[nodiscard]] T Dot(const APoint<T>& lhs, const AVector<T>& rhs) noexcept;

    template <typename T>
    [[nodiscard]] bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const APoint<T>& point);

    using FloatAPoint = APoint<float>;
    using DoubleAPoint = APoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_POINT_H
