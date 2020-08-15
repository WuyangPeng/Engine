// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:22)

#include "Rendering/RenderingExport.h"

#include "Spatial.h"
#include "SpatialData.h"
#include "Culler.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26473)
CORE_TOOLS_RTTI_DEFINE(Rendering,Spatial);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Spatial);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,Spatial);

Rendering::Spatial
    ::Spatial()
	:ParentType{}, m_Parent{ nullptr }, m_SpatialDataPtr{ make_shared<SpatialData>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial
    ::~Spatial()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial
    ::Spatial(const Spatial& rhs)
	:ParentType(rhs), m_Parent{ rhs.m_Parent },m_SpatialDataPtr{ make_shared<SpatialData>(*rhs.m_SpatialDataPtr) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial& Rendering::Spatial
   ::operator= (const Spatial& rhs)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    ParentType::operator=(rhs);
    
    m_Parent = rhs.m_Parent;
    
	m_SpatialDataPtr = make_shared<SpatialData>(*rhs.m_SpatialDataPtr);
    
    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Spatial
    ::IsValid() const noexcept
{
    if(ParentType::IsValid() && m_SpatialDataPtr != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::Spatial
	::SetParent(Spatial* parent) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	m_Parent = parent;
}

bool Rendering::Spatial
   ::Update (double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return Update(applicationTime,true);
}

bool Rendering::Spatial
    ::Update (double applicationTime, bool initiator)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
const auto result = UpdateWorldData(applicationTime);
    UpdateWorldBound();
    if (initiator)
    {
        PropagateBoundToRoot();
    }
    
    return result;
}

bool Rendering::Spatial
    ::UpdateWorldData (double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    // 更新世界变换。
    if (!m_SpatialDataPtr->GetWorldTransformIsCurrent())
    {
        if (m_Parent != nullptr)
        {
            m_SpatialDataPtr->SetLocalTransformToWorldTransform(m_Parent->GetWorldTransform());
        }
        else
        {
            m_SpatialDataPtr->SetLocalTransformToWorldTransform();
        }
    }

	// 更新与该对象相关的任何控制器。
	return ParentType::UpdateControllers(applicationTime);
}

void Rendering::Spatial
    ::PropagateBoundToRoot ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    if (m_Parent)
    {
        m_Parent->UpdateWorldBound();
        m_Parent->PropagateBoundToRoot();
    }
}

Rendering::Spatial* Rendering::Spatial ::GetParent() noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return const_cast<Spatial*>(static_cast<const ClassType*>(this)->GetParent());
}

const Rendering::Spatial* Rendering::Spatial
	::GetParent() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Parent;
}

void Rendering::Spatial
    ::OnGetVisibleSet (Culler& culler, bool noCull)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
 const auto cullingMode = m_SpatialDataPtr->GetCullingMode();
    
    if (cullingMode == CullingMode::Always)
    {
        return;
    }

    if (cullingMode == CullingMode::Never)
    {
        noCull = true;
    }

const auto savePlaneState = culler.GetPlaneState();
    if (noCull || culler.IsVisible(m_SpatialDataPtr->GetWorldBound()))
    {
        GetVisibleSet(culler, noCull);
    }
    culler.SetPlaneState(savePlaneState);
}

void Rendering::Spatial
    ::SetLocalTransform(const Transform& transform)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->SetLocalTransform(transform);
}

void Rendering::Spatial
    ::SetWorldTransform(const Transform& transform)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->DirectSetWorldTransform(transform);
}

void Rendering::Spatial
    ::SetWorldBound(const Bound& bound)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->DirectSetWorldBound(bound);
}

void Rendering::Spatial
    ::SetCullingMode(CullingMode culling)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->SetCullingMode(culling);
}

void Rendering::Spatial
    ::InitWorldBound()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->InitWorldBound();
}

void Rendering::Spatial
    ::BoundGrowToContain(const Bound& worldBound)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_SpatialDataPtr->SetWorldBound(worldBound);
}

const Rendering::Transform Rendering::Spatial
    ::GetLocalTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_SpatialDataPtr->GetLocalTransform();
}

const Rendering::Transform Rendering::Spatial
    ::GetWorldTransform() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_SpatialDataPtr->GetWorldTransform();
}

const Rendering::Bound Rendering::Spatial
    ::GetWorldBound() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_SpatialDataPtr->GetWorldBound();
}

Rendering::CullingMode Rendering::Spatial
    ::GetCullingMode() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_SpatialDataPtr->GetCullingMode();
}

bool Rendering::Spatial
    ::GetWorldBoundIsCurrent() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_SpatialDataPtr->GetWorldBoundIsCurrent();
}
 

// 流支持
Rendering::Spatial
    ::Spatial (LoadConstructor value)
	:ParentType{ value }, m_Parent{ nullptr },m_SpatialDataPtr{ make_shared<SpatialData>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Spatial
    ::GetStreamingSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    auto size = ParentType::GetStreamingSize();
    
    size += m_SpatialDataPtr->GetStreamingSize();
    
    // m_Parent 不保存
    
    return size;
}

uint64_t Rendering::Spatial
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
const auto uniqueID = ParentType::Register(target);
    
    // m_Parent不需要注册，由于parent本身必须发起注册调用其孩子,“this”就是其中之一。
    return uniqueID;
}

void Rendering::Spatial
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_SpatialDataPtr->Save(target);
    
    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Spatial
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
    
    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。
}

void Rendering::Spatial
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
    
    m_Parent = CoreTools::DynamicCast<Spatial>(GetControllerObject());
}

void Rendering::Spatial
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_SpatialDataPtr->Load(source);
    
    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

const Rendering::PickRecordContainer Rendering::Spatial
	::ExecuteRecursive(const APoint& origin, const AVector& direction,float tMin, float tMax) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	SYSTEM_UNUSED_ARG(origin);
	SYSTEM_UNUSED_ARG(direction);
	SYSTEM_UNUSED_ARG(tMin);
	SYSTEM_UNUSED_ARG(tMax);

	return PickRecordContainer();
}

void Rendering::Spatial
	::SetLocalTransformTranslate(const APoint& translate)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	return m_SpatialDataPtr->SetLocalTransformTranslate(translate);
}

void Rendering::Spatial
	::SetLocalTransformRotate(const Matrix& rotate) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	return m_SpatialDataPtr->SetLocalTransformRotate(rotate);
}

void Rendering::Spatial
	::SetWorldTransformOnUpdate( const Transform& transform )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_SpatialDataPtr->SetWorldTransformOnUpdate(transform);
}

#include STSTEM_WARNING_POP