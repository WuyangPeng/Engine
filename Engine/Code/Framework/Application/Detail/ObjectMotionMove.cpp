///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 16:38)

#include "Framework/FrameworkExport.h"

#include "ObjectMotionMove.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"

Framework::ObjectMotionMove::ObjectMotionMove(const SpatialSharedPtr& motionObject, int doRoll, int doYaw, int doPitch, float rotationSpeed)
    : motionObject{ motionObject },
      doRoll{ doRoll },
      doYaw{ doYaw },
      doPitch{ doPitch },
      rotationSpeed{ rotationSpeed },
      axis{},
      angle{ 0.0f },
      rotate{}
{
    Calculate();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ObjectMotionMove)

Framework::ObjectMotionMove::AVector Framework::ObjectMotionMove::GetAxis() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return axis;
}

float Framework::ObjectMotionMove::GetAngle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return angle;
}

Framework::ObjectMotionMove::Matrix Framework::ObjectMotionMove::GetRotate() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return rotate;
}

void Framework::ObjectMotionMove::Calculate()
{
    // 检查对象是否被移动。
    const auto parent = motionObject->GetParent();

    if (doRoll != 0)
    {
        rotate = motionObject->GetLocalTransform().GetRotate();

        angle = doRoll * rotationSpeed;
        if (!parent->IsNullObject())
        {
            axis = Mathematics::AVector{ parent->GetWorldTransform().GetRotate().GetColumn(0) };
        }
        else
        {
            axis = Mathematics::AVectorF::GetUnitX();
        }
    }
    else if (doYaw != 0)
    {
        rotate = motionObject->GetLocalTransform().GetRotate();

        angle = doYaw * rotationSpeed;
        if (!parent->IsNullObject())
        {
            axis = Mathematics::AVector{ parent->GetWorldTransform().GetRotate().GetColumn(1) };
        }
        else
        {
            Mathematics::AVectorF::GetUnitY();
        }
    }
    else if (doPitch != 0)
    {
        rotate = motionObject->GetLocalTransform().GetRotate();

        angle = doPitch * rotationSpeed;
        if (!parent->IsNullObject())
        {
            axis = Mathematics::AVector{ parent->GetWorldTransform().GetRotate().GetColumn(2) };
        }
        else
        {
            axis = Mathematics::AVectorF::GetUnitZ();
        }
    }
}

Framework::ObjectMotionMove::Transform Framework::ObjectMotionMove::GetIncrement() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const Matrix increment{ axis, angle };
    auto aRotate = increment * rotate;
    aRotate.Orthonormalize();

    auto transform = motionObject->GetLocalTransform();
    transform.SetRotate(aRotate);

    return transform;
}
