///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:08)

#ifndef MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H
#define MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

MATHEMATICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(QuerySortToolsImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE QuerySortTools
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySortTools);

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
        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD int GetValue(int index) const;

    private:
        PackageType impl;
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_H
