// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 09:52)

#ifndef MATHEMATICS_QUERY_QUERY3_INT64_H
#define MATHEMATICS_QUERY_QUERY3_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"

namespace Mathematics
{
	template <typename Real>
	class Query3Int64 : public Query3<Real>
	{
	public:
		using ClassType = Query3Int64<Real>;
		using ParentType = Query3<Real>;
		using Vector3D = typename ParentType::Vector3D; 

	public:
		// 输入顶点的组成部分被截断为64位整数，
		// 所以你应该确保顶点是足够大的分配好的数值。
		explicit Query3Int64(const std::vector<Vector3D>& vertices);
		 ~Query3Int64();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// 运行时类型信息。
		 QueryType GetType() const override;

		 PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		 PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

		 CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
		 CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;
	};

	using Query3Int64f = Query3Int64<float>;
	using Query3Int64d = Query3Int64<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_INT64_H
