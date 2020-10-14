// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 15:53)

#include "Rendering/RenderingExport.h"

#include "SkinController.h"
#include "Detail/SkinControllerImpl.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, SkinController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SkinController); 
CORE_TOOLS_FACTORY_DEFINE(Rendering, SkinController);

Rendering::SkinController
	::SkinController(int numVertices, int numBones)
	:ParentType{}, m_Impl{ make_shared<ImplType>(numVertices, numBones) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, SkinController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, SkinController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController,GetNumVertices,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController,GetNumBones,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SkinController,GetBones,int,const Rendering::ConstNodeSharedPtr)


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
	::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBones(bonesIndex, node);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SkinController,SetBones, std::vector<ConstNodeSharedPtr>,void)

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

Rendering::ControllerInterfaceSharedPtr Rendering::SkinController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

bool Rendering::SkinController
	::Update(double applicationTime) 
{
	RENDERING_CLASS_IS_VALID_1;

	if (ParentType::Update(applicationTime))
	{
		// ���ʸö��㻺�������洢���Ŀ�ꡣ
            auto visual = dynamic_cast<Visual*>(GetControllerObject());
		if (visual != nullptr)
		{
			auto vertexBuffer = visual->GetVertexBuffer();

			if (vertexBuffer)
			{
				RENDERING_ASSERTION_2(m_Impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "����������ͻ�����������ͬ�����Ķ���\n");
				VertexBufferAccessor vba{ visual };

				// Ƥ�������ڹ�����������ϵͳ���㣬�����Ӿ�����任����Ϊ��λ��
                                visual->SetWorldTransform(FloatTransform{});

				// �����Ƥ������λ�á�
				for (auto vertex = 0; vertex < m_Impl->GetNumVertices(); ++vertex)
				{
                                      auto position = Mathematics::Float::g_Origin;
					for (auto bone = 0; bone < m_Impl->GetNumBones(); ++bone)
					{
						const auto weight = m_Impl->GetWeights(bone, vertex);
						if (Mathematics::FloatMath::GetZeroTolerance() < Mathematics::FloatMath::FAbs(weight))
						{
                                                    const auto offset = m_Impl->GetOffsets(bone, vertex);
                                                    const auto worldOffset = m_Impl->GetBones(bone)->GetWorldTransform() * offset;
							position += weight * worldOffset;
						}
					}
					visual->GetVertexBuffer()->SetPosition(vba, vertex, position);
				}

				visual->UpdateModelSpace(VisualUpdateType::Normals);
				RENDERER_MANAGE_SINGLETON.UpdateAll(visual->GetConstVertexBuffer().get());

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
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::sm_Type), "��Ч��\n");
	
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

uint64_t Rendering::SkinController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
	//	m_Impl->Register(target);	 
	}

	return uniqueID;
}

void Rendering::SkinController
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SkinController
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
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
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SkinController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP