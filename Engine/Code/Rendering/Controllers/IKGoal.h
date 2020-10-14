// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:33)

#ifndef RENDERING_CONTROLLERS_IKGOAL_H
#define RENDERING_CONTROLLERS_IKGOAL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/Spatial.h"

RENDERING_EXPORT_SHARED_PTR(IKGoalImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKGoal : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(IKGoal, = default);
        using ParentType = Object;
        using APoint = Mathematics::FloatAPoint;

    public:
        IKGoal(const SpatialSharedPtr& target, const SpatialSharedPtr& effector, float weight = 1.0f);
     
   
 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKGoal);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        const ConstSpatialSharedPtr GetTarget() const noexcept;
        const ConstSpatialSharedPtr GetEffector() const noexcept;
        const APoint GetTargetPosition() const;
        const APoint GetEffectorPosition() const;

        void SetWeight(float weight) noexcept;
        float GetWeight() const noexcept;

        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        IMPL_TYPE_DECLARE(IKGoal);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(IKGoal);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( IKGoal);
}

#endif  // RENDERING_CONTROLLERS_IKGOAL_H
