// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:23)

#include "Rendering/RenderingExport.h"

#include "CameraNode.h"
#include "Detail/CameraNodeImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h" 

using std::string;
using std::vector;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering,CameraNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,CameraNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering,CameraNode);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering,CameraNode);

Rendering::CameraNode
	::CameraNode(const CameraSmartPointer& camera)
     :ParentType{},m_Impl{ make_shared<ImplType>(camera) }
{
	if (!m_Impl->IsNullPtr())
    {
        auto transform = m_Impl->GetLocalTransform();
                
        SetLocalTransform(transform);
    }
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CameraNode
    ::~CameraNode ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,CameraNode)

void Rendering::CameraNode
    ::SetCamera (const CameraSmartPointer& camera)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	m_Impl->SetCamera(camera);

	if (!m_Impl->IsNullPtr())
	{
		auto transform = m_Impl->GetLocalTransform();

		SetLocalTransform(transform);

		Update();
	}    
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CameraNode,GetCamera,const Rendering::ConstCameraSmartPointer)

bool Rendering::CameraNode
    ::UpdateWorldData (double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
  const  auto result = ParentType::UpdateWorldData(applicationTime);

	if (!m_Impl->IsNullPtr())
    {
		auto worldTransform = GetWorldTransform();
		auto cameraPosition = worldTransform.GetTranslate();
                const auto rotate = worldTransform.GetRotate();
        
		auto cameraDirectionVector = rotate.GetColumn(0);
		auto cameraUpVector = rotate.GetColumn(1);
		auto cameraRightVector = rotate.GetColumn(2);
 
        m_Impl->SetFrame(cameraPosition, Mathematics::AVector{ cameraDirectionVector }, Mathematics::AVector{ cameraUpVector }, Mathematics::AVector{cameraRightVector});
    }

	return result;
}

const CoreTools::ObjectSmartPointer Rendering::CameraNode
    ::GetObjectByName(const string& name)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	auto found = ParentType::GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
		if (!m_Impl->IsNullPtr())
		{
			return m_Impl->GetObjectByName(name);
		}
		else
		{
			return  CoreTools::ObjectSmartPointer();
		}
    }
}

const vector<CoreTools::ObjectSmartPointer> Rendering::CameraNode
    ::GetAllObjectsByName(const string& name)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	auto parentObjects = ParentType::GetAllObjectsByName(name);

	if (!m_Impl->IsNullPtr())
	{
		auto implObjects = m_Impl->GetAllObjectsByName(name);
		parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());
	}

	return parentObjects;   
}

const CoreTools::ConstObjectSmartPointer Rendering::CameraNode
    ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto found = ParentType::GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
		if (!m_Impl->IsNullPtr())
		{
			return m_Impl->GetConstObjectByName(name);
		}
		else
		{
			return  CoreTools::ConstObjectSmartPointer{};
		}
    }
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::CameraNode
    ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto parentObjects = ParentType::GetAllConstObjectsByName(name);

	if (!m_Impl->IsNullPtr())
	{
		auto implObjects = m_Impl->GetAllConstObjectsByName(name);
		parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());
	}

	return parentObjects;   
}

Rendering::CameraNode
    ::CameraNode (LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>(CameraSmartPointer{}) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::CameraNode
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::CameraNode
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
const	auto uniqueID = ParentType::Register(target);
	if(uniqueID != 0)
	{
		m_Impl->Register(target);
	}
    
    return uniqueID;
}

void Rendering::CameraNode
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::CameraNode
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
    
	m_Impl->Link(source);
}

void Rendering::CameraNode
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::CameraNode
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::CameraNode::ControllerInterfaceSmartPointer Rendering::CameraNode
      ::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSmartPointer{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP