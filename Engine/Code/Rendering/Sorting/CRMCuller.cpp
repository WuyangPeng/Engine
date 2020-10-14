// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:43)

#include "Rendering/RenderingExport.h"

#include "CRMCuller.h" 

#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
 #include SYSTEM_WARNING_DISABLE(26455)
Rendering::CRMCuller
	::CRMCuller(const ConstCameraSharedPtr& camera )  
    :Culler(camera)
{
}

 

void Rendering::CRMCuller
	::Insert(const VisualSharedPtr& visible)
{
    if (mUnique.find(visible) == mUnique.end())
    {
        // The object was not in the set of unique objects, so insert it.
        Culler::Insert(visible);
    }
}

#include STSTEM_WARNING_POP