///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/24 14:09)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_EIGEN_DECOMPOSITION_ACHIEVE
        #define MATHEMATICS_INCLUDED_EIGEN_DECOMPOSITION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_EIGEN_DECOMPOSITION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "EigenDecompositionDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class EigenDecomposition<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class EigenDecomposition<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE