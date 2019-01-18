#pragma once
#include <windows.h>

// Version : eso.live.2.0.7.1154797
// All the pointers are 0x400000 based.
// IDA Pro sig scans
// s_pZoRenderManager:8B C8 89 4D FC EB 0B C1 E0 04 03 45 0C 8B C8 89 45 FC C1 EB 08 81 E3 ? ? ? ? 81 FB ? ? ? ? 7C 0E 81 E3 ? ? ? ? C1 E3 04 03 5D F8 EB 06 C1 E3 04 03 5D 0C 8B 09 8B C3 8B 10 83 E2 0F 33 DB 80 FA 03 0F 94 C3 83 E1 0F 33 D2 80 F9 03 0F 94 C2 85 DA 74 17 DD 40 08
// g_pClientCore:0F 58 CB 0F C6 C0 AA 0F 58 C8 0F 28 44 33
// GetFirstUnit:8B 01 85 C0 74 0D 8B 48 04 85 C9 74 06 8B C1 85 C0 75 F3 C3 - 0x400000
// GetNextUnit:55 8B EC 8B 4D 08 85 C9 74 09 - 0x400000
// GetIterUnit:55 8B EC 8B 45 08 8B 40 10 5D C2 04 00 - 0x400000
// GetName:55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 A1 ? ? ? ? 33 C5 89 45 F0 53 56 57 50 8D 45 F4 64 A3 ? ? ? ? 8B F1 - 0x400000
// GetPosition:55 8B EC 83 B9 ? ? ? ? ? 74 1C - 0x400000
// GetRenderHeading:83 B9 ? ? ? ? ? 74 14 8B 89 ? ? ? ? 8B 01 - 0x400000
// s_pCameraManager:8B 74 24 1C 0F 58 CF
// g_pClientWorld:55 8B EC 83 E4 F0 81 EC ? ? ? ? 53 8B 5D 08 56 8B 75 0C //Scroll Up For Actual Pointer
// ToRenderPosition:55 8B EC 83 EC 1C 56 8B F1 8B 0D ? ? ? ? 57 85 C9 - 0x400000
	
class Offsets
{

public:
	
	enum class ZoRenderManager
	{
		s_pZoRenderManager = 0x1B31F58 - 0x400000,
		m_renderDeviceD3D9 = 0x4,											// From : ZoRenderManager::Present
		m_renderApiType = 0x84,												// From : ZosClient::Initialize
	};

	enum class ZoRenderDeviceD3D9
	{
		m_d3ddevice9 = 0x90,												// From : ZoRenderDeviceD3D9::Present
	};

	enum class ClientCoreHandles
	{
		g_pClientCore = 0x198EC5C - 0x400000,
		m_unitList = 0xD8,													// From : CancelCast
		GetUnitListAddress = 0x005A5EF0 - 0x400000,
	};
	
	enum class UnitList
	{
		GetFirstUnit = 0x00A02190 - 0x400000,									// UnitList::GetFirstUnit
		GetNextUnit = 0x00A03330 - 0x400000,									// UnitList::GetNextUnit
		GetIterUnit = 0x00A021D0 - 0x400000,									// UnitList::GetIterUnit
		m_playerUnit = 0x50,												// From : UnitList::GetPlayerUnit
	};
	
	enum class Unit
	{
		GetName = 0x009F9270 - 0x400000,										// Unit::GetName
		GetPosition = 0x009F1660 - 0x400000,									// Unit::GetPosition
		GetRenderHeading = 0x009F3D20 - 0x400000,								// Unit::GetRenderHeading
		m_type = 0x94,														// From : Unit::IsKillable
	};
	
	enum class CameraManager
	{
		s_pCameraManager = 0x198DC68 - 0x400000,
	};
	
	enum class ClientWorld
	{
		g_pClientWorld = 0x198E6DC - 0x400000,
		m_camera = 0x5E0,													// From : UpdateZoRenderData
	};
	
	enum class ZoCamera
	{
		m_viewMatrix = 0x44,												// From : ZoCamera::GetViewMatrix
		m_projectionMatrix = 0x84,											// From : ZoCamera::GetProjectionMatrix
	};
	
	enum class WorldPosition
	{
		ToRenderPosition = 0x0089FFE0 - 0x400000,
	};

};
