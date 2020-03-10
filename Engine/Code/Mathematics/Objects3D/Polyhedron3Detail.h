// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:05)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_DETAIL_H

#include "Polyhedron3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Polyhedron3<Real>
	::Polyhedron3( int numVertices, Vector3DPtr vertices,int numTriangles,IntPtr indices )
	:m_NumVertices{ numVertices }, m_Vertices{ vertices }, m_NumTriangles{ numTriangles },
	 m_NumIndices{ numTriangles * 3 }, m_Indices{ indices }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::Polyhedron3<Real>
	::~Polyhedron3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polyhedron3<Real>
	::IsValid() const noexcept
{
	if (4 <= m_NumVertices && m_Vertices != nullptr &&
		4 <= m_NumTriangles && m_NumIndices == m_NumTriangles * 3 &&
		m_Indices != nullptr && IndicesIsValid())
	{
		return true;
	}	    
	else
	{
		return false;
	}		
}

template <typename Real>
bool Mathematics::Polyhedron3<Real>
	::IndicesIsValid() const noexcept
{
	for(auto i = 0;i < m_NumIndices;++i)
	{
		if (m_Indices[i] < 0 || m_NumVertices <= m_Indices[i])
		{
			return false;
		}			
	}

	return true;
}

#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polyhedron3<Real>
	::GetNumVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	return m_NumVertices;
}


template <typename Real>
typename const Mathematics::Polyhedron3<Real>::Vector3DPtr Mathematics::Polyhedron3<Real>
	::GetVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	return m_Vertices;
}


template <typename Real>
const typename Mathematics::Polyhedron3<Real>::Vector3D& Mathematics::Polyhedron3<Real>
	::GetVertex( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_NumVertices,"À˜“˝¥ÌŒÛ£°");

	return m_Vertices[index];
}


template <typename Real>
int Mathematics::Polyhedron3<Real>
	::GetNumTriangles() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_NumTriangles;
}


template <typename Real>
int Mathematics::Polyhedron3<Real>
	::GetNumIndices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	return m_NumIndices;
}


template <typename Real>
typename const Mathematics::Polyhedron3<Real>::IntPtr Mathematics::Polyhedron3<Real>
	::GetIndices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	return m_Indices;
}


template <typename Real>
const int* Mathematics::Polyhedron3<Real>
	::GetTriangle( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_NumTriangles,"À˜“˝¥ÌŒÛ‘⁄GetTriangle£°");

	return &m_Indices[3 * index];
}


template <typename Real>
void Mathematics::Polyhedron3<Real>
	::SetVertex( int index, const Vector3D& vertex )
{
	MATHEMATICS_CLASS_IS_VALID_3;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_NumVertices,"À˜“˝¥ÌŒÛ‘⁄SetVertex£°");

	m_Vertices[index] = vertex;
}


template <typename Real>
typename const Mathematics::Polyhedron3<Real>::Vector3D Mathematics::Polyhedron3<Real>
	::ComputeVertexAverage() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	auto average = m_Vertices[0];
	for (auto i = 1; i < m_NumVertices; ++i)
	{
		average += m_Vertices[i];
	}
	average /= boost::numeric_cast<Real>(m_NumVertices);

	return average;
}

template <typename Real>
Real Mathematics::Polyhedron3<Real>
	::ComputeSurfaceArea() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	Real surfaceArea { };

	for (auto i = 0; i < m_NumTriangles; ++i)
	{
		auto v0 = m_Indices[i * 3];
		auto v1 = m_Indices[i * 3 + 1];
		auto v2 = m_Indices[i * 3 + 2];
		auto edge0 = m_Vertices[v1] - m_Vertices[v0];
		auto edge1 = m_Vertices[v2] - m_Vertices[v0];
		auto cross = Vector3DTools::CrossProduct(edge0,edge1);
		surfaceArea += Vector3DTools::VectorMagnitude(cross);
	}

	surfaceArea *= static_cast<Real>(0.5);

	return surfaceArea;
}


template <typename Real>
Real Mathematics::Polyhedron3<Real>
	::ComputeVolume() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	Real volume { };

	for (auto i = 0; i < m_NumTriangles; ++i)
	{
		auto v0 = m_Indices[i * 3];
		auto v1 = m_Indices[i * 3 + 1];
		auto v2 = m_Indices[i * 3 + 2];

		auto cross = Vector3DTools::CrossProduct(m_Vertices[v1],m_Vertices[v2]);

		volume += Vector3DTools::DotProduct(m_Vertices[v0],cross);
	}

	volume /= static_cast<Real>(6.0);

	return volume;
}


#endif // MATHEMATICS_OBJECTS3D_POLYHEDRON3_DETAIL_H


