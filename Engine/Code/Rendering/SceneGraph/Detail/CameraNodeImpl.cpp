// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 15:57)

#include "Rendering/RenderingExport.h"

#include "CameraNodeImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/Contract/Noexcept.h"

using std::string;
using std::vector;
#include STSTEM_WARNING_PUSH 
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::CameraNodeImpl ::CameraNodeImpl(const CameraSharedPtr& camera) noexcept
    : m_Camera{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraNodeImpl)

void Rendering::CameraNodeImpl ::SetCamera(const CameraSharedPtr& camera) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Camera = camera;
}

const Rendering::ConstCameraSharedPtr Rendering::CameraNodeImpl ::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Camera;
}

const Rendering::FloatTransform Rendering::CameraNodeImpl ::GetLocalTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    FloatTransform transform;
    transform.SetTranslate(m_Camera->GetPosition());

    const Matrix rotate{ m_Camera->GetDirectionVector(), m_Camera->GetUpVector(), m_Camera->GetRightVector(),
                         Mathematics::Float::g_Origin, Mathematics::MatrixMajorFlags::Column };

    transform.SetRotate(rotate);

    return transform;
}

void Rendering::CameraNodeImpl ::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    m_Camera->SetFrame(position, directionVector, upVector, rightVector);
}

const CoreTools::ObjectSharedPtr Rendering::CameraNodeImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->GetObjectByName(name);
}

const vector<CoreTools::ObjectSharedPtr> Rendering::CameraNodeImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->GetAllObjectsByName(name);
}

const CoreTools::ConstObjectSharedPtr Rendering::CameraNodeImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->GetConstObjectByName(name);
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::CameraNodeImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->GetAllConstObjectsByName(name);
}

int Rendering::CameraNodeImpl ::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

const    auto size = CORE_TOOLS_STREAM_SIZE(m_Camera);

    return size;
}

uint64_t Rendering::CameraNodeImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->Register(target);
}

void Rendering::CameraNodeImpl ::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");
    target;
    CoreTools::DisableNoexcept();
    //target.WriteSharedPtr(m_Camera);
}

void Rendering::CameraNodeImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    CoreTools::DisableNoexcept();
    // source.ResolveObjectSharedPtrLink(m_Camera);
}

void Rendering::CameraNodeImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    CoreTools::DisableNoexcept();
    // source.ReadSharedPtr(m_Camera);
}

bool Rendering::CameraNodeImpl ::IsNullPtr() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return !m_Camera;
}
#include STSTEM_WARNING_POP 