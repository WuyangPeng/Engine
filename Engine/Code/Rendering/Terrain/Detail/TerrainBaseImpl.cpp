/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:44)

#include "Rendering/RenderingExport.h"

#include "TerrainBaseImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::TerrainBaseImpl::TerrainBaseImpl() noexcept
    : numRows{ 0 },
      numColumns{ 0 },
      size{ 0 },
      minElevation{ 0.0f },
      maxElevation{ 0.0f },
      spacing{ 0.0f },
      length{ 0.0f },
      cameraRow{ std::numeric_limits<int>::max() },
      cameraColumn{ std::numeric_limits<int>::max() },
      camera{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TerrainBaseImpl::TerrainBaseImpl(int numRows, int numColumns, int size, float minElevation, float maxElevation, float spacing, const CameraSharedPtr& camera)
    : numRows{ numRows },
      numColumns{ numColumns },
      size{ size },
      minElevation{ minElevation },
      maxElevation{ maxElevation },
      spacing{ spacing },
      length{ spacing * (static_cast<float>(size) - 1.0f) },
      cameraRow{ std::numeric_limits<int>::max() },
      cameraColumn{ std::numeric_limits<int>::max() },
      camera{ camera }
{
    Check();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::TerrainBaseImpl::Check() const
{
    RENDERING_ASSERTION_0(0 < numRows && 0 < numColumns, "无效的行数或列数。");
    RENDERING_ASSERTION_0(size == 3 || size == 5 || size == 9 || size == 17 || size == 33 || size == 65 || size == 129, "无效的页面大小。");
    RENDERING_ASSERTION_0(minElevation <= maxElevation, "高程极值排序无效。");
    RENDERING_ASSERTION_0(spacing > 0.0f, "间距必须为正。");
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TerrainBaseImpl)

int Rendering::TerrainBaseImpl::GetNumRows() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numRows;
}

int Rendering::TerrainBaseImpl::GetNumColumns() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numColumns;
}

int Rendering::TerrainBaseImpl::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return size;
}

float Rendering::TerrainBaseImpl::GetMinElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minElevation;
}

float Rendering::TerrainBaseImpl::GetMaxElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maxElevation;
}

float Rendering::TerrainBaseImpl::GetSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return spacing;
}

float Rendering::TerrainBaseImpl::GetLength() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return length;
}

Rendering::CameraSharedPtr Rendering::TerrainBaseImpl::GetCamera()
{
    RENDERING_CLASS_IS_VALID_9;

    if (camera.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("camera指针为空。"))
    }

    return camera.object;
}

int Rendering::TerrainBaseImpl::GetCameraRow() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraRow;
}

int Rendering::TerrainBaseImpl::GetCameraColumn() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraColumn;
}

void Rendering::TerrainBaseImpl::SetCameraRow(int aCameraRow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    cameraRow = aCameraRow;
}

void Rendering::TerrainBaseImpl::SetCameraColumn(int aCameraColumn) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    cameraColumn = aCameraColumn;
}

int Rendering::TerrainBaseImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto streamingSize = CoreTools::GetStreamSize(numRows);

    streamingSize += CoreTools::GetStreamSize(numColumns);
    streamingSize += CoreTools::GetStreamSize(size);
    streamingSize += CoreTools::GetStreamSize(minElevation);
    streamingSize += CoreTools::GetStreamSize(maxElevation);
    streamingSize += CoreTools::GetStreamSize(spacing);
    streamingSize += CoreTools::GetStreamSize(length);
    streamingSize += CoreTools::GetStreamSize(cameraRow);
    streamingSize += CoreTools::GetStreamSize(cameraColumn);
    streamingSize += GetStreamSize(camera);

    return streamingSize;
}

void Rendering::TerrainBaseImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(numRows);
    target.Write(numColumns);
    target.Write(size);
    target.Write(minElevation);
    target.Write(maxElevation);
    target.Write(spacing);
    target.Write(length);
    target.Write(cameraRow);
    target.Write(cameraColumn);
    target.WriteObjectAssociated(camera);
}

void Rendering::TerrainBaseImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(numRows);
    source.Read(numColumns);
    source.Read(size);
    source.Read(minElevation);
    source.Read(maxElevation);
    source.Read(spacing);
    source.Read(length);
    source.Read(cameraRow);
    source.Read(cameraColumn);
    source.ReadObjectAssociated(camera);

    Check();
}

void Rendering::TerrainBaseImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(camera);
}

void Rendering::TerrainBaseImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(camera);
}

CoreTools::ObjectSharedPtr Rendering::TerrainBaseImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (camera.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("camera指针为空。"))
    }

    return camera->GetObjectByName(name);
}

Rendering::TerrainBaseImpl::ObjectSharedPtrContainer Rendering::TerrainBaseImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (camera.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("camera指针为空。"))
    }

    return camera->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::TerrainBaseImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (camera.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("camera指针为空。"))
    }

    return camera->GetConstObjectByName(name);
}

Rendering::TerrainBaseImpl::ConstObjectSharedPtrContainer Rendering::TerrainBaseImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (camera.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("camera指针为空。"))
    }

    return camera->GetAllConstObjectsByName(name);
}