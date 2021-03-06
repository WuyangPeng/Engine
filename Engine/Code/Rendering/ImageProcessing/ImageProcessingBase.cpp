// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/26 10:14)

#include "Rendering/RenderingExport.h"

#include "ImageProcessingBase.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include "Mathematics/Base/Float.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/Shaders/ShaderManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26446)
Rendering::ImageProcessingBase ::ImageProcessingBase(int numCols, int numRows, int numTargets)
    : mNumCols(numCols), mNumRows(numRows), mNumTargets(numTargets)
{
    RENDERING_ASSERTION_0(mNumCols > 1 && mNumRows > 0, "Invalid bound.\n");
    RENDERING_ASSERTION_0(mNumTargets > 0, "Invalid number of targets.\n");

    mColSpacing = 1.0f / (float)(mNumCols - 1);
    mRowSpacing = 1.0f / (float)(mNumRows - 1);

    // The screen camera maps (x,y,z) in [0,1]^3 to (x',y,'z') in
    // [-1,1]^2 x [0,1].
    mCamera = std::make_shared<Camera>(false);
    mCamera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    mCamera->SetFrame(Mathematics::FloatAPoint{}, Mathematics::FloatAVector::GetUnitZ(), Mathematics::FloatAVector::GetUnitY(), Mathematics::FloatAVector::GetUnitX());

    // Create the vertex format for the square.
    std::vector<VertexFormatType> triple;
    const VertexFormatType vertexFormatType0(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
    const VertexFormatType vertexFormatType1(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1);
    triple.push_back(vertexFormatType0);
    triple.push_back(vertexFormatType1);

    VertexFormatSharedPtr vformat = VertexFormat::Create(triple);

    vformat->SetAttribute(0, 0, 0, VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
    vformat->SetAttribute(1, 0, 3 * sizeof(float), VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0);
    vformat->SetStride(5 * sizeof(float));

    // Create the vertex buffer for the squares.
    const int vstride = vformat->GetStride();
    VertexBufferSharedPtr vbuffer(std::make_shared<VertexBuffer>(4, vstride));
    VertexBufferAccessor vba(vformat, vbuffer);

    float xmin = 0.0f, xmax = 0.0f, ymin = 0.0f, ymax = 0.0f;
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
        xmin = -0.5f * mColSpacing;
        xmax = 1.0f - 0.5f * mColSpacing;
        ymin = +0.5f * mRowSpacing;
        ymax = 1.0f + 0.5f * mRowSpacing;
        tc0 = Mathematics::Float2(0.0f, 1.0f);
        tc1 = Mathematics::Float2(1.0f, 1.0f);
        tc2 = Mathematics::Float2(1.0f, 0.0f);
        tc3 = Mathematics::Float2(0.0f, 0.0f);
    }

    // ��ͨ������

    vbuffer->SetPosition(vba, 0, Mathematics::APoint(xmin, ymin, 0.0f));
    vbuffer->SetPosition(vba, 1, Mathematics::APoint(xmax, ymin, 0.0f));
    vbuffer->SetPosition(vba, 2, Mathematics::APoint(xmax, ymax, 0.0f));
    vbuffer->SetPosition(vba, 3, Mathematics::APoint(xmin, ymax, 0.0f));

    vbuffer->SetTextureCoord(vba, 0, Mathematics::FloatVector2D(tc0[0], tc0[1]), 0);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::FloatVector2D(tc1[0], tc1[1]), 1);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::FloatVector2D(tc2[0], tc2[1]), 2);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::FloatVector2D(tc3[0], tc3[1]), 3);

    // Create the index buffer for the square.
    IndexBufferSharedPtr ibuffer(std::make_shared < IndexBuffer>(6,static_cast<int>( sizeof(int))));

    int* indices = (int*)ibuffer->GetReadOnlyData();
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 0;
    indices[4] = 2;
    indices[5] = 3;

    // Create the square.
    mRectangle =std::make_shared < TrianglesMesh>(vformat, vbuffer, ibuffer);

    CreateVertexShader();
    mTargets = NEW1<RenderTargetSharedPtr>(mNumTargets);
    for (int i = 0; i < mNumTargets; ++i)
    {
        mTargets[i].reset(NEW0 RenderTarget(1, TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, false, false));
    }
}

