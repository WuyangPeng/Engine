// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:33)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3_DETAIL_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3_DETAIL_H

#include "ExtremalQuery3.h"

#if !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_EXTREMAL_QUERY3_DETAIL)

#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
namespace Physics
{
	template <typename Real>
	ExtremalQuery3<Real>::ExtremalQuery3(const ConvexPolyhedron3* polytope)
		:mPolytope(polytope)
	{
		// Create the triangle normals.
		const Vector3D* vertices = mPolytope->GetVertices();
                const int numTriangles = mPolytope->GetNumTriangles();
		const int* indices = mPolytope->GetIndices();
		mFaceNormals = NEW1<Vector3D >(numTriangles);
		for (int i = 0; i < numTriangles; ++i)
		{
			const Vector3D& v0 = vertices[*indices++];
			const Vector3D& v1 = vertices[*indices++];
			const Vector3D& v2 = vertices[*indices++];
                        const Vector3D edge1 = v1 - v0;
                        const Vector3D edge2 = v2 - v0;
			mFaceNormals[i] = Mathematics::Vector3DTools<Real>::UnitCrossProduct(edge1, edge2);
		}
	}

	template <typename Real>
	ExtremalQuery3<Real>::~ExtremalQuery3()
	{
		EXCEPTION_TRY 
		{
             DELETE1(mFaceNormals);
		}
        EXCEPTION_ALL_CATCH(Physics)		
	}

	template <typename Real>
	const Mathematics::ConvexPolyhedron3<Real>* ExtremalQuery3<Real>::GetPolytope() const noexcept
	{
		return mPolytope;
	}

	template <typename Real>
        const Mathematics::Vector3D<Real>* ExtremalQuery3<Real>::GetFaceNormals() const noexcept
	{
		return mFaceNormals;
	}

}
#include STSTEM_WARNING_POP
#endif // !defined(PHYSICS_EXPORT_TEMPLATE) || defined(PHYSICS_INCLUDED_EXTREMAL_QUERY3_DETAIL)

#endif // PHYSICS_INTERSECTION_EXTREMAL_QUERY3_DETAIL_H