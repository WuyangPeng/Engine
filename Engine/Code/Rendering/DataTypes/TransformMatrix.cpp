///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 16:55)

#include "Rendering/RenderingExport.h"

#include "TransformMatrixDetail.h"

#ifdef RENDERING_TEMPLATE_TEST

namespace Rendering
{
    template class TransformMatrix<float>;
    template class TransformMatrix<double>;
}

#endif  // RENDERING_TEMPLATE_TEST
