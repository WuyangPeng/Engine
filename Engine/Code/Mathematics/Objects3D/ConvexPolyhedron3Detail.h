// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:32)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_DETAIL_H

#include "ConvexPolyhedron3.h"
#include "Polyhedron3Detail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>
	::ConvexPolyhedron3(int numVertices, Vector3DPtr vertices, int numTriangles, typename IntPtr indices, PlanePtr planes)
	:ParentType{ numVertices,vertices,numTriangles,indices }, m_Planes{ planes }, m_SharingTriangles{}
{
	InitPlanes();

	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

// private
template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>
	::InitPlanes()
{
	if (m_Planes == nullptr)
	{
		auto numTriangles = this->GetNumTriangles();
		m_Planes = NEW1<Plane3>(numTriangles);

		for (auto i = 0; i < numTriangles; ++i)
		{
			m_SharingTriangles.insert(i);
		}

		UpdatePlanes();
	}
}

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>
::~ConvexPolyhedron3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ConvexPolyhedron3<Real>::PlanePtr Mathematics::ConvexPolyhedron3<Real>
	::GetPlanes() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_1(m_SharingTriangles.empty(), "需要更新平面！");

	return m_Planes;
}

template <typename Real>
typename const Mathematics::ConvexPolyhedron3<Real>::Plane3& Mathematics::ConvexPolyhedron3<Real>
	::GetPlane(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_1(m_SharingTriangles.empty(), "需要更新平面！");
	MATHEMATICS_ASSERTION_0(0 <= index && index < this->GetNumTriangles(), "无效索引在GetPlane\n");

	return m_Planes[index];
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>
	::SetVertex(int index, const Vector3D& vertex)
{
	MATHEMATICS_CLASS_IS_VALID_3;
	MATHEMATICS_ASSERTION_0(0 <= index && index < this->GetNumVertices(), "无效索引在SetVertex\n");

	ParentType::SetVertex(index, vertex);

	// 跟踪面分享的顶点。他们的平面需要在以后更新。
	auto numTriangles = this->GetNumTriangles();
	for (auto j = 0; j < numTriangles; ++j)
	{
		auto indices = this->GetTriangle(j);
		auto v0 = *indices++;
		auto v1 = *indices++;
		auto v2 = *indices++;
		if (index == v0 || index == v1 || index == v2)
		{
			m_SharingTriangles.insert(j);
		}
	}
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>
	::UpdatePlanes()
{
	MATHEMATICS_CLASS_IS_VALID_3;

	if (IsUpdatePlanes())
	{
		auto average = this->ComputeVertexAverage();
		auto numTriangles = this->GetNumTriangles();
		for (auto i = 0; i < numTriangles; ++i)
		{
			UpdatePlane(i, average);
		}

		m_SharingTriangles.clear();
	}
}

// private
template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>
	::UpdatePlane(int index, const Vector3D& average)
{
	auto indices = this->GetIndices();
	auto base = 3 * index;
	auto v0 = indices[base++];
	auto v1 = indices[base++];
	auto v2 = indices[base];

	const auto& vertex0 = this->GetVertex(v0);
	const auto& vertex1 = this->GetVertex(v1);
	const auto& vertex2 = this->GetVertex(v2);

	auto diff = average - vertex0;
	auto edge1 = vertex1 - vertex0;
	auto edge2 = vertex2 - vertex0;
	auto normal = Vector3DTools::CrossProduct(edge2, edge1);
	auto length = Vector3DTools::VectorMagnitude(normal);
	if (Math::sm_ZeroTolerance < length)
	{
		normal /= length;
		auto dot = Vector3DTools::DotProduct(normal, diff);
		MATHEMATICS_ASSERTION_3(Math::sm_Zero <= dot, "点积必须为非负数\n");
		if (dot < Math::sm_Zero)
		{
			normal = -normal;
		}
	}
	else
	{
		// 三角形退化。使用“normal”指向平均值朝向。
		normal = diff;
		normal.Normalize();
	}

	// 平面具有内指向的法线。
	m_Planes[index] = Plane3{ normal,vertex0 };
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>
	::IsUpdatePlanes() const
{
	CLASS_IS_VALID_CONST_3;

	return !m_SharingTriangles.empty();
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>
	::IsConvex(Real threshold) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_1(threshold <= Math::sm_Zero, "threshold必须为负值！");
	MATHEMATICS_ASSERTION_1(m_SharingTriangles.empty(), "需要更新平面！");

	auto maxDistance = -Math::sm_MaxReal;
	auto minDistance = Math::sm_MaxReal;

	for (auto j = 0; j < this->GetNumTriangles(); ++j)
	{
		const auto& plane = m_Planes[j];
		for (auto i = 0; i < this->GetNumVertices(); ++i)
		{
			auto distance = plane.DistanceTo(ParentType::GetVertex(i));

			if (distance < minDistance)
			{
				minDistance = distance;
			}
			if (maxDistance < distance)
			{
				maxDistance = distance;
			}

			if (distance < threshold)
			{
				return false;
			}
		}
	}

	return true;
}


template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>
	::Contains(const Vector3D& point, Real threshold) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_1(threshold <= Math::sm_Zero, "threshold必须为负值！");
	MATHEMATICS_ASSERTION_1(m_SharingTriangles.empty(), "需要更新平面！");

	for (auto i = 0; i < this->GetNumTriangles(); ++i)
	{
		auto distance = m_Planes[i].DistanceTo(point);

		if (distance < threshold)
		{
			return false;
		}
	}

	return true;
}

#endif // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_DETAIL_H

