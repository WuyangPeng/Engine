// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:40)

#include "Rendering/RenderingExport.h"

#include "ConvexRegionManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegionManager);  
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ConvexRegionManager);

Rendering::ConvexRegionManager
	::ConvexRegionManager ()
{
}

Rendering::ConvexRegionManager
	::ConvexRegionManager(const Mathematics::Planef& modelPlane)
    :BspNode(modelPlane)
{
}

Rendering::ConvexRegionManager
	::~ConvexRegionManager ()
{
}

Rendering::SpatialSmartPointer Rendering::ConvexRegionManager
	::AttachOutside(SpatialSmartPointer outside)
{
 
	 AttachChild(outside);	
	 return outside;
   // return SetChild(1, outside);
}

Rendering::SpatialSmartPointer Rendering::ConvexRegionManager
	::DetachOutside()
{
    return DetachChildAt(1);
}

Rendering::SpatialSmartPointer Rendering::ConvexRegionManager
	::GetOutside()
{
    return GetChild(1);
}

Rendering::ConvexRegionSmartPointer Rendering::ConvexRegionManager
	::GetContainingRegion(const  Mathematics::APointf& point)
{
	return 	GetContainingNode(point).PolymorphicCastObjectSmartPointer<ConvexRegionSmartPointer>();
}

void Rendering::ConvexRegionManager
	::GetVisibleSet (Culler& culler, bool noCull)
{
	ConvexRegionSmartPointer region = GetContainingRegion(culler.GetCamera()->GetPosition());

    if (region.IsValidPtr())
    {
        // Accumulate visible objects starting in the region containing the
        // camera.  Use the CRMCuller to maintain a list of unique objects.
        //pkRegion->GetVisibleSet(m_kCuller,bNoCull);
        mCuller.SetCamera(culler.GetCamera());
        mCuller.SetFrustum(culler.GetFrustum());
        mCuller.ComputeVisibleSet(region);

        // Copy the unique list to the scene culler.
		 
        const int numVisible = mCuller.GetNumVisible();
        for (int i = 0; i < numVisible; ++i)
        {
            culler.Insert(mCuller.GetVisible(i));
        } 
    }
    else
    {
        // The camera is outside the set of regions.  Accumulate visible
        // objects for the outside scene (if it exists).
        if (GetOutside().IsValidPtr())
        {
            GetOutside()->GetVisibleSet(culler, noCull);
        }
    }
}

