// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 15:13)

#include "Rendering/RenderingExport.h"

#include "MorphController.h"
#include "Detail/MorphControllerImpl.h"
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
CORE_TOOLS_RTTI_DEFINE(Rendering, MorphController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MorphController); 
CORE_TOOLS_FACTORY_DEFINE(Rendering, MorphController);

Rendering::MorphController
	::MorphController(int numVertices, int numTargets, int numKeys) 
	:ParentType{}, m_Impl{ make_shared<ImplType>(numVertices,numTargets,numKeys) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, MorphController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, MorphController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController,GetNumVertices, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController,GetNumTargets, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController,GetNumKeys, int)


const Rendering::MorphController::APoint Rendering::MorphController
	::GetVertices(int target, int vertices) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertices(target, vertices);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, MorphController,GetTimes, int,float)


float Rendering::MorphController
	::GetWeights(int key, int target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWeights(key, target);
}

void Rendering::MorphController
	::SetVertices(int target, int vertices, const APoint& point) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetVertices(target, vertices,point);
}

void Rendering::MorphController
	::SetTimes(int key, float times) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTimes(key, times);
}

void Rendering::MorphController
	::SetWeights(int key, int target, float weights) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWeights(key, target,weights);
}

bool Rendering::MorphController
	::Update(double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// 键插值操作使用线性内插。为了获得更高级的插值，
	// 您需要提供一个更复杂的密钥（例如贝塞尔三次或TCB样条曲线）。

    if (ParentType::Update(applicationTime))
    {
		// 访问该顶点缓冲器来存储混合目标。
        auto visual = dynamic_cast<Visual*>(GetControllerObject());
		if (visual != nullptr)
		{
			RENDERING_ASSERTION_2(m_Impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "顶点数不匹配\n"); 

			VertexBufferAccessor vba{ visual };

			// 设置顶点为 target[0].			 
			for (auto i = 0; i < m_Impl->GetNumVertices(); ++i)
			{
				visual->GetVertexBuffer()->SetPosition(vba, i, m_Impl->GetVertices(0,i));				 
			}

			// 查找边界键。
			auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));
			 
			const auto info = GetKeyInfo(ctrlTime);
 
			// 加入剩余的组分在凸状组合
			for (auto i = 1; i < m_Impl->GetNumTargets(); ++i)
			{
				// 添加target[i]在三角形顶点。
				const auto coeff = (1.0f - info.GetNormTime()) * m_Impl->GetWeights(info.GetFirstIndex(),i - 1) + info.GetNormTime() * m_Impl->GetWeights(info.GetSecondIndex(), i - 1);
				 
				for (auto j = 0; j < m_Impl->GetNumVertices(); ++j)
				{
					auto position = vba.GetPosition<APoint>(j);
					position += coeff * GetVertices(i,j);
					visual->GetVertexBuffer()->SetPosition(vba, j, position);				
				}
			}

			visual->UpdateModelSpace(VisualUpdateType::Normals);
			RENDERER_MANAGE_SINGLETON.UpdateAll(visual->GetConstVertexBuffer().get());
 
			return true;
		}		
    }

	return false;  
}

void Rendering::MorphController
	::SetObject(ControllerInterface* object) 
{
	RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");
	
	ParentType::SetObject(object);
}

void Rendering::MorphController
	::SetObjectInCopy(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::SetObject(object);
}

Rendering::ControllerInterfaceSharedPtr Rendering::MorphController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, MorphController,GetKeyInfo, float,const Rendering::ControllerKeyInfo)

										  
Rendering::MorphController
	::MorphController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::MorphController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::MorphController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	
}

void Rendering::MorphController
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::MorphController
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	 
}

void Rendering::MorphController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();	 
}

void Rendering::MorphController
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::MorphController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 
#include STSTEM_WARNING_POP