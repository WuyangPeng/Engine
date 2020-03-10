// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:35)

#include "Physics/PhysicsExport.h"

#ifdef PHYSICS_EXPORT_TEMPLATE

#ifndef PHYSICS_INCLUDED_EXTREMAL_QUERY3BSP_DETAIL
	#define PHYSICS_INCLUDED_EXTREMAL_QUERY3BSP_DETAIL
#endif // PHYSICS_INCLUDED_EXTREMAL_QUERY3BSP_DETAIL

#include "ExtremalQuery3BSPDetail.h" 

namespace Physics
{
	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class ExtremalQuery3BSP<float>;

	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class ExtremalQuery3BSP<double>;
}

#endif // PHYSICS_EXPORT_TEMPLATE
