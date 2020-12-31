///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 11:18)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Intersection/Flags/VertexProjectionMap.h"

#include <memory>

namespace Mathematics
{
    template <typename Real>
    class IntersectorConfigurationImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<IntersectorConfigurationImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<IntersectorConfigurationImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<IntersectorConfigurationImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorConfiguration final
    {
    public:
        using IntersectorConfigurationImpl = IntersectorConfigurationImpl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(IntersectorConfiguration, DESTRUCTOR_DEFAULT);

    public:
        IntersectorConfiguration();

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
        IMPL_TYPE_DECLARE(IntersectorConfiguration);
    };

    using FloatIntersectorConfiguration = IntersectorConfiguration<float>;
    using DoubleIntersectorConfiguration = IntersectorConfiguration<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
