///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:47)

#include "Rendering/RenderingExport.h"

#include "Projector.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Projector);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Projector);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Projector);

Rendering::Projector::Projector(DepthType depthType, bool isPerspective, float epsilon)
    : ParentType{ isPerspective, epsilon }
{
    // 覆盖Camera构造函数设定的深度类型。
    SetDepthType(depthType);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Projector)

Rendering::Projector::Projector(LoadConstructor value)
    : ParentType{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Projector::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(DepthType{});

    return size;
}

int64_t Rendering::Projector::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Projector::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteEnum(GetDepthType());

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Projector::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Projector::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Projector::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    auto depthType = DepthType::Quantity;
    source.ReadEnum(depthType);
    SetDepthType(depthType);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::Projector::Matrix Rendering::Projector::GetBiasScaleMatrix(int index)
{
    static std::array<Matrix, 2> biasScaleMatrix{ Matrix{ 0.5f, 0.0f, 0.0f, 0.5f,
                                                          0.0f, -0.5f, 0.0f, 0.5f,
                                                          0.0f, 0.0f, 1.0f, 0.0f,
                                                          0.0f, 0.0f, 0.0f, 1.0f },

                                                  Matrix{ 0.5f, 0.0f, 0.0f, 0.5f,
                                                          0.0f, +0.5f, 0.0f, 0.5f,
                                                          0.0f, 0.0f, 1.0f, 0.0f,
                                                          0.0f, 0.0f, 0.0f, 1.0f } };

    RENDERING_ASSERTION_0(index == 0 || index == 1, "索引错误！");

    return biasScaleMatrix.at(index);
}
