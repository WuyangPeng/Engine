// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 10:14)

#include "Rendering/RenderingExport.h"

#include "ImageProcessingBase.h" 
#include "Mathematics/Base/Float2.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Shaders/ShaderManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

Rendering::ImageProcessingBase
	::ImageProcessingBase (int numCols, int numRows, int numTargets)
    : mNumCols(numCols), mNumRows(numRows), mNumTargets(numTargets)
{
    RENDERING_ASSERTION_0(mNumCols > 1 && mNumRows > 0, "Invalid bound.\n");
    RENDERING_ASSERTION_0(mNumTargets > 0, "Invalid number of targets.\n");

    mColSpacing = 1.0f/(float)(mNumCols - 1);
    mRowSpacing = 1.0f/(float)(mNumRows - 1);

    // The screen camera maps (x,y,z) in [0,1]^3 to (x',y,'z') in
    // [-1,1]^2 x [0,1].
	mCamera.Reset(NEW0 Camera(false));
    mCamera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	mCamera->SetFrame(Mathematics::APointf::sm_Origin, Mathematics::AVectorf::sm_UnitZ, Mathematics::AVectorf::sm_UnitY, Mathematics::AVectorf::sm_UnitX);

    // Create the vertex format for the square.
	std::vector<VertexFormatType> triple;
	VertexFormatType vertexFormatType0(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
	VertexFormatType vertexFormatType1(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1);
	triple.push_back(vertexFormatType0);
	triple.push_back(vertexFormatType1);

	VertexFormatSmartPointer vformat = VertexFormat::Create(triple);
 
    vformat->SetAttribute(0, 0, 0, VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
    vformat->SetAttribute(1, 0, 3*sizeof(float), VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0);
    vformat->SetStride(5*sizeof(float)); 

    // Create the vertex buffer for the squares.
    int vstride = vformat->GetStride();
    VertexBufferSmartPointer vbuffer ( NEW0 VertexBuffer(4, vstride));
    VertexBufferAccessor vba(vformat, vbuffer);

    float xmin, xmax, ymin, ymax;
    Mathematics::Float2 tc0, tc1, tc2, tc3;
	if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        xmin = 0.0f;
        xmax = 1.0f;
        ymin = 0.0f;
        ymax = 1.0f;
		tc0 = Mathematics::Float2(0.0f, 0.0f);
		tc1 = Mathematics::Float2(1.0f, 0.0f);
		tc2 = Mathematics::Float2(1.0f, 1.0f);
		tc3 = Mathematics::Float2(0.0f, 1.0f);
    }
    else
    {
        xmin = -0.5f*mColSpacing;
        xmax = 1.0f - 0.5f*mColSpacing;
        ymin = +0.5f*mRowSpacing;
        ymax = 1.0f + 0.5f*mRowSpacing;
		tc0 = Mathematics::Float2(0.0f, 1.0f);
		tc1 = Mathematics::Float2(1.0f, 1.0f);
		tc2 = Mathematics::Float2(1.0f, 0.0f);
		tc3 = Mathematics::Float2(0.0f, 0.0f);
    }

	// 先通过编译

	vbuffer->SetPosition(vba, 0, Mathematics::Float3(xmin, ymin, 0.0f));
	vbuffer->SetPosition(vba, 1, Mathematics::Float3(xmax, ymin, 0.0f));
	vbuffer->SetPosition(vba, 2, Mathematics::Float3(xmax, ymax, 0.0f));
	vbuffer->SetPosition(vba, 3, Mathematics::Float3(xmin, ymax, 0.0f));

	vbuffer->SetTextureCoord(vba, 0,Mathematics::Vector2Df(tc0.GetFirstValue(),tc0.GetSecondValue()), 0);
	vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2Df(tc1.GetFirstValue(), tc1.GetSecondValue()), 1);
	vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2Df(tc2.GetFirstValue(), tc2.GetSecondValue()), 2);
	vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2Df(tc3.GetFirstValue(), tc3.GetSecondValue()), 3); 
	 
	
	
    // Create the index buffer for the square.
    IndexBufferSmartPointer ibuffer ( NEW0 IndexBuffer(6, sizeof(int)));
	 
    int* indices = (int*)ibuffer->GetReadOnlyData();
    indices[0] = 0;  indices[1] = 1;  indices[2] = 2;
    indices[3] = 0;  indices[4] = 2;  indices[5] = 3;
	 

    // Create the square.
	mRectangle .Reset( NEW0 TrianglesMesh(vformat, vbuffer, ibuffer));

    CreateVertexShader();
    mTargets = NEW1<RenderTargetSmartPointer>(mNumTargets);
    for (int i = 0; i < mNumTargets; ++i)
    {
		mTargets[i].Reset(NEW0 RenderTarget(1, TextureFormat( System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, false, false));
    }
}

