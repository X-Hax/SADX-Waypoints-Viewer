#include "pch.h"

float ratio = 10.0f;
float yPos = 30.0f;
bool isEnabled = false;

void setColor(int index)
{
	switch (index)
	{
	default:
		SetMaterial(1, 0.035, 0.003, 0.003);
		break;
	case 1:
		SetMaterial(1, 0.074, 0.588, 0.101);
		break;
	case 2:
		SetMaterial(1, 1, 0, 0);
		break;
	case 9:
		SetMaterial(1, 0, 0, 1);
		break;
	}
}

void __cdecl Renderer_Display(ObjectMaster* a1)
{
	if (MissedFrames || !isEnabled || !IsLevelChaoGarden())
		return;

	NJS_VECTOR scale = { 0.1f, 0.1, 0.1 };
	for (uint8_t j = 0; j < 16; j++) {

		for (int i = 0; i < ChaoWayPoints[j].nbIndex; i++)
		{
			setColor(j);
			njPushMatrix(_nj_current_matrix_ptr_);
			njTranslate(_nj_current_matrix_ptr_, (ChaoWayPoints[j].pos[i].x - 16) * ratio, yPos, (ChaoWayPoints[j].pos[i].z - 20) * ratio);
			njScaleV(0, &scale);
			DrawObject(&Sphere_Model);
			njPopMatrix(1);
			ResetMaterial();
		}
	}
}

void Render_Main(ObjectMaster* obj)
{
	if (!IsLevelChaoGarden()) {
		DeleteObject_(obj);
		return;
	}

	if (Controllers[0].PressedButtons & Buttons_Y)
	{
		isEnabled = !isEnabled;
	}

	obj->DisplaySub(obj);
}

void CreateRenderer()
{
	ObjectMaster* loaded = LoadObject(LoadObj_Data1, 2, Render_Main);
	loaded->DisplaySub = Renderer_Display;
	LoadWaypoints();
}