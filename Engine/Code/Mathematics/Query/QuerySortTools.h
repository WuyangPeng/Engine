///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 15:30)

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
        QuerySortTools(int value0, int value1);
        QuerySortTools(int value0, int value1, int value2);
        QuerySortTools(int value0, int value1, int value2, int value3);

        CLASS_INVARIANT_DECLARE;

        // ֧������һ����ص�����������ء�
        // ����Ᵽ֤��v0 < v1 < v2��
        // ����������֤һ�µĲ�ѯʱ��ԭʼ���������û���
        // ��ʹ�ñ�Ҫ�ĸ�������ʱ������ֵ������
        // ������������Ϊ����������
        // �������Ҫô�������������ڼ䷢��ż����λ��
        // ��������������ڼ䷢��������λ����
        // �ú�����������ķ��ţ���������ʾһ����������͡�����Ϊ��������
        [[nodiscard]] NumericalValueSymbol GetSymbol() const noexcept;
        [[nodiscard]] int GetValue(int index) const;

    private:
        IMPL_TYPE_DECLARE(QuerySortTools);
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H
