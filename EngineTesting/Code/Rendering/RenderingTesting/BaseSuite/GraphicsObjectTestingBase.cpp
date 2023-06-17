///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:07)

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
    ASSERT_LESS_EQUAL_FAILURE_THROW(beginIndex, boost::numeric_cast<int>(buffer.size()), "��������С�����ڴ���GraphicsObject��");

    auto saveFileBuffer = std::make_shared<FileBuffer>(boost::numeric_cast<int>(buffer.size()));
    saveFileBuffer->CopyBuffer(buffer.begin() + beginIndex, buffer.end());

    return saveFileBuffer;
}