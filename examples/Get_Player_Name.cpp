string GetPlayerName(){
	DWORD RadarBase;
	g_pEsp->ReadDword((LPCVOID*)(g_pCsgo->client_dll_base + g_pEsp->dwRadarBase), &RadarBase);
	DWORD HudRadar;
	// 0x74 can be change in future. you can find again with reclass. You go RadarBase with ReClass. you can look lines. line should point to CCSGO_HudRadar
	// 0x74 gelecekte değişebilir. ReClass kullanarak bunu bulabilirsin. RadarBase konumuna gidersen satırlara baktığında CCSGO_HudRadar ı işaret eden satırın ofsetidir.
	// Ex/Örn:https://raw.githubusercontent.com/atiksoftware/csgo_memory_hacking_examples/master/examples/example_GetPlayerName.jpg
	g_pEsp->ReadDword((LPCVOID*)(RadarBase + 0x74), &HudRadar);

	char cName[128];
	DWORD NamePoint = HudRadar + (0x174 * (entityIndex + 2)) + 0x18;
	g_pEsp->ReadBytes((LPCVOID*)(NamePoint), 128,&cName);

	return std::string(cName); 
}
