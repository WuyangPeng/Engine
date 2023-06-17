///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:44)

#ifndef RENDERING_SHADERS_FWD_H
#define RENDERING_SHADERS_FWD_H

namespace Rendering
{
    class SingleShaderBaseData;
    class ShaderBaseData;
    class SingleShaderConstantsData;
    class ShaderConstantsData;
    class SingleShaderSamplerData;
    class ShaderSamplerData;
    class ShaderManager;
    class ShaderParameters;
    class ShaderBase;
    class PixelShader;
    class VertexShader;
    class SingleShaderProfileData;
    class ShaderProfileData;
    class AlphaState;
    class CullState;
    class DepthState;
    class StencilState;
    class WireState;
    class OffsetState;
    class VisualPass;
    class VisualTechnique;
    class VisualEffect;
    class SaveVisualEffect;
    class LoadVisualEffect;
    class VisualEffectInstance;

    enum class ShaderDataLookup;
    enum class ShaderAPIType;

    class ShaderData;
    class Shader;
    class VisualProgram;
    class ComputeProgram;
    class ProgramFactory;
    class ProgramDefines;
}

#endif  // RENDERING_SHADERS_FWD_H