///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/19 16:09)

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
