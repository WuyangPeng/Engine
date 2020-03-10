// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:43)

#include "Rendering/RenderingExport.h"

#include "CRMCuller.h" 
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

Rendering::CRMCuller
	::CRMCuller(const ConstCameraSmartPointer& camera )
    :Culler(camera)
{
}

Rendering::CRMCuller
	::~CRMCuller ()
{
}

void Rendering::CRMCuller
	::Insert(const ConstSpatialSmartPointer& visible)
{
    if (mUnique.find(visible) == mUnique.end())
    {
        // The object was not in the set of unique objects, so insert it.
        Culler::Insert(visible);
    }
}

