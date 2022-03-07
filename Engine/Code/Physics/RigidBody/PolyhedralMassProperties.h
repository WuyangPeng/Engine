// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:17)

#ifndef PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_H
#define PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"

namespace Physics
{

// The input triangle mesh must represent a polyhedron.  The triangles are
// represented as triples of indices <V0,V1,V2> into the vertex array.
// The index array has numTriangles such triples.  The Boolean value
// bodyCoords is 'true' if you want the inertia tensor to be relative to
// body coordinates, 'false' if you want it in world coordinates.
//
// NOTE:  The code assumes the rigid body has a constant density of 1.  If
// your application assigns a constant density of 'd', then you must multiply
// the output rfMass by 'd' and the output rkInertia by 'd'.

template <typename Real>  
void ComputeMassProperties (const Mathematics::Vector3<Real>* vertices, int numTriangles,
						    const int* indices, bool bodyCoords, Real& mass,
						    Mathematics::Vector3<Real>& center, Mathematics::Matrix3<Real>& inertia);
}

#endif // PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_H
