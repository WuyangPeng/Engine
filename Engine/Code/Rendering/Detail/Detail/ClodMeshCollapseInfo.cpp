///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:52)

#include "Rendering/RenderingExport.h"

#include "ClodMeshCollapseInfo.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ClodMeshCollapseInfo::ClodMeshCollapseInfo(int vKeep, int vThrow) noexcept
    : vKeepInfo{ vKeep }, vThrowInfo{ vThrow }, tThrow0Info{ -1 }, tThrow1Info{ -1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshCollapseInfo)

int Rendering::ClodMeshCollapseInfo::GetVKeep() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vKeepInfo;
}

void Rendering::ClodMeshCollapseInfo::SetVKeep(int vKeep) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vKeepInfo = vKeep;
}

int Rendering::ClodMeshCollapseInfo::GetVThrow() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vThrowInfo;
}

void Rendering::ClodMeshCollapseInfo::SetVThrow(int vThrow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vThrowInfo = vThrow;
}

int Rendering::ClodMeshCollapseInfo::GetTThrow0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return tThrow0Info;
}

void Rendering::ClodMeshCollapseInfo::SetTThrow0(int tThrow0) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    tThrow0Info = tThrow0;
}

int Rendering::ClodMeshCollapseInfo::GetTThrow1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return tThrow1Info;
}

void Rendering::ClodMeshCollapseInfo::SetTThrow1(int tThrow1) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    tThrow1Info = tThrow1;
}
