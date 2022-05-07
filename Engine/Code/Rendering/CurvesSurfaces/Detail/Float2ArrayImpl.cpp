///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:26)

#include "Rendering/RenderingExport.h"

#include "Float2ArrayImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

Rendering::Float2ArrayImpl::Float2ArrayImpl(const Float2Vector& elements)
    : elements{ elements }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Float2ArrayImpl::Float2ArrayImpl() noexcept
    : elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Float2ArrayImpl)

void Rendering::Float2ArrayImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregateContainer(elements);
}

void Rendering::Float2ArrayImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregateContainerWithNumber(elements);
}

int Rendering::Float2ArrayImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return MATHEMATICS_STREAM_SIZE(elements);
}

int Rendering::Float2ArrayImpl::GetNumElements() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(elements.size());
}

const Rendering::Float2ArrayImpl::Float2* Rendering::Float2ArrayImpl::GetData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return elements.data();
}

const Rendering::Float2ArrayImpl::Float2& Rendering::Float2ArrayImpl::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(elements.size()), "无效索引！\n");

    return elements.at(index);
}

Rendering::Float2ArrayImpl::Float2& Rendering::Float2ArrayImpl::operator[](int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Float2, index);
}
