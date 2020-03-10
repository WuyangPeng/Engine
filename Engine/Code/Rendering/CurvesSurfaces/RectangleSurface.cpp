// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:46)

#include "Rendering/RenderingExport.h"

#include "RectangleSurface.h" 
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurfaceDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RectangleSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RectangleSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RectangleSurface); 

Rendering::RectangleSurface
	::RectangleSurface (Mathematics::ParametricSurfacef* surface,int numUSamples, int numVSamples,
						VertexFormatSmartPointer vformat,const Mathematics::Float2* tcoordMin, const Mathematics::Float2* tcoordMax)
	:ParentType(vformat, VertexBufferSmartPointer(), IndexBufferSmartPointer()), mSurface(surface), mNumUSamples(numUSamples), mNumVSamples(numVSamples)
{
    RENDERING_ASSERTION_0(surface && surface->IsRectangular(), "Invalid surface\n");

	SetVertexFormat(vformat); 

    float uMin = mSurface->GetUMin();
    float uRange = mSurface->GetUMax() - uMin;
    float uDelta = uRange/(float)(mNumUSamples - 1);
    float vMin = mSurface->GetVMin();
    float vRange = mSurface->GetVMax() - vMin;
    float vDelta = vRange/(float)(mNumVSamples - 1);

    // Compute the vertices, normals, and texture coordinates.
    int numVertices = mNumUSamples*mNumVSamples;
    int vstride = vformat->GetStride();
	SetVertexBuffer(VertexBufferSmartPointer(NEW0 VertexBuffer(numVertices, vstride)));
    VertexBufferAccessor vba(vformat, GetVertexBuffer());

    float tuDelta = 0.0f, tvDelta = 0.0f;
    if (tcoordMin && tcoordMax)
    {
		tuDelta = ((*tcoordMax).GetFirstValue() - (*tcoordMin).GetFirstValue()) / uRange;
		tvDelta = ((*tcoordMax).GetSecondValue() - (*tcoordMin).GetSecondValue()) / vRange;
    }

    int uIndex, vIndex, i;
    for (uIndex = 0, i = 0; uIndex < mNumUSamples; ++uIndex)
    {
        float uIncr = uDelta*uIndex;
        float u = uMin + uIncr;
        for (vIndex = 0; vIndex < mNumVSamples; ++vIndex, ++i)
        {
            float vIncr = vDelta*vIndex;
            float v = vMin + vIncr;
			
            //vba.Position<Mathematics::Vector3Df>(i) = mSurface->P(u, v);

            if (vba.HasNormal())
            {
                Mathematics::Vector3Df pos, tan0, tan1, normal;
                mSurface->GetFrame(u, v, pos, tan0, tan1, normal);
				
                //vba.Normal<Mathematics::Vector3Df>(i) = normal;
            }

			const int numTCoords = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
            Mathematics::Vector2Df tcoord((*tcoordMin).GetFirstValue() + tuDelta*uIncr,(*tcoordMin).GetSecondValue() + tvDelta*vIncr);
            for (int unit = 0; unit < numTCoords; ++unit)
            {
                if (vba.HasTextureCoord(unit))
                {
                    RENDERING_ASSERTION_0(vba.GetTextureCoordChannels(unit) == 2,"Texture coordinate must be 2D\n");
					
                   // vba.TCoord<Float2>(unit, i) = tcoord;
                }
            }
        }
    }

    // Compute the surface triangle indices.
    int numTriangles = 2*(mNumUSamples-1)*(mNumVSamples-1);
    int numIndices = 3*numTriangles;
	SetIndexBuffer(IndexBufferSmartPointer(NEW0 IndexBuffer(numIndices, sizeof(int))));
	// ÏÈÍ¨¹ý±àÒë
	
    int* indices = (int*)GetIndexBuffer()->GetReadOnlyData();
    for (uIndex = 0, i = 0; uIndex < mNumUSamples - 1; ++uIndex)
    {
        int i0 = i;
        int i1 = i0 + 1;
        i += mNumVSamples;
        int i2 = i;
        int i3 = i2 + 1;
        for (vIndex = 0; vIndex < mNumVSamples - 1; ++vIndex, indices += 6)
        {
            indices[0] = i0;
            indices[1] = i1;
            indices[2] = i2;
            indices[3] = i1;
            indices[4] = i3;
            indices[5] = i2;
            i0++;
            i1++;
            i2++;
            i3++;
        }
    }
	
	UpdateModelSpace(VisualUpdateType::Normals);
}

