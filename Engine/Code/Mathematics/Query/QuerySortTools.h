// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:45)

#ifndef MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H
#define MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h" 

MATHEMATICS_EXPORT_SHARED_PTR(QuerySortToolsImpl);

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE QuerySortTools
    {
    public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(QuerySortTools);

	public:
		QuerySortTools(int firstValue, int secondValue);
		QuerySortTools(int firstValue, int secondValue,int thirdValue);
		QuerySortTools(int firstValue, int secondValue,int thirdValue,int fourthValue);

		CLASS_INVARIANT_DECLARE;
        
        // ֧������һ����ص�����������ء�
        // ����Ᵽ֤��v0 < v1 < v2��
        // ����������֤һ�µĲ�ѯʱ��ԭʼ���������û���
        // ��ʹ�ñ�Ҫ�ĸ�������ʱ������ֵ������
        // ������������Ϊ����������
        // �������Ҫô�������������ڼ䷢��ż����λ��
        // ��������������ڼ䷢��������λ����
        // �ú�����������ķ��ţ���������ʾһ����������͡�����Ϊ��������
		NumericalValueSymbol GetSymbol() const;
		int GetValue(int index) const;

	private:
		IMPL_TYPE_DECLARE(QuerySortTools);
    };
}

#endif // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H
