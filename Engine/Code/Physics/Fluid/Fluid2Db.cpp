// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 16:33)

#include "Physics/PhysicsExport.h"

#ifdef PHYSICS_EXPORT_TEMPLATE

#ifndef PHYSICS_INCLUDED_FLUID2DB_DETAIL
	#define PHYSICS_INCLUDED_FLUID2DB_DETAIL
#endif // PHYSICS_INCLUDED_FLUID2DB_DETAIL

#include "Fluid2DbDetail.h" 

namespace Physics
{
	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class Fluid2Db<float>;

	template PHYSICS_TEMPLATE_DEFAULT_DECLARE
	class Fluid2Db<double>;
}

#endif // PHYSICS_EXPORT_TEMPLATE