Rendering::ImageProcessingBase
	::~ImageProcessingBase ()
{
    DELETE1(mTargets);
}

void Rendering::ImageProcessingBase
	::CreateEffect (PixelShaderSmartPointer pshader, VisualEffectSmartPointer& effect, VisualEffectInstanceSmartPointer& instance)
{
    // Create the pass.
    VisualPassSmartPointer pass ( NEW0 VisualPass());
    pass->SetPixelShader(pshader);

    // All effects share the vertex shader for the square trimesh.
    pass->SetVertexShader(mVertexShader);

    // Create global state.
	pass->SetAlphaState(AlphaStateSmartPointer(NEW0 AlphaState()));
	pass->SetOffsetState(OffsetStateSmartPointer(NEW0 OffsetState()));
	pass->SetStencilState(StencilStateSmartPointer(NEW0 StencilState()));
	pass->SetWireState(WireStateSmartPointer(NEW0 WireState()));

    // Culling is not needed for image processing.
    CullStateSmartPointer cstate ( NEW0 CullState());
    cstate->SetEnabled ( false);
    pass->SetCullState(cstate);

    // Depth buffering is not needed for image processing.
    DepthStateSmartPointer dstate ( NEW0 DepthState());
    dstate->SetEnabled ( false);
	dstate->SetWritable (false);
    pass->SetDepthState(dstate);

    // Create the effect.
    VisualTechniqueSmartPointer technique ( NEW0 VisualTechnique());
    technique->InsertPass(pass);
    effect .Reset( NEW0 VisualEffect());
    effect->InsertTechnique(technique);

    // Create the effect instance and set the vertex shader constants.
    instance.Reset( NEW0 VisualEffectInstance(effect, 0));

    // Standard transform for vertex shader.
    instance->SetVertexConstant(0, "PVWMatrix", mPVWMatrixConstant);
}

void Rendering::ImageProcessingBase
	::PreDraw ()
{
	if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        // Reflect the image in y to account for OpenGL textures having
        // origin in the upper-left corner.
        mCamera->SetPostProjectionMatrix(Mathematics::Matrixf(1.0f, -1.0f, 1.0f));
    }
}

void Rendering::ImageProcessingBase
	::PostDraw ()
{
	if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)

    {
        // Remove the y-reflection.
		mCamera->SetPostProjectionMatrix(Mathematics::Matrixf::sm_Identity);
    }
}

void Rendering::ImageProcessingBase
	::Initialize (Renderer* renderer, bool openglHack)
{
    // Initialize the image processing by copying the image to a render
    // target.
    renderer->Bind(mTargets[0]);
	renderer->Bind(mTargets[1]);
	renderer->Bind(mMainTexture);
    if (renderer->PreDraw())
    {
        renderer->SetCamera(mCamera);

        // Copy the image to a render target.
        if (openglHack)
        {
            // On Windows Vista with dual NVIDIA GeForce 9800 GT cards running
            // drivers 191.07 and the GpuGaussianBlur3 sample application.
            // If I use mDrawInput and read render target 0 after the
            // Disable(mTargets[0]) below, the target has only black and green
            // pixels.  The green pixels are what p_ScreenShader3 draw for
            // boundary pixels.  If I call ClearColorBuffer with a clear color
            // of blue and without the draw call, the target has all blue
            // pixels, as expected.  If I clear the target and use the draw
            // call, the pixels are all black and green; moreover, the
            // pixels-drawn query in Renderer::DrawPrimitive reports that all
            // pixels in the square have been drawn, as expected.  If I modify
            // p_ScreenShader to test the mMainTexture samples (StateSampler)
            // and return blue whenever the samples are black, the render
            // target has blue and green pixels.  I have checked the
            // mMainTexture system memory and video memory (and mask memory
            // in the p_ScreenShader's other texture)--all appear to be
            // correct.  Everything in the drawing pipeline appear to be set
            // up correctly, so this has the feel of a driver bug.  (The
            // GpuGaussianBlur2 sample application works fine without this
            // hack.)  Switching to using mMainInput instead, everything draws
            // correctly.
            mMainEffectInstance->SetPixelTexture(0, "StateSampler", mMainTexture);
            mRectangle->SetEffectInstance(mMainEffectInstance);
        }
        else
        {
            mDrawEffectInstance->SetPixelTexture(0, "StateSampler", mMainTexture);
            mRectangle->SetEffectInstance(mDrawEffectInstance);
        }

		renderer->Enable(mTargets[0]);
        renderer->ClearColorBuffer();
		renderer->Draw(mRectangle);
		renderer->Disable(mTargets[0]);
        if (openglHack)
        {
            // See the coments above for OpenGL.
		 
            //mMainEffectInstance->SetPixelTexture(0, "StateSampler",  mTargets[1]->GetColorTexture(0));
        }
        else
        {
		 
           // mDrawEffectInstance->SetPixelTexture(0, "StateSampler",  mTargets[1]->GetColorTexture(0));
        }

        // Set the boundary conditions.
        mRectangle->SetEffectInstance(mBoundaryEffectInstance);
		renderer->Enable(mTargets[1]);
		renderer->Draw(mRectangle);
		renderer->Disable(mTargets[1]);

        renderer->PostDraw();
    }
}

