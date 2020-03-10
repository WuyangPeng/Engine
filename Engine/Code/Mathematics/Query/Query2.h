// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:33)

#ifndef MATHEMATICS_QUERY_QUERY2_H
#define MATHEMATICS_QUERY_QUERY2_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query2 : public QueryBase
    {
    public:
        using ClassType = Query2<Real>;
        using ParentType = QueryBase;
        using Vector2D = Vector2D<Real>;
        
    public:
        // 基类处理浮点查询。
        explicit Query2 (const std::vector<Vector2D>& vertices);
        virtual ~Query2 ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
        
		virtual QueryType GetType() const override;
  
        int GetNumVertices () const;
        const Vector2D GetVertice (int index) const;

        // 关于一个点的各种几何对象之间的关系查询。

        // 返回:
        //   LineQueryType::Right, 在线的右侧
        //   LineQueryType::Left, 在线的左侧
        //   LineQueryType::OnLine, 在线上
        virtual LineQueryType ToLine (int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
		virtual LineQueryType ToLine (const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;
        
        // 返回:
        // TriangleQueryType::Outside, 在三角形外
        // TriangleQueryType::Inside, 在三角形内
        // TriangleQueryType::OnTriangle, 在三角形上		
		virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        virtual TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // 返回:
        // CircumcircleQueryType::Outside,在三角形的外接圆外
        // CircumcircleQueryType::Inside, 在三角形的外接圆内
        // CircumcircleQueryType::OnCircumcircle,在三角形的外接圆上
		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        
    private:
        // 输入点
        std::vector<Vector2D> m_Vertices;
    };
    
    using Query2f = Query2<float>;
    using Query2d = Query2<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_H