Rendering::RectangleSurface
	::~RectangleSurface ()
{
    DELETE0(mSurface);
}

void Rendering::RectangleSurface
	::UpdateSurface ()
{
    float uMin = mSurface->GetUMin();
    float uDelta = (mSurface->GetUMax() - uMin)/(float)(mNumUSamples - 1);
    float vMin = mSurface->GetVMin();
    float vDelta = (mSurface->GetVMax() - vMin)/(float)(mNumVSamples - 1);

    VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());
    for (int uIndex = 0, i = 0; uIndex < mNumUSamples; ++uIndex)
    {
        float u = uMin + uDelta*uIndex;
        for (int vIndex = 0; vIndex < mNumVSamples; ++vIndex, ++i)
        {
            float v = vMin + vDelta*vIndex;
			 
           // vba.Position<Mathematics::Vector3Df>(i) = mSurface->P(u, v);

            if (vba.HasNormal())
            {
                Mathematics::Vector3Df pos, tan0, tan1, normal;
                mSurface->GetFrame(u, v, pos, tan0, tan1, normal);
				  
                // vba.Normal<Mathematics::Vector3Df>(i) = normal;
            }
        }
    }

	UpdateModelSpace(VisualUpdateType::Normals);
	RENDERER_MANAGE_SINGLETON.UpdateAll(GetVertexBuffer().GetData());
    
}



// Streaming support.

Rendering::RectangleSurface
	::RectangleSurface (LoadConstructor value)
    :ParentType(value), mSurface(0), mNumUSamples(0), mNumVSamples(0)
{
}

void Rendering::RectangleSurface
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	ParentType::Load(source);

    source.Read(mNumUSamples);
    source.Read(mNumVSamples);

    // TODO.  See note in RectangleSurface::Save.
    mSurface = 0;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::RectangleSurface
	::Link(CoreTools::ObjectLink& source)
{
	ParentType::Link(source);
}

void Rendering::RectangleSurface
	::PostLink ()
{
	ParentType::PostLink();
}

uint64_t Rendering::RectangleSurface
	::Register(CoreTools::ObjectRegister& target) const
{
	return ParentType::Register(target);
}

void Rendering::RectangleSurface
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);

    target.Write(mNumUSamples);
    target.Write(mNumVSamples);

    // TODO.  The class ParametricSurface3 is abstract and does not know
    // about the data representation for the derived-class object that is
    // passed to the RectangleSurface constructor.  Because of this, any
    // loaded RectangleSurface object will require the application to
    // manually set the surface via the SetSurface() member function.
    //
    // Streaming support should be added to the surface classes.

    CORE_TOOLS_END_DEBUG_STREAM_SAVE( target);
}

int Rendering::RectangleSurface
	::GetStreamingSize () const
{
	int size = ParentType::GetStreamingSize();
    size += sizeof(mNumUSamples);
    size += sizeof(mNumVSamples);
    return size;
}


void Rendering::RectangleSurface
	::SetSurface(Mathematics::ParametricSurfacef* surface)
{
	mSurface = surface;
}

const Mathematics::ParametricSurfacef* Rendering::RectangleSurface
	::GetSurface() const
{
	return mSurface;
}

 int Rendering::RectangleSurface
		::GetNumUSamples() const
{
	return mNumUSamples;
}

 int Rendering::RectangleSurface
	 ::GetNumVSamples() const
{
	return mNumVSamples;
}

