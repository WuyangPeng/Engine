// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:57)

#include "Rendering/RenderingExport.h"

#include "CameraNodeImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointer.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;

Rendering::CameraNodeImpl
	::CameraNodeImpl(const CameraSmartPointer& camera)
	: m_Camera{ camera }
{       
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraNodeImpl)

void Rendering::CameraNodeImpl
	::SetCamera(const CameraSmartPointer& camera)
{       
    RENDERING_CLASS_IS_VALID_9;
    
    m_Camera = camera;    
}

const Rendering::ConstCameraSmartPointer Rendering::CameraNodeImpl
	::GetCamera() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Camera.PolymorphicCastConstObjectSmartPointer<ConstCameraSmartPointer>();
}

const Rendering::Transform Rendering::CameraNodeImpl
	::GetLocalTransform() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	Transform transform;
	transform.SetTranslate(m_Camera->GetPosition());

	Matrix rotate{ m_Camera->GetDirectionVector(),m_Camera->GetUpVector(),m_Camera->GetRightVector(),
				   Mathematics::APointf::sm_Origin, Mathematics::MatrixMajorFlags::Column };

	transform.SetRotate(rotate);

	return transform;
}

void Rendering::CameraNodeImpl
	::SetFrame(const APoint& position, const AVector& directionVector,const AVector& upVector, const AVector& rightVector)
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	m_Camera->SetFrame(position, directionVector,upVector, rightVector);
}  

const CoreTools::ObjectSmartPointer Rendering::CameraNodeImpl
	::GetObjectByName(const string& name) 
{    
    RENDERING_CLASS_IS_VALID_9;    
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");
	
	return m_Camera->GetObjectByName(name);
}

const vector<CoreTools::ObjectSmartPointer> Rendering::CameraNodeImpl
    ::GetAllObjectsByName(const string& name)
{  
    RENDERING_CLASS_IS_VALID_9;  
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

    return m_Camera->GetAllObjectsByName(name);    
} 

const CoreTools::ConstObjectSmartPointer Rendering::CameraNodeImpl
	::GetConstObjectByName(const string& name) const
{    
	RENDERING_CLASS_IS_VALID_9;    
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	return m_Camera->GetConstObjectByName(name);
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::CameraNodeImpl
	::GetAllConstObjectsByName(const string& name) const
{  
	RENDERING_CLASS_IS_VALID_9;  
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	return m_Camera->GetAllConstObjectsByName(name);    
} 

int Rendering::CameraNodeImpl
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
	auto size = CORE_TOOLS_STREAM_SIZE(m_Camera);
    
	return size;
}

uint64_t Rendering::CameraNodeImpl
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;  
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	return m_Camera->Register(target);	
}

void Rendering::CameraNodeImpl
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;  
	RENDERING_ASSERTION_1(!IsNullPtr(), "m_Camera为空指针！");

	target.WriteSmartPointer(m_Camera);  
}

void Rendering::CameraNodeImpl
    ::Link (CoreTools::ObjectLink& source)
{   
	RENDERING_CLASS_IS_VALID_9;   
    
    source.ResolveObjectSmartPointerLink(m_Camera);
}

void Rendering::CameraNodeImpl
    ::Load (CoreTools::BufferSource& source)
{
  	RENDERING_CLASS_IS_VALID_9;
	
    source.ReadSmartPointer(m_Camera);   
}

bool Rendering::CameraNodeImpl
	::IsNullPtr() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Camera.IsNullPtr();
}
 

