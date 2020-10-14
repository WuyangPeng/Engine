// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:40)

#include "Rendering/RenderingExport.h"

#include "ConvexRegionManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"

#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
 #include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455) 
CORE_TOOLS_RTTI_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConvexRegionManager);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConvexRegionManager);  
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ConvexRegionManager);

Rendering::ConvexRegionManager
	::ConvexRegionManager ()
{
}

Rendering::ConvexRegionManager
	::ConvexRegionManager(const Mathematics::FloatPlane& modelPlane)
    :BspNode(modelPlane)
{
}

 

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager
	::AttachOutside(SpatialSharedPtr outside)
{
 
	 AttachChild(outside);	
	 return outside;
   // return SetChild(1, outside);
}

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager
	::DetachOutside()
{
    return DetachChildAt(1);
}

Rendering::SpatialSharedPtr Rendering::ConvexRegionManager
	::GetOutside()
{
    return GetChild(1);
}

Rendering::ConvexRegionSharedPtr Rendering::ConvexRegionManager
	::GetContainingRegion(const  Mathematics::FloatAPoint& point)
{
    return boost::polymorphic_pointer_cast<ConvexRegion>(GetContainingNode(point));
}

void Rendering::ConvexRegionManager
	::GetVisibleSet (Culler& culler, bool noCull)
{
	ConvexRegionSharedPtr region = GetContainingRegion(culler.GetCamera()->GetPosition());

    if (region )
    {
        // Accumulate visible objects starting in the region containing the
        // camera.  Use the CRMCuller to maintain a list of unique objects.
        //pkRegion->GetVisibleSet(m_kCuller,bNoCull);
        mCuller.SetCamera(culler.GetCamera());
        mCuller.SetFrustum(culler.GetFrustum());
        mCuller.ComputeVisibleSet(region);

        // Copy the unique list to the scene culler.
 
        for (auto& value : mCuller)
        {
            culler.Insert(value);
        } 
    }
    else
    {
        // The camera is outside the set of regions.  Accumulate visible
        // objects for the outside scene (if it exists).
        if (GetOutside() )
        {
            GetOutside()->GetVisibleSet(culler, noCull);
        }
    }
}

#include STSTEM_WARNING_POP