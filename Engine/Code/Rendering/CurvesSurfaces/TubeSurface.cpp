// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 17:58)

#include "Rendering/RenderingExport.h"

#include "TubeSurface.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TubeSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TubeSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TubeSurface);  

Rendering::TubeSurface
	::TubeSurface (Mathematics::Curve3f* medial, RadialFunction radial, bool closed, const Mathematics::Vector3Df& upVector, int numMedialSamples,int numSliceSamples,
				   bool sampleByArcLength, bool insideView, const Mathematics::Float2* tcoordMin, const Mathematics::Float2* tcoordMax,VertexFormatSmartPointer vformat)
    :ParentType(vformat, VertexBufferSmartPointer(), IndexBufferSmartPointer()), mMedial(medial), mRadial(radial), mNumMedialSamples(numMedialSamples),
     mNumSliceSamples(numSliceSamples), mUpVector(upVector),mSin(0), mCos(0), mClosed(closed), mSampleByArcLength(sampleByArcLength)
{
    // Compute the surface vertices.
    int numVertices;
    if (mClosed)
    {
        numVertices = (mNumSliceSamples + 1)*(mNumMedialSamples + 1);
    }
    else
    {
        numVertices = (mNumSliceSamples + 1)*mNumMedialSamples;
    }

    SetVertexFormat(vformat);
    int vstride = vformat->GetStride();
    SetVertexBuffer(VertexBufferSmartPointer(NEW0 VertexBuffer(numVertices, vstride)));

    ComputeSinCos();
    ComputeVertices();

    // Compute the surface normals.
    if (GetVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Normal) >= 0)
    {
        ComputeNormals();
    }

    // Compute the surface textures coordinates.
    if (tcoordMin && tcoordMax)
    {
        ComputeUVs(*tcoordMin, *tcoordMax);
    }

    // Compute the surface triangle connectivity.
    ComputeIndices(insideView);

    UpdateModelSpace(VisualUpdateType::Normals);
}

Rendering::TubeSurface
	::~TubeSurface ()
{
    DELETE0(mMedial);
    DELETE1(mSin);
    DELETE1(mCos);
}

void Rendering::TubeSurface
	::ComputeSinCos ()
{
    // Compute slice vertex coefficients.  The first and last coefficients
    // are duplicated to allow a closed cross section that has two different
    // pairs of texture coordinates at the shared vertex.

    mSin = NEW1<float>(mNumSliceSamples + 1);
    mCos = NEW1<float>(mNumSliceSamples + 1);

    float invSliceSamples = 1.0f/(float)mNumSliceSamples;
    for (int i = 0; i < mNumSliceSamples; ++i)
    {
        float angle = Mathematics:: Mathf::sm_TwoPI*invSliceSamples*i;
        mCos[i] = Mathematics::Mathf::Cos(angle);
        mSin[i] = Mathematics::Mathf::Sin(angle);
    }
    mSin[mNumSliceSamples] = mSin[0];
    mCos[mNumSliceSamples] = mCos[0];
}

void Rendering::TubeSurface
	::ComputeVertices ()
{
    float tMin = mMedial->GetMinTime();
    float tRange = mMedial->GetMaxTime() - tMin;

    // Sampling by arc length requires the total length of the curve.
    float totalLength;
    if (mSampleByArcLength)
    {
        totalLength = mMedial->GetTotalLength();
    }
    else
    {
        totalLength = 0.0f;
    }

    // Vertex construction requires a normalized time (uses a division).
    float denom;
    if (mClosed)
    {
        denom = 1.0f/(float)mNumMedialSamples;
    }
    else
    {
        denom = 1.0f/(float)(mNumMedialSamples - 1);
    }

    VertexBufferAccessor vba(this);

    for (int m = 0, v = 0; m < mNumMedialSamples; ++m, ++v)
    {
        float t;
        if (mSampleByArcLength)
        {
            t = mMedial->GetTime(m*totalLength*denom);
        }
        else
        {
            t = tMin + m*tRange*denom;
        }

      //  float radius = mRadial(t);

        // Compute frame.
        Mathematics::Vector3Df position, tangent, normal, binormal;
        if (mUpVector != Mathematics::Vector3Df::sm_Zero)
        {
            // Always use 'up' vector N rather than curve normal.  You must
            // constrain the curve so that T and N are never parallel.  To
            // build the frame from this, let
            //     B = Cross(T,N)/Length(Cross(T,N))
            // and replace
            //     N = Cross(B,T)/Length(Cross(B,T)).
            position = mMedial->GetPosition(t);
            tangent = mMedial->GetTangent(t);
            binormal = Mathematics::Vector3DToolsf::UnitCrossProduct(tangent,mUpVector);
            normal = Mathematics::Vector3DToolsf::UnitCrossProduct(binormal,tangent);
        }
        else
        {
            // Use Frenet frame to create slices.
            mMedial->GetFrame(t, position, tangent, normal, binormal);
        }

        // Compute slice vertices, duplication at end point as noted earlier.
        // int save = v;
        for (int i = 0; i < mNumSliceSamples; ++i, ++v)
        {
		
           // vba.Position<Mathematics::Vector3Df>(v) = position + radius*(mCos[i]*normal +  mSin[i]*binormal);
        }
		
       // vba.Position<Mathematics::Vector3Df>(v) = vba.Position<Mathematics::Vector3Df>(save);
    }

    if (mClosed)
    {
        for (int i = 0; i <= mNumSliceSamples; ++i)
        {
           // int i1 = Index(i, mNumMedialSamples);
           // int i0 = Index(i, 0);
		
           // vba.Position<Mathematics::Vector3Df>(i1) = vba.Position<Mathematics::Vector3Df>(i0);
        }
    }
}

