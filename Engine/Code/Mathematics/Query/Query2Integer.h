// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:35)

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
   
        // ���붥�����ɲ��ֱ��ض�Ϊ32λ������
        // ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
        // ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
        explicit Query2Integer (const std::vector<Vector2D>& vertices);
        virtual ~Query2Integer ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual QueryType GetType() const override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ�Ĳ�ѯ��
		virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		
		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex,int mhsVerticesIndex, int rhsVerticesIndex) const override;
        
    };

    using Query2Integerf = Query2Integer<float>;
    using Query2Integerd = Query2Integer<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_INTEGER_H
