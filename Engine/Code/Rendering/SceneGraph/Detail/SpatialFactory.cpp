///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.2 (2023/12/07 11:02)

#include "Rendering/RenderingExport.h"

#include "NullSpatialImpl.h"
#include "ParentSpatialImpl.h"
#include "SpatialFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SpatialFactory::SpatialSharedPtr Rendering::SpatialFactory::Create(CullingMode cullingMode, bool isNull)
{
    if (isNull)
    {
        return std::make_shared<NullSpatialImpl>(cullingMode);
    }
    else
    {
        return std::make_shared<ParentSpatialImpl>(cullingMode);
    }
}
