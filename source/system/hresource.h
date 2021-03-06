#ifndef _H_PUNK_SYSTEM_H_RESOURCE
#define _H_PUNK_SYSTEM_H_RESOURCE

#include "../config.h"
#include "../string/string.h"

namespace System
{
	enum ObjectType : int
	{
		RESOURCE_NONE = -1,
		STATIC_MESH = 10,
		SKIN_MESH,
		QUAD,
		SOUND_2D,
		SOUND_3D,
		FPS_CAMERA,
		PORTAL_NODE,
		AUDIO_BUFFER,
		TEXTURE_2D,
		TEXTURE_3D,
		MATERIAL,
		ARMATURE,
		ARMATURE_ANIMATION_MIXER,
		POINT_LIGHT,		
		SCENE_GRAPH,
		NODE,		
		LIGHT_NODE,
		POINT_LIGHT_NODE,
		CAMERA_NODE,
		MATERIAL_NODE,
		GEOMETRY_NODE,
		STATIC_MESH_NODE,
		SKIN_MESH_NODE,
		TRANSFORM_NODE,
		ARMATURE_NODE,
		BONE_NODE,
		LOCATION_INDOOR,
		STATIC_GEOMETRY,
		SKIN_GEOMETRY,
		GUI_WIDGET,
		GUI_BUTTON,
		GUI_LABEL,
		GUI_TEXT_BOX,
		AUDIO_WAV,
		ACTION,
		ANIMATION,
		TERRAIN,
		TERRAIN_NODE
	};

	PUNK_ENGINE const System::string AsString(ObjectType type);

}

#endif	//	_H_PUNK_SYSTEM_H_RESOURCE