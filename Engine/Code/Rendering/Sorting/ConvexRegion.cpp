// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:39)

#include "Rendering/RenderingExport.h"

#include "ConvexRegion.h"
#include "Portal.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegion);

Rendering::ConvexRegion ::ConvexRegion(int numPortals, Portal** portals)
    : mNumPortals(numPortals), mPortals(portals), mVisited(false)
{
}

Rendering::ConvexRegion ::~ConvexRegion()
{
    EXCEPTION_TRY
    {
        for (int i = 0; i < mNumPortals; ++i)
        {
          //  DELETE0(mPortals[i]);
        }
        //DELETE1(mPortals);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

bool Rendering::ConvexRegion ::UpdateWorldData(double applicationTime)
{
    // Update the region walls and contained objects.
    const bool result = Node::UpdateWorldData(applicationTime);

    // Update the portal geometry.
    for (int i = 0; i < mNumPortals; ++i)
    {
        mPortals[i]->UpdateWorldData(GetWorldTransform());
    }

    return result;
}

void Rendering::ConvexRegion ::GetVisibleSet(Culler& culler, bool noCull)
{
    if (!mVisited)
    {
        mVisited = true;

        // Add anything visible through open portals.
        for (int i = 0; i < mNumPortals; ++i)
        {
            mPortals[i]->GetVisibleSet(culler, noCull);
        }

        // Add the region walls and contained objects.
        Node::GetVisibleSet(culler, noCull);

        mVisited = false;
    }
}

// Name support.
CoreTools::ObjectSharedPtr Rendering::ConvexRegion ::GetObjectByName(const std::string& name)
{
    CoreTools::ObjectSharedPtr found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }
    for (int i = 0; i < mNumPortals; ++i)
    {
        found = mPortals[i]->GetObjectByName(name);
        if (found)
        {
            return found;
        }
    }
    return CoreTools::ObjectSharedPtr();
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::ConvexRegion ::GetAllObjectsByName(const std::string& name)
{
    std::vector<CoreTools::ObjectSharedPtr> objects = ParentType::GetAllObjectsByName(name);

    for (int i = 0; i < mNumPortals; ++i)
    {
        std::vector<CoreTools::ObjectSharedPtr> pointerObjects = mPortals[i]->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::ConvexRegion ::GetConstObjectByName(const std::string& name) const
{
    CoreTools::ConstObjectSharedPtr found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (int i = 0; i < mNumPortals; ++i)
    {
        found = mPortals[i]->GetObjectByName(name);
        if (found)
        {
            return found;
        }
    }

    return CoreTools::ConstObjectSharedPtr();
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ConvexRegion ::GetAllConstObjectsByName(const std::string& name) const
{
    std::vector<CoreTools::ConstObjectSharedPtr> objects = ParentType::GetAllConstObjectsByName(name);

    for (int i = 0; i < mNumPortals; ++i)
    {
        std::vector<CoreTools::ConstObjectSharedPtr> pointerObjects = mPortals[i]->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

// Streaming support.

Rendering::ConvexRegion ::ConvexRegion(LoadConstructor value)
    : Node(value), mNumPortals(0), mPortals(0), mVisited(false)
{
}

void Rendering::ConvexRegion ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    // source.ReadSharedPtr(mNumPortals, mPortals);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::ConvexRegion ::Link(CoreTools::ObjectLink& source)
{
    Node::Link(source);

    //  source.ResolveObjectLink(mNumPortals, mPortals);
}

void Rendering::ConvexRegion ::PostLink()
{
    Node::PostLink();
}

uint64_t Rendering::ConvexRegion ::Register(CoreTools::ObjectRegister& target) const
{
    if (Node::Register(target))
    {
        //    target.Register(mNumPortals, mPortals);
        return true;
    }
    return false;
}

void Rendering::ConvexRegion ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

    // target.WritePointerWithNumber(mNumPortals, mPortals);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::ConvexRegion ::GetStreamingSize() const
{
    int size = Node::GetStreamingSize();
    size += sizeof(mNumPortals);
    size += mNumPortals * CORE_TOOLS_STREAM_SIZE(mPortals[0]);
    return size;
}

int Rendering::ConvexRegion ::GetNumPortals() const noexcept
{
    return mNumPortals;
}

Rendering::Portal* Rendering::ConvexRegion ::GetPortal(int i) const noexcept
{
    return mPortals[i];
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ConvexRegion::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP