// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 11:04)

#include "Rendering/RenderingExport.h"

#include "DlodNode.h"
#include "Detail/DlodNodeImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26434)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, DlodNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DlodNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DlodNode);  

Rendering::DlodNode::DlodNode(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, DlodNode)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, DlodNode)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, DlodNode)

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, DlodNode);

Rendering::DlodNode
	::DlodNode( int numLevelsOfDetail )
	:impl{ make_shared<ImplType>(numLevelsOfDetail) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DlodNode)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode,GetModelCenter,const Rendering::DlodNode::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode,GetWorldCenter,const Rendering::DlodNode::APoint)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, DlodNode,SetModelCenter,APoint,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode,GetNumLevelsOfDetail,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode,GetModelMinDistance,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode,GetModelMaxDistance,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode, GetWorldMinDistance,int,float) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode,GetWorldMaxDistance,int,float)  
 
void Rendering::DlodNode
	::SetModelDistance( int index, float minDistance, float maxDistance )
{
	;

	return impl->SetModelDistance(index,minDistance,maxDistance); 
}


void Rendering::DlodNode
	::GetVisibleSet( Culler& culler, bool noCull )
{
	SelectLevelOfDetail(culler.GetCamera());

	ParentType::GetVisibleSet(culler, noCull);
}

void Rendering::DlodNode
	::SelectLevelOfDetail( const ConstCameraSharedPtr& camera )
{
	// 一个DlodNode的子节点数组被压缩 
	// 这里没有空的插槽和子节点的数量是m_Child.size()，
	// 另外，假设所有模型的距离值分别设置为这些子节点。

	// 计算世界LOD中心
	auto worldTransform = GetWorldTransform();

	impl->SetWorldCenter(worldTransform);

	// 计算世界平方距离间隔。
	impl->SetWorldDistance(worldTransform.GetUniformScale());

	// 选择LOD子节点
	SetActiveChild(System::EnumCastUnderlying(SwitchNodeType::InvalidChild));
	auto difference = impl->GetWorldCenter() - camera->GetPosition();
	auto distance = difference.Length();
	for (auto index = 0; index < impl->GetNumLevelsOfDetail(); ++index)
	{
		if (impl->GetWorldMinDistance(index) <= distance && distance < impl->GetWorldMaxDistance(index))
		{
			SetActiveChild(index);
			break;
		}
	}
}
 #include STSTEM_WARNING_POP