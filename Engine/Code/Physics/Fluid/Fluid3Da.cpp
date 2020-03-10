// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 16:33)

#include "Physics/PhysicsExport.h"

#ifdef PHYSICS_EXPORT_TEMPLATE

#ifndef PHYSICS_INCLUDED_FLUID3DA_DETAIL
	#define PHYSICS_INCLUDED_FLUID3DA_DETAIL
#endif // PHYSICS_INCLUDED_FLUID3DA_DETAIL

#include "Fluid3DaDetail.h" 

namespace Physics
{
	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class Fluid3Da<float>;

	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class Fluid3Da<double>;
}

#endif // PHYSICS_EXPORT_TEMPLATE
