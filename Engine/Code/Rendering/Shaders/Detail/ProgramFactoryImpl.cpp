///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/20 16:17)

#include "Rendering/RenderingExport.h"

#include "ProgramFactoryImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLProgramFactory.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

Rendering::ProgramFactoryImpl::ProgramFactoryImpl(CoreTools::DisableNotThrow disableNotThrow)
    : version{},
      vsEntry{},
      psEntry{},
      gsEntry{},
      csEntry{},
      defines{ disableNotThrow },
      flags{},
      definesStack{},
      flagsStack{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProgramFactoryImpl::ProgramFactoryImpl(const std::string& version, const std::string& vsEntry, const std::string& psEntry, const std::string& gsEntry, const std::string& csEntry, int flags)
    : version{ version },
      vsEntry{ vsEntry },
      psEntry{ psEntry },
      gsEntry{ gsEntry },
      csEntry{ csEntry },
      defines{ CoreTools::DisableNotThrow::Disable },
      flags{ flags },
      definesStack{},
      flagsStack{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramFactoryImpl)

Rendering::ProgramFactoryImpl::VisualProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromFiles(const std::string& vsFile, const std::string& psFile, const std::string& gsFile)
{
    RENDERING_CLASS_IS_VALID_9;

    if (vsFile.empty() || psFile.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("һ�����������һ��������ɫ����һ��������ɫ����"s));
    }

    auto vsSource = GetStringFromFile(vsFile);
    auto psSource = GetStringFromFile(psFile);

    std::string gsSource{};
    if (!gsFile.empty())
    {
        gsSource = GetStringFromFile(gsFile);
    }

    return CreateFromNamedSources(vsFile, vsSource, psFile, psSource, gsFile, gsSource);
}

Rendering::ProgramFactoryImpl::VisualProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromSources(const std::string& vsSource, const std::string& psSource, const std::string& gsSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return CreateFromNamedSources("vs", vsSource, "ps", psSource, "gs", gsSource);
}

Rendering::ProgramFactoryImpl::ComputeProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromFile(const std::string& csFile)
{
    RENDERING_CLASS_IS_VALID_9;

    if (csFile.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("һ�����������һ��������ɫ����"s));
    }

    std::string csSource = GetStringFromFile(csFile);

    return CreateFromNamedSource(csFile, csSource);
}

Rendering::ProgramFactoryImpl::ComputeProgramSharedPtr Rendering::ProgramFactoryImpl::CreateFromSource(const std::string& csSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return CreateFromNamedSource("cs", csSource);
}

std::string Rendering::ProgramFactoryImpl::GetStringFromFile(const std::string& filename)
{
    CoreTools::IFStreamManager manager{ CoreTools::StringConversion::MultiByteConversionStandard(filename) };

    return CoreTools::StringConversion::StandardConversionMultiByte(manager.GetFileContent());
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

    if (definesStack.size() > 0)
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
            return std::make_shared<GLSLProgramFactory>(CoreTools::DisableNotThrow::Disable);

        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("Program��������δ���塣"s));
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