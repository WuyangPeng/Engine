/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/13 23:43)

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

        /// 返回的值用作对应于着色器程序的类型。
        /// 目前，GLSLProgramFactory返回GLSL，
        /// HLSLProgramFactory则返回HLSL。
        NODISCARD ShaderAPIType GetAPI() const noexcept;

        /// 创建GPU显示程序。
        /// 这些文件将被加载、转换为字符串，并传递给实现类的CreateFromNamedSources函数。
        /// 文件名作为“xShaderName”参数传递给CreateFromNamedSources函数，
        /// 以防止着色器编译器在#include路径搜索中需要此参数。
        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource);

        /// 创建GPU计算程序。
        /// 这些文件将被加载、转换为字符串，并传递给实现类的CreateFromNamedSources函数。
        /// 文件名作为“computeShaderName”参数传递给CreateFromNamedSources函数，
        /// 以防止着色器编译器在#include路径搜索中需要此参数。
        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& computeShaderFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& computeShaderSource);

        /// 在公共范围内，以防效果需要文件中的源代码字符串。
        /// 例如，OverlayEffect可以使用此选项。
        NODISCARD static std::string GetStringFromFile(const std::string& fileName);

        /// 支持将ProgramFactory对象传递给可能修改“defines”或“flags”，
        /// 但返回时需要恢复以前状态的函数。
        /// PushDefines()函数将当前的“defines”保存在堆栈上，然后清除“define”。
        /// PushFlags()函数将当前的“flags”保存在堆栈上，然后将“flags”设置为零。
        /// 如果需要修改任一成员的子元素，则必须自己进行管理。
        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

        /// 如果您在构建程序工厂时想要与默认版本不同的GLSL版本，
        /// 则可以在应用程序初始化时设置一次“defaultVersion”。
        /// 尽管我们在CPU端需要OpenGL 4.5的接口，
        /// 但GLSL所需的版本是4.30，以支持计算着色器。
        void SetVersion(const std::string& defaultVersion);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_H
