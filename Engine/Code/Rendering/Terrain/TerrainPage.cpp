// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:58)

#include "Rendering/RenderingExport.h"

#include "TerrainPage.h" 
#include "Rendering/SceneGraph/StandardMesh.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/ExceptionMacro.h" 

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26493)
CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainPage);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainPage);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainPage); 

Rendering::TerrainPage
	::TerrainPage (VertexFormatSharedPtr vformat, int size, unsigned short* heights, const Mathematics::Float2& origin, float minElevation, float maxElevation, float spacing)
	:ParentType(vformat,VertexBufferSharedPtr(),IndexBufferSharedPtr()),mSize(size),mSizeM1(size - 1),
     mHeights(heights),mOrigin(origin), mMinElevation(minElevation), mMaxElevation(maxElevation), mSpacing(spacing)
{
    // size = 2^p + 1, p <= 7
    RENDERING_ASSERTION_0(size ==  3 || size ==  5 || size ==   9 || size == 17 || size == 33 || size == 65 || size == 129, "Invalid page size\n");

    mInvSpacing = 1.0f/mSpacing;
    mMultiplier = (mMaxElevation - mMinElevation)/65535.0f;

    // Create a mesh for the page.
    const float ext = mSpacing*mSizeM1;
    TrianglesMeshSharedPtr mesh = StandardMesh(vformat).Rectangle(mSize, mSize, ext, ext);
    SetVertexFormat(vformat);
    SetVertexBuffer( mesh->GetVertexBuffer());
    SetIndexBuffer(mesh->GetIndexBuffer());     

    // Modify the vertices to use the terrain data.
	VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());
	int numVertices = GetVertexBuffer()->GetNumElements();
    for (int i = 0; i < numVertices; ++i)
    {
         const int x = i % mSize;
         const int y = i / mSize;

		 GetVertexBuffer()->SetPosition(vba, i, Mathematics::FloatAPoint(GetX(x), GetY(y), GetHeight(i)));       
    }

	UpdateModelSpace(VisualUpdateType::Normals);
}

Rendering::TerrainPage
	::~TerrainPage ()
{
	EXCEPTION_TRY
{
 //DELETE1(mHeights);
}
EXCEPTION_ALL_CATCH(Rendering)  
    
}

float Rendering::TerrainPage
	::GetHeight (float x, float y) const
{
    const float xGrid = (x - mOrigin[0]) * mInvSpacing;
    if (xGrid < 0.0f || xGrid >= (float)mSizeM1)
    {
        // Location not in page.
        return Mathematics::FloatMath::sm_MaxReal;
    }

    const float yGrid = (y - mOrigin[1])*mInvSpacing;
    if (yGrid < 0.0f || yGrid >= (float)mSizeM1)
    {
        // Location not in page.
        return Mathematics::FloatMath::sm_MaxReal;
    }

	const float fCol = Mathematics::FloatMath::Floor(xGrid);
    const int iCol = (int)fCol;
	const float fRow = Mathematics::FloatMath::Floor(yGrid);
    const int iRow = (int)fRow;

   const int index = iCol + mSize*iRow;
  const  float dx = xGrid - fCol;
  const float dy = yGrid - fRow;
    float h00 = 0.0f, h10= 0.0f, h01= 0.0f, h11= 0.0f, height= 0.0f;

    if ((iCol & 1) == (iRow & 1))
    {
        const float diff = dx - dy;
        h00 = mMinElevation + mMultiplier*mHeights[index];
        h11 = mMinElevation + mMultiplier*mHeights[index + 1 + mSize];
        if (diff > 0.0f)
        {
            h10 = mMinElevation + mMultiplier*mHeights[index + 1];
            height = (1.0f - diff - dy)*h00 + diff*h10 + dy*h11;
        }
        else
        {
            h01 = mMinElevation + mMultiplier*mHeights[index + mSize];
            height = (1.0f + diff - dx)*h00 - diff*h01 + dx*h11;
        }
    }
    else
    {
        const float sum = dx + dy;
        h10 = mMinElevation + mMultiplier*mHeights[index + 1];
        h01 = mMinElevation + mMultiplier*mHeights[index + mSize];
        if (sum <= 1.0f)
        {
            h00 = mMinElevation + mMultiplier*mHeights[index];
            height = (1.0f - sum)*h00 + dx*h10 + dy*h01;
        }
        else
        {
            h11 = mMinElevation + mMultiplier*mHeights[index + 1 + mSize];
            height = (sum - 1.0f)*h11 + (1.0f - dy)*h10 + (1.0f - dx)*h01;
        }
    }

    return height;
}



