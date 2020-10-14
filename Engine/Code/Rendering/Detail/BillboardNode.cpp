// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:59)

#include "Rendering/RenderingExport.h"

#include "BillboardNode.h"
#include "Detail/BillboardNodeImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, BillboardNode);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, BillboardNode);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, BillboardNode);

Rendering::BillboardNode
	::BillboardNode(const CameraSharedPtr& camera)
	:ParentType{}, m_Impl{ make_shared<ImplType>(camera) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, BillboardNode)

Rendering::ControllerInterfaceSharedPtr Rendering::BillboardNode
	::Clone() const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, BillboardNode,AlignTo,  CameraSharedPtr,void)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BillboardNode,GetCamera,const Rendering::ConstCameraSharedPtr)

bool Rendering::BillboardNode
	::UpdateWorldData(double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	// �������Ƶ�����任�����丸����任����ֲ��任��
	// ��ע�⣬�㲻Ӧ�õ���Node::UpdateWorldData����Ϊ�ú����������ӽڵ㡣
	// ֱ����������������׼һ��BillboardNode���ӽڵ㲻�ܸ��¡�
	Spatial::UpdateWorldData(applicationTime); 

	auto camera = m_Impl->GetCamera();

	if (camera )
    {
       	// �����任������Ƶ�ģ�Ϳռ䡣
		auto modelPosition = GetWorldTransform().GetInverseTransform() * camera->GetPosition();

        // Ҫ�������ƣ��������Ƶ�ģ�Ϳռ��xzƽ���ͶӰ�����Թ���Ƶ�ģ��y����ת�ĽǶȡ�
		// ���ͶӰ�����������ģ���ϵ��� (x = 0 �� z = 0)��
		// ATan2�����㣨����NaN�ģ������û�б�Ҫ������˻���������ֱ���д���
		auto angle = Mathematics::FloatMath::ATan2(modelPosition[0], modelPosition[2]);
		const Mathematics::FloatMatrix orient{ Mathematics::Float::g_UnitY, angle };

		auto transform = GetWorldTransform();
		const auto rotate = transform.GetRotate() * orient;
		transform.SetRotate(rotate);
		SetWorldTransformOnUpdate(transform);
    }

	// ���ڵĹ���Ʒ�����Ը����ӽڵ���и��¡� 
	return ParentType::UpdateImplWorldData(applicationTime); 
}


 
#include STSTEM_WARNING_POP
 