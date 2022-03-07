// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:19)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h" 

namespace Mathematics
{
	// All functions return 'true' if circle/sphere has been constructed,
	// 'false' otherwise (input points are linearly dependent).
	
	// Circle containing three 3D points.
	template <typename Real> 
	bool Circumscribe (const Vector3<Real>& v0, const Vector3<Real>& v1,const Vector3<Real>& v2, Circle3<Real>& circle);
	
	// Sphere containing four 3D points.
	template <typename Real> 
	bool Circumscribe (const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3,  Sphere3<Real>& sphere);
	
	// Circle inscribing triangle of three 3D points.
	template <typename Real>
	bool Inscribe (const Vector3<Real>& v0, const Vector3<Real>& v1,const Vector3<Real>& v2, Circle3<Real>& circle);
	
	// Sphere inscribing tetrahedron of four 3D points.
	template <typename Real>
	bool Inscribe (const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, Sphere3<Real>& sphere);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H
