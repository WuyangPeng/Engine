// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:35)

#ifndef MATHEMATICS_QUERY_QUERY2_INTEGER_H
#define MATHEMATICS_QUERY_QUERY2_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Mathematics/Rational/Integer.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Integer : public Query2<Real>
    {
    public:
        using ClassType = Query2Integer<Real>;
        using ParentType = Query2<Real>;
		using typename ParentType::Vector2D;
		using ParentType::GetNumVertices;
		using ParentType::GetVertice;
        
    public:
   
        // 输入顶点的组成部分被截断为32位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        // 在Integer<N>的N的值被选择足够大，以便确保在函数中算术是正确的。
        explicit Query2Integer (const std::vector<Vector2D>& vertices);
        virtual ~Query2Integer ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual QueryType GetType() const override;

        // 关于一个点的各种几何对象之间的关系的查询。
		virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		
		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const override;
        
    };

    using Query2Integerf = Query2Integer<float>;
    using Query2Integerd = Query2Integer<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_INTEGER_H
