///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#include "Rendering/RenderingExport.h"

#include "FloatArrayImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::FloatArrayImpl::FloatArrayImpl(const FloatVector& elements)
    : elements{ elements }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::FloatArrayImpl::FloatArrayImpl() noexcept
    : elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, FloatArrayImpl)

void Rendering::FloatArrayImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    elements = source.ReadVectorNotUseNumber<float>();
}

void Rendering::FloatArrayImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainerWithNumber(elements);
}

int Rendering::FloatArrayImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CoreTools::GetStreamSize(elements);
}

int Rendering::FloatArrayImpl::GetNumElements() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(elements.size());
}

const float* Rendering::FloatArrayImpl::GetData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return elements.data();
}

const float& Rendering::FloatArrayImpl::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(elements.size()), "无效索引！\n");

    return elements.at(index);
}

float& Rendering::FloatArrayImpl::operator[](int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(float, index);
}
