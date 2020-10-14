// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:44)

#include "Rendering/RenderingExport.h"

#include "Node.h"
#include "Detail/NodeImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Node);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Node);

Rendering::Node ::Node()
    : ParentType{}, m_Impl{}
{
    m_Impl = make_shared<ImplType>(this);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node ::~Node()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node ::Node(const Node& rhs)
    : ParentType(rhs), m_Impl{}
{
    m_Impl = make_shared<ImplType>(this);

   const int count = rhs.GetNumChildren();

    for (auto index = 0; index < count; ++index)
    {
        auto original = rhs.GetConstChild(index);

        SpatialSharedPtr controller = boost::polymorphic_pointer_cast<Spatial>(original->Clone());
        //.PolymorphicCastObjectSharedPtr<SpatialSharedPtr>()

        controller->SetParent(nullptr);

         AttachChild(controller);
    }   

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node& Rendering::Node ::operator=(const Node& rhs)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(rhs);

   const auto count = rhs.GetNumChildren();

    for (auto index = 0; index < count; ++index)
    {
        auto original = rhs.GetConstChild(index);

        SpatialSharedPtr controller{ boost::polymorphic_pointer_cast<Spatial>(original->Clone())  };

        controller->SetParent(nullptr);
        AttachChild(controller);
    }

    return *this;
}

Rendering::Node ::Node(Node&& rhs) noexcept
    : ParentType(std::move(rhs)), m_Impl{ std::move(rhs.m_Impl) }
{
    

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node& Rendering::Node ::operator=(Node&& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(std::move(rhs));

     m_Impl = std::move(rhs.m_Impl);

    return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Node)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Node, GetNumChildren, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, AttachChild, SpatialSharedPtr , int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Node, DetachChild, SpatialSharedPtr, int)
    IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, DetachChildAt, int, Rendering::SpatialSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, GetChild, int, Rendering::SpatialSharedPtr)

bool Rendering::Node ::UpdateWorldData(double applicationTime)
{
    auto result = ParentType::UpdateWorldData(applicationTime);

    if (m_Impl->UpdateWorldData(applicationTime))
    {
        result = true;
    }

    return result;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, GetConstChild, int, Rendering::ConstSpatialSharedPtr)

void Rendering::Node ::UpdateWorldBound()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (!GetWorldBoundIsCurrent())
    {
       const auto bound = m_Impl->GetWorldBound();
        BoundGrowToContain(bound);
    }
}

void Rendering::Node ::GetVisibleSet(Culler& culler, bool noCull)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetVisibleSet(culler, noCull);
}

Rendering::Node ::Node(LoadConstructor value)
    : ParentType{ value }, m_Impl{}
{
    m_Impl = std::make_shared<ImplType>(this);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Node ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += m_Impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::Node ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

const    auto uniqueID = ParentType::Register(target);
    if (uniqueID != 0)
    {
        m_Impl->Register(target);
    }

    return uniqueID;
}

void Rendering::Node ::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    m_Impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Node ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::Link(source);

    m_Impl->Link(source);
}

void Rendering::Node ::PostLink()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::PostLink();
}

void Rendering::Node ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    m_Impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::Node::ControllerInterfaceSharedPtr Rendering::Node ::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

const Rendering::PickRecordContainer Rendering::Node ::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    PickRecordContainer container;

    if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
    {
        for (auto i = 0; i < GetNumChildren(); ++i)
        {
            auto child = GetConstChild(i);
            if (child)
            {
                auto childContainer = child->ExecuteRecursive(origin, direction, tMin, tMax);

                container.InsertPickRecord(childContainer);
            }
        }
    }

    return container;
}

bool Rendering::Node ::UpdateImplWorldData(double applicationTime)
{
    return m_Impl->UpdateWorldData(applicationTime);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Node::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP