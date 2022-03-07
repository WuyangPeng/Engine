// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:23)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshTriangle.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
Mathematics::BasicMeshTriangle

    ::BasicMeshTriangle() noexcept
    : m_Vertex{}, m_Edge{}, triangle{}
{
    for (int i = 0; i < 3; ++i)
    {
        m_Vertex[i] = -1;
        m_Edge[i] = -1;
        triangle[i] = -1;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BasicMeshTriangle ::BasicMeshTriangle(const BasicMeshTriangle& rhs) noexcept
    : m_Vertex{}, m_Edge{}, triangle{}
{
    for (int i = 0; i < 3; ++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
        m_Edge[i] = rhs.m_Edge[i];
        triangle[i] = rhs.triangle[i];
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BasicMeshTriangle& Mathematics::BasicMeshTriangle ::operator=(const BasicMeshTriangle& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (int i = 0; i < 3; ++i)
    {
        m_Vertex[i] = rhs.m_Vertex[i];
        m_Edge[i] = rhs.m_Edge[i];
        triangle[i] = rhs.triangle[i];
    }

    return *this;
}
CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshTriangle)

int Mathematics::BasicMeshTriangle ::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < 3)
    {
        return m_Vertex[index];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}

int Mathematics::BasicMeshTriangle ::GetEdge(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < 3)
    {
        return m_Edge[index];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}

int Mathematics::BasicMeshTriangle ::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < 3)
    {
        return triangle[index];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}

void Mathematics::BasicMeshTriangle ::SetVertex(int index, int vertex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= index && index < 3)
    {
        m_Vertex[index] = vertex;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}

void Mathematics::BasicMeshTriangle ::SetEdge(int index, int edge)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= index && index < 3)
    {
        m_Edge[index] = edge;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}

void Mathematics::BasicMeshTriangle ::SetTriangle(int index, int triangle0)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= index && index < 3)
    {
        triangle[index] = triangle0;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"s));
    }
}
#include STSTEM_WARNING_POP
