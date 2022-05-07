///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 11:06)

#include "Rendering/RenderingExport.h"

#include "DlodNode.h"
#include "Detail/DlodNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DlodNode)

CORE_TOOLS_RTTI_DEFINE(Rendering, DlodNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DlodNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DlodNode);

Rendering::DlodNode::DlodNode(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, DlodNode)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, DlodNode)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, DlodNode)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, DlodNode)

Rendering::DlodNode::DlodNode(int numLevelsOfDetail)
    : ParentType{ NodeCreate::Init }, impl{ numLevelsOfDetail }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DlodNode)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode, GetModelCenter, Rendering::DlodNode::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode, GetWorldCenter, Rendering::DlodNode::APoint)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, DlodNode, SetModelCenter, APoint, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DlodNode, GetNumLevelsOfDetail, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode, GetModelMinDistance, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode, GetModelMaxDistance, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode, GetWorldMinDistance, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DlodNode, GetWorldMaxDistance, int, float)

void Rendering::DlodNode::SetModelDistance(int index, float minDistance, float maxDistance)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetModelDistance(index, minDistance, maxDistance);
}

void Rendering::DlodNode::GetVisibleSet(Culler& culler, bool noCull)
{
    SelectLevelOfDetail(*culler.GetCamera());

    ParentType::GetVisibleSet(culler, noCull);
}

void Rendering::DlodNode::SelectLevelOfDetail(const Camera& camera)
{
    // һ��DlodNode���ӽڵ����鱻ѹ��
    // ����û�пյĲ�ۺ��ӽڵ��������m_Child.size()��
    // ���⣬��������ģ�͵ľ���ֵ�ֱ�����Ϊ��Щ�ӽڵ㡣

    // ��������LOD����
    const auto worldTransform = GetWorldTransform();

    impl->SetWorldCenter(worldTransform);

    // ��������ƽ����������
    impl->SetWorldDistance(worldTransform.GetUniformScale());

    // ѡ��LOD�ӽڵ�
    SetActiveChild(System::EnumCastUnderlying(SwitchNodeType::InvalidChild));
    const auto difference = impl->GetWorldCenter() - camera.GetPosition();
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
