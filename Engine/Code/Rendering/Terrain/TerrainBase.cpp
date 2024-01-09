/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:53)

#include "Rendering/RenderingExport.h"

#include "TerrainBase.h"
#include "Detail/TerrainBaseImpl.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TerrainBase)

CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainBase)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, TerrainBase)

Rendering::TerrainBase::TerrainBase(const std::string& name,
                                    int numRows,
                                    int numColumns,
                                    int size,
                                    float minElevation,
                                    float maxElevation,
                                    float spacing,
                                    const VertexFormatSharedPtr& vertexFormat,
                                    const CameraSharedPtr& camera)
    : ParentType{ name, NodeCreate::Init },
      impl{ numRows, numColumns, size, minElevation, maxElevation, spacing, camera }
{
    AttachTerrainPage(name, numRows, numColumns, size, minElevation, maxElevation, spacing, vertexFormat, camera);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::TerrainBase::AttachTerrainPage(const std::string& name,
                                               int numRows,
                                               int numCols,
                                               int size,
                                               float minElevation,
                                               float maxElevation,
                                               float spacing,
                                               const VertexFormatSharedPtr& vertexFormat,
                                               const CameraSharedPtr& camera)
{
    const auto index = vertexFormat->GetIndex(VertexFormatFlags::Semantic::Position, 0);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点格式没有Semantic::Position。"))
    }

    if (const auto type = vertexFormat->GetAttributeType(index);
        type != DataFormatType::R32G32B32Float && type != DataFormatType::R32G32B32A32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不支持VertexFormat类型。"))
    }

    if (const auto offset = vertexFormat->GetOffset(index);
        offset != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("VertexFormat偏移量必须为0。"))
    }

    if (camera == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("摄像机必须存在。"))
    }

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto column = 0; column < numCols; ++column)
        {
            Vector2 origin{ static_cast<float>(column) * impl->GetLength(), static_cast<float>(row) * impl->GetLength() };

            AttachChild(std::make_shared<TerrainPage>(name, size, minElevation, maxElevation, spacing, impl->GetLength(), origin, vertexFormat));
        }
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TerrainBase)

int Rendering::TerrainBase::GetNumRows() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumRows();
}

int Rendering::TerrainBase::GetNumColumns() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumColumns();
}

int Rendering::TerrainBase::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

float Rendering::TerrainBase::GetMinElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetMinElevation();
}

float Rendering::TerrainBase::GetMaxElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetMinElevation();
}

float Rendering::TerrainBase::GetSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSpacing();
}

Rendering::TerrainBase::TerrainBase(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TerrainBase::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::TerrainBase::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerId = ParentType::Register(target);
    if (0 < registerId)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::TerrainBase::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TerrainBase::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
    impl->Link(source);
}

void Rendering::TerrainBase::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TerrainBase::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::TerrainBase::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::TerrainBase::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::ConstVisualSharedPtr Rendering::TerrainBase::GetPage(int row, int column) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (impl->GetNumRows() <= row || impl->GetNumColumns() <= column)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetPage的输入无效"))
    }

    const auto child = GetConstChild(column + impl->GetNumColumns() * row);

    return boost::polymorphic_pointer_cast<const Visual>(child);
}

void Rendering::TerrainBase::SetHeights(int row, int column, const HeightsType& heights)
{
    RENDERING_CLASS_IS_VALID_1;

    if (impl->GetNumRows() <= row || impl->GetNumColumns() <= column || boost::numeric_cast<int>(heights.size()) < impl->GetSize() * impl->GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("SetHeights的输入无效"))
    }

    const auto child = GetChild(column + impl->GetNumColumns() * row);

    const auto page = boost::polymorphic_pointer_cast<TerrainPage>(child);

    page->SetHeights(heights);
}

Rendering::TerrainBase::HeightsType Rendering::TerrainBase::GetHeights(int row, int column) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (impl->GetNumRows() <= row || impl->GetNumColumns() <= column)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetHeights的输入无效"))
    }

    const auto child = GetConstChild(column + impl->GetNumColumns() * row);

    const auto page = boost::polymorphic_pointer_cast<const TerrainPage>(child);

    return page->GetHeights();
}

