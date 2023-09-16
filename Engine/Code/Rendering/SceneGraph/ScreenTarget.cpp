///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:18)

#include "Rendering/RenderingExport.h"

#include "Camera.h"
#include "ScreenTarget.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::CameraSharedPtr Rendering::ScreenTarget::CreateCamera()
{
    // ���������ӳ��  (x,y,z)  [0,1]^3 �� (x',y,'z') ��
    // [-1,1]^2 x [0,1].
    auto camera = std::make_shared<Camera>(false, true);
    camera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    camera->SetFrame(Mathematics::APointF::GetOrigin(), Mathematics::AVectorF::GetUnitZ(), Mathematics::AVectorF::GetUnitY(), Mathematics::AVectorF::GetUnitX());

    return camera;
}

Rendering::TrianglesMeshSharedPtr Rendering::ScreenTarget::CreateRectangle(const VertexFormatSharedPtr& vertexFormat,
                                                                           int renderTargetWidth,
                                                                           int renderTargetHeight,
                                                                           float xMin,
                                                                           float xMax,
                                                                           float yMin,
                                                                           float yMax,
                                                                           MAYBE_UNUSED float zValue)
{
    if (ValidFormat(*vertexFormat) && ValidSizes(renderTargetWidth, renderTargetHeight))
    {
        const auto vstride = vertexFormat->GetStride();
        auto vertexBuffer = VertexBuffer::Create(*vertexFormat, vstride);

        const auto dx = 0.5f * (xMax - xMin) / static_cast<float>(renderTargetWidth - 1);
        const auto dy = 0.5f * (yMax - yMin) / static_cast<float>(renderTargetHeight - 1);
        xMin -= dx;
        xMax -= dx;
        yMin += dy;
        yMax += dy;

        // ���������ε�����������
        auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, 6, boost::numeric_cast<int>(sizeof(int)));
        InitIndexBufferInParticles(*indexBuffer);

        return std::make_shared<TrianglesMesh>(vertexFormat, vertexBuffer, indexBuffer);
    }

    return nullptr;
}

void Rendering::ScreenTarget::InitIndexBufferInParticles(IndexBuffer& indexBuffer)
{
    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "������Сֻ��Ϊ2��4��");

    const auto numVertices = indexBuffer.GetNumElements();
    const auto numParticles = numVertices / 6;

    if (indexSize == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numParticles; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include SYSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (auto i = 0; i < numParticles; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include SYSTEM_WARNING_POP
            }
        }
    }
}

// private
bool Rendering::ScreenTarget::ValidSizes(int renderTargetWidth, int renderTargetHeight)
{
    if (0 < renderTargetWidth && 0 < renderTargetHeight)
    {
        return true;
    }

    RENDERING_ASSERTION_0(false, "��Ч��ά�ȡ�\n");

    return false;
}

// private
bool Rendering::ScreenTarget::ValidFormat(const VertexFormat& vertexFormat)
{
    auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Position, 0);
    if (index < 0)
    {
        RENDERING_ASSERTION_1(false, "��ʽ����ӵ��λ����Ϣ��\n");
        return false;
    }

    if (vertexFormat.GetAttributeType(index) != DataFormatType::R32G32B32Float)
    {
        RENDERING_ASSERTION_1(false, "λ�ñ�����3Ԫ�顣\n");
        return false;
    }

    index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::TextureCoord, 0);
    if (index < 0)
    {
        RENDERING_ASSERTION_1(false, "��ʽ����ӵ�����������ڵ�Ԫ0��\n");
        return false;
    }

    if (vertexFormat.GetAttributeType(index) != DataFormatType::R32G32Float)
    {
        RENDERING_ASSERTION_1(false, "���������ڵ�Ԫ0������2Ԫ�顣\n");
        return false;
    }

    return true;
}

std::vector<Rendering::ScreenTarget::APoint> Rendering::ScreenTarget::CreatePositions(int renderTargetWidth, int renderTargetHeight, float xMin, float xMax, float yMin, float yMax, float zValue)
{
    std::vector<APoint> positions{};

    if (ValidSizes(renderTargetWidth, renderTargetHeight))
    {
        const auto dx = 0.5f * (xMax - xMin) / boost::numeric_cast<float>(renderTargetWidth - 1);
        const auto dy = 0.5f * (yMax - yMin) / boost::numeric_cast<float>(renderTargetHeight - 1);
        xMin -= dx;
        xMax -= dx;
        yMin += dy;
        yMax += dy;

        positions.emplace_back(xMin, yMin, zValue);
        positions.emplace_back(xMax, yMin, zValue);
        positions.emplace_back(xMax, yMax, zValue);
        positions.emplace_back(xMin, yMax, zValue);
    }

    RENDERING_ASSERTION_1(positions.size() == 0 || positions.size() == 4, "���ص������С����");

    return positions;
}

std::vector<Rendering::ScreenTarget::Vector2D> Rendering::ScreenTarget::CreateTextureCoords()
{
    std::vector<Vector2D> textureCoords{};

    textureCoords.emplace_back(0.0f, 0.0f);
    textureCoords.emplace_back(1.0f, 0.0f);
    textureCoords.emplace_back(1.0f, 1.0f);
    textureCoords.emplace_back(0.0f, 1.0f);

    RENDERING_ASSERTION_1(textureCoords.size() == 4, "���ص������С����");

    return textureCoords;
}
