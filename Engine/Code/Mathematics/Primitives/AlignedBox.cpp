/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/23 09:19)

#include "Mathematics/MathematicsExport.h"

#include "AlignedBoxDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class AlignedBox<2, float>;
    template class AlignedBox<2, double>;
    template class AlignedBox<3, float>;
    template class AlignedBox<3, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST