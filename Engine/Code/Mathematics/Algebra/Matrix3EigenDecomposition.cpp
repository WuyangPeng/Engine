///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 18:36)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE
        #define MATHEMATICS_INCLUDED_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_MATRIX3_EIGEN_DECOMPOSITION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Matrix3Detail.h"
#include "Matrix3EigenDecompositionDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Matrix3EigenDecomposition<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Matrix3EigenDecomposition<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
