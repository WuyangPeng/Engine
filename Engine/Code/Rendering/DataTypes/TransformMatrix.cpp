///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:57)

#include "Rendering/RenderingExport.h"

#include "TransformMatrixDetail.h"

#ifdef RENDERING_TEMPLATE_TEST

namespace Rendering
{
    template class TransformMatrix<float>;
    template class TransformMatrix<double>;
}

#endif  // RENDERING_TEMPLATE_TEST
