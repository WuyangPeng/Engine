///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 13:50)

#include "Rendering/RenderingExport.h"

#include "CameraNodeImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"

using std::string;
using std::vector;

Rendering::CameraNodeImpl::CameraNodeImpl(const CameraSharedPtr& camera) noexcept
    : camera{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraNodeImpl)

void Rendering::CameraNodeImpl::SetCamera(const CameraSharedPtr& aCamera) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    camera.object = aCamera;
}

Rendering::ConstCameraSharedPtr Rendering::CameraNodeImpl::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return camera.object;
}

Rendering::TransformF Rendering::CameraNodeImpl::GetLocalTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    TransformF transform{};
    transform.SetTranslate(camera.object->GetPosition());

    const Matrix rotate{ camera.object->GetDirectionVector(), camera.object->GetUpVector(), camera.object->GetRightVector(), Mathematics::APointF::GetOrigin(), Mathematics::MatrixMajorFlags::Column };

    transform.SetRotate(rotate);

    return transform;
}

void Rendering::CameraNodeImpl::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    camera.object->SetFrame(position, directionVector, upVector, rightVector);
}

CoreTools::ObjectSharedPtr Rendering::CameraNodeImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return camera.object->GetObjectByName(name);
}

vector<CoreTools::ObjectSharedPtr> Rendering::CameraNodeImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return camera.object->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::CameraNodeImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return camera.object->GetConstObjectByName(name);
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::CameraNodeImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return camera.object->GetAllConstObjectsByName(name);
}

int Rendering::CameraNodeImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = CORE_TOOLS_STREAM_SIZE(camera);

    return size;
}

uint64_t Rendering::CameraNodeImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return target.Register(camera);
}

void Rendering::CameraNodeImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    target.WriteObjectAssociated(camera);
}

void Rendering::CameraNodeImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(camera);
}

void Rendering::CameraNodeImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(camera);
}

bool Rendering::CameraNodeImpl::IsNullPtr() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return !camera.object;
}
