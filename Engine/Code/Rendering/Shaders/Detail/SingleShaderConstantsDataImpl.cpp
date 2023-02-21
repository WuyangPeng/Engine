///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 14:43)

#include "Rendering/RenderingExport.h"

#include "SingleShaderConstantsDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;

Rendering::SingleShaderConstantsDataImpl::SingleShaderConstantsDataImpl(const string& name, int numRegistersUsed)
    : name{ name }, numRegistersUsed{ numRegistersUsed }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderConstantsDataImpl::SingleShaderConstantsDataImpl() noexcept
    : name{}, numRegistersUsed{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::SingleShaderConstantsDataImpl::IsValid() const noexcept
{
    if (0 <= numRegistersUsed)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::SingleShaderConstantsDataImpl::SetConstant(const std::string& aName, int aNumRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    name = aName;
    numRegistersUsed = aNumRegistersUsed;
}

string Rendering::SingleShaderConstantsDataImpl::GetConstantName() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return name;
}

int Rendering::SingleShaderConstantsDataImpl::GetNumRegistersUsed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numRegistersUsed;
}

void Rendering::SingleShaderConstantsDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    name = source.ReadString();
    source.Read(numRegistersUsed);
}

void Rendering::SingleShaderConstantsDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(name);
    target.Write(numRegistersUsed);
}

int Rendering::SingleShaderConstantsDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(name);
    size += CoreTools::GetStreamSize(numRegistersUsed);

    return size;
}
