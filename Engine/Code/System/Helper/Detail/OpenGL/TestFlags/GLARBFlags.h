// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:03)

#ifndef SYSTEM_HELPER_GL_ARB_FLAGS_H
#define SYSTEM_HELPER_GL_ARB_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class GLARBMultitextureFlags
	{
		ActiveTextureARB,
		ClientActiveTextureARB,
		MultiTexCoord1dARB,
		MultiTexCoord1dvARB,
		MultiTexCoord1fARB,
		MultiTexCoord1fvARB,
		MultiTexCoord1iARB,
		MultiTexCoord1ivARB,
		MultiTexCoord1sARB,
		MultiTexCoord1svARB,
		MultiTexCoord2dARB,
		MultiTexCoord2dvARB,
		MultiTexCoord2fARB,
		MultiTexCoord2fvARB,
		MultiTexCoord2iARB,
		MultiTexCoord2ivARB,
		MultiTexCoord2sARB,
		MultiTexCoord2svARB,
		MultiTexCoord3dARB,
		MultiTexCoord3dvARB,
		MultiTexCoord3fARB,
		MultiTexCoord3fvARB,
		MultiTexCoord3iARB,
		MultiTexCoord3ivARB,
		MultiTexCoord3sARB,
		MultiTexCoord3svARB,
		MultiTexCoord4dARB,
		MultiTexCoord4dvARB,
		MultiTexCoord4fARB,
		MultiTexCoord4fvARB,
		MultiTexCoord4iARB,
		MultiTexCoord4ivARB,
		MultiTexCoord4sARB,
		MultiTexCoord4svARB,
	};

	enum class GLARBTransposeMatrixFlags
	{
		LoadTransposeMatrixdARB,
		LoadTransposeMatrixfARB,
		MultTransposeMatrixdARB,
		MultTransposeMatrixfARB,
	};

	enum class GLARBMultisampleFlags
	{
		SampleCoverageARB,
	};

	enum class GLARBTextureCompression
	{
		CompressedTexImage1DARB,
		CompressedTexImage2DARB,
		CompressedTexImage3DARB,
		CompressedTexSubImage1DARB,
		CompressedTexSubImage2DARB,
		CompressedTexSubImage3DARB,
		GetCompressedTexImageARB,
	};

	enum class GLARBPointParameters
	{
		PointParameterfARB,
		PointParameterfvARB,
	};

	enum class GLARBVertexBlend
	{
		WeightbvARB,
		WeightsvARB,
		WeightivARB,
		WeightfvARB,
		WeightdvARB,
		WeightubvARB,
		WeightusvARB,
		WeightuivARB,
		WeightPointerARB,
		VertexBlendARB,
	};

	enum class GLARBMatrixPalette
	{
		CurrentPaletteMatrixARB,
		MatrixIndexubvARB,
		MatrixIndexusvARB,
		MatrixIndexuivARB,
		MatrixIndexPointerARB,
	};

	enum class GLARBWindowPos
	{
		WindowPos2dARB,
		WindowPos2dvARB,
		WindowPos2fARB,
		WindowPos2fvARB,
		WindowPos2iARB,
		WindowPos2ivARB,
		WindowPos2sARB,
		WindowPos2svARB,
		WindowPos3dARB,
		WindowPos3dvARB,
		WindowPos3fARB,
		WindowPos3fvARB,
		WindowPos3iARB,
		WindowPos3ivARB,
		WindowPos3sARB,
		WindowPos3svARB,
	};

	enum class GLARBVertexProgram
	{
		BindProgramARB,
		DeleteProgramsARB,
		DisableVertexAttribArrayARB,
		EnableVertexAttribArrayARB,
		GenProgramsARB,
		GetProgramivARB,
		GetProgramEnvParameterdvARB,
		GetProgramEnvParameterfvARB,
		GetProgramLocalParameterdvARB,
		GetProgramLocalParameterfvARB,
		GetProgramStringARB,
		GetVertexAttribdvARB,
		GetVertexAttribfvARB,
		GetVertexAttribivARB,
		GetVertexAttribPointervARB,
		IsProgramARB,
		ProgramEnvParameter4dARB,
		ProgramEnvParameter4dvARB,
		ProgramEnvParameter4fARB,
		ProgramEnvParameter4fvARB,
		ProgramLocalParameter4dARB,
		ProgramLocalParameter4dvARB,
		ProgramLocalParameter4fARB,
		ProgramLocalParameter4fvARB,
		ProgramStringARB,
		VertexAttrib1dARB,
		VertexAttrib1dvARB,
		VertexAttrib1fARB,
		VertexAttrib1fvARB,
		VertexAttrib1sARB,
		VertexAttrib1svARB,
		VertexAttrib2dARB,
		VertexAttrib2dvARB,
		VertexAttrib2fARB,
		VertexAttrib2fvARB,
		VertexAttrib2sARB,
		VertexAttrib2svARB,
		VertexAttrib3dARB,
		VertexAttrib3dvARB,
		VertexAttrib3fARB,
		VertexAttrib3fvARB,
		VertexAttrib3sARB,
		VertexAttrib3svARB,
		VertexAttrib4NbvARB,
		VertexAttrib4NivARB,
		VertexAttrib4NsvARB,
		VertexAttrib4NubARB,
		VertexAttrib4NubvARB,
		VertexAttrib4NuivARB,
		VertexAttrib4NusvARB,
		VertexAttrib4bvARB,
		VertexAttrib4dARB,
		VertexAttrib4dvARB,
		VertexAttrib4fARB,
		VertexAttrib4fvARB,
		VertexAttrib4ivARB,
		VertexAttrib4sARB,
		VertexAttrib4svARB,
		VertexAttrib4ubvARB,
		VertexAttrib4uivARB,
		VertexAttrib4usvARB,
		VertexAttribPointerARB,
	};

	enum class GLARBVertexBufferObject
	{
		BindBufferARB,
		DeleteBuffersARB,
		GenBuffersARB,
		IsBufferARB,
		BufferDataARB,
		BufferSubDataARB,
		GetBufferSubDataARB,
		MapBufferARB,
		UnmapBufferARB,
		GetBufferParameterivARB,
		GetBufferPointervARB,
	};

	enum class GLARBOcclusionQuery
	{
		GenQueriesARB,
		DeleteQueriesARB,
		IsQueryARB,
		BeginQueryARB,
		EndQueryARB,
		GetQueryivARB,
		GetQueryObjectivARB,
		GetQueryObjectuivARB,
	};

	enum class GLARBShaderObjects
	{
		AttachObjectARB,
		CompileShaderARB,
		CreateProgramObjectARB,
		CreateShaderObjectARB,
		DeleteObjectARB,
		DetachObjectARB,
		GetActiveUniformARB,
		GetAttachedObjectsARB,
		GetHandleARB,
		GetInfoLogARB,
		GetObjectParameterfvARB,
		GetObjectParameterivARB,
		GetShaderSourceARB,
		GetUniformfvARB,
		GetUniformivARB,
		GetUniformLocationARB,
		LinkProgramARB,
		ShaderSourceARB,
		Uniform1fARB,
		Uniform2fARB,
		Uniform3fARB,
		Uniform4fARB,
		Uniform1iARB,
		Uniform2iARB,
		Uniform3iARB,
		Uniform4iARB,
		Uniform1fvARB,
		Uniform2fvARB,
		Uniform3fvARB,
		Uniform4fvARB,
		Uniform1ivARB,
		Uniform2ivARB,
		Uniform3ivARB,
		Uniform4ivARB,
		UniformMatrix2fvARB,
		UniformMatrix3fvARB,
		UniformMatrix4fvARB,
		UseProgramObjectARB,
		ValidateProgramARB,
	};

	enum class GLARBVertexShader
	{
		BindAttribLocationARB,
		GetActiveAttribARB,
		GetAttribLocationARB,
	};

	enum class GLARBDrawBuffers
	{
		DrawBuffersARB,
	};

	enum class GLARBColorBufferFloat
	{
		ClampColorARB,
	};

	enum class GLARBFramebufferObject
	{
		BindFramebuffer,
		BindRenderbuffer,
		BlitFramebuffer,
		CheckFramebufferStatus,
		DeleteFramebuffers,
		DeleteRenderbuffers,
		FramebufferRenderbuffer,
		FramebufferTexture1D,
		FramebufferTexture2D,
		FramebufferTexture3D,
		FramebufferTextureLayer,
		GenFramebuffers,
		GenRenderbuffers,
		GenerateMipmap,
		GetFramebufferAttachmentParameteriv,
		GetRenderbufferParameteriv,
		IsFramebuffer,
		IsRenderbuffer,
		RenderbufferStorage,
		RenderbufferStorageMultisample,
	};

	enum class GLARBGeometryShader4
	{
		FramebufferTextureARB,
		FramebufferTextureFaceARB,
		FramebufferTextureLayerARB,
		ProgramParameteriARB,
	};

	enum class GLARBInstancedArrays
	{
		DrawArraysInstancedARB,
		DrawElementsInstancedARB,
		VertexAttribDivisorARB,
	};

	enum class GLARBMapBufferRange
	{
		MapBufferRange,
		FlushMappedBufferRange,
	};

	enum class GLARBTextureBufferObject
	{
		TexBufferARB,
	};

	enum class GLARBVertexArrayObject
	{
		BindVertexArray,
		DeleteVertexArrays,
		GenVertexArrays,
		IsVertexArray,
	};

	enum class GLARBUniformBufferObject
	{
		GetActiveUniformBlockName,
		GetActiveUniformBlockiv,
		GetActiveUniformName,
		GetActiveUniformsiv,
		GetUniformBlockIndex,
		GetUniformIndices,
		UniformBlockBinding,
	};

	enum class GLARBCopyBuffer
	{
		CopyBufferSubData,
	};

	enum class GLARBDrawElementsBaseVertex
	{
		DrawElementsBaseVertex,
		DrawElementsInstancedBaseVertex,
		DrawRangeElementsBaseVertex,
		MultiDrawElementsBaseVertex
	};

	enum class GLARBProvokingVertex
	{
		ProvokingVertex,
	};

	enum class GLARBSync
	{
		ClientWaitSync,
		DeleteSync,
		FenceSync,
		GetInteger64v,
		GetSynciv,
		IsSync,
		WaitSync,
	};

	enum class GLARBTextureMultisample
	{
		GetMultisamplefv,
		SampleMaski,
		TexImage2DMultisample,
		TexImage3DMultisample,
	};

	enum class GLARBDrawBuffersBlend
	{
		BlendEquationSeparateiARB,
		BlendEquationiARB,
		BlendFuncSeparateiARB,
		BlendFunciARB,
	};

	enum class GLARBSampleShading
	{
		MinSampleShadingARB,
	};

	enum class GLARBShadingLanguageInclude
	{
		CompileShaderIncludeARB,
		DeleteNamedStringARB,
		GetNamedStringARB,
		GetNamedStringivARB,
		IsNamedStringARB,
		NamedStringARB,
	};

	enum class GLARBBlendFuncExtended
	{
		BindFragDataLocationIndexed,
		GetFragDataIndex,
	};

	enum class GLARBSamplerObjects
	{
		BindSampler,
		DeleteSamplers,
		GenSamplers,
		GetSamplerParameterIiv,
		GetSamplerParameterIuiv,
		GetSamplerParameterfv,
		GetSamplerParameteriv,
		IsSampler,
		SamplerParameterIiv,
		SamplerParameterIuiv,
		SamplerParameterf,
		SamplerParameterfv,
		SamplerParameteri,
		SamplerParameteriv,
	};

	enum class GLARBTimerQuery
	{
		GetQueryObjecti64v,
		GetQueryObjectui64v,
		QueryCounter,
	};

	enum class GLARBVertexType2TenTenTenRev
	{
		ColorP3ui,
		ColorP3uiv,
		ColorP4ui,
		ColorP4uiv,
		MultiTexCoordP1ui,
		MultiTexCoordP1uiv,
		MultiTexCoordP2ui,
		MultiTexCoordP2uiv,
		MultiTexCoordP3ui,
		MultiTexCoordP3uiv,
		MultiTexCoordP4ui,
		MultiTexCoordP4uiv,
		NormalP3ui,
		NormalP3uiv,
		SecondaryColorP3ui,
		SecondaryColorP3uiv,
		TexCoordP1ui,
		TexCoordP1uiv,
		TexCoordP2ui,
		TexCoordP2uiv,
		TexCoordP3ui,
		TexCoordP3uiv,
		TexCoordP4ui,
		TexCoordP4uiv,
		VertexAttribP1ui,
		VertexAttribP1uiv,
		VertexAttribP2ui,
		VertexAttribP2uiv,
		VertexAttribP3ui,
		VertexAttribP3uiv,
		VertexAttribP4ui,
		VertexAttribP4uiv,
		VertexP2ui,
		VertexP2uiv,
		VertexP3ui,
		VertexP3uiv,
		VertexP4ui,
		VertexP4uiv,
	};

	enum class GLARBDrawIndirect
	{
		DrawArraysIndirect,
		DrawElementsIndirect,
	};

	enum class GLARBGpuShaderFp64
	{
		GetUniformdv,
		Uniform1d,
		Uniform1dv,
		Uniform2d,
		Uniform2dv,
		Uniform3d,
		Uniform3dv,
		Uniform4d,
		Uniform4dv,
		UniformMatrix2dv,
		UniformMatrix2x3dv,
		UniformMatrix2x4dv,
		UniformMatrix3dv,
		UniformMatrix3x2dv,
		UniformMatrix3x4dv,
		UniformMatrix4dv,
		UniformMatrix4x2dv,
		UniformMatrix4x3dv,
	};

	enum class GLARBShaderSubroutine
	{
		GetActiveSubroutineName,
		GetActiveSubroutineUniformName,
		GetActiveSubroutineUniformiv,
		GetProgramStageiv,
		GetSubroutineIndex,
		GetSubroutineUniformLocation,
		GetUniformSubroutineuiv,
		UniformSubroutinesuiv,
	};

	enum class GLARBTessellationShader
	{
		PatchParameterfv,
		PatchParameteri,
	};

	enum class GLARBTransformFeedback2
	{
		BindTransformFeedback,
		DeleteTransformFeedbacks,
		DrawTransformFeedback,
		GenTransformFeedbacks,
		IsTransformFeedback,
		PauseTransformFeedback,
		ResumeTransformFeedback,
	};

	enum class GLARBTransformFeedback3
	{
		BeginQueryIndexed,
		DrawTransformFeedbackStream,
		EndQueryIndexed,
		GetQueryIndexediv,
	};

	enum class GLARBGetProgramBinary
	{
		GetProgramBinary,
		ProgramBinary,
	};

	enum class GLARBSeparateShaderObjects
	{
		ActiveShaderProgram,
		BindProgramPipeline,
		CreateShaderProgramv,
		DeleteProgramPipelines,
		GenProgramPipelines,
		GetProgramPipelineInfoLog,
		GetProgramPipelineiv,
		IsProgramPipeline,
		ProgramUniform1d,
		ProgramUniform1dv,
		ProgramUniform1f,
		ProgramUniform1fv,
		ProgramUniform1i,
		ProgramUniform1iv,
		ProgramUniform1ui,
		ProgramUniform1uiv,
		ProgramUniform2d,
		ProgramUniform2dv,
		ProgramUniform2f,
		ProgramUniform2fv,
		ProgramUniform2i,
		ProgramUniform2iv,
		ProgramUniform2ui,
		ProgramUniform2uiv,
		ProgramUniform3d,
		ProgramUniform3dv,
		ProgramUniform3f,
		ProgramUniform3fv,
		ProgramUniform3i,
		ProgramUniform3iv,
		ProgramUniform3ui,
		ProgramUniform3uiv,
		ProgramUniform4d,
		ProgramUniform4dv,
		ProgramUniform4f,
		ProgramUniform4fv,
		ProgramUniform4i,
		ProgramUniform4iv,
		ProgramUniform4ui,
		ProgramUniform4uiv,
		ProgramUniformMatrix2dv,
		ProgramUniformMatrix2fv,
		ProgramUniformMatrix2x3dv,
		ProgramUniformMatrix2x3fv,
		ProgramUniformMatrix2x4dv,
		ProgramUniformMatrix2x4fv,
		ProgramUniformMatrix3dv,
		ProgramUniformMatrix3fv,
		ProgramUniformMatrix3x2dv,
		ProgramUniformMatrix3x2fv,
		ProgramUniformMatrix3x4dv,
		ProgramUniformMatrix3x4fv,
		ProgramUniformMatrix4dv,
		ProgramUniformMatrix4fv,
		ProgramUniformMatrix4x2dv,
		ProgramUniformMatrix4x2fv,
		ProgramUniformMatrix4x3dv,
		ProgramUniformMatrix4x3fv,
		UseProgramStages,
		ValidateProgramPipeline
	};

	enum class GLARBVertexAttrib64bit
	{
		GetVertexAttribLdv,
		VertexAttribL1d,
		VertexAttribL1dv,
		VertexAttribL2d,
		VertexAttribL2dv,
		VertexAttribL3d,
		VertexAttribL3dv,
		VertexAttribL4d,
		VertexAttribL4dv,
		VertexAttribLPointer
	};

	enum class GLARBViewportArray
	{
		DepthRangeArrayv,
		DepthRangeIndexed,
		GetDoublei_v,
		GetFloati_v,
		ScissorArrayv,
		ScissorIndexed,
		ScissorIndexedv,
		ViewportArrayv,
		ViewportIndexedf,
		ViewportIndexedfv
	};

	enum class GLARBClEvent
	{
		CreateSyncFromCLeventARB,
	};

	enum class GLARBDebugOutput
	{
		DebugMessageCallbackARB,
		DebugMessageControlARB,
		DebugMessageInsertARB,
		GetDebugMessageLogARB
	};

	enum class GLARBRobustness
	{
		GetGraphicsResetStatusARB,
		GetnColorTableARB,
		GetnCompressedTexImageARB,
		GetnConvolutionFilterARB,
		GetnHistogramARB,
		GetnMapdvARB,
		GetnMapfvARB,
		GetnMapivARB,
		GetnMinmaxARB,
		GetnPixelMapfvARB,
		GetnPixelMapuivARB,
		GetnPixelMapusvARB,
		GetnPolygonStippleARB,
		GetnSeparableFilterARB,
		GetnTexImageARB,
		GetnUniformdvARB,
		GetnUniformfvARB,
		GetnUniformivARB,
		GetnUniformuivARB,
		ReadnPixelsARB
	};

	enum class GLARBBaseInstance
	{
		DrawArraysInstancedBaseInstance,
		DrawElementsInstancedBaseInstance,
		DrawElementsInstancedBaseVertexBaseInstance
	};

	enum class GLARBTransformFeedbackInstanced
	{
		DrawTransformFeedbackInstanced,
		DrawTransformFeedbackStreamInstanced,
	};

	enum class GLARBInternalformatQuery
	{
		GetInternalformativ,
	};


	enum class GLARBShaderAtomicCounters
	{
		GetActiveAtomicCounterBufferiv,
	};

	enum class GLARBShaderImageLoadStore
	{
		BindImageTexture,
		MemoryBarrier,
	};

	enum class GLARBTextureStorage
	{
		TexStorage1D,
		TexStorage2D,
		TexStorage3D,
		TextureStorage1DEXT,
		TextureStorage2DEXT,
		TextureStorage3DEXT,
	};

	enum class GLARBClearBufferObject
	{
		ClearBufferData,
		ClearBufferSubData,
		ClearNamedBufferDataEXT,
		ClearNamedBufferSubDataEXT,
	};

	enum class GLARBComputeShader
	{
		DispatchCompute,
		DispatchComputeIndirect,
	};

	enum class GLARBCopyImage
	{
		CopyImageSubData,
	};

	enum class GLARBTextureView
	{
		TextureView,
	};

	enum class GLARBVertexAttribBinding
	{
		BindVertexBuffer,
		VertexAttribBinding,
		VertexAttribFormat,
		VertexAttribIFormat,
		VertexAttribLFormat,
		VertexBindingDivisor,
	};

	enum class GLARBFramebufferNoAttachments
	{
		FramebufferParameteri,
		GetFramebufferParameteriv,
		GetNamedFramebufferParameterivEXT,
		NamedFramebufferParameteriEXT,
	};

	enum class GLARBInternalformatQuery2
	{
		GetInternalformati64v,
	};

	enum class GLARBInvalidateSubdata
	{
		InvalidateBufferData,
		InvalidateBufferSubData,
		InvalidateFramebuffer,
		InvalidateSubFramebuffer,
		InvalidateTexImage,
		InvalidateTexSubImage,
	};

	enum class GLARBMultiDrawIndirect
	{
		MultiDrawArraysIndirect,
		MultiDrawElementsIndirect,
	};

	enum class GLARBProgramInterfaceQuery
	{
		GetProgramInterfaceiv,
		GetProgramResourceIndex,
		GetProgramResourceLocation,
		GetProgramResourceLocationIndex,
		GetProgramResourceName,
		GetProgramResourceiv,
	};

	enum class GLARBShaderStorageBufferObject
	{
		ShaderStorageBlockBinding,
	};

	enum class GLARBTextureBufferRange
	{
		TexBufferRange,
		TextureBufferRangeEXT,
	};

	enum class GLARBTextureStorageMultisample
	{
		TexStorage2DMultisample,
		TexStorage3DMultisample,
		TextureStorage2DMultisampleEXT,
		TextureStorage3DMultisampleEXT,
	};

	enum class GLARBBufferStorage
	{
		BufferStorage,
		NamedBufferStorageEXT,
	};

	enum class GLARBClearTexture
	{
		ClearTexImage,
		ClearTexSubImage,
	};

	enum class GLARBMultiBind
	{
		BindBuffersBase,
		BindBuffersRange,
		BindImageTextures,
		BindSamplers,
		BindTextures,
		BindVertexBuffers,
	};

	enum class GLARBBindlessTexture
	{
		GetImageHandleARB,
		GetTextureHandleARB,
		GetTextureSamplerHandleARB,
		GetVertexAttribLui64vARB,
		IsImageHandleResidentARB,
		IsTextureHandleResidentARB,
		MakeImageHandleNonResidentARB,
		MakeImageHandleResidentARB,
		MakeTextureHandleNonResidentARB,
		MakeTextureHandleResidentARB,
		ProgramUniformHandleui64ARB,
		ProgramUniformHandleui64vARB,
		UniformHandleui64ARB,
		UniformHandleui64vARB,
		VertexAttribL1ui64ARB,
		VertexAttribL1ui64vARB,
	};

	enum class GLARBComputeVariableGroupSize
	{
		DispatchComputeGroupSizeARB,
	};

	enum class GLARBIndirectParameters
	{
		MultiDrawArraysIndirectCountARB,
		MultiDrawElementsIndirectCountARB,
	};

	enum class GLARBSparseTexture
	{
		TexPageCommitmentARB,
		TexturePageCommitmentEXT,
	};

	enum class GLARBClipControl
	{
		ClipControl,
	};

	enum class GLARBDirectStateAccess
	{
		BindTextureUnit,
		BlitNamedFramebuffer,
		CheckNamedFramebufferStatus,
		ClearNamedBufferData,
		ClearNamedBufferSubData,
		ClearNamedFramebufferfi,
		ClearNamedFramebufferfv,
		ClearNamedFramebufferiv,
		ClearNamedFramebufferuiv,
		CompressedTextureSubImage1D,
		CompressedTextureSubImage2D,
		CompressedTextureSubImage3D,
		CopyNamedBufferSubData,
		CopyTextureSubImage1D,
		CopyTextureSubImage2D,
		CopyTextureSubImage3D,
		CreateBuffers,
		CreateFramebuffers,
		CreateProgramPipelines,
		CreateQueries,
		CreateRenderbuffers,
		CreateSamplers,
		CreateTextures,
		CreateTransformFeedbacks,
		CreateVertexArrays,
		DisableVertexArrayAttrib,
		EnableVertexArrayAttrib,
		FlushMappedNamedBufferRange,
		GenerateTextureMipmap,
		GetCompressedTextureImage,
		GetNamedBufferParameteri64v,
		GetNamedBufferParameteriv,
		GetNamedBufferPointerv,
		GetNamedBufferSubData,
		GetNamedFramebufferAttachmentParameteriv,
		GetNamedFramebufferParameteriv,
		GetNamedRenderbufferParameteriv,
		GetQueryBufferObjecti64v,
		GetQueryBufferObjectiv,
		GetQueryBufferObjectui64v,
		GetQueryBufferObjectuiv,
		GetTextureImage,
		GetTextureLevelParameterfv,
		GetTextureLevelParameteriv,
		GetTextureParameterIiv,
		GetTextureParameterIuiv,
		GetTextureParameterfv,
		GetTextureParameteriv,
		GetTransformFeedbacki64_v,
		GetTransformFeedbacki_v,
		GetTransformFeedbackiv,
		GetVertexArrayIndexed64iv,
		GetVertexArrayIndexediv,
		GetVertexArrayiv,
		InvalidateNamedFramebufferData,
		InvalidateNamedFramebufferSubData,
		MapNamedBuffer,
		MapNamedBufferRange,
		NamedBufferData,
		NamedBufferStorage,
		NamedBufferSubData,
		NamedFramebufferDrawBuffer,
		NamedFramebufferDrawBuffers,
		NamedFramebufferParameteri,
		NamedFramebufferReadBuffer,
		NamedFramebufferRenderbuffer,
		NamedFramebufferTexture,
		NamedFramebufferTextureLayer,
		NamedRenderbufferStorage,
		NamedRenderbufferStorageMultisample,
		TextureBuffer,
		TextureBufferRange,
		TextureParameterIiv,
		TextureParameterIuiv,
		TextureParameterf,
		TextureParameterfv,
		TextureParameteri,
		TextureParameteriv,
		TextureStorage1D,
		TextureStorage2D,
		TextureStorage2DMultisample,
		TextureStorage3D,
		TextureStorage3DMultisample,
		TextureSubImage1D,
		TextureSubImage2D,
		TextureSubImage3D,
		TransformFeedbackBufferBase,
		TransformFeedbackBufferRange,
		UnmapNamedBuffer,
		VertexArrayAttribBinding,
		VertexArrayAttribFormat,
		VertexArrayAttribIFormat,
		VertexArrayAttribLFormat,
		VertexArrayBindingDivisor,
		VertexArrayElementBuffer,
		VertexArrayVertexBuffer,
		VertexArrayVertexBuffers,
	};

	enum class GLARBGetTextureSubImage
	{
		GetCompressedTextureSubImage,
		GetTextureSubImage,
	};

	enum class GLARBTextureBarrier
	{
		TextureBarrier,
	};

	enum class GLARBSparseBuffer
	{
		BufferPageCommitmentARB,
	};
}

#endif // SYSTEM_HELPER_GL_ARB_FLAGS_H
