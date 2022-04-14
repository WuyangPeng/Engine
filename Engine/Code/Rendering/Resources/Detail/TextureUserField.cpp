///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 20:17)

#include "Rendering/RenderingExport.h"

#include "TextureUserField.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::TextureUserField::TextureUserField() noexcept
    : userFields{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TextureUserField)

void Rendering::TextureUserField::SetUserField(int index, int32_t userField)
{
    RENDERING_CLASS_IS_VALID_9;

    userFields.at(index) = userField;
}

int32_t Rendering::TextureUserField::GetUserField(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return userFields.at(index);
}

void Rendering::TextureUserField::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadContainer(userFields);
}

void Rendering::TextureUserField::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainer(userFields);
}

int Rendering::TextureUserField::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return TextureMaxUserFields * CORE_TOOLS_STREAM_SIZE(userFields.at(0));
}

void Rendering::TextureUserField::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    outFile.Write(sizeof(int32_t), TextureMaxUserFields, userFields.data());
}

void Rendering::TextureUserField::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    inFile.Read(sizeof(int32_t), TextureMaxUserFields, userFields.data());
}
