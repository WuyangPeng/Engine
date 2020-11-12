///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 15:03)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_BANDED_MATRIX_ACHIEVE
        #define MATHEMATICS_INCLUDED_BANDED_MATRIX_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "BandedMatrixDetail.h"
#include "VariableMatrixDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class BandedMatrix<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class BandedMatrix<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