Rendering::ImageProcessingBase ::~ImageProcessingBase()
{
    EXCEPTION_TRY
    {
        DELETE1(mTargets);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

void Rendering::ImageProcessingBase ::CreateEffect(PixelShaderSharedPtr pshader, VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    // Create the pass.
    VisualPassSharedPtr pass(std::make_shared<VisualPass>());
    pass->SetPixelShader(pshader);

    // All effects share the vertex shader for the square trimesh.
    pass->SetVertexShader(mVertexShader);

    // Create global state.
    pass->SetAlphaState(AlphaStateSharedPtr(std::make_shared<AlphaState>()));
    pass->SetOffsetState(OffsetStateSharedPtr(std::make_shared<OffsetState>()));
    pass->SetStencilState(StencilStateSharedPtr(std::make_shared<StencilState>()));
    pass->SetWireState(WireStateSharedPtr(std::make_shared<WireState>()));

    // Culling is not needed for image processing.
    CullStateSharedPtr cstate(std::make_shared<CullState>());
    cstate->SetEnabled(false);
    pass->SetCullState(cstate);

    // Depth buffering is not needed for image processing.
    DepthStateSharedPtr dstate(std::make_shared<DepthState>());
    dstate->SetEnabled(false);
    dstate->SetWritable(false);
    pass->SetDepthState(dstate);

    // Create the effect.
    VisualTechniqueSharedPtr technique(std::make_shared<VisualTechnique>());
    technique->InsertPass(pass);
    effect = std::make_shared<VisualEffect>();
    effect->InsertTechnique(technique);

    // Create the effect instance and set the vertex shader constants.
    instance = std::make_shared<VisualEffectInstance>(effect, 0);

    // Standard transform for vertex shader.
    instance->SetVertexConstant(0, "PVWMatrix", mPVWMatrixConstant);
}

void Rendering::ImageProcessingBase ::PreDraw()
{
    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        // Reflect the image in y to account for OpenGL textures having
        // origin in the upper-left corner.
        mCamera->SetPostProjectionMatrix(Mathematics::FloatMatrix(1.0f, -1.0f, 1.0f));
    }
}

void Rendering::ImageProcessingBase ::PostDraw()
{
    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)

    {
        // Remove the y-reflection.
        mCamera->SetPostProjectionMatrix(Mathematics::FloatMatrix::GetIdentityMatrix());
    }
}

void Rendering::ImageProcessingBase ::Initialize(Renderer* renderer, bool openglHack)
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

void Rendering::ImageProcessingBase ::ExecuteStep(Renderer* renderer, bool draw)
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

void Rendering::ImageProcessingBase ::CreateVertexShader()
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

    // ��ͨ������

    mVertexShader = VertexShaderSharedPtr{ std::make_shared<VertexShader>("Wm5.ScreenShader", 1, 2, 1, 0) };
    mVertexShader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    mVertexShader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    mVertexShader->SetOutput(1, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    mVertexShader->SetConstant(0, "PVWMatrix", 4);

    auto profile = mVertexShader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, msVRegisters[i][j]);
        }

        profile->SetProgram(i, msVPrograms[i]);
    }

    mPVWMatrixConstant = ProjectionViewWorldMatrixConstantSharedPtr{ std::make_shared<ProjectionViewWorldMatrixConstant>() };
}

int Rendering::ImageProcessingBase::msDx9VRegisters[1]{ 0 };
int Rendering::ImageProcessingBase::msOglVRegisters[1]{ 1 };
int* Rendering::ImageProcessingBase::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::ImageProcessingBase::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
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

int Rendering::ImageProcessingBase ::GetNumCols() const noexcept
{
    return mNumCols;
}

int Rendering::ImageProcessingBase ::GetNumRows() const noexcept
{
    return mNumRows;
}

int Rendering::ImageProcessingBase ::GetNumTargets() const noexcept
{
    return mNumTargets;
}

float Rendering::ImageProcessingBase ::GetColSpacing() const noexcept
{
    return mColSpacing;
}

float Rendering::ImageProcessingBase ::GetRowSpacing() const noexcept
{
    return mRowSpacing;
}

const Rendering::Camera* Rendering::ImageProcessingBase ::GetCamera() const noexcept
{
    return mCamera.get();
}

const Rendering::TrianglesMesh* Rendering::ImageProcessingBase ::GetRectangle() const noexcept
{
    return mRectangle.get();
}

const Rendering::RenderTarget* Rendering::ImageProcessingBase ::GetTarget(int i) const noexcept
{
    if (0 <= i && i < mNumTargets)
    {
        return mTargets[i].get();
    }
    return 0;
}

int Rendering::ImageProcessingBase ::Index(int col, int row) const noexcept
{
    return col + mNumCols * row;
}

const Rendering::Texture2D* Rendering::ImageProcessingBase ::GetMainTexture() const noexcept
{
    return mMainTexture.get();
}

const Rendering::VisualEffectInstance* Rendering::ImageProcessingBase ::GetMainEffectInstance() const noexcept
{
    return mMainEffectInstance.get();
}

#include STSTEM_WARNING_POP