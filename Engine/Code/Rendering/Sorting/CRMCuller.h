///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:27)

#ifndef RENDERING_SORTING_CRM_CULLER_H
#define RENDERING_SORTING_CRM_CULLER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Culler.h"

#include <set>

namespace Rendering
{
    class CRMCuller : public Culler
    {
    public:
        using ClassType = CRMCuller;
        using ParentType = Culler;

    public:
        explicit CRMCuller(const ConstCameraSharedPtr& camera);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Insert(const VisualSharedPtr& visible) override;

    protected:
        std::set<ConstSpatialSharedPtr> unique;
    };
}

#endif  // RENDERING_SORTING_CRM_CULLER_H
