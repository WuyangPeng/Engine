///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:07)

#include "GraphicsObjectTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::GraphicsObjectTestingBase::GraphicsObjectTestingBase(const OStreamShared& stream, GraphicsObjectType beginGraphicsObjectType, GraphicsObjectType endGraphicsObjectType, const std::string& graphicsObjectName)
    : ParentType{ stream }, beginGraphicsObjectType{ beginGraphicsObjectType }, endGraphicsObjectType{ endGraphicsObjectType }, graphicsObjectName{ graphicsObjectName }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GraphicsObjectTestingBase)

Rendering::GraphicsObjectType Rendering::GraphicsObjectTestingBase::GetGraphicsObjectType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return beginGraphicsObjectType;
}

std::string Rendering::GraphicsObjectTestingBase::GetGraphicsObjectName() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return graphicsObjectName;
}

CoreTools::FileBufferSharedPtr Rendering::GraphicsObjectTestingBase::CorrectFileBuffer(int beginIndex, const OriginalBuffer& buffer)
{
    ASSERT_LESS_EQUAL_FAILURE_THROW(beginIndex, boost::numeric_cast<int>(buffer.size()), "缓冲区大小不足于创建GraphicsObject。");

    auto saveFileBuffer = std::make_shared<FileBuffer>(boost::numeric_cast<int>(buffer.size()));
    saveFileBuffer->CopyBuffer(buffer.begin() + beginIndex, buffer.end());

    return saveFileBuffer;
}