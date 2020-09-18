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
        OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(IKGoal);
        using ParentType = Object;
        using APoint = Mathematics::FloatAPoint;

    public:
        IKGoal(const SpatialSmartPointer& target, const SpatialSmartPointer& effector, float weight = 1.0f);
        ~IKGoal();
   
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        IKGoal(IKGoal&&) = default;
        IKGoal& operator=(IKGoal&&) = default;
#include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKGoal);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        const ConstSpatialSmartPointer GetTarget() const noexcept;
        const ConstSpatialSmartPointer GetEffector() const noexcept;
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
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, IKGoal);
}

#endif  // RENDERING_CONTROLLERS_IKGOAL_H
