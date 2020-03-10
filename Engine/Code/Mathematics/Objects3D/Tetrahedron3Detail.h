// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 10:14)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_DETAIL_H

#include "Tetrahedron3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Tetrahedron3<Real>
	::Tetrahedron3( const Vector3D& fristVertex, const Vector3D& secondVertex,const Vector3D& thirdVertex, const Vector3D& fourthVertex )
{
	m_Vertex[0] = fristVertex;
	m_Vertex[1] = secondVertex;
	m_Vertex[2] = thirdVertex;
	m_Vertex[3] = fourthVertex;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


template <typename Real>
Mathematics::Tetrahedron3<Real>
	::Tetrahedron3( const std::vector<Vector3D> vertex )
{
	MATHEMATICS_ASSERTION_0(vertex.size() == 4,"输入的数组大小错误！");

	for (auto i = 0;i < 4;++i)
	{
		m_Vertex[i] = vertex[i];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Tetrahedron3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::Tetrahedron3<Real>::Vector3D Mathematics::Tetrahedron3<Real>
	::GetVertex( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 4,"索引错误！");

	return m_Vertex[index];
}


template <typename Real>
void Mathematics::Tetrahedron3<Real>
	::SetVertex(int index, const Vector3D& vertex)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 4, "索引错误！");

	m_Vertex[index] = vertex;
}


// static
template <typename Real>
std::vector<int> Mathematics::Tetrahedron3<Real>
	::GetFaceIndices( int face )
{
	MATHEMATICS_ASSERTION_0(0 <= face && face <= 3,"索引错误！");

	std::vector<int> index;

	switch(face)
	{
	case 0:
		index.push_back(0);
		index.push_back(2);
		index.push_back(1);
		break;
	case 1:
		index.push_back(0);
		index.push_back(1);
		index.push_back(3);
		break;
	case 2:
		index.push_back(0);
		index.push_back(3);
		index.push_back(2);
		break;
	default: // face == 3 
		index.push_back(1);
		index.push_back(2);
		index.push_back(3);
		break;
	}

	MATHEMATICS_ASSERTION_1(index.size() == 3,"返回的数组大小错误！");

	return index;
}


template <typename Real>
const std::vector<typename Mathematics::Tetrahedron3<Real>::Plane3> Mathematics::Tetrahedron3<Real>
	::GetPlanes() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto edge10 = m_Vertex[1] - m_Vertex[0];
	auto edge20 = m_Vertex[2] - m_Vertex[0];
	auto edge30 = m_Vertex[3] - m_Vertex[0];
	auto edge21 = m_Vertex[2] - m_Vertex[1];
	auto edge31 = m_Vertex[3] - m_Vertex[1];

	Vector3D normal[4];

	normal[0] = Vector3DTools::UnitCrossProduct(edge20,edge10);  // <v0,v2,v1>
	normal[1] = Vector3DTools::UnitCrossProduct(edge10,edge30);  // <v0,v1,v3>
	normal[2] = Vector3DTools::UnitCrossProduct(edge30,edge20);  // <v0,v3,v2>
	normal[3] = Vector3DTools::UnitCrossProduct(edge21,edge31);  // <v1,v2,v3>

	auto det = Vector3DTools::DotProduct(edge10,normal[3]);
	if (det < Real{})
	{
		// 法线是指向内部点，改变他们的方向。
		for (auto i = 0; i < 4; ++i)
		{
			normal[i] = -normal[i];
		}
	}

	std::vector<Plane3> planeVector;

	for (auto i = 0; i < 4; ++i)
	{
		planeVector.emplace_back(normal[i], m_Vertex[i]);
	}

	MATHEMATICS_ASSERTION_1(planeVector.size() == 4,"返回的面大小错误！");

	return planeVector;
}


#endif // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_DETAIL_H
