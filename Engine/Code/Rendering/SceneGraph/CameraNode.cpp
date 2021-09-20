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
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering,CameraNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,CameraNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering,CameraNode);

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }                                                                                        
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, CameraNode);

Rendering::CameraNode
	::CameraNode(const CameraSharedPtr& camera)
     :ParentType{},impl{ make_shared<ImplType>(camera) }
{
	if (!impl->IsNullPtr())
    {
        auto transform = impl->GetLocalTransform();
                
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
    ::SetCamera (const CameraSharedPtr& camera)
{
	;
    
	impl->SetCamera(camera);

	if (!impl->IsNullPtr())
	{
		auto transform = impl->GetLocalTransform();

		SetLocalTransform(transform);

		Update();
	}    
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CameraNode,GetCamera,const Rendering::ConstCameraSharedPtr)

bool Rendering::CameraNode
    ::UpdateWorldData (double applicationTime)
{
	;
    
  const  auto result = ParentType::UpdateWorldData(applicationTime);

	if (!impl->IsNullPtr())
    {
		auto worldTransform = GetWorldTransform();
		auto cameraPosition = worldTransform.GetTranslate();
                const auto rotate = worldTransform.GetRotate();
        
		auto cameraDirectionVector = rotate.GetColumn(0);
		auto cameraUpVector = rotate.GetColumn(1);
		auto cameraRightVector = rotate.GetColumn(2);
 
        impl->SetFrame(cameraPosition, Mathematics::AVector{ cameraDirectionVector }, Mathematics::AVector{ cameraUpVector }, Mathematics::AVector{cameraRightVector});
    }

	return result;
}

const CoreTools::ObjectSharedPtr Rendering::CameraNode
    ::GetObjectByName(const string& name)
{
	;
    
	auto found = ParentType::GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
		if (!impl->IsNullPtr())
		{
			return impl->GetObjectByName(name);
		}
		else
		{
			return  CoreTools::ObjectSharedPtr();
		}
    }
}

const vector<CoreTools::ObjectSharedPtr> Rendering::CameraNode
    ::GetAllObjectsByName(const string& name)
{
	;
    
	auto parentObjects = ParentType::GetAllObjectsByName(name);

	if (!impl->IsNullPtr())
	{
		auto implObjects = impl->GetAllObjectsByName(name);
		parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());
	}

	return parentObjects;   
}

const CoreTools::ConstObjectSharedPtr Rendering::CameraNode
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
		if (!impl->IsNullPtr())
		{
			return impl->GetConstObjectByName(name);
		}
		else
		{
			return  CoreTools::ConstObjectSharedPtr{};
		}
    }
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::CameraNode
    ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto parentObjects = ParentType::GetAllConstObjectsByName(name);

	if (!impl->IsNullPtr())
	{
		auto implObjects = impl->GetAllConstObjectsByName(name);
		parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());
	}

	return parentObjects;   
}

Rendering::CameraNode
    ::CameraNode (LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>(CameraSharedPtr{}) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::CameraNode
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::CameraNode
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
const	auto uniqueID = ParentType::Register(target);
	if(uniqueID != 0)
	{
		impl->Register(target);
	}
    
    return uniqueID;
}

void Rendering::CameraNode
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::CameraNode
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	;
    
	ParentType::Link(source);
    
	impl->Link(source);
}

void Rendering::CameraNode
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::CameraNode
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::CameraNode::ControllerInterfaceSharedPtr Rendering::CameraNode
      ::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::CameraNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP