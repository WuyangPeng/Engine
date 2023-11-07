///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:43)

#ifndef MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
#define MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <vector>

// ����ε�洢��ֵΪ������ʱ���Ƚ�������ȣ�
// ��ʹ�ú���Approximate��������==��

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HomogeneousPoint final : private boost::totally_ordered<HomogeneousPoint<T>>
    {
    public:
        using ClassType = HomogeneousPoint<T>;

        using ContainerType = std::vector<ClassType>;

    public:
        enum class PointIndex
        {
            X = 0,
            Y,
            Z,
            W,
            Size
        };

        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto zIndex = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto wIndex = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto pointSize = System::EnumCastUnderlying(PointIndex::Size);
        using ArrayType = std::array<T, pointSize>;

    public:
        // HomogeneousPoint��ʾһ���� (x,y,z,w)���������㡣
        // ������������w = 1������APoint���ͷ���������������w = 0������AVector����
        constexpr HomogeneousPoint() noexcept
            : x{}, y{}, z{}, w{}
        {
        }

        constexpr HomogeneousPoint(T x, T y, T z, T w) noexcept
            : x{ x }, y{ y }, z{ z }, w{ w }
        {
        }

        CLASS_INVARIANT_DECLARE;

        // �������
        NODISCARD ArrayType GetCoordinate() const noexcept;
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);
        NODISCARD T GetX() const noexcept;
        void SetX(T aX) noexcept;
        NODISCARD T GetY() const noexcept;
        void SetY(T aY) noexcept;
        NODISCARD T GetZ() const noexcept;
        void SetZ(T aZ) noexcept;
        NODISCARD T GetW() const noexcept;
        void SetW(T aW) noexcept;

        void Set(const ArrayType& coordinate);

        NODISCARD static constexpr int GetPointByte() noexcept
        {
            return GetPointSize() * sizeof(T);
        }

        NODISCARD static constexpr int GetPointSize() noexcept
        {
            return pointSize;
        }

    private:
        T x{};
        T y{};
        T z{};
        T w{};
    };

    // �Ƚϣ�����STL����ʹ�ã�
    template <typename T>
    NODISCARD bool operator==(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs);

    template <typename T>
    NODISCARD bool operator<(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs) noexcept;

    template <typename T>
    NODISCARD bool Approximate(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    using HomogeneousPointF = HomogeneousPoint<float>;
    using HomogeneousPointD = HomogeneousPoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
