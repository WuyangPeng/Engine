// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:05)

#include "Rendering/RenderingExport.h"

#include "ScreenTarget.h"
#include "Camera.h"
#include "Rendering/Shaders/ShaderManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
 #include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
 #include SYSTEM_WARNING_DISABLE(26418)
using std::vector;

const Rendering::CameraSharedPtr Rendering::ScreenTarget
	::CreateCamera()
{
	// 场景摄像机映射  (x,y,z)  [0,1]^3 到 (x',y,'z') 在
    // [-1,1]^2 x [0,1].
	CameraSharedPtr camera{ std::make_shared<Camera>(false) };
    camera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        camera->SetFrame(Mathematics::APointF::GetOrigin(), Mathematics::AVectorF::GetUnitZ(), Mathematics::AVectorF::GetUnitY(), Mathematics::AVectorF::GetUnitX());

    return camera;
}

const Rendering::TrianglesMeshSharedPtr Rendering::ScreenTarget
   ::CreateRectangle(const VertexFormatSharedPtr& vertexFormat,int renderTargetWidth, int renderTargetHeight, 
					 float xMin, float xMax, float yMin, float yMax, float zValue)
{
	if (ValidFormat(vertexFormat) && ValidSizes(renderTargetWidth, renderTargetHeight))
    {
		int vstride = vertexFormat->GetStride();
		VertexBufferSharedPtr vertexBuffer{ std::make_shared<VertexBuffer>(4, vstride) };
		VertexBufferAccessor vertexBufferAccessor{ vertexFormat ,
												   vertexBuffer  };

		if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
        {
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 0, Vector2D(0.0f, 0.0f));
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 1, Vector2D(1.0f, 0.0f));
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 2, Vector2D(1.0f, 1.0f));
			vertexBuffer->SetTextureCoord(vertexBufferAccessor, 3, Vector2D(0.0f, 1.0f));
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

   		// 创建正方形的索引缓冲区
		IndexBufferSharedPtr indexBuffer{ std::make_shared< IndexBuffer>(6, (int)sizeof(int)) };
		indexBuffer->InitIndexBufferInParticles();      

		return TrianglesMeshSharedPtr{ std::make_shared < TrianglesMesh>(vertexFormat, vertexBuffer, indexBuffer) };
    }

	return TrianglesMeshSharedPtr();
}

// private
bool Rendering::ScreenTarget
	::ValidSizes(int renderTargetWidth, int renderTargetHeight)
{
	if (0 < renderTargetWidth && 0 < renderTargetHeight)
	{
		return true;
	}

	CoreTools::DisableNoexcept();

	RENDERING_ASSERTION_1(false, "无效的维度。\n");

	return false;
}

// private
bool Rendering::ScreenTarget
	::ValidFormat(const VertexFormatSharedPtr& vertexFormat)
{
	auto index = vertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position, 0);
	if (index < 0)
	{
		RENDERING_ASSERTION_1(false, "格式必须拥有位置信息。\n");
		return false;
	}

	if (vertexFormat->GetAttributeType(index) != VertexFormatFlags::AttributeType::Float3)
	{
		RENDERING_ASSERTION_1(false, "位置必须是3元组。\n");	
		return false;
	}

	index = vertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, 0);
	if (index < 0)
	{
		RENDERING_ASSERTION_1(false, "格式必须拥有纹理坐标在单元0。\n");
		return false;
	}

	if (vertexFormat->GetAttributeType(index) != VertexFormatFlags::AttributeType::Float2)
	{
		RENDERING_ASSERTION_1(false, "纹理坐标在单元0必须是2元组。\n");		
		return false;
	}

	return true;
}


vector<Rendering::ScreenTarget::APoint>	Rendering::ScreenTarget
	::CreatePositions(int renderTargetWidth,int renderTargetHeight,float xMin,float xMax, float yMin, float yMax, float zValue)
{
	vector<APoint> positions;

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

	RENDERING_ASSERTION_1(positions.size() == 0 || positions.size() == 4,"返回的数组大小错误！");

	return positions;
}

vector<Rendering::ScreenTarget::Vector2D> Rendering::ScreenTarget
	::CreateTextureCoords() 
{
	vector<Vector2D> textureCoords;

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

	RENDERING_ASSERTION_1(textureCoords.size() == 4,"返回的数组大小错误！");

	return textureCoords;
}

 

#include STSTEM_WARNING_POP