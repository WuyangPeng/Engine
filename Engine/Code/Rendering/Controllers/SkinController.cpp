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
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering, SkinController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SkinController); 
CORE_TOOLS_FACTORY_DEFINE(Rendering, SkinController);

Rendering::SkinController
	::SkinController(int numVertices, int numBones)
	:ParentType{}, impl{ make_shared<ImplType>(numVertices, numBones) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, SkinController)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SkinController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController,GetNumVertices,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController,GetNumBones,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SkinController,GetBones,int,const Rendering::ConstNodeSharedPtr)


float Rendering::SkinController
	::GetWeights(int bonesIndex, int verticesIndex) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetWeights(bonesIndex, verticesIndex);
}

const Rendering::SkinController::APoint Rendering::SkinController
	::GetOffsets(int bonesIndex, int verticesIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetOffsets(bonesIndex, verticesIndex);
}

void Rendering::SkinController
	::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
	;

	return impl->SetBones(bonesIndex, node);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SkinController,SetBones, std::vector<ConstNodeSharedPtr>,void)

void Rendering::SkinController
	::SetWeights(int bonesIndex, int verticesIndex, float weights) 
{
	;

	return impl->SetWeights(bonesIndex, verticesIndex,weights);
}

void Rendering::SkinController
	::SetWeights(int bonesIndex, const std::vector<float>& weights) 
{
	;

	return impl->SetWeights(bonesIndex, weights);
}

void Rendering::SkinController
	::SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets)
{
	;

	return impl->SetOffsets(bonesIndex, verticesIndex, offsets);
}

void Rendering::SkinController
	::SetOffsets(int bonesIndex, const std::vector<APoint>& offsets) 
{
	;

	return impl->SetOffsets(bonesIndex,  offsets);
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
		// 访问该顶点缓冲器来存储混合目标。
            auto visual = dynamic_cast<Visual*>(GetControllerObject());
		if (visual != nullptr)
		{
			auto vertexBuffer = visual->GetVertexBuffer();

			if (vertexBuffer)
			{
				RENDERING_ASSERTION_2(impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "控制器必须和缓冲器具有相同数量的顶点\n");
				VertexBufferAccessor vba{ visual };

				// 皮肤顶点在骨骼世界坐标系统计算，所以视觉世界变换必须为单位。
                                visual->SetWorldTransform(FloatTransform{});

				// 计算的皮肤顶点位置。
				for (auto vertex = 0; vertex < impl->GetNumVertices(); ++vertex)
				{
                                    auto position = Mathematics::APointF{};
					for (auto bone = 0; bone < impl->GetNumBones(); ++bone)
					{
						const auto weight = impl->GetWeights(bone, vertex);
						if (Mathematics::MathF::GetZeroTolerance() < Mathematics::MathF::FAbs(weight))
						{
                                                    const auto offset = impl->GetOffsets(bone, vertex);
                                                    const auto worldOffset = impl->GetBones(bone)->GetWorldTransform() * offset;
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
	;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");
	
	ParentType::SetObject(object);
}

void Rendering::SkinController
	::SetObjectInCopy(ControllerInterface* object)
{
	;

	ParentType::SetObject(object);
}

Rendering::SkinController
	::SkinController(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::SkinController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	int size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::SkinController ::Register(CoreTools::ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
	//	impl->Register(target);	 
	}

	return uniqueID;
}

void Rendering::SkinController
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SkinController
    ::Link (CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	

	impl->Link(source);
}

void Rendering::SkinController
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::SkinController
    ::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SkinController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP