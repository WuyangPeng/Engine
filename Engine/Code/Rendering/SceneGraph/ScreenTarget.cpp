///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:52)

#include "Rendering/RenderingExport.h"

#include "Camera.h"
#include "ScreenTarget.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/Shaders/ShaderManager.h"

using std::vector;

Rendering::CameraSharedPtr Rendering::ScreenTarget::CreateCamera()
{
    // ���������ӳ��  (x,y,z)  [0,1]^3 �� (x',y,'z') ��
    // [-1,1]^2 x [0,1].
    auto camera = std::make_shared<Camera>(false);
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
                                                                           float zValue)
{
    if (ValidFormat(*vertexFormat) && ValidSizes(renderTargetWidth, renderTargetHeight))
    {
        const auto vstride = vertexFormat->GetStride();
        auto vertexBuffer = VertexBuffer::Create(4, vstride);
        VertexBufferAccessor vertexBufferAccessor{ vertexFormat, vertexBuffer };

        if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
        {
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 0, Vector2D{ 0.0f, 0.0f });
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 1, Vector2D{ 1.0f, 0.0f });
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 2, Vector2D{ 1.0f, 1.0f });
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 3, Vector2D{ 0.0f, 1.0f });
        }
        else
        {
            const auto dx = 0.5f * (xMax - xMin) / static_cast<float>(renderTargetWidth - 1);
            const auto dy = 0.5f * (yMax - yMin) / static_cast<float>(renderTargetHeight - 1);
            xMin -= dx;
            xMax -= dx;
            yMin += dy;
            yMax += dy;

            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 0, Vector2D(0.0f, 1.0f));
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 1, Vector2D(1.0f, 1.0f));
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 2, Vector2D(1.0f, 0.0f));
            vertexBuffer->SetTextureCoord(vertexBufferAccessor, 3, Vector2D(0.0f, 0.0f));
        }

        vertexBuffer->SetPosition(vertexBufferAccessor, 0, APoint(xMin, yMin, zValue));
        vertexBuffer->SetPosition(vertexBufferAccessor, 1, APoint(xMax, yMin, zValue));
        vertexBuffer->SetPosition(vertexBufferAccessor, 2, APoint(xMax, yMax, zValue));
        vertexBuffer->SetPosition(vertexBufferAccessor, 3, APoint(xMin, yMax, zValue));

        // ���������ε�����������
        auto indexBuffer = IndexBuffer::Create(6, boost::numeric_cast<int>(sizeof(int)));
        indexBuffer->InitIndexBufferInParticles();

        return std::make_shared<TrianglesMesh>(vertexFormat, vertexBuffer, indexBuffer);
    }

    return nullptr;
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
    auto index = vertexFormat.GetIndex(VertexFormatFlags::AttributeUsage::Position, 0);
    if (index < 0)
    {
        RENDERING_ASSERTION_1(false, "��ʽ����ӵ��λ����Ϣ��\n");
        return false;
    }

    if (vertexFormat.GetAttributeType(index) != VertexFormatFlags::AttributeType::Float3)
    {
        RENDERING_ASSERTION_1(false, "λ�ñ�����3Ԫ�顣\n");
        return false;
    }

    index = vertexFormat.GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, 0);
    if (index < 0)
    {
        RENDERING_ASSERTION_1(false, "��ʽ����ӵ�����������ڵ�Ԫ0��\n");
        return false;
    }

    if (vertexFormat.GetAttributeType(index) != VertexFormatFlags::AttributeType::Float2)
    {
        RENDERING_ASSERTION_1(false, "���������ڵ�Ԫ0������2Ԫ�顣\n");
        return false;
    }

    return true;
}

vector<Rendering::ScreenTarget::APoint> Rendering::ScreenTarget::CreatePositions(int renderTargetWidth, int renderTargetHeight, float xMin, float xMax, float yMin, float yMax, float zValue)
{
    vector<APoint> positions{};

    if (ValidSizes(renderTargetWidth, renderTargetHeight))
    {
        if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
        {
            xMin = 0.0f;
            xMax = 1.0f;
            yMin = 0.0f;
            yMax = 1.0f;
        }
        else
        {
            const auto dx = 0.5f * (xMax - xMin) / boost::numeric_cast<float>(renderTargetWidth - 1);
            const auto dy = 0.5f * (yMax - yMin) / boost::numeric_cast<float>(renderTargetHeight - 1);
            xMin -= dx;
            xMax -= dx;
            yMin += dy;
            yMax += dy;
        }

        positions.emplace_back(xMin, yMin, zValue);
        positions.emplace_back(xMax, yMin, zValue);
        positions.emplace_back(xMax, yMax, zValue);
        positions.emplace_back(xMin, yMax, zValue);
    }

    RENDERING_ASSERTION_1(positions.size() == 0 || positions.size() == 4, "���ص������С����");

    return positions;
}

vector<Rendering::ScreenTarget::Vector2D> Rendering::ScreenTarget::CreateTextureCoords()
{
    vector<Vector2D> textureCoords{};

    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        textureCoords.emplace_back(0.0f, 0.0f);
        textureCoords.emplace_back(1.0f, 0.0f);
        textureCoords.emplace_back(1.0f, 1.0f);
        textureCoords.emplace_back(0.0f, 1.0f);
    }
    else
    {
        textureCoords.emplace_back(0.0f, 1.0f);
        textureCoords.emplace_back(1.0f, 1.0f);
        textureCoords.emplace_back(1.0f, 0.0f);
        textureCoords.emplace_back(0.0f, 0.0f);
    }

    RENDERING_ASSERTION_1(textureCoords.size() == 4, "���ص������С����");

    return textureCoords;
}
