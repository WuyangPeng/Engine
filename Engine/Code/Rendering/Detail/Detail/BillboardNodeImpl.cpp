// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 10:34)

#include "Rendering/RenderingExport.h"

#include "BillboardNodeImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
using std::string;
using std::vector;

Rendering::BillboardNodeImpl ::BillboardNodeImpl() noexcept
    : m_Camera{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BillboardNodeImpl ::BillboardNodeImpl(const CameraSharedPtr& camera) noexcept
    : m_Camera{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BillboardNodeImpl)

int Rendering::BillboardNodeImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = CORE_TOOLS_STREAM_SIZE(m_Camera);

    return size;
}

void Rendering::BillboardNodeImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //target.WriteSharedPtr(m_Camera);
}

void Rendering::BillboardNodeImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //source.ReadSharedPtr(m_Camera);
}

void Rendering::BillboardNodeImpl ::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //source.ResolveObjectSharedPtrLink(m_Camera);
}

void Rendering::BillboardNodeImpl ::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //target.RegisterSharedPtr(m_Camera);
}

CoreTools::ConstObjectSharedPtr Rendering::BillboardNodeImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return m_Camera->GetConstObjectByName(name);
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::BillboardNodeImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return m_Camera->GetAllConstObjectsByName(name);
}

CoreTools::ObjectSharedPtr Rendering::BillboardNodeImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return m_Camera->GetObjectByName(name);
}

vector<CoreTools::ObjectSharedPtr> Rendering::BillboardNodeImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return m_Camera->GetAllObjectsByName(name);
}

void Rendering::BillboardNodeImpl ::AlignTo(const CameraSharedPtr& camera)
{
    RENDERING_CLASS_IS_VALID_9;

    m_Camera = camera;
}

const Rendering::ConstCameraSharedPtr Rendering::BillboardNodeImpl ::GetCamera() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Camera;
}

#include STSTEM_WARNING_POP
