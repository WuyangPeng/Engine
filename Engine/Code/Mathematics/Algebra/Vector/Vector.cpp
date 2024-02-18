/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/25 11:06)

#include "Mathematics/MathematicsExport.h"

#include "Vector2Detail.h"
#include "Vector3Detail.h"
#include "Vector4Detail.h"
#include "VectorDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class Vector<1, float>;
    template class Vector<1, double>;
    template class Vector<2, float>;
    template class Vector<2, double>;
    template class Vector<3, float>;
    template class Vector<3, double>;
    template class Vector<4, float>;
    template class Vector<4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
