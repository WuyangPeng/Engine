// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 10:34)

#ifndef RENDERING_CONTROLLERS_IKJOINT_H
#define RENDERING_CONTROLLERS_IKJOINT_H

#include "Rendering/RenderingDll.h"

#include "IKGoal.h"
#include "Rendering/SceneGraph/Spatial.h"

EXPORT_SHARED_PTR(Rendering, IKJointImpl, RENDERING_DEFAULT_DECLARE);
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKJoint : public CoreTools::Object
    {
    public:
        void Swap(IKJoint& rhs) noexcept;

    public:
        TYPE_DECLARE(IKJoint);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~IKJoint() noexcept = default;
        IKJoint(const IKJoint& rhs);
        IKJoint& operator=(const IKJoint& rhs);
        IKJoint(IKJoint&& rhs) noexcept;
        IKJoint& operator=(IKJoint&& rhs) noexcept;
        using ParentType = Object;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using IKGoalSharedPtrVector = std::vector<IKGoalSharedPtr>;
        using MatrixRotationAxis = Mathematics::MatrixRotationAxis;

    public:
        IKJoint(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKJoint);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // Joint¸üÐÂ¡£
        const AVector GetAxis(MatrixRotationAxis axisIndex) const;
        void UpdateWorldTransform();
        void UpdateWorldRotateAndTranslate() noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        bool UpdateLocalTranslate(MatrixRotationAxis axisIndex);
        bool UpdateLocalRotate(MatrixRotationAxis axisIndex);

        const ConstSpatialSharedPtr GetObjectSharedPtr() const noexcept;
        const ConstIKGoalSharedPtr GetGoalsSharedPtr(int index) const;
        int GetGoalsNum() const;

        void SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation);
        void SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation);

        bool IsAllowTranslation(MatrixRotationAxis axisIndex) const;
        bool IsAllowRotation(MatrixRotationAxis axisIndex) const;
        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;

    private:
        ImplPtr impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(IKJoint);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(IKJoint);
}

#endif  // RENDERING_CONTROLLERS_IKJOINT_H