void Rendering::TubeSurface
	::ComputeNormals ()
{
    int s, sM1, sP1, m, mM1, mP1;
    Mathematics::Vector3Df dir0, dir1;

    VertexBufferAccessor vba(this);

    // Compute the interior normals (central differences).
    for (m = 1; m <= mNumMedialSamples - 2; ++m)
    {
        for (s = 0; s < mNumSliceSamples; ++s)
        {
            sM1 = (s > 0 ? s - 1 : mNumSliceSamples - 1);
            sP1 = s + 1;
            mM1 = m - 1;
            mP1 = m + 1;
			 
			/*
            dir0 = vba.Position<Mathematics::Vector3Df>(Index(sM1, m)) -
                vba.Position<Mathematics::Vector3Df>(Index(sP1, m));
            dir1 = vba.Position<Mathematics::Vector3Df>(Index(s, mM1)) -
                vba.Position<Mathematics::Vector3Df>(Index(s, mP1));
            vba.Normal<Mathematics::Vector3Df>(Index(s, m)) = dir0.UnitCross(dir1);*/
        }
		 
		/*
        vba.Normal<Mathematics::Vector3Df>(Index(mNumSliceSamples, m)) =
            vba.Normal<Mathematics::Vector3Df>(Index(0, m));*/
    }

    // Compute the boundary normals.
    if (mClosed)
    {
        // Compute with central differences.
        for (s = 0; s < mNumSliceSamples; ++s)
        {
            sM1 = (s > 0 ? s - 1 : mNumSliceSamples - 1);
            sP1 = s + 1;

            // m = 0
			 
			/*
            dir0 = vba.Position<Mathematics::Vector3Df>(Index(sM1, 0)) -
                vba.Position<Mathematics::Vector3Df>(Index(sP1, 0));
            dir1 = vba.Position<Mathematics::Vector3Df>(Index(s, mNumMedialSamples - 1)) -
                vba.Position<Mathematics::Vector3Df>(Index(s, 1));
            vba.Normal<Mathematics::Vector3Df>(s) = dir0.UnitCross(dir1);

            // m = max
            vba.Normal<Mathematics::Vector3Df>(Index(s, mNumMedialSamples)) =
                vba.Normal<Mathematics::Vector3Df>(Index(s, 0));*/
        }
		 
		/*
        vba.Normal<Mathematics::Vector3Df>(Index(mNumSliceSamples, 0)) =
            vba.Normal<Mathematics::Vector3Df>(Index(0, 0));
        vba.Normal<Mathematics::Vector3Df>(Index(mNumSliceSamples, mNumMedialSamples)) =
            vba.Normal<Mathematics::Vector3Df>(Index(0, mNumMedialSamples));*/
    }
    else
    {
        // Compute with one-sided differences.

        // m = 0
        for (s = 0; s < mNumSliceSamples; ++s)
        {
            sM1 = (s > 0 ? s - 1 : mNumSliceSamples - 1);
            sP1 = s + 1;
			 
			/*
            dir0 = vba.Position<Mathematics::Vector3Df>(Index(sM1, 0)) -
                vba.Position<Mathematics::Vector3Df>(Index(sP1, 0));
            dir1 = vba.Position<Mathematics::Vector3Df>(Index(s, 0)) -
                vba.Position<Mathematics::Vector3Df>(Index(s, 1));
            vba.Normal<Mathematics::Vector3Df>(Index(s, 0)) = dir0.UnitCross(dir1);*/
        }
		 
		/*
        vba.Normal<Mathematics::Vector3Df>(Index(mNumSliceSamples, 0)) =
            vba.Normal<Mathematics::Vector3Df>(Index(0, 0));*/

        // m = max-1
        for (s = 0; s < mNumSliceSamples; ++s)
        {
            sM1 = (s > 0 ? s - 1 : mNumSliceSamples - 1);
            sP1 = s + 1;
			 
			/*
            dir0 = vba.Position<Mathematics::Vector3Df>(Index(sM1, mNumMedialSamples - 1)) -
                vba.Position<Mathematics::Vector3Df>(Index(sP1, mNumMedialSamples - 1));
            dir1 = vba.Position<Mathematics::Vector3Df>(Index(s, mNumMedialSamples - 2)) -
                vba.Position<Mathematics::Vector3Df>(Index(s, mNumMedialSamples - 1));
            vba.Normal<Mathematics::Vector3Df>(s) = dir0.UnitCross(dir1);*/
        }
		 
		/*
        vba.Normal<Mathematics::Vector3Df>(Index(mNumSliceSamples, mNumMedialSamples - 1)) =
            vba.Normal<Mathematics::Vector3Df>(Index(0, mNumMedialSamples - 1));*/
    }
}

