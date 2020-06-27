// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:00)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_INTERSECTOR_UTILITY3_DETAIL
	#define MATHEMATICS_INCLUDED_INTERSECTOR_UTILITY3_DETAIL
#endif // MATHEMATICS_INCLUDED_INTERSECTOR_UTILITY3_DETAIL

#include "IntersectorUtility3Detail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	void ClipConvexPolygonAgainstPlane<float>(const Vector3D<float>&, float, int&, Vector3D<float>*);

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	Vector3D<float> GetPointFromIndex<float>(int, const Box3<float>&);

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	void ClipConvexPolygonAgainstPlane<double>(const Vector3D<double>&, double, int&, Vector3D<double>*);

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	Vector3D<double> GetPointFromIndex<double>(int, const Box3<double>&);
}

#endif // MATHEMATICS_EXPORT_TEMPLATE