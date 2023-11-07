///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:43)

#ifndef MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
#define MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <vector>

// 当齐次点存储的值为浮点数时，比较两点相等，
// 请使用函数Approximate，而不是==。

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
        // HomogeneousPoint表示一个从 (x,y,z,w)的齐次坐标点。
        // 仿射点的特征是w = 1（见类APoint）和仿射向量的特征是w = 0（见类AVector）。
        constexpr HomogeneousPoint() noexcept
            : x{}, y{}, z{}, w{}
        {
        }

        constexpr HomogeneousPoint(T x, T y, T z, T w) noexcept
            : x{ x }, y{ y }, z{ z }, w{ w }
        {
        }

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
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

    // 比较（仅供STL容器使用）
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
