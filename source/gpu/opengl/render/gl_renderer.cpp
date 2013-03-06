#include "gl_renderer.h"
#include "gl_batch.h"
#include "../render_context/module.h"
#include "../render_targets/module.h"
#include "../../common/gpu_state.h"
#include "../textures/module.h"

namespace GPU
{
	namespace OpenGL
	{
		RenderPass::RenderPass(std::vector<Batch*>& batches)
			: m_batches(batches)
		{}

		void RenderPass::Run()
		{		
			TextureContext tc;
			for each (auto batch in m_batches)
			{
				tc.Clear();
				AbstractRenderPolicy* policy = nullptr;
				CoreState* state = batch->m_state;
				if (state->m_enable_skinning)
				{				
					tc.SetTexture(0, state->m_map[0]);
					tc.SetTexture(1, state->m_map[1]);
					policy = AbstractRenderPolicy::find(RC_SKINNING);
				}
				else if (state->m_enable_terrain)
				{
					tc.SetTexture(0, state->m_map[0]);
					tc.SetTexture(1, state->m_map[1]);
					tc.SetTexture(2, state->m_map[2]);
					tc.SetTexture(3, state->m_map[3]);
					policy = AbstractRenderPolicy::find(RC_TERRAIN);
				}
				else if (state->m_enable_bump_mapping)
				{
					tc.SetTexture(0, state->m_map[0]);
					tc.SetTexture(1, state->m_map[1]);
					policy = AbstractRenderPolicy::find(RC_BUMP_MAPING);
				}
				else if (state->m_enable_lighting)
				{
					if (state->m_enable_texture)
					{
						if (state->m_enable_diffuse_shading)
						{
							if (state->m_enable_bump_mapping)
							{
								//	skinning-lighting-texture-diffuse-bump
								policy = AbstractRenderPolicy::find(RC_BUMP_MAPING);
							} 
							else if (state->m_enable_specular_shading)
							{
								//	skinning-lighting-texture-diffuse-specular
								policy;	//	should be selected policy with diffuse and specular lighting plus diffuse texture
							}
							else
							{
								//	skinning-lighting-texture-diffuse
								policy;	//	should be selected policy with diffuse color, diffuse texture, with lighting, but without specular color
							}
						}							
					}
					else 
					{
						if (state->m_enable_diffuse_shading)
						{
							if (state->m_enable_specular_shading)
							{
								//	skinning-lighting-diffuse-specular
								policy;	//	should be used specular policy with diffuse and specular but without texturing
							}
							else
							{
								//	skinning-lighting-diffuse
								policy;
							}
						}
					}
				}
				else	//	NO LIGHTING
				{
					if (state->m_enable_texture)
					{
						if (state->m_enable_diffuse_shading)
						{
							//	skinning-texture-diffuse
							policy;	//	should be selected policy with diffuse color, diffuse texture, with lighting, but without specular color
						}							
					}
					else 
					{
						if (state->m_enable_diffuse_shading)
						{
							//	skinning-diffuse
							policy;
						}
					}
				}

				Renderable* renderable = batch->m_renderable;
				tc.Bind();
				policy->Begin();
				policy->BindParameters(*state);				
				renderable->Bind(policy->GetRequiredAttributesSet());
				renderable->Render();
				renderable->Unbind();
				policy->End();
				tc.Unbind();
			}
		}
	}
}