// Streaming support.

Rendering::TerrainPage
	::TerrainPage (LoadConstructor value)
    : ParentType(value), mSize(0), mSizeM1(0), mHeights(0),mOrigin(Mathematics::Float2(0.0f, 0.0f)),
    mMinElevation(0.0f), mMaxElevation(0.0f), mSpacing(0.0f), mInvSpacing(0.0f),  mMultiplier(0.0f)
{
}

void Rendering::TerrainPage
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	ParentType::Load(source);

    source.Read(mSize);
    const int numVertices = mSize*mSize;
  //  source.Read(numVertices, mHeights);
    source.ReadAggregate(mOrigin);
    source.Read(mMinElevation);
    source.Read(mMaxElevation);
    source.Read(mSpacing);

    mSizeM1 = mSize - 1;
    mInvSpacing = 1.0f/mSpacing;
    mMultiplier = (mMaxElevation - mMinElevation)/65535.0f;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TerrainPage
	::Link(CoreTools::ObjectLink& source)
{
	ParentType::Link(source);
}

void Rendering::TerrainPage
	::PostLink ()
{
	ParentType::PostLink();
}

uint64_t Rendering::TerrainPage
	::Register(CoreTools::ObjectRegister& target) const
{
	return ParentType::Register(target);
}

void Rendering::TerrainPage
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);

    target.Write(mSize);
    const int numVertices = mSize*mSize;
   // target.WriteWithNumber(numVertices, mHeights);
    target.WriteAggregate(mOrigin);
    target.Write(mMinElevation);
    target.Write(mMaxElevation);
    target.Write(mSpacing);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TerrainPage
	::GetStreamingSize () const
{
	int size = ParentType::GetStreamingSize();
    size += sizeof(mSize);
    size += mSize*mSize*sizeof(mHeights[0]);
    size += sizeof(mOrigin);
    size += sizeof(mMinElevation);
    size += sizeof(mMaxElevation);
    size += sizeof(mSpacing);
    return size;
}


 int Rendering::TerrainPage
	 ::GetSize () const noexcept
{
	return mSize;
}

 const unsigned short* Rendering::TerrainPage
	 ::GetHeights () const noexcept
{
	return mHeights;
}

 const Mathematics:: Float2& Rendering::TerrainPage
	 ::GetOrigin () const noexcept
{
	return mOrigin;
}

 float Rendering::TerrainPage
	 ::GetMinElevation () const noexcept
{
	return mMinElevation;
}

 float Rendering::TerrainPage
	 ::GetMaxElevation () const noexcept
{
	return mMaxElevation;
}

 float Rendering::TerrainPage
	 ::GetSpacing () const noexcept
{
	return mSpacing;
}

 float Rendering::TerrainPage
	 ::GetX (int x) const
{
     return mOrigin[0] + mSpacing * (float)x;
 }

 float Rendering::TerrainPage
	 ::GetY (int y) const
{
     return mOrigin[1] + mSpacing * (float)y;
 }

 float Rendering::TerrainPage
	 ::GetHeight (int index) const noexcept
{
	return mMinElevation + mMultiplier*(float)mHeights[index];
}

#include STSTEM_WARNING_POP