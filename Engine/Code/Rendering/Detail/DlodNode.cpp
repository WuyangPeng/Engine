///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 11:06)

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
    // 一个DlodNode的子节点数组被压缩
    // 这里没有空的插槽和子节点的数量是m_Child.size()，
    // 另外，假设所有模型的距离值分别设置为这些子节点。

    // 计算世界LOD中心
    const auto worldTransform = GetWorldTransform();

    impl->SetWorldCenter(worldTransform);

    // 计算世界平方距离间隔。
    impl->SetWorldDistance(worldTransform.GetUniformScale());

    // 选择LOD子节点
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
