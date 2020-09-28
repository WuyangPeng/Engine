//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:40)

#ifndef SYSTEM_HELPER_GL_EXT_FLAGS_H
#define SYSTEM_HELPER_GL_EXT_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GlEXTBlendColor
    {
        BlendColorEXT,
    };

    enum class GlEXTPolygonOffset
    {
        PolygonOffsetEXT,
    };

    enum class GlEXTTexture3D
    {
        TexImage3DEXT,
        TexSubImage3DEXT,
    };

    enum class GlEXTSubtexture
    {
        TexSubImage1DEXT,
        TexSubImage2DEXT,
    };

    enum class GlEXTCopyTexture
    {
        CopyTexImage1DEXT,
        CopyTexImage2DEXT,
        CopyTexSubImage1DEXT,
        CopyTexSubImage2DEXT,
        CopyTexSubImage3DEXT,
    };

    enum class GlEXTHistogram
    {
        GetHistogramEXT,
        GetHistogramParameterfvEXT,
        GetHistogramParameterivEXT,
        GetMinmaxEXT,
        GetMinmaxParameterfvEXT,
        GetMinmaxParameterivEXT,
        HistogramEXT,
        MinmaxEXT,
        ResetHistogramEXT,
        ResetMinmaxEXT,
    };

    enum class GlEXTConvolution
    {
        ConvolutionFilter1DEXT,
        ConvolutionFilter2DEXT,
        ConvolutionParameterfEXT,
        ConvolutionParameterfvEXT,
        ConvolutionParameteriEXT,
        ConvolutionParameterivEXT,
        CopyConvolutionFilter1DEXT,
        CopyConvolutionFilter2DEXT,
        GetConvolutionFilterEXT,
        GetConvolutionParameterfvEXT,
        GetConvolutionParameterivEXT,
        GetSeparableFilterEXT,
        SeparableFilter2DEXT,
    };

    enum class GlEXTTextureObject
    {
        AreTexturesResidentEXT,
        BindTextureEXT,
        DeleteTexturesEXT,
        GenTexturesEXT,
        IsTextureEXT,
        PrioritizeTexturesEXT,
    };

    enum class GlEXTVertexArray
    {
        ArrayElementEXT,
        ColorPointerEXT,
        DrawArraysEXT,
        EdgeFlagPointerEXT,
        GetPointervEXT,
        IndexPointerEXT,
        NormalPointerEXT,
        TexCoordPointerEXT,
        VertexPointerEXT,
    };

    enum class GlEXTBlendMinmax
    {
        BlendEquationEXT,
    };

    enum class GlEXTPointParameters
    {
        PointParameterfEXT,
        PointParameterfvEXT,
    };

    enum class GlEXTColorSubtable
    {
        ColorSubTableEXT,
        CopyColorSubTableEXT,
    };

    enum class GlEXTPalettedTexture
    {
        ColorTableEXT,
        GetColorTableEXT,
        GetColorTableParameterfvEXT,
        GetColorTableParameterivEXT,
    };

    enum class GlEXTIndexMaterial
    {
        IndexMaterialEXT,
    };

    enum class GlEXTIndexFunc
    {
        IndexFuncEXT,
    };

    enum class GlEXTCompiledVertexArray
    {
        LockArraysEXT,
        UnlockArraysEXT,
    };

    enum class GlEXTCullVertex
    {
        CullParameterdvEXT,
        CullParameterfvEXT,
    };

    enum class GlEXTFragmentLighting
    {
        FragmentColorMaterialEXT,
        FragmentLightModelfEXT,
        FragmentLightModelfvEXT,
        FragmentLightModeliEXT,
        FragmentLightModelivEXT,
        FragmentLightfEXT,
        FragmentLightfvEXT,
        FragmentLightiEXT,
        FragmentLightivEXT,
        FragmentMaterialfEXT,
        FragmentMaterialfvEXT,
        FragmentMaterialiEXT,
        FragmentMaterialivEXT,
        GetFragmentLightfvEXT,
        GetFragmentLightivEXT,
        GetFragmentMaterialfvEXT,
        GetFragmentMaterialivEXT,
        LightEnviEXT,
    };

    enum class GlEXTDrawRangeElements
    {
        DrawRangeElementsEXT,
    };

    enum class GlEXTLightTexture
    {
        ApplyTextureEXT,
        TextureLightEXT,
        TextureMaterialEXT,
    };

    enum class GlEXTSceneMarker
    {
        BeginSceneEXT,
        EndSceneEXT,
    };

    enum class GlEXTPixelTransform
    {
        PixelTransformParameteriEXT,
        PixelTransformParameterfEXT,
        PixelTransformParameterivEXT,
        PixelTransformParameterfvEXT,
    };

    enum class GlEXTSecondaryColor
    {
        SecondaryColor3bEXT,
        SecondaryColor3bvEXT,
        SecondaryColor3dEXT,
        SecondaryColor3dvEXT,
        SecondaryColor3fEXT,
        SecondaryColor3fvEXT,
        SecondaryColor3iEXT,
        SecondaryColor3ivEXT,
        SecondaryColor3sEXT,
        SecondaryColor3svEXT,
        SecondaryColor3ubEXT,
        SecondaryColor3ubvEXT,
        SecondaryColor3uiEXT,
        SecondaryColor3uivEXT,
        SecondaryColor3usEXT,
        SecondaryColor3usvEXT,
        SecondaryColorPointerEXT,
    };

    enum class GlEXTTexturePerturbNormal
    {
        TextureNormalEXT,
    };

    enum class GlEXTMultiDrawArrays
    {
        MultiDrawArraysEXT,
        MultiDrawElementsEXT,
    };

    enum class GlEXTFogCoord
    {
        FogCoorddEXT,
        FogCoorddvEXT,
        FogCoordfEXT,
        FogCoordfvEXT,
        FogCoordPointerEXT,
    };

    enum class GlEXTCoordinateFrame
    {
        Tangent3bEXT,
        Tangent3bvEXT,
        Tangent3dEXT,
        Tangent3dvEXT,
        Tangent3fEXT,
        Tangent3fvEXT,
        Tangent3iEXT,
        Tangent3ivEXT,
        Tangent3sEXT,
        Tangent3svEXT,
        Binormal3bEXT,
        Binormal3bvEXT,
        Binormal3dEXT,
        Binormal3dvEXT,
        Binormal3fEXT,
        Binormal3fvEXT,
        Binormal3iEXT,
        Binormal3ivEXT,
        Binormal3sEXT,
        Binormal3svEXT,
        TangentPointerEXT,
        BinormalPointerEXT,
    };

    enum class GlEXTBlendFuncSeparate
    {
        BlendFuncSeparateEXT,
    };

    enum class GlEXTVertexWeighting
    {
        VertexWeightfEXT,
        VertexWeightfvEXT,
        VertexWeightPointerEXT,
    };

    enum class GlEXTMultisample
    {
        SampleMaskEXT,
        SamplePatternEXT,
    };

    enum class GlEXTVertexShader
    {
        BeginVertexShaderEXT,
        BindLightParameterEXT,
        BindMaterialParameterEXT,
        BindParameterEXT,
        BindTexGenParameterEXT,
        BindTextureUnitParameterEXT,
        BindVertexShaderEXT,
        DeleteVertexShaderEXT,
        DisableVariantClientStateEXT,
        EnableVariantClientStateEXT,
        EndVertexShaderEXT,
        ExtractComponentEXT,
        GenSymbolsEXT,
        GenVertexShadersEXT,
        GetInvariantBooleanvEXT,
        GetInvariantFloatvEXT,
        GetInvariantIntegervEXT,
        GetLocalConstantBooleanvEXT,
        GetLocalConstantFloatvEXT,
        GetLocalConstantIntegervEXT,
        GetVariantBooleanvEXT,
        GetVariantFloatvEXT,
        GetVariantIntegervEXT,
        GetVariantPointervEXT,
        InsertComponentEXT,
        IsVariantEnabledEXT,
        SetInvariantEXT,
        SetLocalConstantEXT,
        ShaderOp1EXT,
        ShaderOp2EXT,
        ShaderOp3EXT,
        SwizzleEXT,
        VariantPointerEXT,
        VariantbvEXT,
        VariantdvEXT,
        VariantfvEXT,
        VariantivEXT,
        VariantsvEXT,
        VariantubvEXT,
        VariantuivEXT,
        VariantusvEXT,
        WriteMaskEXT,
    };

    enum class GlEXTStencilTwoSide
    {
        ActiveStencilFaceEXT,
    };

    enum class GlEXTDepthBoundsTest
    {
        DepthBoundsEXT,
    };

    enum class GlEXTBlendEquationSeparate
    {
        BlendEquationSeparateEXT,
    };

    enum class GlEXTFramebufferObject
    {
        IsRenderbufferEXT,
        BindRenderbufferEXT,
        DeleteRenderbuffersEXT,
        GenRenderbuffersEXT,
        RenderbufferStorageEXT,
        GetRenderbufferParameterivEXT,
        IsFramebufferEXT,
        BindFramebufferEXT,
        DeleteFramebuffersEXT,
        GenFramebuffersEXT,
        CheckFramebufferStatusEXT,
        FramebufferTexture1DEXT,
        FramebufferTexture2DEXT,
        FramebufferTexture3DEXT,
        FramebufferRenderbufferEXT,
        GetFramebufferAttachmentParameterivEXT,
        GenerateMipmapEXT,
    };

    enum class GlEXTStencilClearTag
    {
        StencilClearTagEXT,
    };

    enum class GlEXTFramebufferBlit
    {
        BlitFramebufferEXT,
    };

    enum class GlEXTFramebufferMultisample
    {
        RenderbufferStorageMultisampleEXT,
    };

    enum class GlEXTTimerQuery
    {
        GetQueryObjecti64vEXT,
        GetQueryObjectui64vEXT,
    };

    enum class GlEXTGpuProgramParameters
    {
        ProgramEnvParameters4fvEXT,
        ProgramLocalParameters4fvEXT,
    };

    enum class GlEXTGeometryShader4
    {
        FramebufferTextureEXT,
        FramebufferTextureFaceEXT,
        ProgramParameteriEXT,
    };

    enum class GlEXTGpuShader4
    {
        BindFragDataLocationEXT,
        GetFragDataLocationEXT,
        GetUniformuivEXT,
        GetVertexAttribIivEXT,
        GetVertexAttribIuivEXT,
        Uniform1uiEXT,
        Uniform1uivEXT,
        Uniform2uiEXT,
        Uniform2uivEXT,
        Uniform3uiEXT,
        Uniform3uivEXT,
        Uniform4uiEXT,
        Uniform4uivEXT,
        VertexAttribI1iEXT,
        VertexAttribI1ivEXT,
        VertexAttribI1uiEXT,
        VertexAttribI1uivEXT,
        VertexAttribI2iEXT,
        VertexAttribI2ivEXT,
        VertexAttribI2uiEXT,
        VertexAttribI2uivEXT,
        VertexAttribI3iEXT,
        VertexAttribI3ivEXT,
        VertexAttribI3uiEXT,
        VertexAttribI3uivEXT,
        VertexAttribI4bvEXT,
        VertexAttribI4iEXT,
        VertexAttribI4ivEXT,
        VertexAttribI4svEXT,
        VertexAttribI4ubvEXT,
        VertexAttribI4uiEXT,
        VertexAttribI4uivEXT,
        VertexAttribI4usvEXT,
        VertexAttribIPointerEXT,
    };

    enum class GlEXTDrawInstanced
    {
        DrawArraysInstancedEXT,
        DrawElementsInstancedEXT,
    };

    enum class GlEXTTextureArray
    {
        FramebufferTextureLayerEXT,
    };

    enum class GlEXTTextureBufferObject
    {
        TexBufferEXT,
    };

    enum class GlEXTDrawBuffers2
    {
        ColorMaskIndexedEXT,
        DisableIndexedEXT,
        EnableIndexedEXT,
        GetBooleanIndexedvEXT,
        GetIntegerIndexedvEXT,
        IsEnabledIndexedEXT,
    };

    enum class GlEXTBindableUniform
    {
        GetUniformBufferSizeEXT,
        GetUniformOffsetEXT,
        UniformBufferEXT,
    };

    enum class GlEXTTextureInteger
    {
        ClearColorIiEXT,
        ClearColorIuiEXT,
        GetTexParameterIivEXT,
        GetTexParameterIuivEXT,
        TexParameterIivEXT,
        TexParameterIuivEXT,
    };

    enum class GlEXTTransformFeedback
    {
        BeginTransformFeedbackEXT,
        BindBufferBaseEXT,
        BindBufferOffsetEXT,
        BindBufferRangeEXT,
        EndTransformFeedbackEXT,
        GetTransformFeedbackVaryingEXT,
        TransformFeedbackVaryingsEXT,
    };

    enum class GlEXTDirectStateAccess
    {
        BindMultiTextureEXT,
        CheckNamedFramebufferStatusEXT,
        ClientAttribDefaultEXT,
        CompressedMultiTexImage1DEXT,
        CompressedMultiTexImage2DEXT,
        CompressedMultiTexImage3DEXT,
        CompressedMultiTexSubImage1DEXT,
        CompressedMultiTexSubImage2DEXT,
        CompressedMultiTexSubImage3DEXT,
        CompressedTextureImage1DEXT,
        CompressedTextureImage2DEXT,
        CompressedTextureImage3DEXT,
        CompressedTextureSubImage1DEXT,
        CompressedTextureSubImage2DEXT,
        CompressedTextureSubImage3DEXT,
        CopyMultiTexImage1DEXT,
        CopyMultiTexImage2DEXT,
        CopyMultiTexSubImage1DEXT,
        CopyMultiTexSubImage2DEXT,
        CopyMultiTexSubImage3DEXT,
        CopyTextureImage1DEXT,
        CopyTextureImage2DEXT,
        CopyTextureSubImage1DEXT,
        CopyTextureSubImage2DEXT,
        CopyTextureSubImage3DEXT,
        DisableClientStateIndexedEXT,
        DisableClientStateiEXT,
        DisableVertexArrayAttribEXT,
        DisableVertexArrayEXT,
        EnableClientStateIndexedEXT,
        EnableClientStateiEXT,
        EnableVertexArrayAttribEXT,
        EnableVertexArrayEXT,
        FlushMappedNamedBufferRangeEXT,
        FramebufferDrawBufferEXT,
        FramebufferDrawBuffersEXT,
        FramebufferReadBufferEXT,
        GenerateMultiTexMipmapEXT,
        GenerateTextureMipmapEXT,
        GetCompressedMultiTexImageEXT,
        GetCompressedTextureImageEXT,
        GetDoubleIndexedvEXT,
        GetDoublei_vEXT,
        GetFloatIndexedvEXT,
        GetFloati_vEXT,
        GetFramebufferParameterivEXT,
        GetMultiTexEnvfvEXT,
        GetMultiTexEnvivEXT,
        GetMultiTexGendvEXT,
        GetMultiTexGenfvEXT,
        GetMultiTexGenivEXT,
        GetMultiTexImageEXT,
        GetMultiTexLevelParameterfvEXT,
        GetMultiTexLevelParameterivEXT,
        GetMultiTexParameterIivEXT,
        GetMultiTexParameterIuivEXT,
        GetMultiTexParameterfvEXT,
        GetMultiTexParameterivEXT,
        GetNamedBufferParameterivEXT,
        GetNamedBufferPointervEXT,
        GetNamedBufferSubDataEXT,
        GetNamedFramebufferAttachmentParameterivEXT,
        GetNamedProgramLocalParameterIivEXT,
        GetNamedProgramLocalParameterIuivEXT,
        GetNamedProgramLocalParameterdvEXT,
        GetNamedProgramLocalParameterfvEXT,
        GetNamedProgramStringEXT,
        GetNamedProgramivEXT,
        GetNamedRenderbufferParameterivEXT,
        GetPointerIndexedvEXT,
        GetPointeri_vEXT,
        GetTextureImageEXT,
        GetTextureLevelParameterfvEXT,
        GetTextureLevelParameterivEXT,
        GetTextureParameterIivEXT,
        GetTextureParameterIuivEXT,
        GetTextureParameterfvEXT,
        GetTextureParameterivEXT,
        GetVertexArrayIntegeri_vEXT,
        GetVertexArrayIntegervEXT,
        GetVertexArrayPointeri_vEXT,
        GetVertexArrayPointervEXT,
        MapNamedBufferEXT,
        MapNamedBufferRangeEXT,
        MatrixFrustumEXT,
        MatrixLoadIdentityEXT,
        MatrixLoadTransposedEXT,
        MatrixLoadTransposefEXT,
        MatrixLoaddEXT,
        MatrixLoadfEXT,
        MatrixMultTransposedEXT,
        MatrixMultTransposefEXT,
        MatrixMultdEXT,
        MatrixMultfEXT,
        MatrixOrthoEXT,
        MatrixPopEXT,
        MatrixPushEXT,
        MatrixRotatedEXT,
        MatrixRotatefEXT,
        MatrixScaledEXT,
        MatrixScalefEXT,
        MatrixTranslatedEXT,
        MatrixTranslatefEXT,
        MultiTexBufferEXT,
        MultiTexCoordPointerEXT,
        MultiTexEnvfEXT,
        MultiTexEnvfvEXT,
        MultiTexEnviEXT,
        MultiTexEnvivEXT,
        MultiTexGendEXT,
        MultiTexGendvEXT,
        MultiTexGenfEXT,
        MultiTexGenfvEXT,
        MultiTexGeniEXT,
        MultiTexGenivEXT,
        MultiTexImage1DEXT,
        MultiTexImage2DEXT,
        MultiTexImage3DEXT,
        MultiTexParameterIivEXT,
        MultiTexParameterIuivEXT,
        MultiTexParameterfEXT,
        MultiTexParameterfvEXT,
        MultiTexParameteriEXT,
        MultiTexParameterivEXT,
        MultiTexRenderbufferEXT,
        MultiTexSubImage1DEXT,
        MultiTexSubImage2DEXT,
        MultiTexSubImage3DEXT,
        NamedBufferDataEXT,
        NamedBufferSubDataEXT,
        NamedCopyBufferSubDataEXT,
        NamedFramebufferRenderbufferEXT,
        NamedFramebufferTexture1DEXT,
        NamedFramebufferTexture2DEXT,
        NamedFramebufferTexture3DEXT,
        NamedFramebufferTextureEXT,
        NamedFramebufferTextureFaceEXT,
        NamedFramebufferTextureLayerEXT,
        NamedProgramLocalParameter4dEXT,
        NamedProgramLocalParameter4dvEXT,
        NamedProgramLocalParameter4fEXT,
        NamedProgramLocalParameter4fvEXT,
        NamedProgramLocalParameterI4iEXT,
        NamedProgramLocalParameterI4ivEXT,
        NamedProgramLocalParameterI4uiEXT,
        NamedProgramLocalParameterI4uivEXT,
        NamedProgramLocalParameters4fvEXT,
        NamedProgramLocalParametersI4ivEXT,
        NamedProgramLocalParametersI4uivEXT,
        NamedProgramStringEXT,
        NamedRenderbufferStorageEXT,
        NamedRenderbufferStorageMultisampleCoverageEXT,
        NamedRenderbufferStorageMultisampleEXT,
        ProgramUniform1fEXT,
        ProgramUniform1fvEXT,
        ProgramUniform1iEXT,
        ProgramUniform1ivEXT,
        ProgramUniform1uiEXT,
        ProgramUniform1uivEXT,
        ProgramUniform2fEXT,
        ProgramUniform2fvEXT,
        ProgramUniform2iEXT,
        ProgramUniform2ivEXT,
        ProgramUniform2uiEXT,
        ProgramUniform2uivEXT,
        ProgramUniform3fEXT,
        ProgramUniform3fvEXT,
        ProgramUniform3iEXT,
        ProgramUniform3ivEXT,
        ProgramUniform3uiEXT,
        ProgramUniform3uivEXT,
        ProgramUniform4fEXT,
        ProgramUniform4fvEXT,
        ProgramUniform4iEXT,
        ProgramUniform4ivEXT,
        ProgramUniform4uiEXT,
        ProgramUniform4uivEXT,
        ProgramUniformMatrix2fvEXT,
        ProgramUniformMatrix2x3fvEXT,
        ProgramUniformMatrix2x4fvEXT,
        ProgramUniformMatrix3fvEXT,
        ProgramUniformMatrix3x2fvEXT,
        ProgramUniformMatrix3x4fvEXT,
        ProgramUniformMatrix4fvEXT,
        ProgramUniformMatrix4x2fvEXT,
        ProgramUniformMatrix4x3fvEXT,
        PushClientAttribDefaultEXT,
        TextureBufferEXT,
        TextureImage1DEXT,
        TextureImage2DEXT,
        TextureImage3DEXT,
        TextureParameterIivEXT,
        TextureParameterIuivEXT,
        TextureParameterfEXT,
        TextureParameterfvEXT,
        TextureParameteriEXT,
        TextureParameterivEXT,
        TextureRenderbufferEXT,
        TextureSubImage1DEXT,
        TextureSubImage2DEXT,
        TextureSubImage3DEXT,
        UnmapNamedBufferEXT,
        VertexArrayColorOffsetEXT,
        VertexArrayEdgeFlagOffsetEXT,
        VertexArrayFogCoordOffsetEXT,
        VertexArrayIndexOffsetEXT,
        VertexArrayMultiTexCoordOffsetEXT,
        VertexArrayNormalOffsetEXT,
        VertexArraySecondaryColorOffsetEXT,
        VertexArrayTexCoordOffsetEXT,
        VertexArrayVertexAttribDivisorEXT,
        VertexArrayVertexAttribIOffsetEXT,
        VertexArrayVertexAttribOffsetEXT,
        VertexArrayVertexOffsetEXT,
    };

    enum class GlEXTProvokingVertex
    {
        ProvokingVertexEXT,
    };

    enum class GlEXTSeparateShaderObjects
    {
        ActiveProgramEXT,
        CreateShaderProgramEXT,
        UseShaderProgramEXT,
    };

    enum class GlEXTShaderImageLoadStore
    {
        BindImageTextureEXT,
        MemoryBarrierEXT,
    };

    enum class GlEXTVertexAttrib64bit
    {
        GetVertexAttribLdvEXT,
        VertexArrayVertexAttribLOffsetEXT,
        VertexAttribL1dEXT,
        VertexAttribL1dvEXT,
        VertexAttribL2dEXT,
        VertexAttribL2dvEXT,
        VertexAttribL3dEXT,
        VertexAttribL3dvEXT,
        VertexAttribL4dEXT,
        VertexAttribL4dvEXT,
        VertexAttribLPointerEXT,
    };

    enum class GlEXTX11SyncObject
    {
        ImportSyncEXT,
    };

    enum class GlEXTDebugLabel
    {
        GetObjectLabelEXT,
        LabelObjectEXT,
    };

    enum class GlEXTDebugMarker
    {
        InsertEventMarkerEXT,
        PopGroupMarkerEXT,
        PushGroupMarkerEXT,
    };

    enum class GlEXTPolygonOffsetClamp
    {
        PolygonOffsetClampEXT,
    };

    enum class GlEXTRasterMultisample
    {
        CoverageModulationNV,
        CoverageModulationTableNV,
        GetCoverageModulationTableNV,
        RasterSamplesEXT,
    };
}

#endif  // SYSTEM_HELPER_GL_EXT_FLAGS_H
