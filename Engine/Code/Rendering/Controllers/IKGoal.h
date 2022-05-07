///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 15:52)

#ifndef RENDERING_CONTROLLERS_IKGOAL_H
#define RENDERING_CONTROLLERS_IKGOAL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/Spatial.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(IKGoal, IKGoalImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKGoal : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(IKGoal);
        using ParentType = Object;
        using APoint = Mathematics::APointF;

    public:
        IKGoal(const SpatialSharedPtr& target, const SpatialSharedPtr& effector, float weight = 1.0f);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKGoal);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD ConstSpatialSharedPtr GetTarget() const noexcept;
        NODISCARD ConstSpatialSharedPtr GetEffector() const noexcept;
        NODISCARD APoint GetTargetPosition() const noexcept;
        NODISCARD APoint GetEffectorPosition() const noexcept;

        void SetWeight(float weight) noexcept;
        NODISCARD float GetWeight() const noexcept;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(IKGoal);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IKGoal);
}

#endif  // RENDERING_CONTROLLERS_IKGOAL_H
