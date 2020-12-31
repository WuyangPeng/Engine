///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/25 11:18)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Flags/VertexProjectionMap.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE IntersectorConfigurationImpl final
    {
    public:
        using ClassType = IntersectorConfigurationImpl<Real>;

    public:
        IntersectorConfigurationImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] VertexProjectionMap GetMap() const noexcept;
        [[nodiscard]] Real GetMin() const noexcept;
        [[nodiscard]] Real GetMax() const noexcept;
        [[nodiscard]] int GetIndex(int index) const;

        void SetMap(VertexProjectionMap vertexProjectionMap) noexcept;
        void SetMin(Real min) noexcept;
        void SetMax(Real max) noexcept;
        void SetIndex(int index, int value);

    private:
        using IndexType = std::array<int, 8>;

    private:
        // ���õġ�����ͶӰͼ��ֵ��
        VertexProjectionMap m_Map;

        // �����˳��
        IndexType m_Index;

        // ͶӰ�����
        Real m_Min;

        Real m_Max;
    };
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_H
