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
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
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
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, DlodNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DlodNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DlodNode);  

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, DlodNode);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, DlodNode);

Rendering::DlodNode
	::DlodNode( int numLevelsOfDetail )
	:m_Impl{ make_shared<ImplType>(numLevelsOfDetail) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DlodNode
	::~DlodNode()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, DlodNode)

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
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetModelDistance(index,minDistance,maxDistance); 
}


void Rendering::DlodNode
	::GetVisibleSet( Culler& culler, bool noCull )
{
	SelectLevelOfDetail(culler.GetCamera());

	ParentType::GetVisibleSet(culler, noCull);
}

void Rendering::DlodNode
	::SelectLevelOfDetail( const ConstCameraSmartPointer& camera )
{
	// 一个DlodNode的子节点数组被压缩 
	// 这里没有空的插槽和子节点的数量是m_Child.size()，
	// 另外，假设所有模型的距离值分别设置为这些子节点。

	// 计算世界LOD中心
	auto worldTransform = GetWorldTransform();

	m_Impl->SetWorldCenter(worldTransform);

	// 计算世界平方距离间隔。
	m_Impl->SetWorldDistance(worldTransform.GetUniformScale());

	// 选择LOD子节点
	SetActiveChild(System::EnumCastUnderlying(SwitchNodeType::InvalidChild));
	auto difference = m_Impl->GetWorldCenter() - camera->GetPosition();
	auto distance = difference.Length();
	for (auto index = 0; index < m_Impl->GetNumLevelsOfDetail(); ++index)
	{
		if (m_Impl->GetWorldMinDistance(index) <= distance && distance < m_Impl->GetWorldMaxDistance(index))
		{
			SetActiveChild(index);
			break;
		}
	}
}
 #include STSTEM_WARNING_POP