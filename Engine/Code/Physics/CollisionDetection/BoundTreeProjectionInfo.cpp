// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:58)

#include "Physics/PhysicsExport.h"

#include "BoundTreeProjectionInfo.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::BoundTreeProjectionInfo
	::BoundTreeProjectionInfo(int triangle, float projection) noexcept
	:m_Triangle(triangle), m_Projection(projection)
{
	PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics,BoundTreeProjectionInfo)

int Physics::BoundTreeProjectionInfo ::GetTriangle() const noexcept
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return m_Triangle;
}

float Physics::BoundTreeProjectionInfo ::GetProjection() const noexcept
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return m_Projection;
}

bool Physics
	::operator<(const BoundTreeProjectionInfo& lhs, const BoundTreeProjectionInfo& rhs) noexcept
{
	return lhs.GetProjection() < rhs.GetProjection();
}

