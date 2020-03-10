// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 15:33)

#include "Rendering/RenderingExport.h"

#include "PlanarShadowEffect.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, PlanarShadowEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PlanarShadowEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PlanarShadowEffect);

Rendering::PlanarShadowEffect
	::PlanarShadowEffect (int numPlanes, Node* shadowCaster)
	:mNumPlanes{ numPlanes },mShadowCaster{ shadowCaster }
{
    mPlanes = NEW1<TrianglesMeshSmartPointer>(mNumPlanes);
    mProjectors = NEW1<LightSmartPointer>(mNumPlanes);
    mShadowColors = NEW1<Mathematics::Float4>(mNumPlanes);

    mAlphaState.Reset(NEW0 AlphaState());
    mDepthState.Reset(NEW0 DepthState());
    mStencilState.Reset(NEW0 StencilState());

    mMaterial.Reset(NEW0 Material());
    mMaterialEffect.Reset(NEW0 MaterialEffect());
    mMaterialEffectInstance.Reset( mMaterialEffect->CreateInstance(mMaterial.GetData()));

    // The material diffuse color changes per plane on every draw call.
    ConstShaderFloatSmartPointer sfloat = mMaterialEffectInstance->GetVertexConstant(0,"MaterialDiffuse");

    const_cast<ShaderFloat*>(sfloat.GetData())->EnableUpdater();
}

Rendering::PlanarShadowEffect
	::~PlanarShadowEffect ()
{
    DELETE1(mPlanes);
    DELETE1(mProjectors);
    DELETE1(mShadowColors);
}