void Rendering::TubeSurface
	::ComputeUVs (const Mathematics::Float2& tcoordMin, const Mathematics::Float2& tcoordMax)
{
    VertexBufferAccessor vba(this);

    Mathematics::Float2 tcoordRange(tcoordMax.GetFirstValue() - tcoordMin.GetFirstValue(), tcoordMax.GetSecondValue() - tcoordMin.GetSecondValue() );
    int mMax = (mClosed ? mNumMedialSamples : mNumMedialSamples - 1);
    for (int m = 0, v = 0; m <= mMax; m++)
    {
        float mRatio = ((float)m)/((float)mMax);
        float mValue = tcoordMin.GetSecondValue() + mRatio*tcoordRange.GetSecondValue();
        for (int s = 0; s <= mNumSliceSamples; ++s, ++v)
        {
            float sRatio = ((float)s)/((float)mNumSliceSamples);
            float sValue = tcoordMin.GetFirstValue() + sRatio*tcoordRange.GetFirstValue();
              Mathematics::Float2 tcoord(sValue, mValue);
            const int numTCoords = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
            for (int unit = 0; unit < numTCoords; ++unit)
            {
                if (vba.HasTextureCoord(unit))
                {
                    RENDERING_ASSERTION_0(vba.GetTextureCoordChannels(unit) == 2, "Texture coordinate must be 2D\n");
				 
                   // vba.TCoord<Float2>(unit, v) = tcoord;
                }
            }
        }
    }
}

void Rendering::TubeSurface
	::ComputeIndices (bool insideView)
{
	insideView;
    int numTriangles;
    if (mClosed)
    {
        numTriangles = 2*mNumSliceSamples*mNumMedialSamples;
    }
    else
    {
        numTriangles = 2*mNumSliceSamples*(mNumMedialSamples-1);
    }

    SetIndexBuffer(IndexBufferSmartPointer(NEW0 IndexBuffer(3*numTriangles, sizeof(int))));

	/*
    int* indices = (int*)mIBuffer->GetData();
    int m, mStart, i0, i1, i2, i3, i;
    for (m = 0, mStart = 0; m < mNumMedialSamples - 1; ++m)
    {
        i0 = mStart;
        i1 = i0 + 1;
        mStart += mNumSliceSamples + 1;
        i2 = mStart;
        i3 = i2 + 1;
        for (i = 0; i < mNumSliceSamples; ++i, indices += 6)
        {
            if (insideView)
            {
                indices[0] = i0++;
                indices[1] = i2;
                indices[2] = i1;
                indices[3] = i1++;
                indices[4] = i2++;
                indices[5] = i3++;
            }
            else  // outside view
            {
                indices[0] = i0++;
                indices[1] = i1;
                indices[2] = i2;
                indices[3] = i1++;
                indices[4] = i3++;
                indices[5] = i2++;
            }
        }
    }
	
    if (mClosed)
    {
        i0 = mStart;
        i1 = i0 + 1;
        i2 = 0;
        i3 = i2 + 1;
        for (i = 0; i < mNumSliceSamples; ++i, indices += 6)
        {
            if (insideView)
            {
                indices[0] = i0++;
                indices[1] = i2;
                indices[2] = i1;
                indices[3] = i1++;
                indices[4] = i2++;
                indices[5] = i3++;
            }
            else  // outside view
            {
                indices[0] = i0++;
                indices[1] = i1;
                indices[2] = i2;
                indices[3] = i1++;
                indices[4] = i3++;
                indices[5] = i2++;
            }
        }
    }*/
}

