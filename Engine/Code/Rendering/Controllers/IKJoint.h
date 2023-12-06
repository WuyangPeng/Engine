///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:02)

#ifndef RENDERING_CONTROLLERS_IKJOINT_H
#define RENDERING_CONTROLLERS_IKJOINT_H

#include "Rendering/RenderingDll.h"

#include "IKGoal.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Spatial.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(IKJoint, IKJointImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKJoint : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(IKJoint);
        using ParentType = Object;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using IKGoalSharedPtrVector = std::vector<CoreTools::ObjectAssociated<IKGoal>>;
        using MatrixRotationAxis = Mathematics::MatrixRotationAxis;

    public:
        IKJoint(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKJoint);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // Joint更新。
        NODISCARD AVector GetAxis(MatrixRotationAxis axisIndex) const;
        void UpdateWorldTransform();
        void UpdateWorldRotateAndTranslate();
        NODISCARD bool UpdateLocalTranslate(MatrixRotationAxis axisIndex);
        NODISCARD bool UpdateLocalRotate(MatrixRotationAxis axisIndex);

        NODISCARD ConstSpatialSharedPtr GetObjectSharedPtr() const noexcept;
        NODISCARD ConstIKGoalSharedPtr GetGoalsSharedPtr(int index) const;
        NODISCARD int GetGoalsNum() const;

        void SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation);
        void SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation);

        NODISCARD bool IsAllowTranslation(MatrixRotationAxis axisIndex) const;
        NODISCARD bool IsAllowRotation(MatrixRotationAxis axisIndex) const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(IKJoint);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IKJoint);
}

#endif  // RENDERING_CONTROLLERS_IKJOINT_H
