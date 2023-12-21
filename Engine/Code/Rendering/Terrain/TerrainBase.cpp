///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:24)

#include "Rendering/RenderingExport.h"

#include "TerrainBase.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainBase);

Rendering::TerrainBase::TerrainBase(const System::String& heightName, const VertexFormatSharedPtr& vformat, const CameraSharedPtr& camera)
    : ParentType{ "TerrainBase", NodeCreate::Init },
      mode{ 0 },
      vFormat{ vformat },
      numRows{},
      numCols{},
      size{},
      minElevation{},
      maxElevation{},
      spacing{},
      pages{},
      cameraRow{ -1 },
      cameraCol{ -1 },
      camera{ camera }
{
    LoadHeader(heightName);

    pages.resize(numRows, std::vector<CoreTools::ObjectAssociated<TerrainPage>>(numCols));

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            auto heightSuffix = std::to_string(row) + "." + std::to_string(col);
            LoadPage(row, col, heightName, CoreTools::StringConversion::MultiByteConversionStandard(heightSuffix));
        }
    }

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            AttachChild(pages.at(row).at(col).object);
        }
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TerrainBase)

Rendering::TerrainPageSharedPtr Rendering::TerrainBase::GetPage(int row, int col)
{
    RENDERING_CLASS_IS_VALID_1;

    return pages.at(row).at(col).object;
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase::GetCurrentPage(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto invLength = 1.0f / (spacing * boost::numeric_cast<float>(size - 1));

    auto col = boost::numeric_cast<int>(Mathematics::MathF::Floor(x * invLength));
    col %= numCols;
    if (col < 0)
    {
        col += numCols;
    }

    auto row = boost::numeric_cast<int>(Mathematics::MathF::Floor(y * invLength));
    row %= numRows;
    if (row < 0)
    {
        row += numRows;
    }

    return pages.at(row).at(col).object;
}

float Rendering::TerrainBase::GetHeight(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto page = GetCurrentPage(x, y);

    x -= page->GetLocalTransform().GetTranslate()[0];
    y -= page->GetLocalTransform().GetTranslate()[1];

    return page->GetHeight(x, y);
}

Mathematics::AVectorF Rendering::TerrainBase::GetNormal(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto xp = x + spacing;
    const auto xm = x - spacing;
    const auto yp = y + spacing;
    const auto ym = y - spacing;

    auto page = GetCurrentPage(xp, y);
    auto xtmp = xp - page->GetLocalTransform().GetTranslate()[0];
    auto ytmp = y - page->GetLocalTransform().GetTranslate()[1];
    const auto hpz = page->GetHeight(xtmp, ytmp);

    page = GetCurrentPage(xm, y);
    xtmp = xm - page->GetLocalTransform().GetTranslate()[0];
    ytmp = y - page->GetLocalTransform().GetTranslate()[1];
    const auto hmz = page->GetHeight(xtmp, ytmp);

    page = GetCurrentPage(x, yp);
    xtmp = x - page->GetLocalTransform().GetTranslate()[0];
    ytmp = yp - page->GetLocalTransform().GetTranslate()[1];
    const auto hzp = page->GetHeight(xtmp, ytmp);

    page = GetCurrentPage(x, ym);
    xtmp = x - page->GetLocalTransform().GetTranslate()[0];
    ytmp = ym - page->GetLocalTransform().GetTranslate()[1];
    const auto hzm = page->GetHeight(xtmp, ytmp);

    Mathematics::AVectorF normal{ hmz - hpz, hzm - hzp, 1.0f };
    normal.Normalize();
    return normal;
}

void Rendering::TerrainBase::LoadHeader(const System::String& heightName)
{
    RENDERING_CLASS_IS_VALID_1;

    auto fileName = heightName + SYSTEM_TEXT(".wmhf");
    CoreTools::ReadFileManager header{ fileName };

    header.Read(sizeof(int32_t), &numRows);
    header.Read(sizeof(int32_t), &numCols);

    uint16_t headerSize;
    header.Read(sizeof(uint16_t), &headerSize);
    size = headerSize;

    header.Read(sizeof(float), &minElevation);
    header.Read(sizeof(float), &maxElevation);
    header.Read(sizeof(float), &spacing);
}

void Rendering::TerrainBase::LoadPage(int row, int col, const System::String& heightName, const System::String& heightSuffix)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto numHeights = size * size;
    std::vector<uint16_t> heights(numHeights);
    auto fileName = heightName + SYSTEM_TEXT(".") + heightSuffix + SYSTEM_TEXT(".wmhf");
    CoreTools::ReadFileManager heightFile{ fileName };

    if (heightFile.GetFileByteSize() > 0)
    {
        heightFile.Read(sizeof(uint16_t), numHeights, heights.data());
    }

    const auto length = spacing * boost::numeric_cast<float>(size - 1);
    Mathematics::Float2 origin{ col * length, row * length };
    auto page = std::make_shared<TerrainPage>(vFormat.object, size, heights, origin, minElevation, maxElevation, spacing);

    pages.at(row).at(col).object = page;
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase::ReplacePage(int row, int col, const System::String& heightName, const System::String& heightSuffix)
{
    RENDERING_CLASS_IS_VALID_1;

    auto save = pages.at(row).at(col);
    LoadPage(row, col, heightName, heightSuffix);

    return save.object;
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase::ReplacePage(int row, int col, TerrainPageSharedPtr newPage)
{
    RENDERING_CLASS_IS_VALID_1;

    auto save = pages.at(row).at(col);
    pages.at(row).at(col).object = newPage;
    return save.object;
}

void Rendering::TerrainBase::OnCameraMotion()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!camera.object)
    {
        return;
    }

    const auto worldEye = camera->GetPosition();
    const auto worldDir = camera->GetDirectionVector();
    const auto modelEye = GetWorldTransform().GetInverseMatrix() * worldEye;
    const auto modelDir = GetWorldTransform().GetInverseMatrix() * worldDir;

    const auto length = spacing * boost::numeric_cast<float>(size - 1);
    const auto invLength = 1.0f / length;
    const auto newCameraCol = boost::numeric_cast<int>(Mathematics::MathF::Floor(modelEye[0] * invLength));
    const auto newCameraRow = boost::numeric_cast<int>(Mathematics::MathF::Floor(modelEye[1] * invLength));
    if (newCameraCol != cameraCol || newCameraRow != cameraRow)
    {
        cameraCol = newCameraCol;
        cameraRow = newCameraRow;

        const auto cminO = cameraCol - numCols / 2;
        auto cminP = cminO % numCols;
        if (cminP < 0)
        {
            cminP += numCols;
        }

        const auto rminO = cameraRow - numRows / 2;
        auto rminP = rminO % numRows;
        if (rminP < 0)
        {
            rminP += numRows;
        }

        auto rO = rminO;
        auto rP = rminP;
        for (auto row = 0; row < numRows; ++row)
        {
            auto cO = cminO;
            auto cP = cminP;
            for (int col = 0; col < numCols; ++col)
            {
                auto page = pages.at(rP).at(cP);
                auto oldOrigin = page->GetOrigin();
                Mathematics::Float2 newOrigin{ cO * length, rO * length };
                const Mathematics::APointF pageTrn{ newOrigin[0] - oldOrigin[0], newOrigin[1] - oldOrigin[1], page->GetLocalTransform().GetTranslate()[2] };

                page->SetLocalTransformTranslate(pageTrn);

                ++cO;
                if (++cP == numCols)
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
        MAYBE_UNUSED const auto result = Update();
    }
}

CoreTools::ObjectSharedPtr Rendering::TerrainBase::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }
    found = vFormat->GetObjectByName(name);
    if (found)
    {
        return found;
    }
    found = camera->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            found = pages.at(row).at(col)->GetObjectByName(name);
            if (found)
            {
                return found;
            }
        }
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::TerrainBase::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllObjectsByName(name);

    auto pointerObjects = vFormat->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = camera->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            pointerObjects = pages.at(row).at(col)->GetAllObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::TerrainBase::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = vFormat->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }
    found = camera->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            found = pages.at(row).at(col)->GetConstObjectByName(name);
            if (found)
            {
                return found;
            }
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::TerrainBase::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    auto pointerObjects = vFormat->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    pointerObjects = camera->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            pointerObjects = pages.at(row).at(col)->GetAllConstObjectsByName(name);
            objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
        }
    }

    return objects;
}