void Rendering::TubeSurface
	::GetTMinSlice (Mathematics::Vector3Df* slice)
{
    VertexBufferAccessor vba(this);
    for (int i = 0; i <= mNumSliceSamples; ++i)
    {
        slice[i] = vba.GetPosition<Mathematics::Vector3Df>(i);
    }
}

void Rendering::TubeSurface
	::GetTMaxSlice (Mathematics::Vector3Df* slice)
{
    VertexBufferAccessor vba(this);
    int j = GetVertexBuffer()->GetNumElements() - mNumSliceSamples - 1;
    for (int i = 0; i <= mNumSliceSamples; ++i, ++j)
    {
        slice[i] = vba.GetPosition<Mathematics::Vector3Df>(j);
    }
}

void Rendering::TubeSurface
	::UpdateSurface ()
{
    ComputeVertices();
    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    if (GetVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Normal) >= 0)
    {
        ComputeNormals();
    }
	RENDERER_MANAGE_SINGLETON.UpdateAll(GetVertexBuffer().GetData()); 
}



// Streaming support.

Rendering::TubeSurface
	::TubeSurface (LoadConstructor value)
    :ParentType(value), mMedial(0),mRadial(0),mNumMedialSamples(0),mNumSliceSamples(0),mUpVector(Mathematics::Vector3Df::sm_Zero),
    mSin(0), mCos(0), mClosed(false), mSampleByArcLength(false)
{
}

void Rendering::TubeSurface
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(mNumMedialSamples);
    source.Read(mNumSliceSamples);
    source.ReadAggregate(mUpVector);
    source.Read(mNumSliceSamples+1, mSin);
    source.Read(mNumSliceSamples+1, mCos);
    mClosed =source.ReadBool();
   mSampleByArcLength = source.ReadBool();

    // TODO.  See note in TubeSurface::Save.
    mMedial = 0;
    mRadial = 0;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TubeSurface
	::Link(CoreTools::ObjectLink& source)
{
    ParentType::Link(source);
}

void Rendering::TubeSurface
	::PostLink ()
{
    ParentType::PostLink();
}

uint64_t Rendering::TubeSurface
	::Register(CoreTools::ObjectRegister& target) const
{
    return ParentType::Register(target);
}

void Rendering::TubeSurface
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(mNumMedialSamples);
    target.Write(mNumSliceSamples);
    target.WriteAggregate(mUpVector);
    target.WriteWithNumber(mNumSliceSamples + 1, mSin);
    target.WriteWithNumber(mNumSliceSamples + 1, mCos);
    target.WriteBool(mClosed);
    target.WriteBool(mSampleByArcLength);

    // TODO.  The class Curve3 is abstract and does not know about the data
    // representation for the derived-class object that is passed to the
    // TubeSurface constructor.  RadialFunction is a type of function.  Saving
    // the function pointer is useless since on loading, there is no current
    // way to 'link' to the correct function pointer.  Because of this, any
    // loaded TubeSurface object will require the application to manually set
    // the curve and function via the Medial() and Radial() members.
    //
    // Streaming support should  be added to the curve classes.

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TubeSurface
	::GetStreamingSize () const
{
    int size = ParentType::GetStreamingSize();
    size += sizeof(mNumMedialSamples);
    size += sizeof(mNumSliceSamples);
    size += sizeof(mUpVector);
    size += (mNumSliceSamples+1)*sizeof(mSin[0]);
    size += (mNumSliceSamples+1)*sizeof(mCos[0]);
    size += CORE_TOOLS_STREAM_SIZE(mClosed);
    size += CORE_TOOLS_STREAM_SIZE(mSampleByArcLength);
    return size;
}


 void Rendering::TubeSurface
	 ::SetMedial(Mathematics:: Curve3f* medial)
{
	mMedial = medial;
}

 const Mathematics::Curve3f* Rendering::TubeSurface
	 ::GetMedial() const
{
	return mMedial;
}

 void Rendering::TubeSurface
	 ::SetRadial(RadialFunction radial)
{
	mRadial = radial;
}

 Rendering::TubeSurface::RadialFunction Rendering::TubeSurface
	 ::GetRadial() const
{
	return mRadial;
}

 void Rendering::TubeSurface
	 ::SetUpVector(const Mathematics::Vector3Df& upVector)
{
	mUpVector = upVector;
}

 const Mathematics::Vector3Df& Rendering::TubeSurface
	 ::GetUpVector() const
{
	return mUpVector;
}

 int Rendering::TubeSurface
	 ::GetNumMedialSamples() const
{
	return mNumMedialSamples;
}

 int Rendering::TubeSurface
	 ::GetNumSliceSamples() const
{
	return mNumSliceSamples;
}

 int Rendering::TubeSurface
	 ::Index(int s, int m)
{
	return s + (mNumSliceSamples + 1)*m;
}

