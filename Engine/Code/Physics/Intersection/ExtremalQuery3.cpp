// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:35)

#include "Physics/PhysicsExport.h"

#ifdef PHYSICS_EXPORT_TEMPLATE

#ifndef PHYSICS_INCLUDED_EXTREMAL_QUERY3_DETAIL
	#define PHYSICS_INCLUDED_EXTREMAL_QUERY3_DETAIL
#endif // PHYSICS_INCLUDED_EXTREMAL_QUERY3_DETAIL
 
#include "ExtremalQuery3Detail.h" 

namespace Physics
{
	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class ExtremalQuery3<float>;

	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class ExtremalQuery3<double>;
}

#endif // PHYSICS_EXPORT_TEMPLATE