Rendering::TerrainBase::TerrainBase(LoadConstructor value)
    : ParentType{ value },
      mode{ 0 },
      vFormat{},
      numRows{},
      numCols{},
      size{},
      minElevation{},
      maxElevation{},
      spacing{},
      pages{},
      cameraRow{ 0 },
      cameraCol{ 0 },
      camera{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TerrainBase::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::TerrainBase::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(mode);
    source.Read(numRows);
    source.Read(numCols);
    source.Read(size);
    source.Read(minElevation);
    source.Read(maxElevation);
    source.Read(spacing);
    source.Read(cameraRow);
    source.Read(cameraCol);
    source.ReadObjectAssociated(vFormat);
    source.ReadObjectAssociated(camera);

    pages.resize(numRows, std::vector<CoreTools::ObjectAssociated<TerrainPage>>(numCols));
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            source.ReadObjectAssociated(pages.at(row).at(col));
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TerrainBase::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    source.ResolveLink(vFormat);
    source.ResolveLink(camera);
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            source.ResolveLink(pages.at(row).at(col));
        }
    }
}

void Rendering::TerrainBase::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::TerrainBase::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto id = ParentType::Register(target);
    if (0 < id)
    {
        target.Register(vFormat);
        target.Register(camera);
        for (auto row = 0; row < numRows; ++row)
        {
            for (auto col = 0; col < numCols; ++col)
            {
                target.Register(pages.at(row).at(col));
            }
        }
        return id;
    }
    return id;
}

