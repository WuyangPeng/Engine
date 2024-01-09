///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.3 (2024/01/09 09:17)

#include "Rendering/RenderingExport.h"

#include "LinkInfo.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::LinkInfo::LinkInfo() noexcept
    : linkCount{ 0 }, program{ 0 }, index{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::LinkInfo::LinkInfo(int linkCount, OpenGLUInt program, OpenGLInt index) noexcept
    : linkCount{ linkCount }, program{ program }, index{ index }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LinkInfo)

int Rendering::LinkInfo::GetLinkCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return linkCount;
}

Rendering::LinkInfo::OpenGLUInt Rendering::LinkInfo::GetProgram() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program;
}

Rendering::LinkInfo::OpenGLInt Rendering::LinkInfo::GetIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return index;
}

void Rendering::LinkInfo::SetLinkCount(int aLinkCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    linkCount = aLinkCount;
}

void Rendering::LinkInfo::SetProgram(OpenGLUInt aProgram) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    program = aProgram;
}

void Rendering::LinkInfo::SetIndex(OpenGLInt aIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    index = aIndex;
}

void Rendering::LinkInfo::AddLinkCount() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    ++linkCount;
}

void Rendering::LinkInfo::ReduceLinkCount() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    --linkCount;
}
