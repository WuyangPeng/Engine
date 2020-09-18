//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/25 17:11)

#ifndef MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
#define MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <vector>
#include <type_traits>

// 当齐次点存储的值为浮点数时，比较两点相等，
// 请使用函数Approximate，而不是==。

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HomogeneousPoint : private boost::totally_ordered<HomogeneousPoint<T>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

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

        static constexpr auto sm_PointSize = System::EnumCastUnderlying(PointIndex::Size);
        using ArrayType = std::array<T, sm_PointSize>;

    public:
        // HomogeneousPoint表示一个从 (x,y,z,w)的齐次坐标点。
        // 仿射点的特征是w = 1（见类APoint）和仿射向量的特征是w = 0（见类AVector）。
        constexpr HomogeneousPoint() noexcept
            : m_X{}, m_Y{}, m_Z{}, m_W{}
        {
        }

        constexpr HomogeneousPoint(T x, T y, T z, T w) noexcept
            : m_X{ x }, m_Y{ y }, m_Z{ z }, m_W{ w }
        {
        }

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        const ArrayType GetCoordinate() const noexcept;
        const T& operator[](int index) const;
        T& operator[](int index);
        T GetX() const noexcept;
        void SetX(T x) noexcept;
        T GetY() const noexcept;
        void SetY(T y) noexcept;
        T GetZ() const noexcept;
        void SetZ(T y) noexcept;
        T GetW() const noexcept;
        void SetW(T y) noexcept;

        void Set(const ArrayType& coordinate) noexcept;

        static constexpr int GetPointByte() noexcept
        {
            return GetPointSize() * sizeof(T);
        }

        static constexpr int GetPointSize() noexcept
        {
            return sm_PointSize;
        }

    private:
        T m_X{};
        T m_Y{};
        T m_Z{};
        T m_W{};
    };

    // 比较（仅供STL容器使用）
    template <typename T>
    bool operator==(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs);

    template <typename T>
    bool operator<(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs) noexcept;

    template <typename T>
    bool Approximate(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    using FloatHomogeneousPoint = HomogeneousPoint<float>;
    using DoubleHomogeneousPoint = HomogeneousPoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
