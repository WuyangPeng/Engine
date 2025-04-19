///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:39)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_H
#define MATHEMATICS_ALGEBRA_A_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "HomogeneousPoint.h"
#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint final
    {
    public:
        using ClassType = APoint<T>;

        using MathType = Math<T>;
        using AVectorType = AVector<T>;
        using Vector3Type = Vector3<T>;
        using HomogeneousPointType = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto pointSize = System::EnumCastUnderlying(HomogeneousPointType::PointIndex::W);
        using ArrayType = std::array<T, pointSize>;

    public:
        // APoint��ʾ�������� (x,y,z,1)�� Ĭ�� (0,0,0,1)
        constexpr APoint() noexcept
            : APoint{ MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) }
        {
        }

        constexpr APoint(T x, T y, T z) noexcept
            : homogeneousPoint{ x, y, z, MathType::GetValue(1) }
        {
        }

        explicit APoint(const Vector3Type& rhs) noexcept;
        explicit APoint(const ArrayType& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD T GetX() const noexcept;
        void SetX(T x) noexcept;
        NODISCARD T GetY() const noexcept;
        void SetY(T y) noexcept;
        NODISCARD T GetZ() const noexcept;
        void SetZ(T z) noexcept;

        NODISCARD Vector3Type GetVector3() const noexcept;
        NODISCARD HomogeneousPointType GetHomogeneousPoint() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ��������֧�ַ��������

        // һ����ӻ��һ�������Ľ����һ����
        APoint& operator+=(const AVectorType& rhs);
        APoint& operator-=(const AVectorType& rhs);

        APoint& operator+=(const APoint& rhs);
        APoint& operator-=(const APoint& rhs);
        APoint& operator*=(T scalar);
        APoint& operator/=(T scalar);
        NODISCARD APoint operator-() const noexcept;

        NODISCARD T GetNorm() const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD static constexpr APoint GetOrigin() noexcept
        {
            return APoint{};
        }

        NODISCARD static constexpr APoint GetUnit() noexcept
        {
            return APoint{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) };
        }

    private:
        HomogeneousPointType homogeneousPoint;
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
    NODISCARD bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const APoint<T>& point);

    using APointF = APoint<float>;
    using APointD = APoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_POINT_H
