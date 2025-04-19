/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/13 23:43)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderAPIType.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(ProgramFactoryImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProgramFactory
    {
    public:
        NON_COPY_TYPE_DECLARE(ProgramFactory);

        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;
        using ProgramSources = std::array<std::string, System::EnumCastUnderlying(ShaderAPIType::NumAPI)>;

    public:
        explicit ProgramFactory(RendererTypes rendererTypes);

        CLASS_INVARIANT_DECLARE;

        /// ���ص�ֵ������Ӧ����ɫ����������͡�
        /// Ŀǰ��GLSLProgramFactory����GLSL��
        /// HLSLProgramFactory�򷵻�HLSL��
        NODISCARD ShaderAPIType GetAPI() const noexcept;

        /// ����GPU��ʾ����
        /// ��Щ�ļ��������ء�ת��Ϊ�ַ����������ݸ�ʵ�����CreateFromNamedSources������
        /// �ļ�����Ϊ��xShaderName���������ݸ�CreateFromNamedSources������
        /// �Է�ֹ��ɫ����������#include·����������Ҫ�˲�����
        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource);

        /// ����GPU�������
        /// ��Щ�ļ��������ء�ת��Ϊ�ַ����������ݸ�ʵ�����CreateFromNamedSources������
        /// �ļ�����Ϊ��computeShaderName���������ݸ�CreateFromNamedSources������
        /// �Է�ֹ��ɫ����������#include·����������Ҫ�˲�����
        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& computeShaderFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& computeShaderSource);

        /// �ڹ�����Χ�ڣ��Է�Ч����Ҫ�ļ��е�Դ�����ַ�����
        /// ���磬OverlayEffect����ʹ�ô�ѡ�
        NODISCARD static std::string GetStringFromFile(const std::string& fileName);

        /// ֧�ֽ�ProgramFactory���󴫵ݸ������޸ġ�defines����flags����
        /// ������ʱ��Ҫ�ָ���ǰ״̬�ĺ�����
        /// PushDefines()��������ǰ�ġ�defines�������ڶ�ջ�ϣ�Ȼ�������define����
        /// PushFlags()��������ǰ�ġ�flags�������ڶ�ջ�ϣ�Ȼ�󽫡�flags������Ϊ�㡣
        /// �����Ҫ�޸���һ��Ա����Ԫ�أ�������Լ����й���
        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

        /// ������ڹ������򹤳�ʱ��Ҫ��Ĭ�ϰ汾��ͬ��GLSL�汾��
        /// �������Ӧ�ó����ʼ��ʱ����һ�Ρ�defaultVersion����
        /// ����������CPU����ҪOpenGL 4.5�Ľӿڣ�
        /// ��GLSL����İ汾��4.30����֧�ּ�����ɫ����
        void SetVersion(const std::string& defaultVersion);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_H
