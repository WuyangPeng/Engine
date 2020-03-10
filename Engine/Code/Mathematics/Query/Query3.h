// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:37)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Query3 : public QueryBase
	{
	public:
		using ClassType = Query3<Real>;
		using ParentType = QueryBase;
		using Vector3D = Vector3D<Real>;

	public:
		// 基类处理浮点查询。
		explicit Query3(const std::vector<Vector3D>& vertices);
		virtual ~Query3();
 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE; 

		virtual QueryType GetType() const override;

		int GetNumVertices() const;
		const Vector3D GetVertice(int index) const;

		// 关于一个点的各种几何对象之间的关系查询。

		// 返回:		
		// PlaneQueryType::PositiveSide, 在平面的正面 
		// PlaneQueryType::NegativeSide, 在平面的负面 
		// PlaneQueryType::OnPlane, 在平面上
		virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
		virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const;

		// 返回:		
		// TetrahedronQueryType::Outside, 四面体外  
		// TetrahedronQueryType::Inside, 四面体内
		// TetrahedronQueryType::OnTetrahedron,在四面体上
		virtual TetrahedronQueryType ToTetrahedron(int index, int v0,int v1, int v2, int v3) const;
		virtual TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0,int v1, int v2, int v3) const;

		// 返回:
		// Returns:
		// CircumsphereQueryType::Outside, 在四面体的外切球外 
		// CircumsphereQueryType::Inside,在四面体的外切球内
		// CircumsphereQueryType::OnCircumsphere, 在四面体的外切球上
		virtual CircumsphereQueryType ToCircumsphere(int index, int v0,int v1, int v2, int v3) const;
		virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0,int v1, int v2, int v3) const;

	private:
		// 输入点
		std::vector<Vector3D> m_Vertices;
	};

	using Query3f = Query3<float>;
	using Query3d = Query3<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_H
