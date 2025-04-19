/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 11:16)

#ifndef MATHEMATICS_OBJECTS_2D_TRIANGLE2_H
#define MATHEMATICS_OBJECTS_2D_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Triangle2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle2<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using ContainerType = std::vector<Vector2Type>;

    public:
        // �����α�ʾΪ�����������飺
        Triangle2(const Vector2Type& vector0, const Vector2Type& vector1, const Vector2Type& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �ӵ�point�������εľ��롣
        NODISCARD Real DistanceTo(const Vector2Type& point) const;

        NODISCARD ContainerType GetVertex() const;
        NODISCARD Vector2Type GetVertex(int index) const;

    private:
        constexpr static auto vertexSize = 3;

        using ArrayType = std::array<Vector2Type, vertexSize>;

    private:
        ArrayType vertex;
    };

    using Triangle2F = Triangle2<float>;
    using Triangle2D = Triangle2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_TRIANGLE2_H