void Rendering::PlanarShadowEffect
	::Draw (Renderer* renderer,const VisibleSet& visibleSet)
{
    // Draw the potentially visible portions of the shadow caster.
    const int numVisible = visibleSet.GetNumVisible();
    int j;
    for (j = 0; j < numVisible; ++j)
    {
        renderer->Draw((const Visual*)visibleSet.GetVisible(j).GetData());
    }

    // Save the current global state overrides for restoration later.
    const ConstDepthStateSmartPointer saveDState = renderer->GetOverrideDepthState();
    const ConstStencilStateSmartPointer saveSState = renderer->GetOverrideStencilState();

    // Override the global state to support this effect.
    renderer->SetOverrideDepthState(mDepthState);
    renderer->SetOverrideStencilState(mStencilState);

    // Get the camera to store post-world transformations.
    ConstCameraSmartPointer camera = renderer->GetCamera();

    for (int i = 0; i < mNumPlanes; ++i)
    {
        // Enable depth buffering.  NOTE: The plane object should not have a
        // ZBufferState object that changes the current settings.
        mDepthState->SetEnabled (true);
        mDepthState->SetWritable ( true);
        mDepthState->SetCompare (  DepthStateFlags::CompareMode::LessEqual);

        // Enable the stencil buffer so that the shadow can be clipped by the
        // plane.  The stencil values are set whenever the corresponding
        // plane pixels are visible.
        mStencilState->SetEnabled ( true);
        mStencilState->SetCompare ( StencilStateFlags::CompareMode::Always);
        mStencilState->SetReference ( (unsigned int)(i + 1));
        mStencilState->SetOnFail ( StencilStateFlags::OperationType::Keep);      // irrelevant
        mStencilState->SetOnZFail ( StencilStateFlags::OperationType::Keep);     // invisible to 0
        mStencilState->SetOnZPass ( StencilStateFlags::OperationType::Replace);  // visible to i+1

        // Draw the plane.
        renderer->Draw(mPlanes[i].GetData());

        // Blend the shadow color with the pixels drawn on the projection
        // plane.  The blending equation is
        //   (rf,gf,bf) = as*(rs,gs,bs) + (1-as)*(rd,gd,bd)
        // where (rf,gf,bf) is the final color to be written to the frame
        // buffer, (rs,gs,bs,as) is the shadow color, and (rd,gd,bd) is the
        // current color of the frame buffer.
        const ConstAlphaStateSmartPointer saveAState = renderer->GetOverrideAlphaState();
        renderer->SetOverrideAlphaState(mAlphaState);
        mAlphaState->SetBlendEnabled ( true);
        mAlphaState->SetSourceBlend ( AlphaStateFlags::SourceBlendMode::SourceAlpha);
        mAlphaState->SetDestinationBlend ( AlphaStateFlags::DestinationBlendMode::OneMinusSourceAlpha);
        mMaterial->SetDiffuse (Colour<float>(mShadowColors[i].GetFirstValue(),mShadowColors[i].GetSecondValue(),mShadowColors[i].GetThirdValue(),mShadowColors[i].GetFourthValue()));
		 
        // Disable the depth buffer reading so that no depth-buffer fighting
        // occurs.  The drawing of pixels is controlled solely by the stencil
        // value.
        mDepthState->SetEnabled ( false);

        // Only draw where the plane has been drawn.
        mStencilState->SetEnabled ( true);
        mStencilState->SetCompare ( StencilStateFlags::CompareMode::Equal);
        mStencilState->SetReference (  (unsigned int)(i + 1));
        mStencilState->SetOnFail (  StencilStateFlags::OperationType::Keep);   // invisible kept 0
        mStencilState->SetOnZFail (   StencilStateFlags::OperationType::Keep);  // irrelevant
        mStencilState->SetOnZPass ( StencilStateFlags::OperationType::Zero);  // visible set to 0

        // Get the projection matrix relative to the projector (light).
        Mathematics::Matrixf projection;
        if (!GetProjectionMatrix(i, projection))
        {
            continue;
        }
		// ��ͨ������
        //camera->SetPreViewMatrix(projection);

        // Draw the caster again, but temporarily use a material effect so
        // that the shadow color is blended onto the plane.  TODO:  This
        // drawing pass should use a VisibleSet relative to the projector so
        // that objects that are out of view (i.e. culled relative to the
        // camera and not in the camera's VisibleSet) can cast shadows.
        for (j = 0; j < numVisible; ++j)
        {
            Visual* visual = (Visual*)visibleSet.GetVisible(j).GetData();
            ConstVisualEffectInstanceSmartPointer save = visual->GetEffectInstance();
            visual->SetEffectInstance(mMaterialEffectInstance);
            renderer->Draw(visual);
			// ��ͨ������
           // visual->SetEffectInstance(save);
        }
		// ��ͨ������
        // camera->SetPreViewMatrix(Mathematics::Matrixf::sm_Identity);

        renderer->SetOverrideAlphaState(saveAState);
    }

    // Restore the global state that existed before this function call.
    renderer->SetOverrideStencilState(saveSState);
    renderer->SetOverrideDepthState(saveDState);
}

bool Rendering::PlanarShadowEffect
	::GetProjectionMatrix (int i, Mathematics::Matrixf& projection)
{
    // Compute the equation for the shadow plane in world coordinates.
    //Mathematics::APointf vertex[3];
	TrianglePosition vertex =  mPlanes[i]->GetWorldTriangle(0);
    Mathematics::Planef worldPlane(vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition());

    // This is a conservative test to see whether a shadow should be cast.
    // This can cause incorrect results if the caster is large and intersects
    // the plane, but ordinarily we are not trying to cast shadows in such
    // situations.
    if (mShadowCaster->GetWorldBound().WhichSide(worldPlane) < Mathematics::NumericalValueSymbol::Zero)
    {
        // The shadow caster is on the far side of plane, so it cannot cast
        // a shadow.
        return false;
    }

    // Compute the projection matrix for the light source.
    LightSmartPointer projector = mProjectors[i];
    Mathematics::AVectorf normal = worldPlane.GetNormal();
    if (projector->GetType() == LightType::Directional)
    {
        float NdD = Dot(normal,projector->GetDirectionVector());
        if (NdD >= 0.0f)
        {
            // The projection must be onto the "positive side" of the plane.
            return false;
        }

        projection.MakeObliqueProjection(vertex.GetFirstPosition(), normal,  projector->GetDirectionVector());
    }
    else if (projector->GetType() == LightType::Point ||  projector->GetType() == LightType::Spot)
    {
        float NdE = Dot(projector->GetPosition(),normal);
        if (NdE <= 0.0f)
        {
            // The projection must be onto the "positive side" of the plane.
            return false;
        }

        projection.MakePerspectiveProjection(vertex.GetFirstPosition(), normal, projector->GetPosition());
    }
    else
    {
        RENDERING_ASSERTION_0(false, "Light type not supported.\n");
        return false;
    }

    return true;
}



