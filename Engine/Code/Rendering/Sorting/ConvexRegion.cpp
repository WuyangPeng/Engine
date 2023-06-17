///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:28)

#include "Rendering/RenderingExport.h"

#include "ConvexRegion.h"
#include "Portal.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegion);

Rendering::ConvexRegion::ConvexRegion(int numPortals, const std::vector<CoreTools::ObjectAssociated<Portal>>& portals)
    : ParentType{ NodeCreate::Init }, numPortals{ numPortals }, portals{ portals }, visited{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ConvexRegion)

bool Rendering::ConvexRegion::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto result = ParentType::UpdateWorldData(applicationTime);

    for (auto i = 0; i < numPortals; ++i)
    {
        portals.at(i)->UpdateWorldData(GetWorldTransform());
    }

    return result;
}

void Rendering::ConvexRegion::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!visited)
    {
        visited = true;

        for (auto i = 0; i < numPortals; ++i)
        {
            portals.at(i)->GetVisibleSet(culler, noCull);
        }

        ParentType::GetVisibleSet(culler, noCull);

        visited = false;
    }
}

CoreTools::ObjectSharedPtr Rendering::ConvexRegion::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }
    for (auto i = 0; i < numPortals; ++i)
    {
        found = portals.at(i)->GetObjectByName(name);
        if (found)
        {
            return found;
        }
    }
    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::ConvexRegion::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllObjectsByName(name);

    for (auto i = 0; i < numPortals; ++i)
    {
        auto pointerObjects = portals.at(i)->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::ConvexRegion::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto i = 0; i < numPortals; ++i)
    {
        found = portals.at(i).object->GetObjectByName(name);
        if (found)
        {
            return found;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ConvexRegion::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    for (int i = 0; i < numPortals; ++i)
    {
        auto pointerObjects = portals.at(i)->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

Rendering::ConvexRegion::ConvexRegion(LoadConstructor value)
    : ParentType{ value }, numPortals{ 0 }, portals{ 0 }, visited{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::ConvexRegion::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadObjectAssociatedContainer(portals);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::ConvexRegion::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    source.ResolveLinkContainer(portals);
}

void Rendering::ConvexRegion::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::ConvexRegion::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (ParentType::Register(target))
    {
        target.RegisterContainer(portals);
        return true;
    }
    return false;
}

void Rendering::ConvexRegion::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteObjectAssociatedContainerWithNumber(portals);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::ConvexRegion::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(numPortals);
    size += numPortals * CoreTools::GetStreamSize(portals.at(0));
    return size;
}

int Rendering::ConvexRegion::GetNumPortals() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPortals;
}

Rendering::PortalSharedPtr Rendering::ConvexRegion::GetPortal(int i) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return portals.at(i).object;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ConvexRegion::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
