///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:30)

#include "Rendering/RenderingExport.h"

#include "TextureSingle.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureSingle);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureSingle);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, TextureSingle);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TextureSingle);

Rendering::TextureSingle::TextureSingle(int numElements, int elementSize, GraphicsObjectType type)
    : ParentType{ numElements, elementSize, type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureSingle::TextureSingle(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ numElements, elementSize, storage, type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureSingle)

int Rendering::TextureSingle::GetOffsetFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetLevelOffset(0, level);
}

Rendering::TextureSingle::ConstSpanIterator Rendering::TextureSingle::GetDataForSingle(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetDataFor(0, level);
}

Rendering::TextureSingle::SpanIterator Rendering::TextureSingle::GetDataForSingle(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return ParentType::GetDataFor(0, level);
}