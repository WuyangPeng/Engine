// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:33)

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
        // ���ദ�����ѯ��
        explicit Query2 (const std::vector<Vector2D>& vertices);
        virtual ~Query2 ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
        
		virtual QueryType GetType() const override;
  
        int GetNumVertices () const;
        const Vector2D GetVertice (int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        //   LineQueryType::Right, ���ߵ��Ҳ�
        //   LineQueryType::Left, ���ߵ����
        //   LineQueryType::OnLine, ������
        virtual LineQueryType ToLine (int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
		virtual LineQueryType ToLine (const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;
        
        // ����:
        // TriangleQueryType::Outside, ����������
        // TriangleQueryType::Inside, ����������
        // TriangleQueryType::OnTriangle, ����������		
		virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        virtual TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // CircumcircleQueryType::Outside,�������ε����Բ��
        // CircumcircleQueryType::Inside, �������ε����Բ��
        // CircumcircleQueryType::OnCircumcircle,�������ε����Բ��
		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        
    private:
        // �����
        std::vector<Vector2D> m_Vertices;
    };
    
    using Query2f = Query2<float>;
    using Query2d = Query2<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_H
