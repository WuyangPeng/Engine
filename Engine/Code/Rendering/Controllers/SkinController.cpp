// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 15:53)

#include "Rendering/RenderingExport.h"

#include "SkinController.h"
#include "Detail/SkinControllerImpl.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, SkinController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SkinController); 
CORE_TOOLS_FACTORY_DEFINE(Rendering, SkinController);

Rendering::SkinController
	::SkinController(int numVertices, int numBones)
	:ParentType{}, m_Impl{ make_shared<ImplType>(numVertices, numBones) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SkinController
	::~SkinController() 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, SkinController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, SkinController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SkinController,GetNumVertices,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SkinController,GetNumBones,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SkinController,GetBones,int,const Rendering::ConstNodeSmartPointer)


float Rendering::SkinController
	::GetWeights(int bonesIndex, int verticesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWeights(bonesIndex, verticesIndex);
}

const Rendering::SkinController::APoint Rendering::SkinController
	::GetOffsets(int bonesIndex, int verticesIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetOffsets(bonesIndex, verticesIndex);
}

void Rendering::SkinController
	::SetBones(int bonesIndex, const ConstNodeSmartPointer& node)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBones(bonesIndex, node);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SkinController,SetBones, std::vector<ConstNodeSmartPointer>,void)

void Rendering::SkinController
	::SetWeights(int bonesIndex, int verticesIndex, float weights) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWeights(bonesIndex, verticesIndex,weights);
}

void Rendering::SkinController
	::SetWeights(int bonesIndex, const std::vector<float>& weights) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWeights(bonesIndex, weights);
}

void Rendering::SkinController
	::SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetOffsets(bonesIndex, verticesIndex, offsets);
}

void Rendering::SkinController
	::SetOffsets(int bonesIndex, const std::vector<APoint>& offsets) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetOffsets(bonesIndex,  offsets);
}

Rendering::ControllerInterfaceSmartPointer Rendering::SkinController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
}

bool Rendering::SkinController
	::Update(double applicationTime) 
{
	RENDERING_CLASS_IS_VALID_1;

	if (ParentType::Update(applicationTime))
	{
		// 访问该顶点缓冲器来存储混合目标。
		auto visual = CoreTools::StaticCast<Visual>(GetControllerObject());
		if (visual != nullptr)
		{
			auto vertexBuffer = visual->GetVertexBuffer();

			if (!vertexBuffer.IsNullPtr())
			{
				RENDERING_ASSERTION_2(m_Impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "控制器必须和缓冲器具有相同数量的顶点\n");
				VertexBufferAccessor vba{ visual };

				// 皮肤顶点在骨骼世界坐标系统计算，所以视觉世界变换必须为单位。
				visual->SetWorldTransform(Transform::sm_Identity);

				// 计算的皮肤顶点位置。
				for (auto vertex = 0; vertex < m_Impl->GetNumVertices(); ++vertex)
				{
					auto position = APoint::sm_Origin;
					for (auto bone = 0; bone < m_Impl->GetNumBones(); ++bone)
					{
						auto weight = m_Impl->GetWeights(bone, vertex);
						if (Mathematics::Mathf::sm_ZeroTolerance < Mathematics::Mathf::FAbs(weight))
						{
							auto offset = m_Impl->GetOffsets(bone, vertex);
							auto worldOffset = m_Impl->GetBones(bone)->GetWorldTransform() * offset;
							position += weight * worldOffset;
						}
					}
					visual->GetVertexBuffer()->SetPosition(vba, vertex, position);
				}

				visual->UpdateModelSpace(VisualUpdateType::Normals);
				RENDERER_MANAGE_SINGLETON.UpdateAll(visual->GetConstVertexBuffer().GetData());

				return true;
			}			
		}		
	}

	return false;	
}

void Rendering::SkinController
	::SetObject(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::sm_Type), "无效类\n");
	
	ParentType::SetObject(object);
}

void Rendering::SkinController
	::SetObjectInCopy(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::SetObject(object);
}

Rendering::SkinController
	::SkinController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::SkinController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	int size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::SkinController
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		m_Impl->Register(target);	 
	}

	return uniqueID;
}

void Rendering::SkinController
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SkinController
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	

	m_Impl->Link(source);
}

void Rendering::SkinController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::SkinController
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


 