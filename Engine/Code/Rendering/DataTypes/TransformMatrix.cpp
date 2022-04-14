///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:55)

#include "Rendering/RenderingExport.h"

#include "TransformMatrixDetail.h"

#ifdef RENDERING_TEMPLATE_TEST

namespace Rendering
{
    template class TransformMatrix<float>;
    template class TransformMatrix<double>;
}

#endif  // RENDERING_TEMPLATE_TEST
