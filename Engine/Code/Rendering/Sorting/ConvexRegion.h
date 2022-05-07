///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 14:40)

#ifndef RENDERING_SORTING_CONVEX_REGION_H
#define RENDERING_SORTING_CONVEX_REGION_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/Sorting/SortingFwd.h"

namespace Rendering
{
    class ConvexRegion : public Node
    {
    public:
        using ClassType = ConvexRegion;
        using ParentType = Node;
        using PortalSharedPtr = std::shared_ptr<Portal>;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ConvexRegion);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        ConvexRegion(int numPortals, const std::vector<CoreTools::ObjectAssociated<Portal>>& portals);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumPortals() const noexcept;
        NODISCARD PortalSharedPtr GetPortal(int i) const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        NODISCARD bool UpdateWorldData(double applicationTime) override;

    private:
        int numPortals;
        std::vector<CoreTools::ObjectAssociated<Portal>> portals;

        bool visited;

    public:
        void GetVisibleSet(Culler& culler, bool noCull) override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ConvexRegion);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ConvexRegion);
}

#endif  // RENDERING_SORTING_CONVEX_REGION_H