float Rendering::TerrainBase::GetHeight(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto page = GetPage(x, y);
    const auto translate = page->GetLocalTransform().GetTranslate();

    return page->GetHeight(x - translate[0], y - translate[1]);
}

Rendering::TerrainBase::Vector3 Rendering::TerrainBase::GetNormal(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto spacing = impl->GetSpacing();

    const auto xp = x + spacing;
    const auto xm = x - spacing;
    const auto yp = y + spacing;
    const auto ym = y - spacing;

    auto page = GetPage(xp, y);
    auto translate = page->GetLocalTransform().GetTranslate();
    const auto hpz = page->GetHeight(xp - translate[0], y - translate[1]);

    page = GetPage(xm, y);
    translate = page->GetLocalTransform().GetTranslate();
    const auto hmz = page->GetHeight(xm - translate[0], y - translate[1]);

    page = GetPage(x, yp);
    translate = page->GetLocalTransform().GetTranslate();
    const auto hzp = page->GetHeight(x - translate[0], yp - translate[1]);

    page = GetPage(x, ym);
    translate = page->GetLocalTransform().GetTranslate();
    const auto hzm = page->GetHeight(x - translate[0], ym - translate[1]);

    Vector3 normal{ hmz - hpz, hzm - hzp, 1.0f };
    normal.Normalize();

    return normal;
}

void Rendering::TerrainBase::OnCameraMotion()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto camera = impl->GetCamera();
    const auto worldEye = camera->GetPosition();
    const auto modelEye = GetWorldTransform().GetInverseMatrix() * worldEye;
    const auto length = impl->GetLength();

    const auto newCameraColumn = boost::numeric_cast<int>(std::floor(modelEye[0] / length));
    const auto newCameraRow = boost::numeric_cast<int>(std::floor(modelEye[1] / length));
    if (newCameraColumn != impl->GetCameraColumn() || newCameraRow != impl->GetCameraRow())
    {
        impl->SetCameraColumn(newCameraColumn);
        impl->SetCameraRow(newCameraRow);

        const auto numRows = impl->GetNumRows();
        const auto numColumns = impl->GetNumColumns();

        const auto cMinO = impl->GetCameraColumn() - numColumns / 2;
        const auto cMinP = (cMinO + numColumns) % numColumns;
        const auto rMinO = impl->GetCameraRow() - numRows / 2;
        const auto rMinP = (rMinO + numRows) % numRows;

        auto rO = rMinO;
        auto rP = rMinP;
        for (auto row = 0; row < numRows; ++row)
        {
            auto cO = cMinO;
            auto cP = cMinP;
            for (auto col = 0; col < numColumns; ++col)
            {
                const auto child = GetChild(cP + numColumns * rP);
                const auto page = boost::polymorphic_pointer_cast<TerrainPage>(child);
                const auto oldOrigin = page->GetOrigin();

                Mathematics::Vector2 newOrigin{ static_cast<float>(cO) * length, static_cast<float>(rO) * length };
                const Vector3 pageTranslate{ newOrigin[0] - oldOrigin[0],
                                             newOrigin[1] - oldOrigin[1],
                                             page->GetLocalTransform().GetTranslate()[2] };
                page->SetLocalTransformTranslate(APoint{ pageTranslate });

                ++cO;
                if (++cP == numColumns)
                {
                    cP = 0;
                }
            }

            ++rO;
            if (++rP == numRows)
            {
                rP = 0;
            }
        }

        const auto result = Update();
        System::UnusedFunction(result);
    }
}

Rendering::ConstTerrainPageSharedPtr Rendering::TerrainBase::GetPage(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto length = impl->GetLength();
    const auto numColumns = impl->GetNumColumns();
    const auto numRows = impl->GetNumRows();

    auto column = boost::numeric_cast<int>(std::floor(x / length));
    column = (column + numColumns) % numColumns;
    auto row = boost::numeric_cast<int>(std::floor(y / length));
    row = (row + numRows) % numRows;

    const auto child = GetConstChild(column + numColumns * row);

    return boost::polymorphic_pointer_cast<const TerrainPage>(child);
}
