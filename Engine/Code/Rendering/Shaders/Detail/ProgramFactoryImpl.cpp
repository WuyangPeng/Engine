/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/13 23:58)

#include "Rendering/RenderingExport.h"

#include "NullProgramFactory.h"
#include "ProgramFactoryImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/DirectX11Renderer/Detail/HLSL/HLSLProgramFactory.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLProgramFactory.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

Rendering::ProgramFactoryImpl::ProgramFactoryImpl(CoreTools::DisableNotThrow disableNotThrow)
    : version{},
      vertexShaderEntry{},
      pixelShaderEntry{},
      geometryShaderEntry{},
      computeShaderEntry{},
      defines{ ProgramDefines::Create() },
      flags{},
      definesStack{},
      flagsStack{}
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProgramFactoryImpl::ProgramFactoryImpl(std::string version, std::string vertexShaderEntry, std::string pixelShaderEntry, std::string geometryShaderEntry, std::string computeShaderEntry, int flags)
    : version{ std::move(version) },
      vertexShaderEntry{ std::move(vertexShaderEntry) },
      pixelShaderEntry{ std::move(pixelShaderEntry) },
      geometryShaderEntry{ std::move(geometryShaderEntry) },
      computeShaderEntry{ std::move(computeShaderEntry) },
      defines{ ProgramDefines::Create() },
      flags{ flags },
      definesStack{},
      flagsStack{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramFactoryImpl)

Rendering::ProgramFactoryImpl::VisualProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile)
{
    RENDERING_CLASS_IS_VALID_9;

    if (vertexShaderFile.empty() || pixelShaderFile.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("一个程序必须有一个顶点着色器和一个像素着色器。"s))
    }

    const auto vertexShaderSource = GetStringFromFile(vertexShaderFile);
    const auto pixelShaderSource = GetStringFromFile(pixelShaderFile);

    std::string geometryShaderSource{};
    if (!geometryShaderFile.empty())
    {
        geometryShaderSource = GetStringFromFile(geometryShaderFile);
    }

    return CreateFromNamedSources(vertexShaderFile, vertexShaderSource, pixelShaderFile, pixelShaderSource, geometryShaderFile, geometryShaderSource);
}

Rendering::ProgramFactoryImpl::VisualProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return CreateFromNamedSources("vs", vertexShaderSource, "ps", pixelShaderSource, "gs", geometryShaderSource);
}

Rendering::ProgramFactoryImpl::ComputeProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromFile(const std::string& computeShaderFile)
{
    RENDERING_CLASS_IS_VALID_9;

    if (computeShaderFile.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("一个程序必须有一个计算着色器。"s))
    }

    const auto computeShaderSource = GetStringFromFile(computeShaderFile);

    return CreateFromNamedSource(computeShaderFile, computeShaderSource);
}

Rendering::ProgramFactoryImpl::ComputeProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromSource(const std::string& computeShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return CreateFromNamedSource("cs", computeShaderSource);
}

std::string Rendering::ProgramFactoryImpl::GetStringFromFile(const std::string& fileName)
{
    const CoreTools::IFileStreamManager manager{ CoreTools::StringConversion::MultiByteConversionStandard(fileName) };

    auto shaderSource = CoreTools::StringConversion::StandardConversionMultiByte(manager.GetFileContent());

    if (shaderSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("空的着色器源字符串。"s))
    }

    return shaderSource;
}

void Rendering::ProgramFactoryImpl::PushDefines()
{
    RENDERING_CLASS_IS_VALID_9;

    definesStack.emplace(defines);
    defines.Clear();
}

void Rendering::ProgramFactoryImpl::PopDefines()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!definesStack.empty())
    {
        defines = definesStack.top();
        definesStack.pop();
    }
}

void Rendering::ProgramFactoryImpl::PushFlags()
{
    RENDERING_CLASS_IS_VALID_9;

    flagsStack.emplace(flags);
    flags = 0;
}

void Rendering::ProgramFactoryImpl::PopFlags() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (!flagsStack.empty())
    {
        flags = flagsStack.top();
        flagsStack.pop();
    }
}

Rendering::ProgramFactoryImpl::ProgramFactorySharedPtr Rendering::ProgramFactoryImpl::Create(RendererTypes rendererTypes)
{
    switch (rendererTypes)
    {
        case RendererTypes::Glut:
        case RendererTypes::OpenGL:
        case RendererTypes::OpenGLES:
            return GLSLProgramFactory::Create();

        case RendererTypes::DirectX11:
            return std::make_shared<HLSLProgramFactory>(CoreTools::DisableNotThrow::Disable);

        case RendererTypes::Windows:
            return std::make_shared<NullProgramFactory>(CoreTools::DisableNotThrow::Disable);

        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("Program工厂类型未定义。"s))
}

std::string Rendering::ProgramFactoryImpl::GetVersion() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return version;
}

int Rendering::ProgramFactoryImpl::GetDefinesSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return defines.GetSize();
}

Rendering::ProgramDefines Rendering::ProgramFactoryImpl::GetProgramDefines() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return defines;
}

Rendering::ProgramFactoryImpl::ContainerConstIter Rendering::ProgramFactoryImpl::begin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return defines.begin();
}

Rendering::ProgramFactoryImpl::ContainerConstIter Rendering::ProgramFactoryImpl::end() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return defines.end();
}

void Rendering::ProgramFactoryImpl::SetVersion(const std::string& defaultVersion)
{
    RENDERING_CLASS_IS_VALID_9;

    version = defaultVersion;
}
