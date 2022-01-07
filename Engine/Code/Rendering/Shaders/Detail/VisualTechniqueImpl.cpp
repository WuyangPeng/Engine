// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:49)

#include "Rendering/RenderingExport.h"

#include "VisualTechniqueImpl.h"

#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26418)
using std::string;
using std::vector;

Rendering::VisualTechniqueImpl ::VisualTechniqueImpl()
    : m_Passes{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualTechniqueImpl)

int Rendering::VisualTechniqueImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CORE_TOOLS_STREAM_SIZE(m_Passes);
}

void Rendering::VisualTechniqueImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //target.WriteSharedPtr(m_Passes);
}

void Rendering::VisualTechniqueImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //source.ReadSharedPtr(m_Passes);
}

void Rendering::VisualTechniqueImpl ::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    if (!m_Passes.empty())
    {
        //source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_Passes.size()), &m_Passes[0]);
    }
}

void Rendering::VisualTechniqueImpl ::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    if (!m_Passes.empty())
    {
        //target.RegisterSharedPtr(boost::numeric_cast<int>(m_Passes.size()), &m_Passes[0]);
    }
}

void Rendering::VisualTechniqueImpl ::InsertPass(const VisualPassSharedPtr& pass)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(pass != nullptr, " ‰»Îµƒpass±ÿ–Î «”––ßµƒ°£");

    m_Passes.push_back(pass);
}

int Rendering::VisualTechniqueImpl ::GetNumPasses() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Passes.size());
}

const Rendering::ConstVisualPassSharedPtr Rendering::VisualTechniqueImpl ::GetPass(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex];
}

const Rendering::ConstVertexShaderSharedPtr Rendering::VisualTechniqueImpl ::GetVertexShader(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetVertexShader();
}

const Rendering::ConstPixelShaderSharedPtr Rendering::VisualTechniqueImpl ::GetPixelShader(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetPixelShader();
}

const Rendering::ConstAlphaStateSharedPtr Rendering::VisualTechniqueImpl ::GetAlphaState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetAlphaState();
}

const Rendering::ConstCullStateSharedPtr Rendering::VisualTechniqueImpl ::GetCullState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetCullState();
}

const Rendering::ConstDepthStateSharedPtr Rendering::VisualTechniqueImpl ::GetDepthState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetDepthState();
}

const Rendering::ConstOffsetStateSharedPtr Rendering::VisualTechniqueImpl ::GetOffsetState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetOffsetState();
}

const Rendering::ConstStencilStateSharedPtr Rendering::VisualTechniqueImpl ::GetStencilState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetStencilState();
}

const Rendering::ConstWireStateSharedPtr Rendering::VisualTechniqueImpl ::GetWireState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "À˜“˝¥ÌŒÛ£°");

    return m_Passes[passIndex]->GetWireState();
}

CoreTools::ObjectSharedPtr Rendering::VisualTechniqueImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& pointer : m_Passes)
    {
        auto found = pointer->GetObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return CoreTools::ObjectSharedPtr();
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualTechniqueImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects;

    for (auto& pointer : m_Passes)
    {
        auto singleObjects = pointer->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualTechniqueImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& pointer : m_Passes)
    {
        auto found = pointer->GetConstObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return CoreTools::ConstObjectSharedPtr();
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualTechniqueImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ConstObjectSharedPtr> objects;

    for (const auto& pointer : m_Passes)
    {
        auto singleObjects = pointer->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

void Rendering::VisualTechniqueImpl ::SaveVisualPass(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numPasses = GetNumPasses();
    manager.Write(sizeof(int), &numPasses);
    for (auto i = 0; i < numPasses; ++i)
    {
        m_Passes[i]->SaveShader(manager);
        m_Passes[i]->SaveState(manager);
    }
}

void Rendering::VisualTechniqueImpl ::LoadVisualPass(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numPasses = 0;
    manager.Read(sizeof(int), &numPasses);

    for (auto i = 0; i < numPasses; ++i)
    {
        VisualPassSharedPtr pass{ std::make_shared<VisualPass>() };

        pass->LoadShader(manager);
        pass->LoadState(manager);

        InsertPass(pass);
    }
}
#include STSTEM_WARNING_POP