void Rendering::TerrainBase::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(mode);
    target.Write(numRows);
    target.Write(numCols);
    target.Write(size);
    target.Write(minElevation);
    target.Write(maxElevation);
    target.Write(spacing);
    target.Write(cameraRow);
    target.Write(cameraCol);
    target.WriteObjectAssociated(vFormat);
    target.WriteObjectAssociated(camera);

    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numCols; ++col)
        {
            target.WriteObjectAssociated(pages.at(row).at(col));
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TerrainBase::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto streamingSize = ParentType::GetStreamingSize();

    streamingSize += CoreTools::GetStreamSize(mode);
    streamingSize += CoreTools::GetStreamSize(numRows);
    streamingSize += CoreTools::GetStreamSize(numCols);
    streamingSize += CoreTools::GetStreamSize(streamingSize);
    streamingSize += CoreTools::GetStreamSize(minElevation);
    streamingSize += CoreTools::GetStreamSize(maxElevation);
    streamingSize += CoreTools::GetStreamSize(spacing);
    streamingSize += CoreTools::GetStreamSize(cameraRow);
    streamingSize += CoreTools::GetStreamSize(cameraCol);
    streamingSize += CoreTools::GetStreamSize(vFormat);
    streamingSize += CoreTools::GetStreamSize(camera);
    streamingSize += numRows * numCols * CoreTools::GetStreamSize(pages.at(0).at(0));
    return streamingSize;
}

int Rendering::TerrainBase::GetRowQuantity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numRows;
}

int Rendering::TerrainBase::GetColQuantity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numCols;
}

int Rendering::TerrainBase::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return size;
}

float Rendering::TerrainBase::GetMinElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return minElevation;
}

float Rendering::TerrainBase::GetMaxElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return maxElevation;
}

float Rendering::TerrainBase::GetSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return spacing;
}
