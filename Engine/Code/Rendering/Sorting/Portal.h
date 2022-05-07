///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 16:13)

#ifndef RENDERING_SORTING_PORTAL_H
#define RENDERING_SORTING_PORTAL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/WeakObjectAssociated.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Plane.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Sorting/SortingFwd.h"

namespace Rendering
{
    class Portal : public CoreTools::Object
    {
    public:
        using ClassType = Portal;
        using ParentType = Object;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Portal);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        Portal(int numVertices, const std::vector<Mathematics::APointF>& modelVertices, const Mathematics::PlaneF& modelPlane, const std::shared_ptr<ConvexRegion>& adjacentRegion, bool open);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        void UpdateWorldData(const TransformF& worldTransform);
        void GetVisibleSet(Culler& culler, bool noCull);

    protected:
        NODISCARD bool ReducedFrustum(const Culler& culler, std::array<float, 6>& reducedFrustum);

    private:
        CoreTools::WeakObjectAssociated<ConvexRegion> adjacentRegion;
        bool open;

        int numVertices;
        std::vector<Mathematics::APointF> modelVertices;
        std::vector<Mathematics::APointF> worldVertices;
        Mathematics::PlaneF modelPlane;
        Mathematics::PlaneF worldPlane;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Portal);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Portal);
}

#endif  // RENDERING_SORTING_PORTAL_H
