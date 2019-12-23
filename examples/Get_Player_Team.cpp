int GetPlayerTeam(){
	int team;
	g_pEsp->ReadInt((LPCVOID*)(entityPoint + g_pEsp->m_iTeamNum), &team);
	return team;
}