void Rendering::ImageProcessingBase
	::ExecuteStep (Renderer* renderer, bool draw)
{
    // Draw the image.
    if (draw)
    {
        PreDraw();
        mRectangle->SetEffectInstance(mDrawEffectInstance);
		renderer->Draw(mRectangle);
        PostDraw();
    }

    // Take a step using the main effect.
    mRectangle->SetEffectInstance(mMainEffectInstance);
    renderer->Enable(mTargets[0]);
	renderer->Draw(mRectangle);
	renderer->Disable(mTargets[0]);

    // Set the boundary conditions.
    mRectangle->SetEffectInstance(mBoundaryEffectInstance);
	renderer->Enable(mTargets[1]);
	renderer->Draw(mRectangle);
	renderer->Disable(mTargets[1]);
}

void Rendering::ImageProcessingBase
	::CreateVertexShader ()
{
    // void v_ScreenShader
    // (
    //     in float3 modelPosition : POSITION,
    //     in float2 modelTCoord : TEXCOORD0,
    //     out float4 clipPosition : POSITION,
    //     out float2 vertexTCoord : TEXCOORD0,
    //     uniform float4x4 PVWMatrix
    // )
    // {
    //     // Transform the position from model space to clip space.
    //     clipPosition = mul(PVWMatrix, float4(modelPosition,1.0f));
    //
    //     // Pass through the texture coordinates.
    //     vertexTCoord = modelTCoord;
    // }

	// 先通过编译
	 
	mVertexShader = VertexShaderSmartPointer{ NEW0 VertexShader("Wm5.ScreenShader", 1, 2, 1, 0) };
    mVertexShader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    mVertexShader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4,  ShaderFlags::VariableSemantic::Position);
    mVertexShader->SetOutput(1, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    mVertexShader->SetConstant(0, "PVWMatrix", 4);


	auto profile = mVertexShader->GetProfile();

	for (auto i = 0; i < ShaderFlags::MaxProfiles; ++i)
	{
		for (auto j = 0; j < 1; ++j)
		{
			profile->SetBaseRegister(i, j, msVRegisters[i][j]);
		}

		profile->SetProgram(i, msVPrograms[i]);
	}

	mPVWMatrixConstant = ProjectionViewWorldMatrixConstantSmartPointer{ NEW0 ProjectionViewWorldMatrixConstant() };
	 
}

int Rendering::ImageProcessingBase::msDx9VRegisters[1]   { 0 };
int Rendering::ImageProcessingBase::msOglVRegisters[1]   { 1 };
int* Rendering::ImageProcessingBase::msVRegisters[ShaderFlags::MaxProfiles]  
{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::ImageProcessingBase::msVPrograms[ShaderFlags::MaxProfiles] 
{
    // VP_NONE
    "",

    // VP_VS_1_1
    "",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xy, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xy, v1\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[5] = { { 1 },\n"
    "		program.local[1..4] };\n"
    "TEMP R0;\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
    "END\n"
};


 int Rendering::ImageProcessingBase
	 ::GetNumCols() const
{
	return mNumCols;
}

 int Rendering::ImageProcessingBase
	 ::GetNumRows() const
{
	return mNumRows;
}

 int Rendering::ImageProcessingBase
	 ::GetNumTargets() const
{
	return mNumTargets;
}

 float Rendering::ImageProcessingBase
	 ::GetColSpacing() const
{
	return mColSpacing;
}

 float Rendering::ImageProcessingBase
	 ::GetRowSpacing() const
{
	return mRowSpacing;
}

 const Rendering::Camera* Rendering::ImageProcessingBase
	 ::GetCamera() const
{
	return mCamera.GetData();
}

 const Rendering::TrianglesMesh* Rendering::ImageProcessingBase
	 ::GetRectangle() const
{
	return mRectangle.GetData();
}

 const Rendering::RenderTarget* Rendering::ImageProcessingBase
	 ::GetTarget(int i) const
{
	if (0 <= i && i < mNumTargets)
	{
		return mTargets[i].GetData();
	}
	return 0;
}

 int Rendering::ImageProcessingBase
	 ::Index(int col, int row) const
{
	return col + mNumCols*row;
}

 const Rendering::Texture2D* Rendering::ImageProcessingBase
	 ::GetMainTexture() const
{
	return mMainTexture.GetData();
}

 const Rendering::VisualEffectInstance* Rendering::ImageProcessingBase
	 ::GetMainEffectInstance() const
{
	return mMainEffectInstance.GetData();
}

