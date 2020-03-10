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
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h" 

CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegion);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegion);

Rendering::ConvexRegion
	::ConvexRegion (int numPortals, Portal** portals)
    :mNumPortals(numPortals),mPortals(portals),mVisited(false)
{
}

Rendering::ConvexRegion
	::~ConvexRegion ()
{
    for (int i = 0; i < mNumPortals; ++i)
    {
        DELETE0(mPortals[i]);
    }
    DELETE1(mPortals);
}

bool Rendering::ConvexRegion
	::UpdateWorldData (double applicationTime)
{
    // Update the region walls and contained objects.
	bool result = Node::UpdateWorldData(applicationTime);

    // Update the portal geometry.
    for (int i = 0; i < mNumPortals; ++i)
    {
        mPortals[i]->UpdateWorldData(GetWorldTransform());
    }

	return result;
}

void Rendering::ConvexRegion
	::GetVisibleSet (Culler& culler, bool noCull)
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
const CoreTools::ObjectSmartPointer Rendering::ConvexRegion
	:: GetObjectByName(const std::string& name)
{
	CoreTools::ObjectSmartPointer found = ParentType::GetObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}
	for (int i = 0; i < mNumPortals; ++i)
	{
	 
		found = mPortals[i]->GetObjectByName(name);
		if (found.IsValidPtr())
		{
			return found;
		}
	} 
	return CoreTools::ObjectSmartPointer();
}

const std::vector<CoreTools::ObjectSmartPointer> Rendering::ConvexRegion
	::GetAllObjectsByName(const std::string& name)
{
	std::vector<CoreTools::ObjectSmartPointer> objects = ParentType::GetAllObjectsByName(name);

	for (int i = 0; i < mNumPortals; ++i)
	{
		std::vector<CoreTools::ObjectSmartPointer> pointerObjects = mPortals[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}
	


	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::ConvexRegion
	::GetConstObjectByName(const std::string& name) const
{
	CoreTools::ConstObjectSmartPointer found = ParentType::GetConstObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}

	for (int i = 0; i < mNumPortals; ++i)
	{

		found = mPortals[i]->GetObjectByName(name);
		if (found.IsValidPtr())
		{
			return found;
		}
	}


	return CoreTools::ConstObjectSmartPointer();
}

const std::vector<CoreTools::ConstObjectSmartPointer> Rendering::ConvexRegion
	::GetAllConstObjectsByName(const std::string& name) const
{
	std::vector<CoreTools::ConstObjectSmartPointer> objects = ParentType::GetAllConstObjectsByName(name);

 

	for (int i = 0; i < mNumPortals; ++i)
	{
		std::vector<CoreTools::ConstObjectSmartPointer> pointerObjects = mPortals[i]->GetAllConstObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;
} 

// Streaming support.

Rendering::ConvexRegion
	::ConvexRegion (LoadConstructor value)
    :Node(value),mNumPortals(0),mPortals(0),mVisited(false)
{
}

void Rendering::ConvexRegion
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    // source.ReadSmartPointer(mNumPortals, mPortals);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::ConvexRegion
	::Link(CoreTools::ObjectLink& source)
{
    Node::Link(source);

    source.ResolveObjectLink(mNumPortals, mPortals);
}

void Rendering::ConvexRegion
	::PostLink ()
{
    Node::PostLink();
}

uint64_t Rendering::ConvexRegion
	::Register(CoreTools::ObjectRegister& target) const
{
    if (Node::Register(target))
    {
        target.Register(mNumPortals, mPortals);
        return true;
    }
    return false;
}

void Rendering::ConvexRegion
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

    target.WritePointerWithNumber(mNumPortals, mPortals);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::ConvexRegion
	::GetStreamingSize () const
{
    int size = Node::GetStreamingSize();
    size += sizeof(mNumPortals);
	size += mNumPortals*CORE_TOOLS_STREAM_SIZE(mPortals[0]);
    return size;
}


 int Rendering::ConvexRegion
	 ::GetNumPortals () const
{
	return mNumPortals;
}

 Rendering::Portal* Rendering::ConvexRegion
	 ::GetPortal (int i) const
{
	return mPortals[i];
}