// Name support.
const CoreTools::ObjectSmartPointer Rendering::PlanarShadowEffect::
	GetObjectByName(const std::string& name)
{
	CoreTools::ObjectSmartPointer found = ParentType::GetObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}

	for (int i = 0; i < mNumPlanes; ++i)
	{
		CoreTools::ObjectSmartPointer found2 = mPlanes[i]->GetObjectByName(name);
		if (found2.IsValidPtr())
			return found2;

		found2 = mProjectors[i]->GetObjectByName(name);
		if (found2.IsValidPtr())
			return found2;
	}
		// Avoid the cycle by not checking mShadowCaster.
	return CoreTools::ObjectSmartPointer();
}     

const std::vector<CoreTools::ObjectSmartPointer> Rendering::PlanarShadowEffect
	::GetAllObjectsByName(const std::string& name)
{
	std::vector<CoreTools::ObjectSmartPointer> objects;
	CoreTools::ObjectSmartPointer found = ParentType::GetObjectByName(name);
	if (found.IsValidPtr())
	{
		objects.push_back(found);
	}

	for (int i = 0; i < mNumPlanes; ++i)
	{
		std::vector<CoreTools::ObjectSmartPointer> pointerObjects = mPlanes[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

		pointerObjects = mProjectors[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}
	// Avoid the cycle by not checking mShadowCaster.
	return objects;	
}   

const CoreTools::ConstObjectSmartPointer Rendering::PlanarShadowEffect
	::GetConstObjectByName(const std::string& name) const
{
		CoreTools::ConstObjectSmartPointer found = ParentType::GetConstObjectByName(name);
	if (found.IsValidPtr())
	{
		return found;
	}

	for (int i = 0; i < mNumPlanes; ++i)
	{
		CoreTools::ConstObjectSmartPointer found2 = mPlanes[i]->GetConstObjectByName(name);
		if (found2.IsValidPtr())
			return found2;

		found2 = mProjectors[i]->GetObjectByName(name);
		if (found2.IsValidPtr())
			return found2;
	}
		// Avoid the cycle by not checking mShadowCaster.
	return CoreTools::ConstObjectSmartPointer();
} 

const std::vector<CoreTools::ConstObjectSmartPointer> Rendering::PlanarShadowEffect
	::GetAllConstObjectsByName(const std::string& name) const 
{
	std::vector<CoreTools::ConstObjectSmartPointer> objects  = ParentType::GetAllConstObjectsByName(name);

	for (int i = 0; i < mNumPlanes; ++i)
	{
		std::vector<CoreTools::ObjectSmartPointer> pointerObjects = mPlanes[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

		pointerObjects = mProjectors[i]->GetAllObjectsByName(name);

		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;
}


// Streaming support.

Rendering::PlanarShadowEffect
	::PlanarShadowEffect (LoadConstructor value)
    :GlobalEffect(value), mNumPlanes(0), mPlanes(0), mProjectors(0), mShadowColors(0)
{
}

void Rendering::PlanarShadowEffect
	::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    GlobalEffect::Load(source);

    source.ReadAggregate(mNumPlanes, mShadowColors);
    source.ReadSmartPointer(mNumPlanes, mPlanes);
    source.ReadSmartPointer(mNumPlanes, mProjectors);
    source.ReadSmartPointer(mShadowCaster);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::PlanarShadowEffect
	::Link(CoreTools::ObjectLink& source)
{
    GlobalEffect::Link(source);

    source.ResolveObjectSmartPointerLink(mNumPlanes, mPlanes);
    source.ResolveObjectSmartPointerLink(mNumPlanes, mProjectors);
    source.ResolveObjectSmartPointerLink(mShadowCaster);
}

void Rendering::PlanarShadowEffect
	::PostLink ()
{
    GlobalEffect::PostLink();

    mAlphaState .Reset( NEW0 AlphaState());
    mDepthState .Reset( NEW0 DepthState());
    mStencilState .Reset( NEW0 StencilState());
    mMaterial .Reset( NEW0 Material());
    mMaterialEffect .Reset( NEW0 MaterialEffect());
    mMaterialEffectInstance .Reset( mMaterialEffect->CreateInstance(mMaterial.GetData()));
}

uint64_t Rendering::PlanarShadowEffect
	::Register(CoreTools::ObjectRegister& target) const
{
    uint64_t id = GlobalEffect::Register(target);
	if(0 < id)
    {
        target.RegisterSmartPointer(mNumPlanes, mPlanes);
        target.RegisterSmartPointer(mNumPlanes, mProjectors);
        target.RegisterSmartPointer(mShadowCaster);
        return id;
    }
    return id;
}

void Rendering::PlanarShadowEffect
	::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    GlobalEffect::Save(target);

    target.WriteAggregateWithNumber(mNumPlanes, mShadowColors);
    target.WriteSmartPointerWithNumber(mNumPlanes, mPlanes);
    target.WriteSmartPointerWithNumber(mNumPlanes, mProjectors);
    target.WriteSmartPointer(mShadowCaster);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::PlanarShadowEffect
	::GetStreamingSize () const
{
    int size = GlobalEffect::GetStreamingSize();
    size += CORE_TOOLS_STREAM_SIZE(mNumPlanes);
    size += mNumPlanes*CORE_TOOLS_STREAM_SIZE(mShadowCaster);
    size += mNumPlanes*RENDERING_STREAM_SIZE(mPlanes[0]);
    size += mNumPlanes*RENDERING_STREAM_SIZE(mProjectors[0]);
    size += RENDERING_STREAM_SIZE(mShadowCaster);
    return size;
}



int Rendering::PlanarShadowEffect
	::GetNumPlanes () const
{
	return mNumPlanes;
}

void Rendering::PlanarShadowEffect
	::SetPlane (int i, TrianglesMeshSmartPointer plane)
{
	// The culling flag is set to "always" because this effect is responsible
	// for drawing the TriMesh.  This prevents drawing attempts by another
	// scene graph for which 'plane' is a leaf node.
	mPlanes[i] = plane;
	mPlanes[i]->SetCullingMode(CullingMode::Always);
}

Rendering::TrianglesMeshSmartPointer Rendering::PlanarShadowEffect
	::GetPlane (int i) const
{
	return mPlanes[i];
}

  void Rendering::PlanarShadowEffect
	  ::SetProjector (int i, Light* projector)
{
	mProjectors[i] .Reset( projector);
}

  Rendering::Light* Rendering::PlanarShadowEffect
	  ::GetProjector (int i) const
{
	return mProjectors[i].GetData();
}

  void Rendering::PlanarShadowEffect
	  ::SetShadowColor (int i,const Mathematics::Float4& shadowColor)
{
	mShadowColors[i] = shadowColor;
}

  const Mathematics::Float4& Rendering::PlanarShadowEffect
	  ::GetShadowColor (int i) const
{
	return mShadowColors[i];
}
