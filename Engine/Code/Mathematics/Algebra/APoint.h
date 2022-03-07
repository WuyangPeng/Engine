///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/03 22:35)

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
        using Vector3 = Vector3<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto aPointSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);
        using ArrayType = std::array<T, aPointSize>;

    public:
        // APoint��ʾ�������� (x,y,z,1)�� Ĭ�� (0,0,0,1)
        constexpr APoint() noexcept
            : APoint{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }
        {
        }

        constexpr APoint(T x, T y, T z) noexcept
            : homogeneousPoint{ x, y, z, Math::GetValue(1) }
        {
        }

        explicit APoint(const Vector3& rhs) noexcept;
        explicit APoint(const ArrayType& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD T GetX() const noexcept;
        void SetX(T x) noexcept;
        NODISCARD T GetY() const noexcept;
        void SetY(T y) noexcept;
        NODISCARD T GetZ() const noexcept;
        void SetZ(T y) noexcept;

        NODISCARD Vector3 GetVector3() const noexcept;
        NODISCARD HomogeneousPoint GetHomogeneousPoint() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ��������֧�ַ��������

        // һ����ӻ��һ�������Ľ����һ����
        APoint& operator+=(const AVector& rhs);
        APoint& operator-=(const AVector& rhs);

        APoint& operator+=(const APoint& rhs);
        APoint& operator-=(const APoint& rhs);
        APoint& operator*=(T scalar);
        APoint& operator/=(T scalar);
        NODISCARD APoint operator-() const noexcept;

        NODISCARD T GetNorm() const noexcept;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        NODISCARD static constexpr APoint GetOrigin() noexcept
        {
            return APoint{};
        }

    private:
        HomogeneousPoint homogeneousPoint;
    };

    // ���������Ϊһ������
    template <typename T>
    NODISCARD AVector<T> operator-(const APoint<T>& lhs, const APoint<T>& rhs) noexcept;

    // һ�������ӻ��Сһ�������Ľ����һ����
    template <typename T>
    NODISCARD APoint<T> operator+(const APoint<T>& lhs, const AVector<T>& rhs);
    template <typename T>
    NODISCARD APoint<T> operator-(const APoint<T>& lhs, const AVector<T>& rhs);

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
    NODISCARD APoint<T> operator+(const APoint<T>& lhs, const APoint<T>& rhs);

    template <typename T>
    NODISCARD APoint<T> operator*(const APoint<T>& lhs, T scalar);

    template <typename T>
    NODISCARD APoint<T> operator/(const APoint<T>& lhs, T scalar);

    template <typename T>
    NODISCARD APoint<T> operator*(T scalar, const APoint<T>& rhs);

    // �ڷ�������ǲ��������һ�����һ���������ڻ��� Ȼ����������ƽ��ʱ������һ������Ķ��塣
    // ������ԣ�ƽ����Dot(N,X-P) = 0������N��һ��������P��ƽ����һ���ض��ĵ㣬��X����ƽ���ϵ�����㡣
    // ��X - P��һ����������ôDot(N,X - P)���ܺõض��塣���ƽ�汻��дΪDot(N,X) = Dot(N,P)�����ڷ���������ǲ�֧�ֵģ�
    // �������磬������ʱ��Ҫ����Dot(N,P)���������У�APoint��w���������ԣ�����ζ��APoint����Ϊ������
    template <typename T>
    NODISCARD T Dot(const APoint<T>& lhs, const AVector<T>& rhs) noexcept;

    template <typename T>
    NODISCARD bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const APoint<T>& point);

    using APointF = APoint<float>;
    using APointD = APoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_POINT_H
