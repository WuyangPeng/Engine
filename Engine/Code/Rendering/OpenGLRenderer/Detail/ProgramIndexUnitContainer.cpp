///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.3 (2024/01/09 09:29)

#include "Rendering/RenderingExport.h"

#include "ProgramIndexUnitContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ProgramIndexUnitContainer::ProgramIndexUnitContainer() noexcept
    : linkContainer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramIndexUnitContainer)

int Rendering::ProgramIndexUnitContainer::AcquireUnit(OpenGLUInt program, OpenGLInt index)
{
    RENDERING_CLASS_IS_VALID_9;

    auto availUnit = -1;
    auto unit = 0;
    for (auto& item : linkContainer)
    {
        /// 如果已分配并正在使用，是否增加链接计数？
        if (program == item.GetProgram() && index == item.GetIndex())
        {
            item.AddLinkCount();
            return unit;
        }

        /// 找到一个以前使用过但现在可用的单元。
        if (item.GetLinkCount() == 0)
        {
            if (availUnit == -1)
            {
                availUnit = unit;
            }
        }

        ++unit;
    }

    /// 以前没有使用过的新单元号？
    if (availUnit == -1)
    {
        /// 请考虑查询最大单元数，并检查是否未超过此数。
        availUnit = boost::numeric_cast<int>(linkContainer.size());
        linkContainer.emplace_back(1, program, index);
    }

    auto& item = linkContainer.at(availUnit);
    item.SetLinkCount(1);
    item.SetProgram(program);
    item.SetIndex(index);

    return availUnit;
}

int Rendering::ProgramIndexUnitContainer::GetUnit(OpenGLUInt program, OpenGLInt index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto unit = 0;
    for (auto& item : linkContainer)
    {
        if (program == item.GetProgram() && index == item.GetIndex())
        {
            return unit;
        }

        ++unit;
    }

    return -1;
}

void Rendering::ProgramIndexUnitContainer::ReleaseUnit(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (index < boost::numeric_cast<int>(linkContainer.size()))
    {
        if (auto& item = linkContainer.at(index);
            0 < item.GetLinkCount())
        {
            item.ReduceLinkCount();
        }
    }
}

int Rendering::ProgramIndexUnitContainer::GetUnitLinkCount(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (unit < boost::numeric_cast<int>(linkContainer.size()))
    {
        return linkContainer.at(unit).GetLinkCount();
    }

    return 0;
}

Rendering::LinkInfo Rendering::ProgramIndexUnitContainer::GetUnitProgramIndex(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (unit < boost::numeric_cast<int>(linkContainer.size()))
    {
        if (auto& item = linkContainer.at(unit);
            0 < item.GetLinkCount())
        {
            return LinkInfo{ 1, item.GetProgram(), item.GetIndex() };
        }
    }

    return LinkInfo{};
}
