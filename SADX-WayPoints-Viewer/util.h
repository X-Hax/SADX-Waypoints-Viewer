#pragma once

struct POS_XZ
{
	int x;
	int z;
};

struct LAND_ATTR_INDEX
{
	int nbIndex;
	POS_XZ pos[1024];
};

DataArray(LAND_ATTR_INDEX, ChaoWayPoints, 0x3CA6EC8, 16);
VoidFunc(LoadWaypoints, 0x719E10);